#include "utils.h"

bool isModHolded(uint16_t mod) {
    if (get_mods() & MOD_BIT(mod)) {
        return true;
    }
    return false;
}

void key_with_modded(keyrecord_t *record, uint16_t mod, uint16_t plain, bool applyModOnPlain, uint16_t modded, bool applyModOnModded) {
    if (record->event.pressed) {
        if (isModHolded(mod)) {
            if (applyModOnModded) {
                tap_code(modded);
            } else {
                unregister_code(mod);
                tap_code(modded);
                register_code(mod);
            }
        } else {
            if (applyModOnPlain) {
                register_code(mod);
                tap_code(plain);
                unregister_code(mod);
            } else {
                tap_code(plain);
            }
        }
    }
}
