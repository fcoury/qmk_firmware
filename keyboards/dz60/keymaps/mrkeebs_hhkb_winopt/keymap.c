#include QMK_KEYBOARD_H

// Layer shorthand
enum layers {
    _BASE = 0, // Base
    _WIN,      // Windows
    _CTRL      // Extras
};

#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))
#define KC_TWIN TG(_WIN)

const uint8_t RGBLED_RAINBOW_SWIRL_INTERVALS[] PROGMEM = {10, 5, 5};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------------.
 * | ` ~ |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |  \  |  `  |
 * |-----------------------------------------------------------------------------------------+
 * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \   |
 * |-----------------------------------------------------------------------------------------+
 * | Caps    |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
 * |-----------------------------------------------------------------------------------------+
 * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |    RSh    | FN  |
 * |-----------------------------------------------------------------------------------------+
 * | Ctrl |  Alt  |  Cmd  |                   Space                    | Cmd | RAlt |  Ctrl  |
 * `-----------------------------------------------------------------------------------------'
 */

  [_BASE] = LAYOUT(
      KC_GESC, KC_1,      KC_2,    KC_3,   KC_4,   KC_5,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,
      KC_TAB,  KC_Q,      KC_W,    KC_E,   KC_R,   KC_T,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
      KC_LCTL, KC_A,      KC_S,    KC_D,   KC_F,   KC_G,   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,       KC_ENT    ,
      KC_LSFT, _______,   KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(_CTRL),
   		KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, KC_SPC, KC_SPC, KC_RGUI, KC_RGUI, KC_RGUI, KC_RALT, KC_RCTL
      ),

  [_WIN] = LAYOUT(
      _______, _______,    _______,    _______,   _______,   _______,   _______,    _______,    _______,    _______,    _______,    _______, _______,  _______, _______,
      _______, _______,    _______,    _______,   _______,   _______,   _______,    _______,    _______,    _______,    _______,    _______, _______, _______,
      _______, _______,    _______,    _______,   _______,   _______,   _______,    _______,    _______,    _______,    _______, _______,       _______,
      _______, _______,  _______,    _______,   _______,   _______,   _______,    _______,    _______,    _______, _______,  _______, _______, _______,
   		KC_LCTL, KC_LGUI, KC_LALT, _______, _______, _______, _______, _______, _______, _______, _______
      ),

  [_CTRL] = LAYOUT(
      KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_F11, KC_F12, _______, KC_DEL,
      _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_HOME, KC_END, KC_UP, _______, RESET,
      _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______, _______, _______, KC_PGUP, KC_LEFT, KC_RIGHT, _______,
      _______, _______, KC_PSCR, KC_SLCK, _______, _______, _______, _______, _______, _______, KC_PGDN, KC_DOWN, _______, _______,
		  _______, _______, _______, _______, _______, _______, KC_TWIN, KC_TWIN, KC_TWIN, _______, _______
      ),
};

enum function_id {
    SHIFT_ESC,
};

const uint16_t PROGMEM fn_actions[] = {
  [0]  = ACTION_FUNCTION(SHIFT_ESC),
};

uint8_t prev = _BASE;
uint32_t desired = 1;

void matrix_init_user() {
  rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
  rgblight_disable();
}

uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);
  // if (prev != _CTRL) {
  switch (layer) {
    case _BASE:
      // rgblight_sethsv(0, 255, 255);
      rgblight_disable();
      rgblight_set();
      break;
    case _WIN:
      rgblight_sethsv(0, 0, 255);
      rgblight_enable();
      rgblight_set();
      break;
    case _CTRL:
      break;
  }
  // } else {
  //     desired = ç();
  // }
  prev = layer;
  return state;
}

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  static uint8_t shift_esc_shift_mask;
  switch (id) {
    case SHIFT_ESC:
      shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
      if (record->event.pressed) {
        if (shift_esc_shift_mask) {
          add_key(KC_GRV);
          send_keyboard_report();
        } else {
          add_key(KC_ESC);
          send_keyboard_report();
        }
      } else {
        if (shift_esc_shift_mask) {
          del_key(KC_GRV);
          send_keyboard_report();
        } else {
          del_key(KC_ESC);
          send_keyboard_report();
        }
      }
      break;
  }
}
