/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* Select hand configuration */
#define EE_HANDS

// #define SSD1306OLED
#undef USE_I2C
#undef SSD1306OLED

#define USE_SERIAL_PD2

#define ONESHOT_TAP_TOGGLE 3
#define ONESHOT_TIMEOUT 1500

#define TAPPING_TERM 180
#define TAPPING_TERM_PER_KEY

#define IGNORE_MOD_TAP_INTERRUPT


// #define TAPPING_FORCE_HOLD
// #define PERMISSIVE_HOLD
// #define LEADER_PER_KEY_TIMING
// #define LEADER_TIMEOUT 300

#ifdef RGBLIGHT_ENABLE
    #undef RGBLED_NUM
    #define RGBLIGHT_ANIMATIONS
    #define RGBLED_NUM 27
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 8
    #define RGBLIGHT_SAT_STEP 8
    #define RGBLIGHT_VAL_STEP 8
#endif

// #ifdef RGB_MATRIX_ENABLE
    // #define RGBLED_NUM 54  // Number of LEDs
    // #define DRIVER_LED_TOTAL RGBLED_NUM
// #endif

#ifdef RGB_MATRIX_ENABLE
#    define RGB_MATRIX_KEYPRESSES  // reacts to keypresses
// #   define RGB_MATRIX_KEYRELEASES // reacts to keyreleases (instead of keypresses)
// #   define RGB_DISABLE_AFTER_TIMEOUT 0 // number of ticks to wait until disabling effects
#    define RGB_DISABLE_WHEN_USB_SUSPENDED true  // turn off effects when suspended
// #   define RGB_MATRIX_LED_PROCESS_LIMIT (DRIVER_LED_TOTAL + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
// #   define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150  // limits maximum brightness of LEDs to 200 out of 255. If not defined maximum brightness is set to 255
#    define RGB_MATRIX_HUE_STEP 8
#    define RGB_MATRIX_SAT_STEP 8
#    define RGB_MATRIX_VAL_STEP 5
#    define RGB_MATRIX_SPD_STEP 10
#endif



#undef PRODUCT

// #define OLED_FONT_H "keyboards/crkbd/keymaps/voitd_oled/glcdfontstarter.c"

#define OLED_DISABLE_TIMEOUT
// #define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
