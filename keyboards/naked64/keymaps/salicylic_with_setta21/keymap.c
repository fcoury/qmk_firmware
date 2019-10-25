#include QMK_KEYBOARD_H
#include "keymap_jp.h"


#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
  _QWERTY = 0,
  _MOUSE,
  _BROWSER,
  _FLOCK,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
  RGB_RST = SAFE_RANGE,
  SEND_SUM,
  SEND_AVE,
  SEND_CIF,
  SEND_MAX,
  SEND_MIN
};

enum tapdances{
  TD_ESFL = 0,
  TD_ESQW,
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_ESFL] = ACTION_TAP_DANCE_DUAL_ROLE(KC_ESC, _FLOCK),
  [TD_ESQW] = ACTION_TAP_DANCE_DUAL_ROLE(KC_ESC, _QWERTY),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_with_setta21( \
  //,--------------------------------------------------------------|             |--------------------------------------------------------------.      |-----------------------------------------------|
   TG(_MOUSE),TD(TD_ESFL), KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                  KC_6,    KC_7,    KC_8,    KC_9,    KC_0, JP_MINS, KC_BSPC,LT(_LOWER, KC_P0),KC_P1, KC_P4,  KC_P7,KC_NLCK, KC_ESC, \
  //|--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|      |-------+-------+-------+-------+-------+-------|
 TG(_BROWSER),  KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, JP_LBRC, JP_RBRC,                 KC_P2,  KC_P5,  KC_P8,KC_PSLS,  KC_F2, \
  //|--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|      |-------+-------+-------+-------+-------+-------|
              KC_LCTRL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                  KC_H,    KC_J,    KC_K,    KC_L, JP_MINS, JP_BSLS,  KC_ENT,LT(_RAISE, KC_PDOT),KC_P3,KC_P6, KC_P9,KC_PAST, KC_EQL, \
  //         |--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|      |---------------+---------------+-------+-------|
               KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                  KC_N,    KC_M, JP_COMM,  JP_DOT, JP_SLSH,   KC_UP, KC_RSFT,               KC_PENT,        KC_PPLS,KC_PMNS, KC_DEL, \
  //         |--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|      |-----------------------------------------------|
               KC_ZKHK,          KC_LGUI,LT(_LOWER,KC_ENT), KC_BSPC,                KC_DEL,LT(_RAISE,KC_SPC),ALT_T(KC_HENK),KC_LEFT,KC_DOWN,KC_RIGHT \
          //`-----------------------------------------------------------------------------------------------------------------------------------'
  ),

  [_MOUSE] = LAYOUT_With_Setta21( \
  //,--------------------------------------------------------------|             |--------------------------------------------------------------.      |-----------------------------------------------|
   TG(_MOUSE), _______, _______, _______, _______, _______, _______,               _______, _______, _______, _______, _______, _______, _______,       _______,_______,_______,_______,_______,_______, \
  //|--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|      |-------+-------+-------+-------+-------+-------|
      XXXXXXX, _______, _______, _______, _______, _______, _______,               _______, _______, _______, _______, _______, _______, _______,               _______,_______,_______,_______,_______, \
  //|--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|      |-------+-------+-------+-------+-------+-------|
               _______, _______, _______, _______, _______, _______,               _______, _______, _______, _______, _______, _______, _______,       _______,_______,_______,_______,_______,_______, \
  //         |--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|      |---------------+---------------+-------+-------|
               _______, _______, _______, _______, _______, _______,               _______, _______, _______, _______, KC_BTN1, KC_MS_U, KC_BTN2,               _______,        _______,_______,_______, \
  //         |--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|      |-----------------------------------------------|
               _______,          _______,          _______, _______,               _______,          _______, _______, KC_MS_L, KC_MS_D, KC_MS_R  \
          //`-----------------------------------------------------------------------------------------------------------------------------------'
  ),

  [_BROWSER] = LAYOUT_With_Setta21( \
  //,--------------------------------------------------------------|             |--------------------------------------------------------------.      |-----------------------------------------------|
      XXXXXXX, _______, _______, _______, _______, _______, _______,               _______, _______, _______, _______, _______, _______, _______,       _______,_______,_______,_______,_______,_______, \
  //|--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|      |-------+-------+-------+-------+-------+-------|
 TG(_BROWSER), _______, _______, _______, _______, _______, _______,               _______, _______, _______, _______, _______, _______, KC_PGUP,               _______,_______,_______,_______,_______, \
  //|--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|      |-------+-------+-------+-------+-------+-------|
               _______, _______, _______, _______, _______, _______,               _______, _______, _______, _______, _______, _______, KC_PGDN,       _______,_______,_______,_______,_______,_______, \
  //         |--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|      |---------------+---------------+-------+-------|
               _______, _______, _______, _______, _______, _______,               _______, _______, _______, _______,LCTL(LSFT(KC_T)),KC_UP,LCTL(KC_W),        _______,        _______,_______,_______, \
  //         |--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|      |-----------------------------------------------|
               _______,          _______,          _______, _______,               _______,          _______, _______,LCTL(LSFT(KC_TAB)),KC_DOWN,LCTL(KC_TAB) \
          //`-----------------------------------------------------------------------------------------------------------------------------------'
  ),

  [_FLOCK] = LAYOUT_With_Setta21( \
  //,--------------------------------------------------------------|             |--------------------------------------------------------------.      |-----------------------------------------------|
      _______,TD(TD_ESQW),KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                 KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,       _______,_______,_______,_______,_______,_______, \
  //|--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|      |-------+-------+-------+-------+-------+-------|
      _______, _______, _______, _______, _______, _______, _______,               _______, _______, _______, _______, _______, _______, _______,               _______,_______,_______,_______,_______, \
  //|--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|      |-------+-------+-------+-------+-------+-------|
               _______, _______, _______, _______, _______, _______,               _______, _______, _______, _______, _______, _______, _______,       _______,_______,_______,_______,_______,_______, \
  //         |--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|      |---------------+---------------+-------+-------|
               _______, _______, _______, _______, _______, _______,               _______, _______, _______, _______, _______, _______, _______,               _______,        _______,_______,_______, \
  //         |--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|      |-----------------------------------------------|
               _______,          _______,          _______, _______,               _______,          _______, _______, _______, _______, _______  \
          //`-----------------------------------------------------------------------------------------------------------------------------------'
  ),

  [_LOWER] = LAYOUT_with_setta21( \
  //,--------------------------------------------------------------|             |--------------------------------------------------------------.      |-----------------------------------------------|
      _______,  KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                 KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,    MO(_LOWER),XXXXXXX,KC_LEFT,XXXXXXX,XXXXXXX, KC_ESC, \
  //|--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|      |-------+-------+-------+-------+-------+-------|
      _______, JP_QUOT, JP_EXLM, JP_QUES, JP_LBRC, JP_RBRC, JP_TILD,                 KC_P6,   KC_P7,   KC_P8,   KC_P9, JP_ASTR, JP_SLSH, XXXXXXX,               KC_DOWN,KC_DOWN,  KC_UP,KC_PSLS,  KC_F2, \
  //|--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|      |-------+-------+-------+-------+-------+-------|
               JP_QUOT, JP_HASH,  JP_DQT, JP_LPRN, JP_RPRN,   JP_AT,               XXXXXXX,   KC_P4,   KC_P5,   KC_P6, JP_MINS,  JP_EQL,  KC_ENT,    MO(_RAISE),XXXXXXX,KC_RIGHT,XXXXXXX,KC_PAST,KC_EQL, \
  //         |--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|      |---------------+---------------+-------+-------|
               JP_CIRC, JP_PERC, JP_AMPR, JP_SCLN, JP_COLN, JP_PIPE,                 KC_P0,   KC_P1,   KC_P2,   KC_P3, JP_PLUS,   KC_UP, KC_RSFT,               KC_PENT,        KC_PPLS,KC_PMNS, KC_DEL, \
  //         |--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|      |-----------------------------------------------|
               KC_ZKHK,          _______,       MO(_LOWER), _______,               _______,       MO(_RAISE),  JP_DOT, KC_LEFT, KC_DOWN, KC_RIGHT \
          //`-----------------------------------------------------------------------------------------------------------------------------------'
  ),

  [_RAISE] = LAYOUT_with_setta21( \
  //,--------------------------------------------------------------|             |--------------------------------------------------------------.      |------------------------------------------------|
      _______,  KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                 KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,       _______, KC_F11,  KC_F4,  KC_F7,SEND_MIN, KC_ESC, \
  //|--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|      |-------+-------+-------+-------+--------+-------|
      _______,  KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,               XXXXXXX, XXXXXXX,   KC_UP, XXXXXXX, KC_PGUP, XXXXXXX, XXXXXXX,                KC_F12,  KC_F5,  KC_F8,SEND_MAX,  KC_F2, \
  //|--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|      |-------+-------+-------+-------+--------+-------|
        LCTL_T(KC_F11), XXXXXXX,   KC_F2,   KC_F3,   KC_F4,   KC_F5,               XXXXXXX, KC_LEFT, KC_DOWN,KC_RIGHT, XXXXXXX, XXXXXXX, _______,       _______,  KC_F3,  KC_F6,  KC_F9,SEND_CIF, KC_EQL, \
  //         |--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|      |---------------+---------------+--------+-------|
         SFT_T(KC_F12),   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGDN, _______, _______,               KC_RPRN,       SEND_SUM,SEND_AVE, KC_DEL, \
  //         |--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|      |------------------------------------------------|
               _______,          _______,          _______, _______,               _______,          _______, _______, _______, _______, _______  \
          //`-----------------------------------------------------------------------------------------------------------------------------------'
  ),


  [_ADJUST] = LAYOUT_with_setta21( /* Base */
  //,--------------------------------------------------------------|             |--------------------------------------------------------------.      |-----------------------------------------------|
      _______,   RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                 KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,       _______,RGB_VAD,RGB_HUD,RGB_SAD,XXXXXXX,_______, \
  //|--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|      |-------+-------+-------+-------+-------+-------|
      _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,               RGB_RST, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,               RGB_VAI,RGB_HUI,RGB_SAI,XXXXXXX,_______, \
  //|--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|      |-------+-------+-------+-------+-------+-------|
               _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,               RGB_TOG, RGB_MOD, XXXXXXX,LCA(KC_DEL),LALT(KC_PSCR),KC_PSCR,XXXXXXX, _______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,_______, \
  //         |--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|      |---------------+---------------+-------+-------|
               _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,               RGB_VAD, RGB_VAI, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, XXXXXXX,               RGB_MOD,        RGB_TOG,_______,_______, \
  //         |--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|      |-----------------------------------------------|
               _______,          _______,          _______, _______,               _______,          _______, _______, _______, _______, _______  \
          //`-----------------------------------------------------------------------------------------------------------------------------------'
  )
};

//A description for expressing the layer position in LED mode.
layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
#ifdef RGBLIGHT_ENABLE
    switch (get_highest_layer(state)) {
    case _MOUSE:
      rgblight_sethsv_at(HSV_RED, 0);
      break;
    case _BROWSER:
      rgblight_sethsv_at(HSV_RED, 1);
      break;
    case _FLOCK:
      rgblight_sethsv_range(HSV_YELLOW, 0, 2);
      break;
    case _LOWER:
      rgblight_sethsv_range(HSV_BLUE, 0, 2);
      break;
    case _RAISE:
      rgblight_sethsv_range(HSV_RED, 0, 2);
      break;
    case _ADJUST:
      rgblight_sethsv_range(HSV_PURPLE, 0, 2);
      break;
    default: //  for any other layers, or the default layer
      rgblight_sethsv_range( 0, 0, 0, 0, 2);
      break;
    }
    rgblight_set_effect_range( 2, 6);
#endif
return state;
}

int RGB_current_mode;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  bool result = false;
  switch (keycode) {
    case SEND_SUM:
      if (record->event.pressed) {
        SEND_STRING("=SUM(");
      }
      break;
    case SEND_AVE:
      if (record->event.pressed) {
        SEND_STRING("=AVERAGE(");
      }
      break;
    case SEND_CIF:
      if (record->event.pressed) {
        SEND_STRING("=COUNTIF(");
      }
      break;
    case SEND_MAX:
      if (record->event.pressed) {
        SEND_STRING("=MAX(");
      }
      break;
    case SEND_MIN:
      if (record->event.pressed) {
        SEND_STRING("=MIN(");
      }
      break;
    #ifdef RGBLIGHT_ENABLE
      case RGB_MOD:
          if (record->event.pressed) {
            rgblight_mode(RGB_current_mode);
            rgblight_step();
            RGB_current_mode = rgblight_config.mode;
          }
        break;
      case RGB_RST:
          if (record->event.pressed) {
            eeconfig_update_rgblight_default();
            rgblight_enable();
            RGB_current_mode = rgblight_config.mode;
          }
        break;
    #endif
    default:
      result = true;
      break;
  }

  return result;
}

void matrix_init_user(void) {

}
