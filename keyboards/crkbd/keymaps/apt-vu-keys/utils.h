#pragma once

#include QMK_KEYBOARD_H

bool isModHolded(uint16_t mod);
void key_with_modded(keyrecord_t *record, uint16_t mod, uint16_t plain, bool applyModOnPlain, uint16_t modded, bool applyModOnModded);
