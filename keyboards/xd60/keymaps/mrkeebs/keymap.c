#include "xd60.h"
#include "action_layer.h"

#define ______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // 0: Base Layer
  LAYOUT_ALL(
      KC_GESC,               KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS,  KC_EQL,                KC_BSPC,  KC_GRV,        \
      KC_TAB,                KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC,  KC_RBRC,               KC_BSLS,                 \
      MT(MOD_LCTL, KC_CAPS), KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT,  KC_NO,                 KC_ENT,                  \
      KC_LSFT,               KC_NO,   KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,  MT(MOD_RSFT, KC_SLSH), KC_UP,   LT(1, KC_SLSH), \
      KC_LCTL,               KC_LALT, KC_LGUI,                          KC_SPC,                          KC_RGUI, F(0),     KC_LEFT,               KC_DOWN,  KC_RIGHT),

  // 1: Function Layer
  LAYOUT_ALL(
      KC_GRV, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_F11,  KC_F12,  KC_DEL, KC_DEL,
      ______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, ______, ______, ______,  ______,  RESET,
      ______, KC_MUTE, KC_VOLD, KC_VOLU, ______,  ______,  ______,  ______,  ______,  ______, ______, ______,  ______,  ______,
      ______, ______,  KC_PSCR, KC_LSCR, ______,  ______,  ______,  ______,  ______,  ______, ______, ______,  ______,  KC_PGUP, ______,
      ______, ______,  ______,                             ______,                            ______, ______,  KC_HOME, KC_PGDN, KC_END),
};

// Custom Actions
const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),  // to Fn overlay
};

// Macros
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {

  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) { register_code(KC_RSFT); }
      else { unregister_code(KC_RSFT); }
      break;
  }

  return MACRO_NONE;
};

// Loop
void matrix_scan_user(void) {
  // Empty
};
