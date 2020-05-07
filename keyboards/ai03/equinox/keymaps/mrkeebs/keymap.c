/* Copyright 2019 Felipe Coury
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
    _BASE = 0, // Base (Mac Mods default)
    _WIN,      // Win Mods
    _EXTR,     // Extra
    _CTRL      // Control
};

#define KC_CTAB MT(MOD_LCTL, KC_TAB)  // Control held, Tab pressed
#define KC_EXSP LT(_EXTR, KC_SPC)     // Extras layer held, Space pressed
#define KC_CTSL LT(_CTRL, KC_SLSH)    // Control layer held, Slash pressed
#define KC_TWIN TG(_WIN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_all( /* Base with Mac Mods */
    KC_GESC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_CTAB, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_CTSL,
    KC_LCTL, KC_LALT, KC_LGUI,          KC_EXSP,          KC_EXSP,      KC_SPC,      KC_TWIN, KC_RALT, KC_RCTL
  ),
  [_WIN] = LAYOUT_all( /* Windows Mods */
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, KC_LGUI, KC_LALT,          _______,          _______,     _______,      _______, _______, _______
  ),
  [_EXTR] = LAYOUT_all( /* Extra Keys */
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______, _______, KC_EQL,  KC_MINS, _______, _______, KC_EQL,  KC_MINS, KC_SCLN, KC_QUOT, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_BSLS, _______,
    _______, _______, _______,          _______,          _______,     _______,      _______, _______, _______
  ),
  [_CTRL] = LAYOUT_all( /* Keyboard Functions Control */
    RESET,   _______, _______, _______, _______, _______, _______, KC_HOME, KC_END,  KC_UP,   _______, KC_DEL,
    _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______, KC_PGUP, KC_LEFT, KC_RGHT, _______, _______,
    _______, KC_PSCR, KC_LSCR, _______, _______, _______, _______, _______, KC_PGDN, KC_DOWN, _______, _______,
    _______, _______, _______,          _______,          _______,     _______,      _______, _______, _______
  )
};

/** New layer template
  [_XXXX] = LAYOUT_all(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______,          _______,          _______,     _______,      _______, _______, _______
  )
*/
