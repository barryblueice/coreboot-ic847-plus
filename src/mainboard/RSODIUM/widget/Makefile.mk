## SPDX-License-Identifier: GPL-2.0-only

bootblock-y += gpio.c
bootblock-y += early_init.c

romstage-y += gpio.c
romstage-y += early_init.c

ramstage-y += mainboard.c
ramstage-y += hda_verb.c
ramstage-$(CONFIG_MAINBOARD_USE_LIBGFXINIT) += gma-mainboard.ads
