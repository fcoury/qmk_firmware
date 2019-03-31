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
#define KC_L1K0 LT(1, KC_KP_0)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_NP] = /* Numpad */
    LAYOUT_numpad_4x4(KC_KP_7, KC_KP_8, KC_KP_9, KC_PPLS, \
                      KC_KP_4, KC_KP_5, KC_KP_6,          \
                      KC_KP_1, KC_KP_2, KC_KP_3, KC_PENT, \
                      KC_L1K0,          KC_PDOT),
  [_L1] = /* LAYER 1 */
    LAYOUT_numpad_4x4(_______, _______, _______, _______, \
                      _______, _______, _______,          \
                      _______, _______, _______, _______, \
                      _______,          _______),
};
