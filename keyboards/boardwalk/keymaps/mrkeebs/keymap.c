/*
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
enum layer {
  _BASE,
  _EXTR,
  _FN,
};

#define KC_EXSP LT(_EXTR, KC_SPC)     // Extras layer held, Space pressed

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 /* HHKB
 * .-----------------------------------------------------------------------------------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      | -      | =      | 6      | 7      | 8      | 9      | 0      | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      | [      | ]      | Y      | U      | I      | O      | P      | '      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | CAP LK | A      | S      | D      | F      | G      | HOME   | PG UP  | H      | J      | K      | L      | ;      | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | LSHIFT | Z      | X      | C      | V      | B      | END    | PG DN  | N      | M      | ,      | .      | /      | M2 |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
 * |        | LCTRL  | FN     | LALT   | LGUI   |      SPACE      |      SPACE      | LEFT   | DOWN  | UP      | RIGHT  |        |
 * '-----------------------------------------------------------------------------------------------------------------------------'
 */

 [_BASE] = LAYOUT_ortho_hhkb(
  KC_ESC,  KC_1,     KC_2,   KC_3,    KC_4,    KC_5,    KC_MINS, KC_EQL,  KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_RBRC, KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HOME, KC_PGUP, KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,  \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_END,  KC_PGDN, KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MO(_FN), \
           KC_LCTL, KC_LALT, KC_LGUI, KC_LGUI,       KC_EXSP,        KC_SPC,      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT           \
 ),


 [_EXTR] = LAYOUT_ortho_hhkb(
  KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,  KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,  \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_QUOT, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
           _______, _______, _______, _______,       _______,        _______,      _______, _______, _______, _______           \
 ),

 [_FN] = LAYOUT_ortho_hhkb(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, KC_UP,   KC_UP,   RESET,   \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_RGHT, _______, \
  _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______, _______, _______, _______, _______, KC_DOWN, _______, _______, \
           _______, _______, _______, _______,       _______,        _______,      _______, _______, _______, _______           \
 ),

};
