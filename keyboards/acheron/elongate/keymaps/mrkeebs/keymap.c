/* Copyright 2020 MrKeebs
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Layer shorthand
enum layers {
  _BASE = 0, // Base
  _EXTR,     // Extra
  _CTRL,     // Control
  _NMLK,     // Numlock
  _MACR
};

#define KC_CTAB MT(MOD_LCTL, KC_TAB)  // Control held, Tab pressed
#define KC_EXSP LT(_EXTR, KC_SPC)     // Extras layer held, Space pressed
#define KC_CTSL LT(_CTRL, KC_SLSH)    // Control layer held, Slash pressed

#define KC_NMLK TG(_NMLK)             // Toggles between Numbers and Fns on numpad
#define KC_MACR TG(_MACR)             // Toggles macro layer on numpad

#define MC_MUTE LCTL(LALT(LGUI(KC_0)))
#define MC_VOLD LCTL(LALT(LGUI(KC_MINS)))
#define MC_VOLU LCTL(LALT(LGUI(KC_EQL)))

const uint8_t RGBLED_RAINBOW_SWIRL_INTERVALS[] PROGMEM = {10, 5, 5};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT( /* Base */
  KC_GESC, KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,  KC_7,    KC_8, KC_9, \
  KC_CTAB, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   ,          KC_ENT ,  KC_4,    KC_5, KC_6, \
  KC_LSFT,          KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_UP,    KC_1,    KC_2, KC_3, \
  KC_LCTL, KC_LGUI, KC_LALT,          KC_EXSP,                   KC_SPC ,          KC_CTSL, KC_LEFT, KC_DOWN,  KC_RGHT, KC_0, KC_DOT
),
[_EXTR] = LAYOUT( /* Extras */
  KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______, _______, _______, _______, \
  _______, _______, KC_EQL , KC_MINS, _______, _______, KC_EQL , KC_MINS, KC_SCLN, KC_QUOT,          _______, _______, _______, _______, \
  _______,          _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_BSLS, KC_SLSH, _______, _______, _______, _______, \
  _______, _______, _______,          _______,                   _______,          _______, _______, _______, _______, _______, _______
),
[_CTRL] = LAYOUT( /* Control */
  _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD,RGB_M_SW, _______, _______, KC_HOME, KC_UP  , KC_PGUP, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET  ,          _______, KC_LEFT, _______, KC_RGHT, \
  _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_END , KC_DOWN, KC_PGDN, \
  _______, _______, _______,          _______,                   _______,          _______, _______, _______, _______, KC_INS , KC_DEL
)
};

uint32_t layer_state_set_user(uint32_t state) {
  writePin(F7, layer_state & (1<<1));
  writePin(C7, layer_state & (1<<2));
  writePin(B6, layer_state & (1<<3));

  return state;
}

bool led_update_user(led_t led_state) {
  writePinHigh(D2);
  writePinHigh(D1);
  writePinHigh(D0);

  return false;
}
