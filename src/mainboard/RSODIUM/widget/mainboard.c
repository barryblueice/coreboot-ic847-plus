/* SPDX-License-Identifier: GPL-2.0-only */

#include <device/device.h>
#include <console/console.h>
#include <southbridge/intel/bd82x6x/pch.h>

static void mainboard_enable(struct device *dev)
{
	/*
	 * Add board-specific initialization here.
	 * Most things are handled automatically by the Sandy Bridge /
	 * bd82x6x drivers, so this can be empty for a first boot attempt.
	 */
}

struct chip_operations mainboard_ops = {
	.enable_dev = mainboard_enable,
};
