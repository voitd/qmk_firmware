#include QMK_KEYBOARD_H
#include "split_util.h"

extern uint8_t is_master;
void rgb_matrix_layer_helper(uint8_t hue, uint8_t sat, uint8_t val, uint8_t mode, uint8_t speed, uint8_t led_type);
// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#ifdef OLED_DRIVER_ENABLE
static uint32_t        oled_timer = 0;
static char     keylog_str[6]   = {};
static uint16_t log_timer       = 0;
static const char PROGMEM code_to_name[0xFF] = {
//   0    1    2    3    4    5    6    7    8    9    A    B    c    D    E    F
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',  // 0x
    'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2',  // 1x
    '3', '4', '5', '6', '7', '8', '9', '0',  20,  19,  27,  26,  22, '-', '=', '[',  // 2x
    ']','\\', '#', ';','\'', '`', ',', '.', '/', 128, ' ', ' ', ' ', ' ', ' ', ' ',  // 3x
    ' ', ' ', ' ', ' ', ' ', ' ', 'P', 'S', ' ', ' ', ' ', ' ',  16, ' ', ' ', ' ',  // 4x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 5x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 6x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 7x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 8x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 9x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Ax
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Bx
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Cx
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Dx
    'C', 'S', 'A', 'C', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Ex
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '        // Fx
};

void add_keylog(uint16_t keycode);
#endif

#define _COLEMAK 0
#define _SYM 1
#define _FUNC 2

#define LTRB S(KC_COMM) // <
#define RTRB S(KC_DOT)  // >
#define LCBRC S(KC_LBRC) // [
#define RCBRC S(KC_RBRC) // ]
#define LRBR S(KC_9) // (
#define RRBR S(KC_0) // )

#define SCRNSHT G(S(KC_5))
#define AREASHT G(S(KC_4))
#define ALLSHT G(S(KC_3))

#define WIN_L LCA(KC_LEFT)
#define WIN_R LCA(KC_RGHT)
#define WIN_CTR LCA(KC_ENT)
#define WIN_FLL LCA(KC_F)
#define WIN_WIDE LCA(KC_W)

#define ALF G(KC_SPC)

#define HOME G(KC_LEFT)
#define END G(KC_RGHT)
#define FWD G(KC_RBRC)
#define BACK G(KC_LBRC)
#define TILDA S(KC_GRV)
#define COL S(KC_SCLN)

#define CMD_TAB CMD_T(KC_TAB)
#define CTL_TAB CTL_T(KC_TAB)

#define SHFT_ENT SFT_T(KC_ENT)
#define SHCTL_ENT MT(MOD_LSFT|MOD_LGUI, KC_ENT)

#define CTL_ESC CTL_T(KC_ESC)
#define SHFT_ESC SFT_T(KC_ESC)
#define CMD_ESC CMD_T(KC_ESC)

#define NUM_SPC LT(_NUM, KC_SPC)
#define NAV_SPC LT(_NAV, KC_SPC)

#define N_NUM LT(_NUM, KC_N)

#define NUM_BSPC LT(_NUM, KC_BSPC)
#define SYM_BSPC LT(_SYM, KC_BSPC)

#define SYM_SPC LT(_SYM, KC_SPC)

#define LA_SYM MO(_SYM)
#define LA_NUM MO(_NUM)

#define OS_SYM OSL(_SYM)
#define OS_FUN OSL(_FUNC)
#define OS_NUM OSL(_NUM)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK] = LAYOUT_split_3x6_3(

// ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------
     OS_FUN , KC_Q    , KC_W    , KC_F    , KC_P    , KC_G    ,                       KC_J   ,  KC_L   , KC_U    , KC_Y    , KC_QUOT , OS_FUN ,
// ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------
    RGB_MOD , KC_A    , KC_R    , KC_S    , KC_T    , KC_D    ,                       KC_H   ,  KC_N   , KC_E    , KC_I    , KC_O    , KC_SCLN,
// ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------
   SHCTL_ENT, KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    ,                       KC_K   ,  KC_M   , KC_COMM , KC_DOT  , KC_SLSH ,   ALF  ,
// ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------
                                            CMD_TAB , SYM_BSPC, SHFT_ENT,  SHFT_ENT, SYM_SPC , CTL_ESC
//                                         ---------+---------+---------  ---------+---------+---------
),
  [_SYM] = LAYOUT_split_3x6_3(

// +---------+---------+--------+---------+---------+---------                     ---------+---------+---------+---------+---------+----------
      KC_1   ,  KC_2   ,  KC_3  , KC_LPRN , KC_LCBR , KC_PLUS ,                     KC_MINS , KC_RCBR , KC_RPRN , KC_TILD , KC_GRV  , KC_ASTR ,
// +---------+---------+--------+---------+---------+---------                     ---------+---------+---------+---------+---------+----------
      KC_4   ,  KC_5   ,  KC_6  ,  KC_0   , KC_EQL  , _______ ,                     KC_LEFT ,  KC_UP  , KC_DOWN , KC_RIGHT, KC_DLR  , KC_EXLM ,
// +---------+---------+--------+---------+---------+---------                     ---------+---------+---------+---------+---------+----------
      KC_7   ,  KC_8   ,  KC_9  , KC_LBRC ,  LTRB   , _______ ,                     KC_UNDS ,   RTRB  , KC_RBRC , KC_AMPR , KC_PIPE , KC_AMPR ,
// +---------+---------+--------+---------+---------+---------                     ---------+---------+---------+---------+---------+----------
                                            KC_LGUI , _______ , KC_RSFT,   KC_RSFT , _______ , KC_RCTL
//                                         ---------+---------+---------  ---------+---------+---------
),
  [_FUNC] = LAYOUT_split_3x6_3(
// ---------+---------+---------+--------+---------+---------+                      ---------+---------+---------+--------+---------+----------
    AREASHT , _______ ,   COL   , _______ , _______ , _______ ,                       _______ , _______ , _______ , RGB_HUI, RGB_SAI , WIN_FLL ,
// ---------+---------+------------------+---------+----------                      ---------+---------+------------------+---------+----------
    SCRNSHT , _______ , _______ , _______ , _______ , _______ ,                       _______ , _______ , _______ , RGB_MOD, RGB_TOG , WIN_CTR ,
// ---------+---------+------------------+---------+----------                      ---------+---------+------------------+---------+----------
    ALLSHT  , _______ , _______ , _______ , _______ , _______ ,                       _______ , _______ , _______ , RGB_HUD, RGB_SAD , WIN_WIDE,
// ---------+---------+------------------+---------+----------                      ---------+---------+------------------+---------+----------
                                            _______ , _______ , _______,    _______, _______ , _______
//                                         ---------+---------+---------  ---------+---------+---------
),

};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
        oled_timer = timer_read32();
        add_keylog(keycode);
#endif
#ifndef SPLIT_KEYBOARD
        if (keycode == RESET && !is_master) {
            return false;
        }
#endif
    }
    return true;
}

 #ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_master) {
    return OLED_ROTATION_270;
  } else {
    return OLED_ROTATION_180;
  }
}

void add_keylog(uint16_t keycode) {
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX) || (keycode >= QK_MODS && keycode <= QK_MODS_MAX)) {
        keycode = keycode & 0xFF;
    } else if (keycode > 0xFF) {
        keycode = 0;
    }

    for (uint8_t i = 4; i > 0; --i) {
        keylog_str[i] = keylog_str[i - 1];
    }

    if (keycode < (sizeof(code_to_name) / sizeof(char))) {
        keylog_str[0] = pgm_read_byte(&code_to_name[keycode]);
    }

    log_timer = timer_read();
}

void update_log(void) {
    if (timer_elapsed(log_timer) > 750) {
        //add_keylog(0);
    }
}

void render_keylogger_status(void) {
    oled_write_P(PSTR("KYLOG"), false);
    oled_write(keylog_str, false);
}

void render_mod_status(uint8_t modifiers) {
    // oled_write_P(PSTR("MOD:"), false);
    oled_write_P(PSTR("S"), (modifiers & MOD_MASK_SHIFT));
    oled_write_P(PSTR("C"), (modifiers & MOD_MASK_CTRL));
    oled_write_P(PSTR("A"), (modifiers & MOD_MASK_ALT));
    oled_write_ln_P(PSTR("G"), (modifiers & MOD_MASK_GUI));
    oled_write_ln_P(PSTR(" "), false);
}

void render_layer_state(void) {
    oled_write_ln_P(PSTR("     "), false);
    // oled_write_ln_P(PSTR("NUM"), layer_state_is(_NUM));
    // oled_write_ln_P(PSTR("NAV"), layer_state_is(_NAV));
    // oled_write_ln_P(PSTR("GAME"), layer_state_is(_GAME));
    oled_write_ln_P(PSTR("CLMK"), layer_state_is(_COLEMAK));
    oled_write_ln_P(PSTR("     "), false);
    oled_write_ln_P(PSTR("SMBL"), layer_state_is(_SYM));
    oled_write_ln_P(PSTR("     "), false);
    oled_write_ln_P(PSTR("FUNC"), layer_state_is(_FUNC));
    oled_write_ln_P(PSTR("     "), false);
}

void render_keylock_status(uint8_t led_usb_state) {
    oled_write_P(PSTR("Lock:"), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("N"), led_usb_state & (1 << USB_LED_NUM_LOCK));
    oled_write_P(PSTR("C"), led_usb_state & (1 << USB_LED_CAPS_LOCK));
    oled_write_ln_P(PSTR("S"), led_usb_state & (1 << USB_LED_SCROLL_LOCK));
    oled_write_ln_P(PSTR(" "), false);
}


//void render_bootmagic_status(void) {
//    /* Show Ctrl-Gui Swap options */
//    static const char PROGMEM logo[][2][3] = {
//        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
//        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
//    };
//    oled_write_P(PSTR("BTMGK"), false);
//    oled_write_P(PSTR(" "), false);
//    oled_write_P(logo[0][0], !keymap_config.swap_lctl_lgui);
//    oled_write_P(logo[1][0], keymap_config.swap_lctl_lgui);
//    oled_write_P(PSTR(" "), false);
//    oled_write_P(logo[0][1], !keymap_config.swap_lctl_lgui);
//    oled_write_P(logo[1][1], keymap_config.swap_lctl_lgui);
//    oled_write_P(PSTR(" NKRO"), keymap_config.nkro);
//}

void render_rj_logo(void) {
  static const char PROGMEM crkbd_logo[] = {
      0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
      0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
      0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
      0};
  oled_write_P(crkbd_logo, false);
}

void render_status_main(void) {
    //layers first//
    render_mod_status(get_mods()|get_oneshot_mods());
    render_layer_state();
    /* Show Keyboard Layout  */
    //  render_keylock_status(host_keyboard_leds());
    render_keylogger_status();
}

void render_status_secondary(void) {
    //old layout
  //render_layer_state();
  //render_mod_status(get_mods()|get_oneshot_mods());
  //render_keylogger_status();
    render_rj_logo();
}


void oled_task_user(void) {
    if (timer_elapsed32(oled_timer) > 30000) {
        oled_off();
        return;
    }
#ifndef SPLIT_KEYBOARD
    else { oled_on(); }
#endif

    update_log();
    if (is_master) {
        render_status_main();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_status_secondary();
    }
}

#endif

#ifdef RGB_MATRIX_ENABLE

void suspend_power_down_keymap(void) {
    rgb_matrix_set_suspend_state(true);
}

void suspend_wakeup_init_keymap(void) {
    rgb_matrix_set_suspend_state(false);
}

void rgb_matrix_indicators_user(void) {
    if (rgb_matrix_config.enable
#    ifdef RGB_DISABLE_WHEN_USB_SUSPENDED
        && !g_suspend_state
#    endif
    ) {
        switch (biton32(layer_state)) {
            case _COLEMAK:
                rgb_matrix_layer_helper(HSV_RED, 0, rgb_matrix_config.speed, LED_FLAG_UNDERGLOW);
                break;
            case _FUNC:
                rgb_matrix_layer_helper(HSV_TURQUOISE, 0, rgb_matrix_config.speed, LED_FLAG_UNDERGLOW);
                break;
            case _SYM:
                rgb_matrix_layer_helper(HSV_MAGENTA, 0, rgb_matrix_config.speed, LED_FLAG_UNDERGLOW);
                break;
            // case _NAV:
                // rgb_matrix_layer_helper(HSV_CYAN, 0, rgb_matrix_config.speed, LED_FLAG_UNDERGLOW);
                // break;
            // case _SYMBOL:
                // rgb_matrix_layer_helper(HSV_GREEN, 0, rgb_matrix_config.speed, LED_FLAG_UNDERGLOW);
                // break;
            default:
                rgb_matrix_layer_helper(HSV_BLUE, 0, rgb_matrix_config.speed, LED_FLAG_UNDERGLOW);
                break;
            }
    }
}
#endif

#ifdef RGB_MATRIX_ENABLE
#    include "lib/lib8tion/lib8tion.h"
extern led_config_t g_led_config;
void rgb_matrix_layer_helper(uint8_t hue, uint8_t sat, uint8_t val, uint8_t mode, uint8_t speed, uint8_t led_type) {
    HSV hsv = {hue, sat, val};
    if (hsv.v > rgb_matrix_config.hsv.v) {
        hsv.v = rgb_matrix_config.hsv.v;
    }

    switch (mode) {
        case 1:  // breathing
        {
            uint16_t time = scale16by8(g_rgb_counters.tick, speed / 8);
            hsv.v         = scale8(abs8(sin8(time) - 128) * 2, hsv.v);
            RGB rgb       = hsv_to_rgb(hsv);
            for (uint8_t i = 0; i < DRIVER_LED_TOTAL; i++) {
                if (HAS_FLAGS(g_led_config.flags[i], led_type)) {
                    rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
                }
            }
            break;
        }
        default:  // Solid Color
        {
            RGB rgb = hsv_to_rgb(hsv);
            for (uint8_t i = 0; i < DRIVER_LED_TOTAL; i++) {
                if (HAS_FLAGS(g_led_config.flags[i], led_type)) {
                    rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
                }
            }
            break;
        }
    }
}
#endif
