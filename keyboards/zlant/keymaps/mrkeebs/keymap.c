#include QMK_KEYBOARD_H

#define BASE  0
#define FN    1
#define MEDIA 2

#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	LAYOUT(
		KC_GESC,              KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
		MT(MOD_LCTL, KC_TAB), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, LT(2, KC_ENT),
		KC_LSFT,              KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_UP, MT(MOD_RSFT, KC_SLSH),
		KC_LCTL,              KC_LGUI, KC_LALT, KC_LALT, LT(1, KC_SPC), KC_SPC, KC_SPC, KC_SPC, MO(3), KC_LEFT, KC_DOWN, KC_RGHT),

	LAYOUT(
		KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, _______,
		_______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, _______,           KC_MINS, KC_EQL, KC_QUOT, _______,
		_______, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______,        KC_LBRC, KC_RBRC, KC_PGUP, KC_BSLS,
		RGB_VAI, RGB_VAD, RESET, KC_PSCR, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_END),

	LAYOUT(
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,
		_______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_DQUO, _______,
		_______, KC_PSCR, KC_LSCR, _______, _______, _______, _______, _______, KC_LCBR, KC_RCBR, KC_PGUP, KC_PIPE,
		_______, RGB_MOD, RGB_HUI, RGB_HUD, RGB_VAI, RGB_VAD, _______, _______, _______, KC_HOME, KC_PGDN, KC_END ),

	LAYOUT(
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______)

};
