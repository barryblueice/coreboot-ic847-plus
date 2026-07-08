/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * GPIO configuration for Acme Widget (QM77/QS77 PCH)
 *
 * IMPORTANT: This is a TEMPLATE based on the Kontron KTQM77.
 * You MUST replace these values with GPIOs dumped from your
 * original BIOS using:
 *
 *   inteltool -g   (run on the target board with stock BIOS + Linux)
 *
 * Each GPIO has three settings:
 *   MODE:    GPIO_MODE_NATIVE (use PCH function) or GPIO_MODE_GPIO
 *   DIR:     GPIO_DIR_INPUT or GPIO_DIR_OUTPUT
 *   LEVEL:   GPIO_LEVEL_HIGH or GPIO_LEVEL_LOW
 *
 * Key native functions on Panther Point:
 *   GPIO17 = VR_HOT#          GPIO29 = SLP_LAN#
 *   GPIO18 = PCIECLKRQ1#      GPIO30 = SUSWARN#
 *   GPIO26 = PCIECLKRQ4#      GPIO31 = ACPRESENT
 *   GPIO32 = CLKRUN#          GPIO61 = SUS_STAT#
 *   GPIO40-43 = OC1#~OC4#     GPIO62 = SUSCLK
 *   GPIO44-47 = PCIECLKRQ#    GPIO63 = SLP_S5#
 *   GPIO59 = OC0#             GPIO73 = PCIECLKRQ0#
 *   GPIO74 = SML1ALERT#       GPIO75 = SML1DATA
 */

#include <southbridge/intel/common/gpio.h>

/* ===== GPIO Set 1 (GPIO0 ~ GPIO31) ===== */

static const struct pch_gpio_set1 pch_gpio_set1_mode = {
	.gpio0  = GPIO_MODE_GPIO,
	.gpio1  = GPIO_MODE_GPIO,
	.gpio2  = GPIO_MODE_GPIO,
	.gpio3  = GPIO_MODE_GPIO,
	.gpio4  = GPIO_MODE_GPIO,
	.gpio5  = GPIO_MODE_GPIO,
	.gpio6  = GPIO_MODE_GPIO,
	.gpio7  = GPIO_MODE_GPIO,
	.gpio8  = GPIO_MODE_GPIO,
	.gpio9  = GPIO_MODE_NATIVE,	/* OC5# */
	.gpio10 = GPIO_MODE_NATIVE,	/* OC6# */
	.gpio11 = GPIO_MODE_NATIVE,	/* SMBALERT# */
	.gpio12 = GPIO_MODE_NATIVE,
	.gpio13 = GPIO_MODE_GPIO,
	.gpio14 = GPIO_MODE_NATIVE,	/* OC7# */
	.gpio15 = GPIO_MODE_GPIO,
	.gpio16 = GPIO_MODE_GPIO,
	.gpio17 = GPIO_MODE_GPIO,	/* VR_HOT# — set GPIO to disable */
	.gpio18 = GPIO_MODE_NATIVE,	/* PCIECLKRQ1# */
	.gpio19 = GPIO_MODE_GPIO,
	.gpio20 = GPIO_MODE_GPIO,
	.gpio21 = GPIO_MODE_GPIO,
	.gpio22 = GPIO_MODE_GPIO,
	.gpio23 = GPIO_MODE_NATIVE,	/* LDRQ1# */
	.gpio24 = GPIO_MODE_GPIO,
	.gpio25 = GPIO_MODE_GPIO,
	.gpio26 = GPIO_MODE_NATIVE,	/* PCIECLKRQ4# */
	.gpio27 = GPIO_MODE_GPIO,
	.gpio28 = GPIO_MODE_GPIO,
	.gpio29 = GPIO_MODE_NATIVE,	/* SLP_LAN# */
	.gpio30 = GPIO_MODE_NATIVE,	/* SUSWARN# */
	.gpio31 = GPIO_MODE_NATIVE,	/* ACPRESENT */
};

static const struct pch_gpio_set1 pch_gpio_set1_direction = {
	.gpio0  = GPIO_DIR_INPUT,
	.gpio1  = GPIO_DIR_INPUT,
	.gpio2  = GPIO_DIR_INPUT,
	.gpio3  = GPIO_DIR_INPUT,
	.gpio4  = GPIO_DIR_INPUT,
	.gpio5  = GPIO_DIR_INPUT,
	.gpio6  = GPIO_DIR_INPUT,
	.gpio7  = GPIO_DIR_INPUT,
	.gpio8  = GPIO_DIR_OUTPUT,
	.gpio9  = GPIO_DIR_INPUT,
	.gpio10 = GPIO_DIR_INPUT,
	.gpio11 = GPIO_DIR_INPUT,
	.gpio12 = GPIO_DIR_INPUT,
	.gpio13 = GPIO_DIR_INPUT,
	.gpio14 = GPIO_DIR_INPUT,
	.gpio15 = GPIO_DIR_OUTPUT,
	.gpio16 = GPIO_DIR_INPUT,
	.gpio17 = GPIO_DIR_INPUT,	/* VR_HOT# */
	.gpio18 = GPIO_DIR_INPUT,
	.gpio19 = GPIO_DIR_OUTPUT,
	.gpio20 = GPIO_DIR_INPUT,
	.gpio21 = GPIO_DIR_INPUT,
	.gpio22 = GPIO_DIR_INPUT,
	.gpio23 = GPIO_DIR_INPUT,
	.gpio24 = GPIO_DIR_OUTPUT,
	.gpio25 = GPIO_DIR_INPUT,
	.gpio26 = GPIO_DIR_INPUT,
	.gpio27 = GPIO_DIR_INPUT,
	.gpio28 = GPIO_DIR_OUTPUT,
	.gpio29 = GPIO_DIR_INPUT,
	.gpio30 = GPIO_DIR_INPUT,
	.gpio31 = GPIO_DIR_INPUT,
};

static const struct pch_gpio_set1 pch_gpio_set1_level = {
	.gpio0  = GPIO_LEVEL_LOW,
	.gpio1  = GPIO_LEVEL_LOW,
	.gpio2  = GPIO_LEVEL_LOW,
	.gpio3  = GPIO_LEVEL_LOW,
	.gpio4  = GPIO_LEVEL_LOW,
	.gpio5  = GPIO_LEVEL_LOW,
	.gpio6  = GPIO_LEVEL_LOW,
	.gpio7  = GPIO_LEVEL_LOW,
	.gpio8  = GPIO_LEVEL_LOW,
	.gpio9  = GPIO_LEVEL_LOW,
	.gpio10 = GPIO_LEVEL_LOW,
	.gpio11 = GPIO_LEVEL_LOW,
	.gpio12 = GPIO_LEVEL_LOW,
	.gpio13 = GPIO_LEVEL_LOW,
	.gpio14 = GPIO_LEVEL_LOW,
	.gpio15 = GPIO_LEVEL_LOW,
	.gpio16 = GPIO_LEVEL_LOW,
	.gpio17 = GPIO_LEVEL_HIGH,	/* VR_HOT# — pull high to avoid false trigger */
	.gpio18 = GPIO_LEVEL_LOW,
	.gpio19 = GPIO_LEVEL_HIGH,
	.gpio20 = GPIO_LEVEL_LOW,
	.gpio21 = GPIO_LEVEL_LOW,
	.gpio22 = GPIO_LEVEL_LOW,
	.gpio23 = GPIO_LEVEL_LOW,
	.gpio24 = GPIO_LEVEL_HIGH,
	.gpio25 = GPIO_LEVEL_LOW,
	.gpio26 = GPIO_LEVEL_LOW,
	.gpio27 = GPIO_LEVEL_LOW,
	.gpio28 = GPIO_LEVEL_HIGH,
	.gpio29 = GPIO_LEVEL_LOW,
	.gpio30 = GPIO_LEVEL_LOW,
	.gpio31 = GPIO_LEVEL_LOW,
};

/* ===== GPIO Set 2 (GPIO32 ~ GPIO63) ===== */

static const struct pch_gpio_set2 pch_gpio_set2_mode = {
	.gpio32 = GPIO_MODE_NATIVE,	/* CLKRUN# */
	.gpio33 = GPIO_MODE_GPIO,
	.gpio34 = GPIO_MODE_GPIO,
	.gpio35 = GPIO_MODE_GPIO,
	.gpio36 = GPIO_MODE_GPIO,
	.gpio37 = GPIO_MODE_GPIO,
	.gpio38 = GPIO_MODE_GPIO,
	.gpio39 = GPIO_MODE_GPIO,
	.gpio40 = GPIO_MODE_NATIVE,	/* OC1# */
	.gpio41 = GPIO_MODE_NATIVE,	/* OC2# */
	.gpio42 = GPIO_MODE_NATIVE,	/* OC3# */
	.gpio43 = GPIO_MODE_NATIVE,	/* OC4# */
	.gpio44 = GPIO_MODE_NATIVE,	/* PCIECLKRQ5# */
	.gpio45 = GPIO_MODE_NATIVE,	/* PCIECLKRQ6# */
	.gpio46 = GPIO_MODE_NATIVE,	/* PCIECLKRQ7# */
	.gpio47 = GPIO_MODE_NATIVE,	/* PEG_A_CLKRQ# */
	.gpio48 = GPIO_MODE_GPIO,
	.gpio49 = GPIO_MODE_GPIO,
	.gpio50 = GPIO_MODE_GPIO,
	.gpio51 = GPIO_MODE_GPIO,
	.gpio52 = GPIO_MODE_GPIO,
	.gpio53 = GPIO_MODE_GPIO,
	.gpio54 = GPIO_MODE_GPIO,
	.gpio55 = GPIO_MODE_GPIO,
	.gpio56 = GPIO_MODE_GPIO,
	.gpio57 = GPIO_MODE_GPIO,
	.gpio58 = GPIO_MODE_NATIVE,	/* SML1CLK */
	.gpio59 = GPIO_MODE_NATIVE,	/* OC0# */
	.gpio60 = GPIO_MODE_GPIO,
	.gpio61 = GPIO_MODE_NATIVE,	/* SUS_STAT# */
	.gpio62 = GPIO_MODE_NATIVE,	/* SUSCLK */
	.gpio63 = GPIO_MODE_NATIVE,	/* SLP_S5# */
};

static const struct pch_gpio_set2 pch_gpio_set2_direction = {
	.gpio32 = GPIO_DIR_INPUT,
	.gpio33 = GPIO_DIR_OUTPUT,
	.gpio34 = GPIO_DIR_INPUT,
	.gpio35 = GPIO_DIR_OUTPUT,
	.gpio36 = GPIO_DIR_INPUT,
	.gpio37 = GPIO_DIR_INPUT,
	.gpio38 = GPIO_DIR_INPUT,
	.gpio39 = GPIO_DIR_INPUT,
	.gpio40 = GPIO_DIR_INPUT,
	.gpio41 = GPIO_DIR_INPUT,
	.gpio42 = GPIO_DIR_INPUT,
	.gpio43 = GPIO_DIR_INPUT,
	.gpio44 = GPIO_DIR_INPUT,
	.gpio45 = GPIO_DIR_INPUT,
	.gpio46 = GPIO_DIR_INPUT,
	.gpio47 = GPIO_DIR_INPUT,
	.gpio48 = GPIO_DIR_INPUT,
	.gpio49 = GPIO_DIR_INPUT,
	.gpio50 = GPIO_DIR_OUTPUT,
	.gpio51 = GPIO_DIR_INPUT,
	.gpio52 = GPIO_DIR_OUTPUT,
	.gpio53 = GPIO_DIR_OUTPUT,
	.gpio54 = GPIO_DIR_OUTPUT,
	.gpio55 = GPIO_DIR_INPUT,
	.gpio56 = GPIO_DIR_INPUT,
	.gpio57 = GPIO_DIR_INPUT,
	.gpio58 = GPIO_DIR_INPUT,
	.gpio59 = GPIO_DIR_INPUT,
	.gpio60 = GPIO_DIR_OUTPUT,
	.gpio61 = GPIO_DIR_INPUT,
	.gpio62 = GPIO_DIR_INPUT,
	.gpio63 = GPIO_DIR_INPUT,
};

static const struct pch_gpio_set2 pch_gpio_set2_level = {
	.gpio32 = GPIO_LEVEL_LOW,
	.gpio33 = GPIO_LEVEL_LOW,
	.gpio34 = GPIO_LEVEL_LOW,
	.gpio35 = GPIO_LEVEL_HIGH,
	.gpio36 = GPIO_LEVEL_LOW,
	.gpio37 = GPIO_LEVEL_LOW,
	.gpio38 = GPIO_LEVEL_LOW,
	.gpio39 = GPIO_LEVEL_LOW,
	.gpio40 = GPIO_LEVEL_LOW,
	.gpio41 = GPIO_LEVEL_LOW,
	.gpio42 = GPIO_LEVEL_LOW,
	.gpio43 = GPIO_LEVEL_LOW,
	.gpio44 = GPIO_LEVEL_LOW,
	.gpio45 = GPIO_LEVEL_LOW,
	.gpio46 = GPIO_LEVEL_LOW,
	.gpio47 = GPIO_LEVEL_LOW,
	.gpio48 = GPIO_LEVEL_LOW,
	.gpio49 = GPIO_LEVEL_LOW,
	.gpio50 = GPIO_LEVEL_LOW,
	.gpio51 = GPIO_LEVEL_LOW,
	.gpio52 = GPIO_LEVEL_HIGH,
	.gpio53 = GPIO_LEVEL_HIGH,
	.gpio54 = GPIO_LEVEL_LOW,
	.gpio55 = GPIO_LEVEL_LOW,
	.gpio56 = GPIO_LEVEL_LOW,
	.gpio57 = GPIO_LEVEL_LOW,
	.gpio58 = GPIO_LEVEL_LOW,
	.gpio59 = GPIO_LEVEL_LOW,
	.gpio60 = GPIO_LEVEL_HIGH,
	.gpio61 = GPIO_LEVEL_LOW,
	.gpio62 = GPIO_LEVEL_LOW,
	.gpio63 = GPIO_LEVEL_LOW,
};

/* ===== GPIO Set 3 (GPIO64 ~ GPIO75) ===== */

static const struct pch_gpio_set3 pch_gpio_set3_mode = {
	.gpio64 = GPIO_MODE_GPIO,
	.gpio65 = GPIO_MODE_GPIO,
	.gpio66 = GPIO_MODE_GPIO,
	.gpio67 = GPIO_MODE_NATIVE,	/* CLKOUTFLEX3 */
	.gpio68 = GPIO_MODE_GPIO,
	.gpio69 = GPIO_MODE_GPIO,
	.gpio70 = GPIO_MODE_GPIO,
	.gpio71 = GPIO_MODE_GPIO,
	.gpio72 = GPIO_MODE_NATIVE,
	.gpio73 = GPIO_MODE_NATIVE,	/* PCIECLKRQ0# */
	.gpio74 = GPIO_MODE_NATIVE,	/* SML1ALERT#/PCHHOT# */
	.gpio75 = GPIO_MODE_NATIVE,	/* SML1DATA */
};

static const struct pch_gpio_set3 pch_gpio_set3_direction = {
	.gpio64 = GPIO_DIR_OUTPUT,
	.gpio65 = GPIO_DIR_OUTPUT,
	.gpio66 = GPIO_DIR_OUTPUT,
	.gpio67 = GPIO_DIR_INPUT,
	.gpio68 = GPIO_DIR_INPUT,
	.gpio69 = GPIO_DIR_INPUT,
	.gpio70 = GPIO_DIR_INPUT,
	.gpio71 = GPIO_DIR_INPUT,
	.gpio72 = GPIO_DIR_INPUT,
	.gpio73 = GPIO_DIR_INPUT,
	.gpio74 = GPIO_DIR_INPUT,
	.gpio75 = GPIO_DIR_INPUT,
};

static const struct pch_gpio_set3 pch_gpio_set3_level = {
	.gpio64 = GPIO_LEVEL_LOW,
	.gpio65 = GPIO_LEVEL_LOW,
	.gpio66 = GPIO_LEVEL_LOW,
	.gpio67 = GPIO_LEVEL_LOW,
	.gpio68 = GPIO_LEVEL_LOW,
	.gpio69 = GPIO_LEVEL_LOW,
	.gpio70 = GPIO_LEVEL_LOW,
	.gpio71 = GPIO_LEVEL_LOW,
	.gpio72 = GPIO_LEVEL_LOW,
	.gpio73 = GPIO_LEVEL_LOW,
	.gpio74 = GPIO_LEVEL_LOW,
	.gpio75 = GPIO_LEVEL_LOW,
};

const struct pch_gpio_map mainboard_gpio_map = {
	.set1 = {
		.mode		= &pch_gpio_set1_mode,
		.direction	= &pch_gpio_set1_direction,
		.level		= &pch_gpio_set1_level,
	},
	.set2 = {
		.mode		= &pch_gpio_set2_mode,
		.direction	= &pch_gpio_set2_direction,
		.level		= &pch_gpio_set2_level,
	},
	.set3 = {
		.mode		= &pch_gpio_set3_mode,
		.direction	= &pch_gpio_set3_direction,
		.level		= &pch_gpio_set3_level,
	},
};
