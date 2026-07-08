/* SPDX-License-Identifier: GPL-2.0-only */

#include <device/device.h>
#include <device/pci_ops.h>
#include <arch/io.h>
#include <console/console.h>
#include <option.h>
#include <southbridge/intel/bd82x6x/pch.h>

static void mainboard_enable(struct device *dev)
{
	unsigned int vr_hot;
	u16 gpio_base;
	u32 val;

	vr_hot = get_uint_option("vr_hot", 0);

	gpio_base = pci_read_config16(PCH_LPC_DEV, GPIO_BASE) & 0xfffc;

	if (vr_hot) {
		val = inl(gpio_base + 0x04);
		val &= ~(1 << 17);
		outl(val, gpio_base + 0x04);

		val = inl(gpio_base + 0x0c);
		val &= ~(1 << 17);
		outl(val, gpio_base + 0x0c);

		printk(BIOS_INFO, "VR_HOT#: forced low\n");
	} else {
		val = inl(gpio_base + 0x04);
		val |= (1 << 17);
		outl(val, gpio_base + 0x04);

		printk(BIOS_INFO, "VR_HOT#: disabled (input)\n");
	}
}

struct chip_operations mainboard_ops = {
	.enable_dev = mainboard_enable,
};
