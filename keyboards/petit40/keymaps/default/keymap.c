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
#define KC_SFLS MT(MOD_RSFT, KC_SLSH)
#define KC_FSPC LT(1, KC_SPC)
#define KC_FENT LT(2, KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT( /* Base */
  KC_GEST, KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BKSP, \
    KC_CTAB, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   ,  KC_FENT ,  \
      KC_LSFT, KC_Z    , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SFLS,  \
    KC_LCTL, KC_LALT, KC_LGUI,   KC_FSPC,        KC_SPC,      KC_RGUI,  KC_RALT,   KC_RCTL   \
),
[1] = LAYOUT(
  KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______, \
    _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL , KC_SCLN , KC_QUOT,  _______,  \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ , _______,  \
    _______, _______, _______,   _______,        _______,      _______,  _______,   _______   \
),
[2] = LAYOUT(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ , _______,  \
    _______, _______, _______,   _______,        _______,      _______,  _______,   _______   \
),
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};


void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {

}
