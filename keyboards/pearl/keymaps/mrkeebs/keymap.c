/*
Copyright 2017 Luiz Ribeiro <luizribeiro@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_spacebar(
      KC_GESC,               KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_LBRC, KC_BSPC,
      MT(MOD_LCTL, KC_TAB),  KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, LT(3, KC_ENT),
      KC_LSFT,               KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, MO(2),
      KC_LALT,    KC_LGUI,    LT(1, KC_SPC),        KC_RGUI,  KC_RCTL
      ),
  [1] = LAYOUT_spacebar(
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,  KC_BSPC,
      _______, _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_QUOT, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_BSLS, _______,
      _______, _______, _______, _______, _______
      ),
  [2] = LAYOUT_spacebar(
      _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, RGB_M_SW, KC_UP,    _______, KC_DEL,
      _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______, RGB_SPI, RGB_SPD, KC_LEFT,  KC_RIGHT, _______,
      _______, KC_PSCR, KC_LSCR, KC_MRWD, KC_MFFD, _______, _______, _______, _______, KC_DOWN,  KC_DOWN,  _______,
      _______, _______, _______, _______, _______
      ),
  [3] = LAYOUT_spacebar(
      _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, RGB_M_SW, _______, _______,  _______,
      _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______, _______, _______, KC_PGUP, _______, _______,
      _______, KC_PSCR, KC_LSCR, KC_MRWD, KC_MFFD, _______, _______, _______, KC_HOME, KC_PGDN, KC_END, _______,
      _______, _______, _______, _______, _______
      ),
};

uint32_t layer_state_set_kb(uint32_t state) {
  // if we are on layer 1
  if (state & (1<<1)){
    // light num lock led
    PORTD &= ~(1 << PD0);
  }
  else{
    PORTD |= (1 << PD0);
  }
  // if we are on layer 2
  if (state & (1<<2)){
    // light caps lock led
    PORTD &= ~(1 << PD1);
  }
  else{
    PORTD |= (1 << PD1);
  }
  // if we are on layer 3
  if (state & (1<<3)){
    // light scroll lock led
    PORTD &= ~(1 << PD6);
  }
  else{
    PORTD |= (1 << PD6);
  }
    return state;
}
