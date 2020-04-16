#include QMK_KEYBOARD_H
#include "muse.h"

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

#define LC_LOWR MO(_LOWER)
#define LC_RAIS MO(_RAISE)
#define KC_ENRS LT(_RAISE, KC_ENT)
#define KC_SLSF MT(MOD_RSFT, KC_SLSH)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	/* Layer 0
	 * ,-----------------------------------------------------------------------------------.
	 * | Esc   |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
	 * |-------+------+------+------+------+-------------+------+------+------+------+------|
	 * | CtlTab|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
	 * |-------+------+------+------+------+------|------+------+------+------+------+------|
	 * | Shift |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  | / L2 |
	 * |-------+------+------+------+------+------+------+------+------+------+------+------|
	 * | Ctrl  |  GUI | Caps |  Alt |Layer1|    Space    |Layer2|  /   | Left | Down |Right |
	 * `-----------------------------------------------------------------------------------'
	 */
	[_QWERTY] = LAYOUT_planck_grid(
		KC_GESC,               KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
		MT(MOD_LCTL, KC_TAB),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENRS,
		KC_LSFT,               KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_SLSF,
		KC_LCTL, 							 KC_LGUI, KC_LGUI, KC_LALT, LC_LOWR, KC_SPC, KC_SPC, LC_RAIS, KC_SLSH, KC_LEFT, KC_DOWN, KC_RGHT
  ),


	/* Layer 1 (r_ Indicates RGB Controls)
	 * ,-----------------------------------------------------------------------------------.
	 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
	 * |------+------+------+------+------+-------------+------+------+------+------+------|
	 * |      |r_TOG |r_Mode|r_Hue+|r_Hue-|      |      |   -  |   =  |   [  |   '  |      |
	 * |------+------+------+------+------+------|------+------+------+------+------+------|
	 * |      |BL_TOG|BL_STEP|     |      |      |      |      |      |      |      |      |
	 * |------+------+------+------+------+------+------+------+------+------+------+------|
	 * |      |      |      |      |      |      |      |      |      |      |      |      |
	 * `-----------------------------------------------------------------------------------'
	 */
	[_LOWER] = LAYOUT_planck_grid(
		_______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
		_______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_M_SW, _______, _______, KC_MINS, KC_EQL,  KC_QUOT, _______,
		_______, BL_TOGG, BL_STEP, _______, _______, _______,  _______, _______, KC_LBRC, KC_RBRC, KC_PGUP, KC_BSLS,
		_______, _______, _______, _______, _______, _______,  _______, _______, _______, KC_HOME, KC_PGDN, KC_END
  ),

	/* Layer 2
	 * ,-----------------------------------------------------------------------------------.
	 * |   `  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |      |
	 * |------+------+------+------+------+-------------+------+------+------+------+------|
	 * |      | Vol- | Vol+ | Mute |      |      |      |  F11 |  F12 |      |      |      |
	 * |------+------+------+------+------+------|------+------+------+------+------+------|
	 * |      |      |      |      |      |      |      |      |      |      |      |      |
	 * |------+------+------+------+------+------+------+------+------+------+------+------|
	 * | Reset|      |      |      |      |      |      |      |      |      |      |      |
	 * `-----------------------------------------------------------------------------------'
	 */
	[_RAISE] = LAYOUT_planck_grid(
		KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
		KC_CAPS, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______, KC_F11,  KC_F12,  _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
	),

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 20;

extern float clicky_rand;

void matrix_scan_user(void) {
  #ifdef AUDIO_ENABLE
    if (muse_mode) {
      if (muse_counter == 0) {
        uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
        if (muse_note != last_muse_note) {
          stop_note(compute_freq_for_midi_note(last_muse_note));
          play_note(compute_freq_for_midi_note(muse_note), 0xF);
          last_muse_note = muse_note;
        }
      }
      muse_counter = (muse_counter + 1) % muse_tempo;
    }
  #endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case LC_RAIS:
    case LC_LOWR:
      return false;
    default:
      return true;
  }
}
