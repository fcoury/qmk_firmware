#include QMK_KEYBOARD_H

// Layer shorthand
enum layers {
    _BASE = 0, // Base
    _EXTR,     // Extra
    _CTRL      // Control
};

#define KC_CTAB MT(MOD_LCTL, KC_TAB)  // Control held, Tab pressed
#define KC_EXSP LT(_EXTR, KC_SPC)     // Extras layer held, Space pressed
#define KC_CTSL LT(_CTRL, KC_SLSH)    // Control layer held, Slash pressed

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Base Layer
   * .-----------------------------------------------------------------------.
   * | Esc |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  | BkSp |
   * |------------------------------------------------------------------------|
   * | Tab   |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  Return  |
   * |------------------------------------------------------------------------|
   * | Shift    |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |   /   |
   * |------------------------------------------------------------------------|
   * | Ctrl  | Win | Alt   | Fn1      |  Space         | Alt   | Win |  Ctrl  |
   * '------------------------------------------------------------------------'
   */
  [_BASE] = LAYOUT(
    KC_GESC, KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC, \
    KC_CTAB, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_ENT ,          \
    KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_CTSL,          \
    KC_LCTL, KC_LALT, KC_LGUI, KC_EXSP,          KC_SPC,  KC_RGUI, KC_RCTL, KC_NO
  ),

  /**
   * Extras - Layer for standard layout keys not present on the Base layer
   * .-----------------------------------------------------------------------.
   * |  `  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |      |
   * |------------------------------------------------------------------------|
   * |       |     |     |     |     |     |  =  |  -  |  ;  |  '  |          |
   * |------------------------------------------------------------------------|
   * | Shift    |     |     |     |     |     |     |     |  [  |  ]  |   \   |
   * |------------------------------------------------------------------------|
   * |       |     |       |          |                |       |     |        |
   * '------------------------------------------------------------------------'
   */
  [_EXTR] = LAYOUT(
    KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______, \
    _______, _______, KC_EQL , KC_MINS, _______, _______, KC_EQL , KC_MINS, KC_SCLN, KC_QUOT, _______,          \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_BSLS,          \
    _______, _______, _______, _______,          _______, _______, _______, _______
  ),

  /**
   * Control - Extra control keys for arrows, volume, brightness and media control
   * ,------------------------------------------------------------------------,
   * |     |     |     |     |     |     |     |     |     | Up  |     | Del  |
   * |------------------------------------------------------------------------|
   * |       |Mute |VolDn|VolUp|     |     |     |     |Left |Right|          |
   * |------------------------------------------------------------------------|
   * |          |BrgDn|BrgUp|     |     |     |     |     |Down |     |       |
   * |------------------------------------------------------------------------|
   * |       |     |       |          |                |       |     |        |
   * '------------------------------------------------------------------------'
   */
  [_CTRL] = LAYOUT(
    RESET,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_UP  , _______, KC_DEL , \
    _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______, _______, KC_LEFT, KC_RGHT, _______,          \
    _______, KC_PSCR, KC_LSCR, _______, _______, _______, _______, _______, KC_DOWN, _______, _______,          \
    _______, _______, _______, _______,          _______, _______, _______, _______
  ),

};
