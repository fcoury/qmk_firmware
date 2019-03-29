#include QMK_KEYBOARD_H

#include <print.h>

// Defines the keycodes used by our macros in process_record_user
// enum custom_keycodes {
//   CHICORY40_BT_PWR = SAFE_RANGE,
//   CHICORY40_RGB_PWR,
// };

#define KC_CTAB MT(MOD_LCTL, KC_TAB)  // Control held, Tab pressed

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split(
		KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_BSPC,
		KC_CTAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_ENT,
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_LABK, OUT_BT, KC_RSFT,
		KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_SPC, KC_P, MO(1), KC_RGUI, KC_RCTL
	),

  [1] = LAYOUT_split(
		RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, OUT_AUTO,
		_______, _______, _______, _______, _______, _______, _______, _______, _______
	),
};

void matrix_init_user(void) {
	print("Happy matrix\n");
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	printf("key: %d", keycode);
	return true;
}

//   switch (keycode) {
//     case CHICORY40_BT_PWR:
//       if (record->event.pressed) {
//         // when keycode CHICORY40_BT_PWR is pressed
//       } else {
//         // when keycode CHICORY40_BT_PWR is released
//       }
//       break;
//     case CHICORY40_RGB_PWR:
//       if (record->event.pressed) {
//         // when keycode CHICORY40_RGB_PWR is pressed
// 		PORTE ^= (1<<2);
//       } else {
//         // when keycode CHICORY40_RGB_PWR is released
//       }
//       break;
//   }
//   return true;
// }

// void matrix_scan_user(void) {

// }

// void led_set_user(uint8_t usb_led) {

// }
