/* SPDX-License-Identifier: GPL-2.0-only */

#include <bootblock_common.h>
#include <device/pci_ops.h>
#include <northbridge/intel/sandybridge/sandybridge.h>
#include <southbridge/intel/bd82x6x/pch.h>

void mainboard_pch_lpc_setup(void)
{
	/* No SuperIO on this board - leave LPC at default */
}

void bootblock_mainboard_early_init(void)
{
	/* No SuperIO serial - use PCH UART or USB debug */
}

#if !CONFIG(USE_NATIVE_RAMINIT)
void mainboard_fill_pei_data(struct pei_data *pei_data)
{
	/* Only needed for MRC blob, can be empty for native RAM init */
}
#endif

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
