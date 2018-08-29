/* Copyright 2018 REPLACE_WITH_YOUR_NAME
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

#define KC_CTAB MT(MOD_LCTL, KC_TAB)
#define KC_F1SP LT(1, KC_SPC)
#define KC_F2SL LT(2, KC_SLSH)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /**
   * Base layer
   * ,------------------------------------------------------------------------,
   * | Esc |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  | BkSp |
   * |------------------------------------------------------------------------|
   * | Tab   |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  Return  |
   * |------------------------------------------------------------------------|
   * | Shift    |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |   /   |
   * |------------------------------------------------------------------------|
   * | Ctrl  | Win | Alt   | Fn1      |  Space         | Alt   | Win |  Ctrl  |
   * '------------------------------------------------------------------------'
   */
  [0] = LAYOUT(
    KC_GESC, KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC, \
    KC_CTAB  , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   ,  KC_ENT ,  \
    KC_LSFT    , KC_Z    , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_F2SL,  \
    KC_LCTL  , KC_LALT, KC_LGUI,   KC_F1SP,        KC_SPC,      KC_RGUI,  KC_RALT,   KC_RCTL   \
  ),

  /**
   * Extras - Layer for standard layout keys not present on the Base layer
   * ,------------------------------------------------------------------------,
   * |  `  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |      |
   * |------------------------------------------------------------------------|
   * |       |     |     |     |     |     |  =  |  -  |  ;  |  '  |          |
   * |------------------------------------------------------------------------|
   * | Shift    |     |     |     |     |     |     |     |  [  |  ]  |   \   |
   * |------------------------------------------------------------------------|
   * |       |     |       |          |                |       |     |        |
   * '------------------------------------------------------------------------'
   */
  [1] = LAYOUT(
    KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______, \
      _______, _______, _______, _______, _______, _______, KC_EQL , KC_MINS, KC_SCLN , KC_QUOT,  _______,  \
        _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_BSLS,  \
      _______, _______, _______,   _______,        _______,      _______,  _______,   _______   \
  ),

  /**
   * Control - Extra control keys for arrows, volume, brightness and media control
   * ,------------------------------------------------------------------------,
   * |     |     |     |     |     |     |     |     |     | Up  |     | Del  |
   * |------------------------------------------------------------------------|
   * |       |Mute |VolDn|VolUp|     |     |     |     |Left |Right|          |
   * |------------------------------------------------------------------------|
   * |          |BrgDn|BrgUp|     |     |     |     |     |Down |     |       |
   * |------------------------------------------------------------------------|
   * |       |     |       |          |                |       |     |        |
   * '------------------------------------------------------------------------'
   */
  [2] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UP  , _______, KC_DEL , \
      _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______, _______, KC_LEFT, KC_RGHT,  _______,  \
        _______, KC_PSCR, KC_LSCR, _______, _______, _______, _______, _______, KC_DOWN, _______ , _______,  \
      _______, _______, _______,   _______,        _______,      _______,  _______,   _______   \
  ),
};
