#include QMK_KEYBOARD_H

enum layers {
  _BL = 0,    // Base Layer
  _FL         // Function Layer
};

#define _______ KC_TRNS
#define KC_FNLR MO(_FL)
#define RGB_MSW RGB_M_SW

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* _BL: Base Layer, mostly standard 65% QWERTY layout.
     *  .---------------------------------------------------------------.
     *  |GrE|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |Hom|
     *  |---------------------------------------------------------------|
     *  |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \|PgU|
     *  |---------------------------------------------------------------|
     *  |Ctrl  |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return  |PgD|
     *  |---------------------------------------------------------------|
     *  |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |Up |Fn1|
     *  |---------------------------------------------------------------|
     *  |Ctrl|Gui |Alt |      Space             |Alt  |Ctrl |Lft|Dwn|Rgt|
     *  `---------------------------------------------------------------'
     */
   [_BL] = LAYOUT(
      KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_BSPC, KC_HOME,
      KC_TAB,           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,
      KC_LCTL,          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,           KC_PGDN,
      KC_LSFT, KC_NO,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_FNLR,
      KC_LCTL, KC_LGUI, KC_LALT,          KC_SPC,  KC_SPC,  KC_SPC,                    KC_RALT, KC_RALT, KC_RCTL,          KC_LEFT, KC_DOWN, KC_RGHT
      ),

    /* _FL: Function Layer, Function Keys, RGB, Audio and Brightness.
     *  .---------------------------------------------------------------.
     *  |Grv| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|Delete |   |
     *  |---------------------------------------------------------------|
     *  |     |RgT|RgM|Hu+|Hu-|Sa+|Sa-|Va+|Va-|Swr|   |Up |   |Reset|   |
     *  |---------------------------------------------------------------|
     *  |CapsLk|Mut|Vo+|Vo-|   |   |   |   |   |   |Lft|Rgt|        |   |
     *  |---------------------------------------------------------------|
     *  |        |Br+|Br-|   |   |   |   |   |   |   |Dwn|      |   |   |
     *  |---------------------------------------------------------------|
     *  |    |    |    |                        |Fn1  |     |   |   |   |
     *  `---------------------------------------------------------------'
     */
  [_FL] = LAYOUT(
      KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,   KC_F11,  KC_F12,  _______, KC_DEL,  _______,
      _______,          RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, RGB_MSW, _______, KC_UP,   _______, RESET,   _______,
      KC_CAPS,          KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_RGHT, _______,          _______,
      _______, _______, KC_PSCR, KC_LSCR, _______, _______, _______, _______, _______, _______, _______, KC_DOWN,          _______, _______, _______,
      _______, _______, _______,          _______, _______, _______,                   _______, _______, _______,          _______, _______, _______
      ),
};
