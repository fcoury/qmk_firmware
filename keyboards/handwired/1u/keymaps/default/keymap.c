#include QMK_KEYBOARD_H

#define KC_FN_B LT(1, KC_B)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	KEYMAP(
		KC_A, KC_FN_B,
		KC_FN_B, KC_FN_B),

	KEYMAP(
		OUT_BT, OUT_BT,
		OUT_BT, OUT_BT),
};
