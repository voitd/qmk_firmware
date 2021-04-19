/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#define _COLEMAK 0
#define _LEFT 1
#define _RIGHT 2
#define _BOTH 3
#define _FUNC 4

enum custom_keycodes {
  LPASS = SAFE_RANGE,
  MACOS,
};

#define TILDA S(KC_GRV)
#define LPR S(KC_9)
#define RPR S(KC_0)
#define UDR S(KC_MINUS)
#define COL S(KC_SCLN)
#define LCBRC S(KC_LBRC)
#define RCBRC S(KC_RBRC)
#define CMD_TAB LCMD_T(KC_TAB)
#define CTL_TAB LCTL_T(KC_TAB)
#define CTL_ENT LCTL_T(KC_ENT)
#define L_BSPC LT(_LEFT, KC_BSPC)
#define R_SPC LT(_RIGHT, KC_SPC)
#define B_BSPC LT(_BOTH, KC_BSPC)
#define B_SPC LT(_BOTH, KC_SPC)
#define MAX_FUNC LT(_FUNC, KC_F4)
#define MPLY_FUNC LT(_FUNC, KC_MPLY)
#define S_ENT SFT_T(KC_ENT)
#define S_ESC SFT_T(KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_COLEMAK] = LAYOUT(
  //|-----------------------------------------------|                                  |-----------------------------------------------|
     KC_F11,   KC_Q,   KC_W,   KC_F,   KC_P,  KC_B,                                       KC_J,   KC_L,   KC_U,   KC_Y, KC_QUOT, KC_F12,
  //|-------+-------+-------+-------+-------+-------|                                  |-------+-------+-------+-------+-------+-------|
     KC_LBRC,  KC_A,   KC_R,   KC_S,   KC_T,  KC_G,                                       KC_K,   KC_N,   KC_E,   KC_O,   KC_I, KC_RBRC,
  //|-------+-------+-------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-------+-------+-------|
     XXXXXXX,  KC_Z,   KC_X,   KC_C,   KC_D,  KC_V,  XXXXXXX,XXXXXXX,   XXXXXXX,XXXXXXX,  KC_M,   KC_H, KC_COMM, KC_DOT,KC_SLSH,XXXXXXX,
  //|-------+-------+-------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-------+-------+-------|
                           MPLY_FUNC,CMD_TAB, L_BSPC, S_ENT, XXXXXXX,   XXXXXXX, S_ESC,  R_SPC, CTL_TAB,MAX_FUNC
  //                        |-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------|
    ),
    [_LEFT] = LAYOUT(
  //|-----------------------------------------------|                                  |-----------------------------------------------|
     _______,_______,  LPR  , LCBRC , KC_EQL,XXXXXXX,                                   KC_DOWN,KC_RIGHT,RCBRC ,  RPR  ,KC_GRV ,_______,
  //|-------+-------+-------+-------+-------+-------|                                  |-------+-------+-------+-------+-------+-------|
     _______, KC_1  , KC_2  , KC_3  , KC_4  ,KC_PIPE,                                   KC_UP,   KC_7 ,  KC_8 ,  KC_9 ,  KC_0 ,_______,
  //|-------+-------+-------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-------+-------+-------|
     _______,_______,KC_SCLN,  COL  ,KC_MINUS, KC_5, XXXXXXX,XXXXXXX,   XXXXXXX,XXXXXXX,  KC_6  ,KC_LEFT, COL  ,KC_SCLN,_______,_______,
  //|-------+-------+-------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-------+-------+-------|
                             _______,_______,_______,_______,_______,   _______,_______, B_SPC ,_______,_______
  //                        |-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------|
    ),
    [_RIGHT] = LAYOUT(
  //|-----------------------------------------------|                                  |-----------------------------------------------|
     _______,_______,  LPR  , LCBRC , KC_EQL,XXXXXXX,                                   KC_DOWN,KC_RIGHT,RCBRC ,  RPR  ,KC_GRV ,_______,
  //|-------+-------+-------+-------+-------+-------|                                  |-------+-------+-------+-------+-------+-------|
     _______, KC_1  , KC_2  , KC_3  , KC_4  ,KC_MINUS,                                   KC_UP,   KC_7 ,  KC_8 ,  KC_9 ,  KC_0 ,_______,
  //|-------+-------+-------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-------+-------+-------|
     _______,_______,KC_SCLN,  COL  ,KC_MINUS, KC_5, XXXXXXX,XXXXXXX,   XXXXXXX,XXXXXXX,  KC_6  ,KC_LEFT, COL  ,KC_SCLN,_______,_______,
  //|-------+-------+-------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-------+-------+-------|
                             _______,_______,B_BSPC,_______,_______,   _______,_______,_______,_______,_______
  //                        |-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------|
    ),
    [_BOTH] = LAYOUT(
  //|-----------------------------------------------|                                  |-----------------------------------------------|
     _______,_______,  LPR,   LCBRC, KC_PLUS,_______,                                C(KC_DOWN),C(KC_RIGHT),RCBRC, RPR ,  TILDA,_______,\
  //|-------+-------+-------+-------+-------+-------|                                  |-------+-------+-------+-------+-------+-------|
     _______,S(KC_1),S(KC_2),S(KC_3),S(KC_4),KC_BSLASH,                                C(KC_UP),S(KC_7),S(KC_8),S(KC_9),S(KC_0),_______,
  //|-------+-------+-------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-------+-------+-------|
     _______,_______,KC_SCLN,  COL  ,  UDR,  S(KC_5),XXXXXXX,XXXXXXX,   XXXXXXX,XXXXXXX,S(KC_6),C(KC_LEFT), COL  ,KC_SCLN,_______,_______,
  //|-------+-------+-------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-------+-------+-------|
                             _______,_______,_______,_______,_______,   _______,_______,_______,_______,_______
  //                        |-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------|
    ),
    [_FUNC] = LAYOUT(
  //|-----------------------------------------------|                                  |-----------------------------------------------|
     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                                   XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
  //|-------+-------+-------+-------+-------+-------|                                  |-------+-------+-------+-------+-------+-------|
     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                                   XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
  //|-------+-------+-------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-------+-------+-------|
     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX, MACOS, LPASS,     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
  //|-------+-------+-------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-------+-------+-------|
                             XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,RGB_MOD,  RGB_RMOD,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX
  //                        |-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------|
    )
};

/* layer_state_t layer_state_set_user(layer_state_t state) { */
/*     return update_tri_layer_state(state, _DIGIT, _SDIGIT, _FUNC); */
/* } */

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

static void render_kyria_logo(void) {
    static const char PROGMEM kyria_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
        0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    };
    oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
}

static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}

static void render_status(void) {
    // QMK Logo and version information
    render_qmk_logo();
    oled_write_P(PSTR("Kyria rev1.0\n\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _COLEMAK:
            oled_write_P(PSTR("Colemak\n"), false);
            break;
        case _LEFT:
            oled_write_P(PSTR("Digit\n"), false);
            break;
        case _RIGHT:
            oled_write_P(PSTR("Digit\n"), false);
            break;
        case _BOTH:
            oled_write_P(PSTR("Symbol\n"), false);
            break;
        case _FUNC:
            oled_write_P(PSTR("FUNC\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_kyria_logo();
    }
}
#endif

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        switch (get_highest_layer(layer_state)) {
            case _COLEMAK:
                if (clockwise) {
                    tap_code(KC_VOLD);
                } else {
                    tap_code(KC_VOLU);
                }
                break;
            case _FUNC:
                if (clockwise) {
                    tap_code(KC_MPRV);
                } else {
                    tap_code(KC_MNXT);
                }
                break;
        }
    }
    else if (index == 1) {
        switch (get_highest_layer(layer_state)) {
            case _COLEMAK:
                if (clockwise) {
                    tap_code(KC_F9);
                } else {
                    tap_code(KC_F10);
                }
                break;
            case _FUNC:
                if (clockwise) {
                    tap_code(KC_F7);
                } else {
                    tap_code(KC_F8);
                }
                break;
        }
    }
}
#endif

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
        case MAX_FUNC:
            return TAPPING_TERM + 100;
        default:
            return TAPPING_TERM;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LPASS:
            if (record->event.pressed) {
                SEND_STRING("test");
            } else {
            }
            break;
        case MACOS:
            if (record->event.pressed) {
                SEND_STRING("test");
            } else {
            }
            break;
    }
    return true;
};
