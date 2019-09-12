/* Copyright 2019 Gondolindrim
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
    _CTRL      // Control
};

#define KC_CTAB MT(MOD_LCTL, KC_TAB)  // Control held, Tab pressed
#define KC_EXSP LT(_EXTR, KC_SPC)     // Extras layer held, Space pressed
#define KC_CTSL LT(_CTRL, KC_SLSH)    // Control layer held, Slash pressed

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT( /* Base */
    KC_GESC, KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,  KC_7,    KC_8, KC_9, \
    KC_CTAB, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , _______, KC_ENT ,  KC_4,    KC_5, KC_6, \
    KC_LSFT, _______, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_UP,    KC_1,    KC_2, KC_3, \
    KC_LCTL, KC_LGUI, KC_LALT, _______, KC_EXSP, _______, _______, KC_SPC , _______, KC_CTSL, KC_LEFT, KC_DOWN,  KC_RGHT, KC_0, KC_DOT
  ),
  [_EXTR] = LAYOUT(
    _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______, _______, _______, _______, \
    _______, _______, KC_EQL , KC_MINS, _______, _______, KC_EQL , KC_MINS, KC_SCLN, KC_QUOT, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_SLSH, KC_BSLS, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
  [_CTRL] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET  , _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
};
