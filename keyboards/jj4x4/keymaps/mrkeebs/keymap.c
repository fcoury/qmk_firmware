/* Copyright 2019
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

enum layers {
  _BASE = 0,
  _FN1,
  _FN2,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_ortho_4x4(
    KC_PPLS,  KC_KP_9,  KC_KP_8,  KC_KP_7, \
    KC_PPLS,  KC_KP_6,  KC_KP_5,  KC_KP_4, \
    KC_PENT,  KC_KP_3,  KC_KP_2,  KC_KP_1, \
    TG(_FN1), KC_PDOT,  KC_KP_0,  KC_KP_0  \
  ),
  [_FN1] = LAYOUT_ortho_4x4(
    RGB_TOG,  RGB_HUI,  RGB_SAI,  RGB_VAI, \
    RGB_MOD,  RGB_HUD,  RGB_SAD,  RGB_VAD, \
    _______,  _______,  _______,  RESET,   \
    BL_STEP,  _______,  _______,  _______   \
  )

};
