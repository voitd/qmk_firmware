#include QMK_KEYBOARD_H
#include "split_util.h"

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

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
            oled_write_P(PSTR("      COLEMAK       "), false);
            break;
        case _FUNC:
            oled_write_P(PSTR("      FUNCTION      "), false);
            break;
        case _SYM:
            oled_write_P(PSTR("      SYMBOL        "), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undefined"), false);
    }
}

void oled_task_user(void) {
    render_qmk_and_layer();
}
#endif
