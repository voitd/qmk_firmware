#include QMK_KEYBOARD_H
#include "oneshot.h"
#include "utils.h"
#include "split_util.h"

extern uint8_t is_master;

enum layers {
    DEF,
    DICT,
    NUM,
};

enum {
    TD_RGB_TOG_MOD,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_RGB_TOG_MOD] = ACTION_TAP_DANCE_DOUBLE(RGB_TOG, RGB_MOD),
};

uint16_t timer_bspc_num = 0;
uint16_t timer_spc_num = 0;
uint16_t num_toggled_by = 0;

enum custom_keycodes {
  PIPE = SAFE_RANGE,
  // mod tap modifiers
  BSPC_NUM,
  SPC_NUM,
  // : ;
  COL_SCLN,
  // . :
  DOT_COL,
  // , ;
  COM_SCLN,
  DICT_F13,

  // flipped digits
  EXCL_1,
  AT_2,
  HASH_3,
  DLR_4,
  PERC_5,
  CIRC_6,
  AMPR_7,
  ASTR_8,
  TILD_9,
  GRV_0,

  // 9 <
  _9_LABR,
  // 0 <
  _0_RABR,

  // { [
  LCBRC,
  // } ]
  RCBRC,

  // russian aliases
  WEAK_HARD,
  W_Q,
  // vu-keys copy paste on DICT
  WEAK_HARD_C,
  SCLN_V,

  // Custom oneshot mod implementation with no timers.
  OS_SHFT,
  OS_CTRL,
  OS_ALT,
  OS_CMD,
};

// ()
#define LRBR S(KC_9)
#define RRBR S(KC_0)

#define ENT_SHIFT LSFT_T(KC_ENT)
#define ESC_SHIFT LSFT_T(KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [DEF] = LAYOUT_split_3x6_3(
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------
      KC_F14  , KC_Q    , KC_C    , KC_D    , KC_M    , KC_V    ,                      KC_B    , KC_W    , KC_U    , KC_K    , KC_QUOT , KC_F14  ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------
      KC_F11  , KC_N    , KC_S    , KC_T    , KC_R    , KC_L    ,                      KC_Y    , KC_A    , KC_E    , KC_O    , KC_I    , KC_F12  ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------
      DICT_F13, KC_X    , KC_F    , KC_G    , KC_H    , KC_Z    ,                      KC_SLASH, KC_P    , DOT_COL , KC_J    , COM_SCLN,TD(TD_RGB_TOG_MOD),
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------
                                    OS_CMD  , SPC_NUM ,ENT_SHIFT,                     ESC_SHIFT, BSPC_NUM, OS_CTRL ),
  [DICT] = LAYOUT_split_3x6_3(
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------
      _______ , W_Q     ,WEAK_HARD_C, KC_Z  , KC_G    , SCLN_V  ,                      KC_P    , KC_D    , KC_R    , KC_L    , KC_X    , _______ ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------
      KC_O    , KC_E    , KC_B    , KC_T    , KC_J    , KC_F    ,                      KC_K    , KC_Y    , KC_N    , KC_C    , KC_H    , KC_I    ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------
      _______ , KC_A    , KC_QUOT , KC_LBRC , KC_S    , KC_DOT  ,                      KC_COMMA, KC_V    , KC_SLASH , KC_U   ,S(KC_SLASH),_______,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------
                                    _______ , _______ , _______,                       _______ , _______ , _______ ),
  [NUM] = LAYOUT_split_3x6_3(
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------
      RGB_HUI , OS_CMD  , OS_CTRL , LRBR    , LCBRC   , KC_5    ,                      KC_6    , RCBRC   , RRBR    , KC_UP   , KC_GRV  , RGB_HUD ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------
      RGB_SAI , KC_1    , KC_2    , KC_3    , KC_4    , KC_RIGHT,                      KC_EQL  , KC_7    , KC_8    , _9_LABR , _0_RABR , RGB_VAI ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------
      RGB_SAD , OS_ALT  , OS_SHFT , _______ , KC_LEFT , KC_TAB  ,                      KC_TAB  , KC_MINUS, PIPE    , KC_DOWN , _______ , RGB_VAD ,
  // ---------+---------+---------+---------+---------+---------                      ---------+---------+---------+---------+---------+---------
                                    _______ , _______ , _______ ,                      _______ , _______ , _______ )
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ESC_SHIFT:
        case ENT_SHIFT:
            return TAPPING_TERM + 70;
        default:
            return TAPPING_TERM;
   }
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
        case DEF:
            oled_write_P(PSTR("________base_______"), false);
            break;
        case NUM:
            oled_write_P(PSTR("_______numbers_____"), false);
            break;
        case DICT:
            oled_write_P(PSTR("_______dictor______"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undefined"), false);
    }
}

void oled_task_user(void) {
    render_qmk_and_layer();
}
#endif

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
        /* case ENT_NUM: */
        case KC_F11:
            return true;
        default:
            return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
        case SPC_NUM:
        case BSPC_NUM:
        case KC_LSFT:
        case OS_SHFT:
        case OS_CTRL:
        case OS_ALT:
        case OS_CMD:
            return true;
        default:
            return false;
    }
}

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_oneshot( &os_shft_state, KC_LSFT, OS_SHFT, keycode, record);
    update_oneshot( &os_ctrl_state, KC_LCTL, OS_CTRL, keycode, record);
    update_oneshot( &os_alt_state, KC_LALT, OS_ALT, keycode, record);
    update_oneshot( &os_cmd_state, KC_LCMD, OS_CMD, keycode, record);

    switch (keycode) {
        case EXCL_1:
            key_with_modded(record, KC_LSHIFT, KC_1, true, KC_1, false);
            break;
        case AT_2:
            key_with_modded(record, KC_LSHIFT, KC_2, true, KC_2, false);
            break;
        case HASH_3:
            key_with_modded(record, KC_LSHIFT, KC_3, true, KC_3, false);
            break;
        case DLR_4:
            key_with_modded(record, KC_LSHIFT, KC_4, true, KC_4, false);
            break;
        case PERC_5:
            key_with_modded(record, KC_LSHIFT, KC_5, true, KC_5, false);
            break;
        case CIRC_6:
            key_with_modded(record, KC_LSHIFT, KC_6, true, KC_6, false);
            break;
        case AMPR_7:
            key_with_modded(record, KC_LSHIFT, KC_7, true, KC_7, false);
            break;
        case ASTR_8:
            key_with_modded(record, KC_LSHIFT, KC_8, true, KC_8, false);
            break;
        case TILD_9:
            key_with_modded(record, KC_LSHIFT, KC_TILD, true, KC_9, false);
            break;
        case GRV_0:
            key_with_modded(record, KC_LSHIFT, KC_TILD, false, KC_0, false);
            break;
        case _9_LABR:
            key_with_modded(record, KC_LSHIFT, KC_9, false, KC_COMMA, true);
            break;
        case _0_RABR:
            key_with_modded(record, KC_LSHIFT, KC_0, false, KC_DOT, true);
            break;
        case COL_SCLN:
            key_with_modded(record, KC_LSHIFT, KC_SCLN, true, KC_SCLN, false);
            break;
        case PIPE:
            key_with_modded(record, KC_LSHIFT, KC_BSLASH, true, KC_BSLASH, false);
            break;
        case DOT_COL:
            key_with_modded(record, KC_LSHIFT, KC_DOT, false, KC_SCLN, true);
            break;
        case COM_SCLN:
            key_with_modded(record, KC_LSHIFT, KC_COMMA, false, KC_SCLN, false);
            break;
        case LCBRC:
            key_with_modded(record, KC_LSHIFT, KC_LBRC, true, KC_LBRC, false);
            break;
        case RCBRC:
            key_with_modded(record, KC_LSHIFT, KC_RBRC, true, KC_RBRC, false);
            break;
        // russian aliases
        case W_Q:
            key_with_modded(record, KC_LSHIFT, KC_W, false, KC_Q, false);
            break;
        case WEAK_HARD:
            key_with_modded(record, KC_LSHIFT, KC_M, false, KC_RBRC, false);
        case BSPC_NUM:
            if (record->event.pressed) {
                if(layer_state_is(NUM)) {
                    register_code(KC_LSHIFT);
                    tap_code(KC_SCLN);
                    unregister_code(KC_LSHIFT);
                } else {
                    layer_invert(NUM);
                    num_toggled_by = 1;
                    timer_bspc_num = timer_read();
                }
            } else {
                if (timer_elapsed(timer_bspc_num) < TAPPING_TERM) {
                    tap_code(KC_BSPC);
                }
                if (num_toggled_by == 1) {
                    layer_invert(NUM);
                    num_toggled_by = 0;
                }
            }
            break;
        case SPC_NUM:
            if (record->event.pressed) {
                if(layer_state_is(NUM)) {
                    register_code(KC_LSHIFT);
                    tap_code(KC_SCLN);
                    unregister_code(KC_LSHIFT);
                } else {
                    layer_invert(NUM);
                    num_toggled_by = 2;
                    timer_spc_num = timer_read();
                }
            } else {
                if (timer_elapsed(timer_spc_num) < TAPPING_TERM) {
                    tap_code(KC_SPC);
                }
                if (num_toggled_by == 2) {
                    layer_invert(NUM);
                    num_toggled_by = 0;
                }
            }
            break;
        // copy paste on dict
        case SCLN_V:
            key_with_modded(record, KC_LCMD, KC_SCLN, false, KC_V, true);
            break;
        case WEAK_HARD_C:
            if (record->event.pressed) {
                if (isModHolded(KC_LCMD)) {
                    tap_code(KC_C);
                } else if (isModHolded(KC_LSHIFT)) {
                    unregister_code(KC_LSHIFT);
                    tap_code(KC_RBRC);
                    register_code(KC_LSHIFT);
                } else {
                    tap_code(KC_M);
                }
            }
            break;
        case DICT_F13:
            if(record->event.pressed) {
                tap_code(KC_F13);
                if (get_mods() & (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT))) {
                } else {
                    if(layer_state_is(DICT)) {
                        layer_move(DEF);
                    } else {
                        layer_move(DICT);
                    }
                }
            } else {
            }
            break;
    };
    return true;
};
