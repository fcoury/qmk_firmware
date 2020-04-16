/* Copyright 2018 Carlos Filoteo
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
#ifdef LED_ENABLE
  #include "protocol/serial.h"
#endif

#define _______ KC_TRNS
#define LT3_TAB LT(3, KC_TAB)
#define MT_RSFT_ENT MT(MOD_RSFT, KC_ENT)

enum custom_keycodes {
    LED_TOG = SAFE_RANGE,
    LED_CHG
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Base Layer
   * ,-------------------------------------------------------------------------.
   * | Esc |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |Bspace |
   * |-------------------------------------------------------------------------+
   * |Tab/L3|  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |   '  |
   * |-------------------------------------------------------------------------+
   * | Shift |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |Sh/En|
   * |-------------------------------------------------------------------------+
   * | Ctrl| Alt | Gui | App |  L2  |   Space   | Spc  | L1 | Down|  Up | Right|
   * `-------------------------------------------------------------------------'
   */

LAYOUT(
  KC_GESC,              KC_Q,    KC_W,    KC_E,    KC_R,          KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  MT(MOD_LCTL, KC_TAB), KC_A,    KC_S,    KC_D,    KC_F,          KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, LT(2, KC_ENT),
  KC_LSFT,              KC_Z,    KC_X,    KC_C,    KC_V,          KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   MT(MOD_RSFT, KC_SLSH),
  KC_LCTL,              KC_LALT, KC_LGUI, KC_LGUI, LT(1, KC_SPC),      KC_SPC,        KC_SPC,  MO(1),   KC_LEFT, KC_DOWN,   KC_RGHT
),

  /* FN Layer 1
   * ,-------------------------------------------------------------------------.
   * | ` ~ |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  | Delete|
   * |-------------------------------------------------------------------------+
   * |      |     |     |     |     |     |     |  -  |  =  |  [  |  ]  |  \   |
   * |-------------------------------------------------------------------------+
   * |       | F11 | F12 | F13 | F14 | F15 | F16 | F17 | F18 | F19 | F20 |     |
   * |-------------------------------------------------------------------------+
   * |     |     |     |Capsl|      |          |       | Home| PgDn| PgUp| End |
   * `-------------------------------------------------------------------------'
   */

LAYOUT( /* Right */
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_CAPS, KC_MUTE, KC_VOLD, KC_VOLU, BL_TOGG, RGB_TOG, RGB_MOD, _______, KC_MINS, KC_EQL,  KC_QUOT, _______,
  _______, KC_PSCR, KC_LSCR, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_PGUP, KC_BSLS,
  _______, _______, _______, _______, _______,     _______,      _______, _______, KC_HOME, KC_PGDN, KC_END
),

  /* FN Layer 2
   * ,-------------------------------------------------------------------------.
   * |   ~  |  !  |  @  |  #  |  $  |  %  |  ^  |  &  |  *  |  (  |  )  |Delete|
   * |-------------------------------------------------------------------------+
   * |      |     |     |     |     |     |     |  _  |  +  |  { |  }  |   |   |
   * |-------------------------------------------------------------------------+
   * |       | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 |     |
   * |-------------------------------------------------------------------------+
   * |     |     |     |Capsl|      |          |       | Home| PgDn| PgUp| End |
   * `-------------------------------------------------------------------------'
   */

LAYOUT( /* Left */
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, KC_DEL,
  _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, RGB_M_SW, _______, _______,
  _______, KC_PSCR, KC_LSCR, _______, _______, _______, _______, _______, _______, _______,  _______, RESET,
  _______, _______, _______, _______, _______,     _______,      _______, _______, _______,  _______, _______
),

  /* FN Layer 2
   * ,-------------------------------------------------------------------------.
   * | Esc | Calc|Webhm| Mail| Comp|     |     |     |     |     |PrtSc|       |
   * |-------------------------------------------------------------------------+
   * |      |     |     |     |     |     |     |     |     |     |     |      |
   * |-------------------------------------------------------------------------+
   * |       |LEDtg|LEDch|     |     |     |     |     |     |     |     |     |
   * |-------------------------------------------------------------------------+
   * |     |     |     |     |      |          |       |MousL|MousD|MousU|MousR|
   * `-------------------------------------------------------------------------'
   */

LAYOUT( /* Tab */
  KC_ESC,  KC_CALC, KC_WHOM, KC_MAIL, KC_MYCM, _______, _______, _______, _______, _______, KC_PSCR, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, LED_TOG, LED_CHG, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,     _______,      _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R
),
};

//LED keymap functions
 #ifdef LED_ENABLE
void led_chmode(void) {
  serial_send(101);
}

void led_toggle(void) {
  serial_send(100);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch(keycode) {
      case LED_TOG:
        #ifdef LED_ENABLE
        led_toggle();
        #endif
        return false;
      case LED_CHG:
        #ifdef LED_ENABLE
        led_chmode();
        #endif
        return false;
    }
  }
  return true;
};
#endif
