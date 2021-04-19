#include QMK_KEYBOARD_H

#define _BASE 0
#define _DICT 1
#define _SYM 2
#define _CTL 3

enum custom_keycodes {
  PIPE = SAFE_RANGE,
  COL,
  DOT_COL,
  COM_SCLN,
  DICT_F13,
  WEAK_HARD,
  I_O,
  Q_W
};

#define TILDA S(KC_GRV)
#define LCBRC S(KC_LBRC)
#define RCBRC S(KC_RBRC)
#define LRBR S(KC_9)
#define RRBR S(KC_0)

#define CMD_TAB CMD_T(KC_TAB)
#define CTL_TAB CTL_T(KC_TAB)
#define SHFT_ENT SFT_T(KC_ENT)
#define SHFT_ESC SFT_T(KC_ESC)

#define SYM_BSPC LT(_SYM, KC_BSPC)
#define SYM_SPC LT(_SYM, KC_SPC)
#define CTL_BSPC LT(_CTL, KC_BSPC)
#define CTL_SPC LT(_CTL, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT(
// ---------+---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------+---------
    RESET   , KC_F11  , KC_Q    , KC_M    , KC_N    , KC_D    , COM_SCLN,                      KC_G    , KC_U    , KC_Y    , KC_K    , KC_QUOT , KC_F12  , _______ ,
// ---------+---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------+---------
              KC_LBRC , KC_H    , KC_S    , KC_R    , KC_T    , KC_L    ,                      KC_B    , KC_A    , KC_E    , KC_O    , KC_I    , KC_RBRC ,
// ---------+---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------+---------
              DICT_F13, KC_X    , KC_C    , KC_V    , KC_P    , KC_Z    ,                      KC_SLASH, KC_W    , KC_F    , KC_J    , DOT_COL , _______ ,
// ---------+---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------+---------
                                                      CMD_TAB , SYM_BSPC, SHFT_ENT,  SHFT_ESC, SYM_SPC , CTL_TAB
//                                                   ---------+---------+---------  ---------+---------+---------
),
[_DICT] = LAYOUT(
// ---------+---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------+---------
    _______ , KC_Q    , KC_W    ,WEAK_HARD, KC_Z    , KC_SCLN ,S(KC_SLASH),                    KC_P    , KC_D    , KC_R    , KC_L    , KC_X    , _______ , _______ ,
// ---------+---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------+---------
              KC_O    , KC_E    , KC_B    , KC_T    , KC_J    , KC_F    ,                      KC_K    , KC_Y    , KC_N    , KC_C    , KC_H    , KC_I    ,
// ---------+---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------+---------
              _______ , KC_A    , KC_QUOT , KC_LBRC , KC_S    , KC_DOT  ,                      KC_COMMA, KC_V    , KC_G    , KC_U    , KC_SLASH, _______ ,
// ---------+---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------+---------
                                                      _______ , _______ , _______,   _______ , _______ , _______
//                                                   ---------+---------+---------  ---------+---------+---------
),
[_SYM] = LAYOUT(
// ---------+---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------+---------
    _______ , RGB_TOG , RGB_SAI , KC_4    , KC_5    , KC_6    , KC_0    ,                      KC_EQUAL, LRBR    , RRBR    , KC_UP   , KC_GRV  , _______ , _______ ,
// ---------+---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------+---------
              RGB_HUI , KC_LEFT , KC_1    , KC_2    , KC_3    ,KC_RIGHT ,                      KC_MINUS, LCBRC   , RCBRC   , PIPE    , COL     , RGB_VAI ,
// ---------+---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------+---------
              RGB_HUD , RGB_SAD , KC_7    , KC_8    , KC_9    ,_______  ,                   S(KC_EQUAL),S(KC_COMMA),S(KC_DOT),KC_DOWN, _______ , RGB_VAD ,
// ---------+---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------+---------
                                                      _______ , CTL_BSPC, _______,   _______ , CTL_SPC , _______
//                                                   ---------+---------+---------  ---------+---------+---------
),
[_CTL] = LAYOUT(
// ---------+---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------+---------
    _______ , _______ , C(KC_Q) , C(KC_M) , C(KC_N) , C(KC_D) , COM_SCLN,                      C(KC_G) , C(KC_U) , C(KC_Y) , C(KC_K) ,C(KC_QUOT), _______, _______ ,
// ---------+---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------+---------
            C(KC_LBRC), C(KC_H) , C(KC_S) , C(KC_R) , C(KC_T) , C(KC_L) ,                      C(KC_B) , C(KC_A) , C(KC_E) , C(KC_O) , C(KC_I) , C(KC_RBRC),
// ---------+---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------+---------
              _______ , C(KC_X) , C(KC_C) , C(KC_V) , C(KC_P) , C(KC_Z) ,                   C(KC_SLASH), C(KC_W) , C(KC_F) , C(KC_J) , DOT_COL , _______ ,
// ---------+---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------+---------
                                                      _______ , _______ , _______,   _______ , _______ , _______
//                                                   ---------+---------+---------  ---------+---------+---------
)
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CMD_TAB:
            return TAPPING_TERM + 70;
        case CTL_TAB:
            return TAPPING_TERM + 70;
        case SYM_BSPC:
            return TAPPING_TERM + 70;
        case SYM_SPC:
            return TAPPING_TERM + 70;
        case CTL_BSPC:
            return TAPPING_TERM + 70;
        case CTL_SPC:
            return TAPPING_TERM + 70;
        case SHFT_ENT:
            return TAPPING_TERM + 70;
        case SHFT_ESC:
            return TAPPING_TERM + 70;
        default:
            return TAPPING_TERM;
    }
}

uint16_t typing_timer = 0;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case COL:
            if (record->event.pressed) {
                if (get_mods() & (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT))) {
                    unregister_code(KC_LSHIFT);
                    tap_code(KC_SCLN);
                    register_code(KC_LSHIFT);
                } else {
                    register_code(KC_LSHIFT);
                    tap_code(KC_SCLN);
                    unregister_code(KC_LSHIFT);
                }
            } else {
            }
            break;
        case PIPE:
            if (record->event.pressed) {
                if (get_mods() & (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT))) {
                    unregister_code(KC_LSHIFT);
                    tap_code(KC_BSLASH);
                    register_code(KC_LSHIFT);
                } else {
                    register_code(KC_LSHIFT);
                    tap_code(KC_BSLASH);
                    unregister_code(KC_LSHIFT);
                }
            } else {
            }
            break;
        case WEAK_HARD:
            if (record->event.pressed) {
                if (get_mods() & (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT))) {
                    unregister_code(KC_LSFT);
                    tap_code(KC_RBRC);
                    register_code(KC_LSFT);
                } else {
                    tap_code(KC_M);
                }
            } else {
            }
            break;
        case I_O:
            if (record->event.pressed) {
                if (get_mods() & (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT))) {
                    unregister_code(KC_LSFT);
                    tap_code(KC_O);
                    register_code(KC_LSFT);
                } else {
                    tap_code(KC_I);
                }
            } else {
            }
            break;
        case Q_W:
            if (record->event.pressed) {
                if (get_mods() & (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT))) {
                    unregister_code(KC_LSFT);
                    tap_code(KC_W);
                    register_code(KC_LSFT);
                } else {
                    tap_code(KC_Q);
                }
            } else {
            }
            break;
        case DICT_F13:
            if(record->event.pressed) {
                tap_code(KC_F13);
                if (get_mods() & (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT))) {
                } else {
                    if(layer_state_is(_DICT)) {
                        layer_move(_BASE);
                    } else {
                        layer_move(_DICT);
                    }
                }
            } else {
            }
            break;
        case DOT_COL:
            if (record->event.pressed) {
                if (get_mods() & (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT))) {
                    tap_code(KC_SCLN);
                } else {
                    tap_code(KC_DOT);
                }
            } else {
            }
            break;
        case COM_SCLN:
            if (record->event.pressed) {
                if (get_mods() & (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT))) {
                    unregister_code(KC_LSFT);
                    tap_code(KC_SCLN);
                    register_code(KC_LSFT);
                } else {
                    tap_code(KC_COMMA);
                }
            } else {
            }
            break;
    }
    return true;
};
