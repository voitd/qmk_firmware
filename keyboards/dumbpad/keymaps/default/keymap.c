/* Copyright 2019 imchipwood
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

#define _MAIN 0

enum custom_keycodes {
  LPASS = SAFE_RANGE,
  MACOS,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_MAIN] = LAYOUT(
                   KC_F1,         KC_F2,   KC_F3,  KC_F4,
                   KC_F5,         KC_F6,   KC_F7,  KC_F8,
                   KC_F9,         KC_F10,  KC_F11, KC_F12,
    KC_AUDIO_MUTE, KC_AUDIO_MUTE, MACOS,   LPASS,  KC_MEDIA_PLAY_PAUSE
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
      case LPASS:
          if (record->event.pressed) {
          } else {
          }
          break;
      case MACOS:
          if (record->event.pressed) {
          } else {
          }
          break;
  }
  return true;
  return true;
}

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  //debug_enable = true;
  //debug_matrix = true;
  //debug_keyboard = true;
  //debug_mouse = true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}

void encoder_update_user(uint8_t index, bool clockwise) {
  /*  Custom encoder control - handles CW/CCW turning of encoder
   *  Default behavior:
   *    main layer:
   *       CW: move mouse right
   *      CCW: move mouse left
   *    other layers:
   *       CW: = (equals/plus - increase slider in Adobe products)
   *      CCW: - (minus/underscore - decrease slider in adobe products)
   */
  if (index == 0) {
    if (clockwise) {
        tap_code(KC_VOLD);
    } else {
        tap_code(KC_VOLU);
    }
  } else {
    if (clockwise) {
        tap_code(KC_MEDIA_PREV_TRACK);
    } else {
        tap_code(KC_MEDIA_NEXT_TRACK);
    }
  }
}
