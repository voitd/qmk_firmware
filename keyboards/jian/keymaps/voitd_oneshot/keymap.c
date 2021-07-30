#include QMK_KEYBOARD_H

#define _BASE 0
#define _NUM 1
#define _SYM 2

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
#define OS_NUM OSL(_NUM)

enum keycodes {
    SW_WIN,  // Switch to next window         (cmd-tab)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT(
// ---------+---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------+---------
    RESET   , OS_SYM  , KC_Q    , KC_W    , KC_F    , KC_P    , KC_G    ,                       KC_J   ,   KC_L  , KC_U    , KC_Y    , KC_QUOT , OS_NUM  ,  ALF   ,
// ---------+---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------+---------
              SW_WIN  , KC_A    , KC_R    , KC_S    , KC_T    , KC_D    ,                       KC_H   ,  N_NUM  , KC_E    , KC_I    , KC_O    , KC_SCLN ,
// ---------+---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------+---------
             SHCTL_ENT, KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    ,                       KC_K   ,   KC_M  ,KC_COMM  , KC_DOT  , KC_SLSH , OS_NUM  ,
// ---------+---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------+---------
                                                      CMD_TAB , SYM_BSPC, SHFT_ENT,  SHFT_ENT, SYM_SPC , CTL_ESC
//                                                   ---------+---------+---------  ---------+---------+---------
),
[_NUM] = LAYOUT(
// ---------+---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------+---------
     WIN_L  , _______ , _______ ,  KC_1   ,  KC_2   ,  KC_3   , _______ ,                      _______ , _______ , _______ , _______ ,  KC_0   , WIN_FLL ,  WIN_R ,
// ---------+---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------+---------
              _______ , _______ ,  KC_4   ,  KC_5   ,  KC_6   ,  KC_0   ,                      _______ , _______ , _______ , _______ , _______ , WIN_CTR ,
// ---------+---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------+---------
              _______ , _______ ,  KC_7   ,  KC_8   ,  KC_9   , _______ ,                      _______ , _______ , _______ , _______ , _______ , WIN_WIDE,
// ---------+---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------+---------
                                                      KC_LGUI , _______ , _______ ,  KC_RSFT , KC_RALT , KC_RCTL
//                                                   ---------+---------+---------  ---------+---------+---------
),
[_SYM] = LAYOUT(
// ---------+---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------+---------
  C(KC_LEFT), AREASHT , _______ ,   COL   , KC_LPRN , KC_LCBR , KC_PLUS ,                      KC_MINS , KC_RCBR , KC_RPRN , KC_ASTR , KC_GRV  , KC_TILD ,C(KC_RIGHT),
// ---------+---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------+---------
              SCRNSHT , _______ , KC_DLR  , KC_PERC , KC_EQL  , KC_TAB  ,                      KC_LEFT ,  KC_UP  , KC_DOWN , KC_RIGHT, KC_SCLN , _______ ,
// ---------+---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------+---------
              ALLSHT  , KC_EXLM ,  KC_AT  , KC_LBRC ,  LTRB   , KC_DOT  ,                      KC_UNDS ,   RTRB  , KC_RBRC , KC_AMPR , KC_PIPE , _______ ,
// ---------+---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------+---------
                                                      _______ , _______ , _______,  SHCTL_ENT, _______ , _______
//                                                   ---------+---------+---------  ---------+---------+---------
),

};

bool sw_win_active = false;

void update_swapper(
    bool *active,
    uint16_t cmdish,
    uint16_t tabish,
    uint16_t trigger,
    uint16_t keycode,
    keyrecord_t *record
) {
    if (keycode == trigger) {
        if (record->event.pressed) {
            if (!*active) {
                *active = true;
                register_code(cmdish);
            }
            register_code(tabish);
        } else {
            unregister_code(tabish);
            // Don't unregister cmdish until some other key is hit or released.
        }
    } else if (*active) {
        unregister_code(cmdish);
        *active = false;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_swapper(
        &sw_win_active, KC_LGUI, KC_TAB, SW_WIN,
        keycode, record
    );
    return true;
}
