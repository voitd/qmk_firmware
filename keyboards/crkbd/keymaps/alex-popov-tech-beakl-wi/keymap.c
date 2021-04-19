#include QMK_KEYBOARD_H
#include "split_util.h"

extern uint8_t is_master;

#define _BASE 0
#define _DICT 1
#define _LSYM 2
#define _RSYM 3
/* #define _CTL 4 */

enum custom_keycodes {
  COL = SAFE_RANGE,
  WEAK_HARD,
  PIPE,
  DICT_F13,
};


#define TILDA S(KC_GRV)
#define LCBRC S(KC_LBRC)
#define RCBRC S(KC_RBRC)
#define LRBR S(KC_9)
#define RRBR S(KC_0)

#define CMD_TAB CMD_T(KC_TAB)
#define SYM_BSPC LT(_LSYM, KC_BSPC)
#define SYM_SPC LT(_RSYM, KC_SPC)
/* #define CTL_BSPC LT(_CTL, KC_BSPC) */
/* #define CTL_SPC LT(_CTL, KC_SPC) */
#define CTRL_ENT CTL_T(KC_ENT)
#define CTRL_ESC CTL_T(KC_ESC)
#define SHFT_ENT SFT_T(KC_ENT)
#define SHFT_ESC SFT_T(KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_3(
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------
      KC_F11  , COL     , KC_Y    , KC_O    , KC_U    , KC_MINUS,                      KC_G    , KC_D    , KC_N    , KC_M    , KC_Z    , KC_F12 ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------
      KC_LBRC , KC_Q    , KC_H    , KC_E    , KC_A    , KC_W    ,                      KC_C    , KC_T    , KC_R    , KC_S    , KC_L    , KC_RBRC,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------
      DICT_F13, KC_J    , KC_COMM , KC_DOT  , KC_K    , KC_QUOT ,                      KC_B    , KC_P    , KC_V    , KC_F    , KC_X    ,KC_SLASH,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------
                                              KC_I    , SYM_BSPC,SHFT_ENT,   CTRL_ESC, SYM_SPC , CMD_TAB
  //                                         ---------+---------+---------  ---------+---------+---------
  ),
  [_DICT] = LAYOUT_split_3x6_3(
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------
      KC_Q    , KC_W    ,WEAK_HARD, KC_Z    , KC_QUOT ,KC_LBRC ,                       KC_P    , KC_D    , KC_R    , KC_L    , KC_X    , KC_O   ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------
      _______ , KC_E    , KC_B    , KC_T    , KC_J    , KC_F   ,                       KC_K    , KC_Y    , KC_N    , KC_C    , KC_H    , KC_I   ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------
      _______ , KC_A    ,S(KC_SLASH),KC_SLASH, KC_S   , KC_DOT ,                       KC_COMMA, KC_V    , KC_G    , KC_U    , KC_SCLN , _______,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------
                                               _______, _______,  _______,   _______ , _______ , _______
  //                                         ---------+---------+---------  ---------+---------+---------
  ),
  [_LSYM] = LAYOUT_split_3x6_3(
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------
      RGB_TOG , RGB_MOD , _______ , LRBR    , RRBR    , PIPE   ,                       _______ , KC_4    , KC_5    , KC_6    , _______ , _______,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------
      RGB_HUI , _______ , KC_LEFT , LCBRC   , RCBRC   , _______,                       KC_0    , KC_1    , KC_2    , KC_3    , KC_RIGHT, RGB_VAI,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------
      RGB_HUD , KC_DOWN , _______ , KC_EQL  , KC_UP   , KC_GRV ,                       _______ , KC_7    , KC_8    , KC_9    , _______ , RGB_VAD,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------
                                              _______ , _______ , _______,   _______ , _______ , _______
  //                                         ---------+---------+---------  ---------+---------+---------
  ),
  [_RSYM] = LAYOUT_split_3x6_3(
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------
      RGB_M_P , _______ , _______ , LRBR    , RRBR    , PIPE   ,                       _______ , KC_4    , KC_5    , KC_6    , _______ , _______,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------
      RGB_SAI , _______ , KC_LEFT , LCBRC   , RCBRC   , _______,                       KC_0    , KC_1    , KC_2    , KC_3    , KC_RIGHT, _______,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------
      RGB_SAD , KC_DOWN , _______ , KC_EQL  , KC_UP   , KC_GRV ,                       _______ , KC_7    , KC_8    , KC_9    , _______ , _______,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------
                                              _______ , _______ , _______,   _______ , _______ , _______
  //                                         ---------+---------+---------  ---------+---------+---------
  ),
  /* [_CTL] = LAYOUT_split_3x6_3( */
  /* // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- */
  /*     _______ , _______ , C(KC_Y) , C(KC_O) , C(KC_U) , KC_MINUS,                      C(KC_G) , C(KC_D) , C(KC_N) , C(KC_M) , C(KC_Z) , _______ , */
  /* // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- */
  /*    C(KC_LBRC), C(KC_Q), C(KC_H) , C(KC_E) , C(KC_A) , C(KC_W) ,                      C(KC_C) , C(KC_T) , C(KC_R) , C(KC_S) , C(KC_L) ,C(KC_RBRC), */
  /* // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- */
  /*     _______ , C(KC_J) , C(KC_COMM),C(KC_DOT),C(KC_K), C(KC_QUOT),                    C(KC_B) , C(KC_P) , C(KC_V) , C(KC_F) , C(KC_X) ,C(KC_SLASH), */
  /* // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+--------- */
  /*                                             _______ , _______ , _______,   _______ , _______ , _______ */
  /* //                                         ---------+---------+---------  ---------+---------+--------- */
  /* ), */
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    /* switch (keycode) { */
        /* case L_BSPC: */
        /*     return TAPPING_TERM + 50; */
        /* case R_SPC: */
        /*     return TAPPING_TERM + 50; */
        /* case B_BSPC: */
        /*     return TAPPING_TERM + 50; */
        /* case B_SPC: */
        /*     return TAPPING_TERM + 50; */
        /* case SHFT_ENT: */
        /*     return TAPPING_TERM + 70; */
        /* case SHFT_ESC: */
        /*     return TAPPING_TERM + 70; */
        /* case CTL_I: */
        /*     return TAPPING_TERM - 70; */
        /* default: */
            return TAPPING_TERM;
    /* } */
}

/* uint32_t layer_state_set_user(uint32_t state) { */
/*   return update_tri_layer_state(state, _LEFT, _RIGHT, _BOTH); */
/* } */

const char *read_logo(void);
#ifdef OLED_DRIVER_ENABLE
void render_qmk_and_layer(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };
    oled_write_P(qmk_logo, false);

    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("________base_______"), false);
            break;
        case _LSYM:
            oled_write_P(PSTR("________sym________"), false);
            break;
        case _RSYM:
            oled_write_P(PSTR("________sym________"), false);
            break;
        /* case _CTL: */
            /* oled_write_P(PSTR("________ctl________"), false); */
            /* break; */
        case _DICT:
            oled_write_P(PSTR("______dictator_____"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undefined"), false);
    }
}

void oled_task_user(void) {
    render_qmk_and_layer();
}
#endif

uint16_t timer = 0;

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

    }
    return true;
};
