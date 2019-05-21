/* Copyright 2019 funderburker
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
    _BASE = 0, // Base
    _ALT,      // Alternate
    _MEDIA,    // Media
    _CTRL,     // Control
    _EXTR,     // Extra
		_RGB
};

#define KC_CTAB MT(MOD_LCTL, KC_TAB)  // Control held, Tab pressed
#define KC_EXSP LT(_EXTR, KC_SPC)     // Extras layer held, Space pressed
#define KC_RGEN LT(_RGB,  KC_ENT)     // RGB layer held, Enter pressed

#define MC_MUTE LCTL(LALT(LGUI(KC_0)))
#define MC_VOLD LCTL(LALT(LGUI(KC_MINS)))
#define MC_VOLU LCTL(LALT(LGUI(KC_EQL)))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Default layer
  [_BASE] = LAYOUT_all(
		KC_HOME, KC_ESC,  KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
		KC_PGUP, KC_CTAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT, KC_RGEN,
		KC_PGDN, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, MO(_CTRL),
		KC_END,  KC_LGUI, KC_LALT,                 KC_EXSP, KC_SPC,            KC_RALT, KC_LCTL
  ),

  // Alternate layer
  [_ALT] = LAYOUT_all(
		MC_MUTE, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		MC_VOLU, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		MC_VOLD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		KC_MPLY, _______, _______, _______, _______, _______, _______
  ),

  // Media layer
  [_MEDIA] = LAYOUT_all(
		KC_MUTE, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		KC_VOLU, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		KC_VOLD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		KC_MPLY, _______, _______, _______, _______, _______, _______
  ),

  // Control layer
  [_CTRL] = LAYOUT_all(
		TG(_ALT),   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_END,  KC_UP,   _______, KC_DEL,
		TG(_MEDIA), _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______, _______, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT, RESET,
		_______,    _______, KC_MPLY, KC_MPRV, KC_MNXT, _______, _______, _______, _______, KC_END,  KC_PGDN, KC_DOWN, _______, _______,
		_______,    _______, _______, _______, _______, _______, _______
  ),

  // Extra keys layer
  [_EXTR] = LAYOUT_all(
		_______, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PLUS, KC_MINS, _______, _______, _______,
		_______, _______, _______, _______, _______, KC_SPC,  _______, _______, _______, _______, _______, KC_BSLS, _______, _______,
		_______, KC_ESC,  _______, _______, _______, _______, _______
  ),

  // RGB layer
  [_RGB] = LAYOUT_all(
    RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,
		_______, KC_CAPS, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, BL_TOGG, BL_INC, _______, _______, _______, _______, _______, _______,
		_______, _______, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, BL_STEP, BL_DEC, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______
  ),
};
