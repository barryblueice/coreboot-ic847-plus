/* SPDX-License-Identifier: GPL-2.0-only */

#include <bootblock_common.h>
#include <device/pci_ops.h>
#include <northbridge/intel/sandybridge/sandybridge.h>
#include <southbridge/intel/bd82x6x/pch.h>

void bootblock_mainboard_early_init(void)
{
	/*
	 * Early GPIO and board-specific setup.
	 * GPIOs are already programmed by the common GPIO setup
	 * (setup_pch_gpios), called before this hook.
	 *
	 * Add any board-specific early init here:
	 * - Super I/O early config
	 * - EC early init (e.g. EC communication setup)
	 * - Special GPIO toggling
	 */
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
