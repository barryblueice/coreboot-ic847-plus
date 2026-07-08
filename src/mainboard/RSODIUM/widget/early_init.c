/* SPDX-License-Identifier: GPL-2.0-only */

#include <bootblock_common.h>
#include <device/pci_ops.h>
#include <device/pnp_ops.h>
#include <northbridge/intel/sandybridge/sandybridge.h>
#include <southbridge/intel/bd82x6x/pch.h>
#include <southbridge/intel/common/lpc_def.h>
#include <superio/winbond/common/winbond.h>
#include <superio/winbond/w83627dhg/w83627dhg.h>

#define SIO_PORT 0x2e
#define SERIAL_DEV PNP_DEV(SIO_PORT, W83627DHG_SP1)

/*
 * Configure LPC decode ranges so the PCH forwards I/O cycles
 * to the Super I/O chip on the LPC bus.
 */
void mainboard_pch_lpc_setup(void)
{
	/* COM1 decode range: 0x3f8-0x3ff (COMA = 0) */
	pci_write_config16(PCH_LPC_DEV, LPC_IO_DEC, 0x0000);

	/* Enable LPC: SIO config (2e/2f), KBC (60/64), COM1 */
	pci_write_config16(PCH_LPC_DEV, LPC_EN,
			   CNF1_LPC_EN | KBC_LPC_EN | COMA_LPC_EN);
}

void bootblock_mainboard_early_init(void)
{
	/* Enable Super I/O serial port for early console output */
	winbond_enable_serial(SERIAL_DEV, CONFIG_TTYS0_BASE);
}

void mainboard_fill_pei_data(struct pei_data *pei_data)
{
	/* Only needed for MRC blob, can be empty for native RAM init */
}

void mainboard_early_init(bool s3resume)
{
	/*
	 * Called during romstage after RAM init.
	 * Use for things like:
	 * - Enabling/disabling PEG (discrete GPU)
	 * - Late GPIO tweaks
	 */
}

void mainboard_late_rcba_config(void)
{
	/*
	 * Called after mainboard_early_init.
	 * Use for RCBA register tweaks on the PCH side.
	 */
}
