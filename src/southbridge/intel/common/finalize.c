/* SPDX-License-Identifier: GPL-2.0-only */

#include <console/console.h>
#include <device/pci_ops.h>
#include <option.h>
#include <security/lockdown/lockdown.h>
#include <southbridge/intel/common/pmbase.h>
#include <southbridge/intel/common/pmutil.h>
#include <southbridge/intel/common/rcba.h>
#include <spi-generic.h>

#include "finalize.h"

void intel_pch_finalize_smm(void)
{
	const pci_devfn_t lpc_dev = PCI_DEV(0, 0x1f, 0);

	/* Locking SPIBAR (FLOCKDN) prevents the SMM SmmStore variable write
	 * path from programming the SPI flash on this board, which makes the
	 * EDK2 payload fail to initialise its non-volatile variable store
	 * ("Firmware Volume for Variable Store is corrupted"). Keep the SPI
	 * opcode registers unlocked so SMM can still service SmmStore writes. */

	if (CONFIG(SPI_FLASH_SMM))
		spi_init();

	/* TCLOCKDN: TC Lockdown */
	RCBA32_OR(0x0050, (1UL << 31));

	/* BIOS Interface Lockdown */
	RCBA32_OR(0x3410, (1 << 0));

	/* Function Disable SUS Well Lockdown */
	RCBA_AND_OR(8, 0x3420, ~0U, (1 << 7));

	pci_or_config16(lpc_dev, D31F0_GEN_PMCON_1, SMI_LOCK);

	pci_or_config8(lpc_dev, D31F0_GEN_PMCON_LOCK,
		       ACPI_BASE_LOCK | SLP_STR_POL_LOCK);

	/*
	 * On this platform the ME is in an abnormal state (Manufacturing Mode,
	 * fw_init_complete=0, EOP skipped). When the ME is present but not
	 * fully initialised, a plain host reset (CF9=0x06) does not reset the
	 * ME, and the ME mishandles the reset - on this board it powers the
	 * platform down to G3 (like pulling the plug) instead of rebooting.
	 *
	 * Setting CF9GR (ETR3 bit 20) makes CF9 writes of 0x06 / 0x0e perform
	 * a global reset of host AND ME together (see the i82801ix comment in
	 * src/southbridge/intel/i82801ix/early_init.c: "Bit 20 activates global
	 * reset of host and ME on cf9 writes of 0x6 and 0xe (required if ME is
	 * disabled but present)"). That lets the abnormal ME reset cleanly and
	 * return the platform to S0 instead of dropping to G3.
	 *
	 * Only do this when the ME is in manufacturing mode (HFSTS1[4]=1);
	 * a normal ME keeps CF9GR cleared and locked as before.
	 *
	 * PCH_ME_DEV (0:16.0) HFSTS1 is at config offset 0x40, bit 4 is
	 * mfg_mode - identical on ibexpeak/bd82x6x/lynxpoint.
	 */
	const u32 me_hfs = pci_read_config32(PCI_DEV(0, 0x16, 0), 0x40);
	if (me_hfs & (1 << 4)) {
		/* ME in manufacturing mode: enable host+ME global reset on CF9. */
		pci_or_config32(lpc_dev, D31F0_ETR3, ETR3_CF9GR);
		printk(BIOS_INFO, "ME in manufacturing mode: enabling CF9GR (global reset)\n");
	} else {
		pci_update_config32(lpc_dev, D31F0_ETR3, ~ETR3_CF9GR, ETR3_CF9LOCK);
	}

	if (CONFIG(SOUTHBRIDGE_INTEL_LYNXPOINT))
		/* PMSYNC */
		RCBA32_OR(0x33c4, (1UL << 31));

	/* R/WO registers */
	RCBA32(0x21a4) = RCBA32(0x21a4);
	pci_write_config32(PCI_DEV(0, 27, 0), 0x74,
		    pci_read_config32(PCI_DEV(0, 27, 0), 0x74));

	if (enable_smm_bios_protection())
		write_pmbase16(SMI_EN, read_pmbase16(SMI_EN) | TCO_EN);

	write_pmbase16(TCO1_CNT, read_pmbase16(TCO1_CNT) | TCO_LOCK);

	post_code(POSTCODE_OS_BOOT);
}
