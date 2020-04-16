/* Copyright 2018 Holten Campbell
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
    _BASE, // Base
    _EXTR, // Extra
    _CTRL  // Control
};

#define KC_CTAB MT(MOD_LCTL, KC_TAB)  // Control held, Tab pressed
#define KC_EXSP LT(_EXTR, KC_SPC)     // Extras layer held, Space pressed
#define KC_CTSL LT(_CTRL, KC_SLSH)    // Control layer held, Slash pressed

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_GESC, KC_Q,    KC_W, KC_E,     KC_R,    KC_T,    KC_Y,        KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL, KC_BSPC,
    KC_CTAB, KC_A,    KC_S, KC_D,     KC_F,    KC_G,    KC_H,        KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT, KC_Z,    KC_X, KC_C,     KC_V,    KC_B,    LT(3, KC_B), KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_CTSL,
    KC_LCTL, KC_LGUI,       KC_LALT,  KC_EXSP,    KC_SPC,        KC_RALT,          KC_RGUI, KC_RCTL
  ),

  [_EXTR] = LAYOUT(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,  _______,
    _______, KC_MINS, KC_EQL,  KC_MINS, _______, _______,     _______, _______, KC_EQL,  KC_MINS, KC_QUOT, _______,
    _______, _______, _______, _______, _______, _______,     _______, _______, _______, KC_LBRC, KC_RBRC, KC_BSLS, _______,
    _______, _______,          _______, _______,              _______,          _______,          _______, _______
  ),

  [_CTRL] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   KC_UP, _______, KC_DEL , \
    _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT, RESET, \
    _______, KC_PSCR, KC_LSCR, _______, _______, _______, _______, _______, KC_END,  KC_PGDN, KC_DOWN, _______, _______,          \
    _______, _______, _______, _______, _______, _______, _______, _______
  ),
};

void matrix_init_user(void) {
  // set CapsLock LED to output and low
  setPinOutput(B1);
  writePinLow(B1);
  // set NumLock LED to output and low
  setPinOutput(B2);
  writePinLow(B2);
  // set ScrollLock LED to output and low
  setPinOutput(B3);
  writePinLow(B3);
}

//function for layer indicator LED
uint32_t layer_state_set_user(uint32_t state)
{
    if (state & (1<<1)) {
    writePinHigh(B1);
    } else {
        writePinLow(B1);
    }
    if (state & (1<<2)) {
    writePinHigh(B2);
    } else {
        writePinLow(B2);
    }
    if (state & (1<<3)) {
    writePinHigh(B3);
    } else {
        writePinLow(B3);
    }
    return state;
}
