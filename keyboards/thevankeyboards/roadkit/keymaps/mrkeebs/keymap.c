#include "roadkit.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#define _NP 0
#define _L1 1
#define _L2 2

// Macro name shortcuts
#define NUMPAD M(_NP)
#define LAYER1 M(_L1)
#define LAYER2 M(_L2)

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Macros
enum custom_keycodes {
    OBS_ACTION = SAFE_RANGE,
    OBS_WEBCAM,
    OBS_SCREEN,
    OBS_WEBZOOM,
    OBS_INTRO
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_NP] = /* Numpad */
    LAYOUT_ortho_4x4(KC_KP_7, KC_KP_8,   KC_KP_9,   KC_KP_MINUS,           \
                     KC_KP_4, KC_KP_5,   KC_KP_6,   KC_KP_PLUS,            \
                     KC_KP_1, KC_KP_2,   KC_KP_3,   LT(2, KC_KP_ASTERISK), \
                     KC_KP_0, TG(_L1),   KC_KP_DOT, KC_KP_ENTER),
  [_L1] = /* LAYER 1 */
    LAYOUT_ortho_4x4(_______,    _______,    _______,     _______, \
                     OBS_SCREEN, OBS_INTRO,  _______,     _______, \
                     OBS_WEBCAM, OBS_ACTION, OBS_WEBZOOM, _______, \
                     _______,    _______,    _______,     _______),
  [_L2] = /* LAYER 2 */
    LAYOUT_ortho_4x4(BL_TOGG, BL_INC,  BL_STEP,  BL_OFF,  \
                     _______, BL_DEC,  BL_BRTG,  _______, \
                     _______, _______, _______,  _______, \
                     _______, RESET,   KC_BSPC,  _______)
};

const uint16_t PROGMEM fn_actions[] = {

};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case OBS_ACTION:
              SEND_STRING(SS_LALT(SS_LGUI("1")));
              return false;
            case OBS_WEBCAM:
              SEND_STRING(SS_LALT(SS_LGUI("2")));
              return false;
            case OBS_SCREEN:
              SEND_STRING(SS_LALT(SS_LGUI("3")));
              return false;
            case OBS_WEBZOOM:
              SEND_STRING(SS_LALT(SS_LGUI("4")));
              return false;
            case OBS_INTRO:
              SEND_STRING(SS_LALT(SS_LGUI("5")));
              return false;
        }
    }
    return true;

}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case _L2:
          if (record->event.pressed) {
            persistent_default_layer_set(1UL<<_L2);
          }
          break;
        case _L1:
          if (record->event.pressed) {
            persistent_default_layer_set(1UL<<_L1);
          }
          break;
        case _NP:
          if (record->event.pressed) {
            persistent_default_layer_set(1UL<<_NP);
          }
          break;
      }
    return MACRO_NONE;
};

uint32_t layer_state_set_user(uint32_t state) {
  switch (biton32(state)) {
    case _L1:
      backlight_set(2);
      break;
    case _NP:
      backlight_set(3);
      break;
  }
  return state;
}
