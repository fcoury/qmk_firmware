/* Copyright 2019 Felipe Coury <felipe.coury@gmail.com>
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

/*
 * ,---------------------------------------------------------------.
 * |Esc | Q  | W  | E  | R  | T  | Y  | U  | I  | O  | P  |  Bspc  |
 * |---------------------------------------------------------------|
 * | Tab  | A  | S  | D  | F  | G  | H  | J  | K  | L  | '  |Enter |
 * |---------------------------------------------------------------|
 * | Shift  | Z  | X  | C  | V  | B  | N  | M  | ,  | Up |    .    |
 * |---------------------------------------------------------------|
 *      |Ctrl|Gui |Alt | Spc/Lwr |   Spc/Rse   |Left|Down|Rght|
 *      `-----------------------------------------------------'
 */

	[0] = LAYOUT(
		KC_GESC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
		KC_CTAB, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_CTSL,
		KC_LCTL, KC_LGUI, KC_LALT, KC_EXSP,  KC_SPC,  KC_LEFT, KC_DOWN, KC_RIGHT
	),

/*
 * ,---------------------------------------------------------------.
 * | ~  | !  | @  | #  | $  | %  | ^  | &  | *  | (  | )  |        |
 * |---------------------------------------------------------------|
 * | Del  | F1 | F2 | F3 | F4 | F5 | F6 | _  | +  | {  | }  |  |   |
 * |---------------------------------------------------------------|
 * |        | F7 | F8 | F9 |F10 |F11 |F12 |    | ;  |PgUp|   /     |
 * |---------------------------------------------------------------|
 *      |    |    |    |         |             |Home|PgDn|End |
 *      `-----------------------------------------------------'
 */

	[_EXTR] = LAYOUT(
    KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______, \
    _______, _______, KC_EQL , KC_MINS, _______, _______, _______, KC_EQL , KC_MINS, KC_SCLN, KC_QUOT, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_BSLS,          \
    _______, _______, _______, _______, _______, _______, _______, _______
	),

/*
 * ,---------------------------------------------------------------.
 * | `  | 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  | 0  |        |
 * |---------------------------------------------------------------|
 * | Ins  | F1 | F2 | F3 | F4 | F5 | F6 | -  | =  | [  | ]  |  \   |
 * |---------------------------------------------------------------|
 * |        | F7 | F8 | F9 |F10 |F11 |F12  |    |    |   |         |
 * |---------------------------------------------------------------|
 *      |VolD|Mute|VolU|         |             |    |    |    |
 *      `-----------------------------------------------------'
 */

	[_CTRL] = LAYOUT(
    RESET,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_UP,   KC_UP, KC_DEL , \
    _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______, _______, KC_PGUP, KC_LEFT, KC_RGHT, _______, \
    _______, KC_PSCR, KC_LSCR, _______, _______, _______, _______, _______, KC_PGDN, KC_DOWN, _______,          \
    _______, _______, _______, _______, _______, _______, _______, _______
	),
};

void led_set_user(uint8_t usb_led) {
	if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
		dimple_led_on();
	} else {
		dimple_led_off();
	}
}

uint32_t layer_state_set_user(uint32_t state) {
#ifdef RGBLIGHT_ENABLE
	switch (biton32(state)) {
		case _BASE:
			rgblight_sethsv_noeeprom(HSV_WHITE);
			break;
		case _EXTR:
			rgblight_sethsv_noeeprom(HSV_GOLD);
			break;
		case _CTRL:
			rgblight_sethsv_noeeprom(HSV_WHITE);
			break;
		default:
			rgblight_sethsv_noeeprom(HSV_WHITE);
			break;
	}
#endif
return state;
}
