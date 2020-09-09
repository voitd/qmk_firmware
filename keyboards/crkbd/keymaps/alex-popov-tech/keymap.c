#include QMK_KEYBOARD_H


#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _COLEMAK 0
#define _LEFT 1
#define _RIGHT 2
#define _BOTH 3

enum custom_keycodes {
  COLEMAK = SAFE_RANGE,
  LEFT,
  RIGHT,
  BOTH,
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

#define TILDA S(KC_GRV)
#define LPR S(KC_9)
#define RPR S(KC_0)
#define UDR S(KC_MINUS)
#define COL S(KC_SCLN)
#define LCBRC S(KC_LBRC)
#define RCBRC S(KC_RBRC)
#define CMD_LBRC LCMD_T(LCBRC)
#define CMD_RBRC LCMD_T(RCBRC)
#define CMD_TAB LCMD_T(KC_TAB)
#define LEFT_BSPC LT(_LEFT, KC_BSPC)
#define RIGHT_SPC LT(_RIGHT, KC_SPC)
#define BOTH_BSPC LT(_BOTH, KC_BSPC)
#define BOTH_SPC LT(_BOTH, KC_SPC)
#define SFT_ENT SFT_T(KC_ENT)
#define SFT_ESC SFT_T(KC_ESC)
#define CTL_LBRC LCTL_T(KC_LBRC)
#define CTL_RBRC LCTL_T(KC_RBRC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  KC__VOLDOWN,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y,  KC_QUOT,KC__VOLUP,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     CTL_LBRC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_K,    KC_N,    KC_E,    KC_O,    KC_I,  CTL_RBRC, \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_F11,   KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_M,    KC_H,   KC_COMM, KC_DOT, KC_SLSH,  KC_F12, \
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         CMD_TAB,LEFT_BSPC, SFT_ENT,    SFT_ESC,RIGHT_SPC,CMD_TAB \
                                      //`--------------------------'  `--------------------------'
  ),
  [_LEFT] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_PLUS, KC_SCLN,  LPR,    KC_EQL,  _______,                      KC_DOWN,KC_RIGHT,   RPR,    TILDA,  KC_GRV,  KC_F5 ,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_F1,   KC_1,    KC_2,    KC_3,    KC_4,   _______,                       KC_UP,   KC_7,    KC_8,    KC_9,    KC_0,   KC_F3 ,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_F2,   UDR,    KC_PIPE,  LCBRC,  KC_MINS,  KC_5,                         KC_6,  KC_LEFT,   RCBRC,   COL,  KC_BSLASH, KC_F4 ,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______,BOTH_SPC, _______ \
                                      //`--------------------------'  `--------------------------'
    ),
  [_RIGHT] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_PLUS, KC_SCLN,  LPR,    KC_EQL,  _______,                      KC_DOWN,KC_RIGHT,   RPR,    TILDA,  KC_GRV,  KC_F5 ,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_F1,   KC_1,    KC_2,    KC_3,    KC_4,   _______,                       KC_UP,   KC_7,    KC_8,    KC_9,    KC_0,   KC_F3 ,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_F2,   UDR,    KC_PIPE,  LCBRC,  KC_MINS,  KC_5,                         KC_6,  KC_LEFT,   RCBRC,   COL,  KC_BSLASH, KC_F4 ,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______,BOTH_BSPC,_______,    _______, _______, _______ \
                                      //`--------------------------'  `--------------------------'
    ),
  [_BOTH] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  KC__VOLDOWN, C(KC_Q), C(KC_W), C(KC_F), C(KC_P), C(KC_B),                      C(KC_J),C(KC_L), C(KC_U), C(KC_Y),C(KC_QUOT),KC__VOLUP,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     CTL_LBRC, C(KC_A), C(KC_R), C(KC_S), C(KC_T), C(KC_G),                      C(KC_K),C(KC_N), C(KC_E), C(KC_O), C(KC_I),CTL_RBRC, \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_F11,  C(KC_Z), C(KC_X), C(KC_C), C(KC_D), C(KC_V),                      C(KC_M),C(KC_H), C(KC_COMM),C(KC_DOT),C(KC_SLSH),KC_F12, \
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______ \
                                      //`--------------------------'  `--------------------------'
    )

};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer2);
  } else {
    layer_off(layer2);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    //matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED
