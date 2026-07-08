/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * HDA Audio Verb Table
 *
 * TODO: Replace with the codec verb data for YOUR board.
 * You can get this by:
 *   1. Boot stock BIOS + Linux
 *   2. cat /proc/asound/card0/codec#0
 *   3. Use the codec vendor/device ID and pin configs
 *
 * For a first build, you can leave this as a minimal stub —
 * audio just won't work until you fill it in.
 */

#include <device/azalia_device.h>

const u32 cim_verb_data[] = {
	/* Placeholder — replace with your board's codec data */
	/* Format:
	 *   0xVVVVDDDD,  // Codec Vendor/Device ID
	 *   0xSSSSSSSS,  // Subsystem ID
	 *   0x000000NN,  // Number of jacks
	 *   AZALIA_PIN_CFG(0, nid, 0xNNNNNNNN),  // per jack
	 *   ...
	 */
};

const u32 pc_beep_verbs[] = {
	/* Placeholder — beep configuration */
};
AZALIA_ARRAY_SIZES;
