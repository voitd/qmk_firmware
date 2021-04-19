#include QMK_KEYBOARD_H
#include "split_util.h"

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _COLEMAK 0
#define _LEFT 1
#define _RIGHT 2
#define _BOTH 3

#define TILDA S(KC_GRV)
#define LPR S(KC_9)
#define RPR S(KC_0)
#define UDR S(KC_MINUS)
#define COL S(KC_SCLN)
#define LCBRC S(KC_LBRC)
#define RCBRC S(KC_RBRC)
#define CMD_LBRC LCMD_T(KC_LBRC)
#define CTL_RBRC LCTL_T(KC_RBRC)
#define CMD_TAB LCMD_T(KC_TAB)
#define CTL_TAB LCTL_T(KC_TAB)
#define CTL_ENT LCTL_T(KC_ENT)
#define L_BSPC LT(_LEFT, KC_BSPC)
#define R_SPC LT(_RIGHT, KC_SPC)
#define B_BSPC LT(_BOTH, KC_BSPC)
#define B_SPC LT(_BOTH, KC_SPC)
#define S_ENT SFT_T(KC_ENT)
#define S_ESC SFT_T(KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_F11,   KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y,  KC_QUOT,  KC_F12, \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LBRC ,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_K,    KC_N,    KC_E,    KC_O,    KC_I,  KC_RBRC , \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,  KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_M,    KC_H,   KC_COMM, KC_DOT, KC_SLSH,  _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         CMD_TAB, L_BSPC,  S_ENT,       S_ESC,  R_SPC,  CTL_TAB \
                                      //`--------------------------'  `--------------------------'
  ),
  [_LEFT] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______,   LPR,    LCBRC,  KC_EQL,  _______,                      KC_DOWN,KC_RIGHT, RCBRC,     RPR,    KC_GRV, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,  KC_1,    KC_2,    KC_3,    KC_4,   KC_PIPE,                       KC_UP,   KC_7,    KC_8,    KC_9,    KC_0,   _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, KC_SCLN,  COL   ,KC_MINUS,  KC_5,                         KC_6,   KC_LEFT,   COL  , KC_SCLN, _______, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______,  R_SPC , _______ \
                                      //`--------------------------'  `--------------------------'
    ),
  [_RIGHT] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______,   LPR,    LCBRC,  KC_EQL,  _______,                      KC_DOWN,KC_RIGHT, RCBRC,     RPR,    KC_GRV, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,  KC_1,    KC_2,    KC_3,    KC_4,   KC_PIPE,                       KC_UP,   KC_7,    KC_8,    KC_9,    KC_0,   _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, KC_SCLN,  COL   ,KC_MINUS,  KC_5,                         KC_6,   KC_LEFT,   COL  , KC_SCLN, _______, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, L_BSPC , _______,    _______, _______, _______ \
                                      //`--------------------------'  `--------------------------'
    ),
  [_BOTH] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______,   LPR,    LCBRC,  KC_PLUS, _______,                      C(KC_J), C(KC_L),  RCBRC,  RPR,    TILDA, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, S(KC_1), S(KC_2), S(KC_3), S(KC_4),KC_BSLASH,                     C(KC_K), S(KC_7), S(KC_8), S(KC_9), S(KC_0), _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, KC_SCLN,  COL   ,   UDR  , S(KC_5),                      S(KC_6), C(KC_H), COL  , KC_SCLN, _______, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______ \
                                      //`--------------------------'  `--------------------------'
    )
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case L_BSPC:
            return TAPPING_TERM + 50;
        case R_SPC:
            return TAPPING_TERM + 50;
        case B_BSPC:
            return TAPPING_TERM + 50;
        case B_SPC:
            return TAPPING_TERM + 50;
        case CMD_TAB:
            return TAPPING_TERM + 70;
        case S_ENT:
            return TAPPING_TERM + 70;
        case S_ESC:
            return TAPPING_TERM + 70;
        default:
            return TAPPING_TERM;
    }
}

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LEFT, _RIGHT, _BOTH);
}

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
        case _COLEMAK:
            oled_write_P(PSTR("_______colemak______"), false);
            break;
        case _LEFT:
            oled_write_P(PSTR("________left________"), false);
            break;
        case _RIGHT:
            oled_write_P(PSTR("________right_______"), false);
            break;
        case _BOTH:
            oled_write_P(PSTR("________both________"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undefined"), false);
    }
}

void oled_task_user(void) {
    render_qmk_and_layer();
}
#endif
