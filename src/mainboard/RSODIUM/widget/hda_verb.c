/* SPDX-License-Identifier: GPL-2.0-only */
/* Minimal stub - no audio on this board */

#include <device/azalia_device.h>

const u32 cim_verb_data[] = {};
const u32 pc_beep_verbs[] = {};
struct azalia_codec *mainboard_azalia_codecs;
AZALIA_ARRAY_SIZES;
