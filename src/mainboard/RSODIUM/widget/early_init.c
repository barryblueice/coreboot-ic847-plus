/* SPDX-License-Identifier: GPL-2.0-only */

#include <bootblock_common.h>
#include <device/pci_ops.h>
#include <device/pnp_ops.h>
#include <northbridge/intel/sandybridge/sandybridge.h>
#include <southbridge/intel/bd82x6x/pch.h>
#include <superio/winbond/common/winbond.h>
#include <superio/winbond/w83627dhg/w83627dhg.h>

#define SIO_PORT 0x2e
#define SERIAL_DEV PNP_DEV(SIO_PORT, W83627DHG_SP1)

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
