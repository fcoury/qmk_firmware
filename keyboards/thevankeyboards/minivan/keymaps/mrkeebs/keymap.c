#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_arrow( /* Qwerty */
    KC_GESC,              KC_Q,    KC_W,    KC_E,  KC_R, KC_T,    KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC,
    MT(MOD_LCTL, KC_TAB), KC_A,    KC_S,    KC_D,  KC_F, KC_G,    KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, LT(2, KC_ENT),
    KC_LSFT,              KC_Z,    KC_X,    KC_C,  KC_V, KC_B,    KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_UP,   MT(MOD_RSFT, KC_SLSH),
    KC_LCTL,              KC_LALT, KC_LGUI, LT(1, KC_SPC), KC_SPC, MO(4), KC_LEFT, KC_DOWN, KC_RIGHT
  ),
  [1] = LAYOUT_arrow( /* LAYER 1 */
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_QUOT, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_PGUP, KC_BSLS,
    _______, _______, _______,                   _______, _______,          _______, KC_HOME, KC_PGDN, KC_END
  ),
  [2] = LAYOUT_arrow( /* LAYER 2 */
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
    _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, KC_MPLY, _______, _______, KC_UNDS, KC_PLUS, KC_DQUO, _______,
    _______, KC_PSCR, KC_LSCR, _______, _______, _______, _______, _______, KC_LCBR, KC_RCBR, KC_PGUP, KC_PIPE,
    _______, _______, _______,                   _______, _______,          _______, KC_HOME, KC_PGDN, KC_END
  ),
  [3] = LAYOUT_arrow( /* LAYER 3 */
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F11,  KC_F12,  _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______,                   _______, _______,          _______, _______, _______, _______
  ),
  [4] = LAYOUT_arrow( /* Mouse and LED Layer */
    KC_ESC,  KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, _______,  _______, _______, _______, _______, _______, _______,
    KC_TAB,  KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, BL_BRTG,  _______, BL_DEC,  BL_INC,  BL_TOGG, _______, RESET,
    _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______,  _______, _______, _______, _______, _______, _______,
    _______, _______, _______,                   KC_SPACE, _______,          _______, _______, _______, _______
  )
};

const uint16_t PROGMEM fn_actions[] = {
};
