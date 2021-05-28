#include QMK_KEYBOARD_H

// double taps
typedef struct {
  bool is_press_action;
  int state;
} tap;

enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  DOUBLE_SINGLE_TAP = 5, //send two single taps
  TRIPLE_TAP = 6,
  TRIPLE_HOLD = 7
};

int cur_dance(qk_tap_dance_state_t *state);
void x_finished(qk_tap_dance_state_t *state, void *user_data);
void x_reset(qk_tap_dance_state_t *state, void *user_data);

enum {
  TD_Q_ESC = 0, // Q and ESC
  TD_A_TAB,     // A and TAB
  TD_P_BSP,     // P and BACKSPACE
  TD_B_COM,     // B and COMMA (,)
  TD_N_DOT,     // N and DOT (.)
  TD_M_SLS,     // M and SLASH (/)
  TD_H_EQL,     // H and EQUAL (=)
  TD_J_MIN,     // J and MINUS (-)
  TD_K_SCL,     // K and SEMICOLON (;)
  TD_L_ENT,     // L and ENTER
  TD_V_MOD,     // V is V on tap, ALT on hold, Alt+V (paste) on double tap
	TD_L_QFN,     // L is L on tap, FN2 on hold, Enter on double tap
};

#define KC_QESC TD(TD_Q_ESC) // Q and ESC
#define KC_ATAB TD(TD_A_TAB) // A and TAB
#define KC_PBSP TD(TD_P_BSP) // P and Backspace
#define KC_BCOM TD(TD_B_COM) // B and COMMA
#define KC_NDOT TD(TD_N_DOT) // N and DOT
#define KC_MSLS TD(TD_M_SLS) // M and SLASH
#define KC_JMIN TD(TD_J_MIN) // J and MINUS
#define KC_HEQL TD(TD_H_EQL) // H and EQUAL
#define KC_KSCL TD(TD_K_SCL) // K and SEMICOLON
#define KC_LQUO TD(TD_L_ENT) // L and ENTER
#define KC_VMOD TD(TD_V_MOD) // V special handler

#define KC_LQFN TD(TD_L_QFN) // Tap L, double QUOTE, hold Layer 2

// hold for MOD
#define KC_ZSFT MT(MOD_LSFT, KC_Z)
#define KC_XCTL MT(MOD_LCTL, KC_X)
#define KC_CWIN MT(MOD_LGUI, KC_C)
#define KC_VALT MT(MOD_LALT, KC_V)
#define KC_GRSF MT(MOD_RSFT, KC_GRV)

// hold for layer
#define KC_LSPC LT(1, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(
		KC_QESC, KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
		KC_ATAB, KC_S,    KC_D,    KC_F,    KC_G,    KC_HEQL, KC_JMIN, KC_KSCL, KC_LQFN,
		KC_ZSFT, KC_XCTL, KC_CWIN, KC_VMOD, KC_BCOM, KC_NDOT, KC_MSLS,
		KC_LSPC
	),

	[1] = LAYOUT(
		KC_1,    KC_2,    KC_3,    KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   ,
		KC_TAB,  _______, _______, _______, _______, KC_EQL , KC_MINS, KC_SCLN, KC_QUOT,
		_______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_BSLS,
		_______
	),

	[2] = LAYOUT(
		KC_GRV,  _______, _______, _______, KC_HOME, KC_END,  KC_UP,   _______, _______, RESET,
		_______, _______, _______, _______, KC_PGUP, KC_LEFT, KC_RGHT, _______, _______,
		_______, _______, _______, _______, KC_PGDN, KC_DOWN, _______,
		_______
	),

};

int cur_dance(qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed)  return SINGLE_TAP;
    //key has not been interrupted, but they key is still held. Means you want to send a 'HOLD'.
    else return SINGLE_HOLD;
  }
  else if (state->count == 2) {
    /*
     * DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
     * action when hitting 'pp'. Suggested use case for this return value is when you want to send two
     * keystrokes of the key, and not the 'double tap' action/macro.
    */
    if (state->interrupted) return DOUBLE_SINGLE_TAP;
    else if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  //Assumes no one is trying to type the same letter three times (at least not quickly).
  //If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
  //an exception here to return a 'TRIPLE_SINGLE_TAP', and define that enum just like 'DOUBLE_SINGLE_TAP'
  if (state->count == 3) {
    if (state->interrupted || !state->pressed)  return TRIPLE_TAP;
    else return TRIPLE_HOLD;
  }
  else return 8; //magic number. At some point this method will expand to work for more presses
}

static tap vtap_state = {
  .is_press_action = true,
  .state = 0
};

void v_finished(qk_tap_dance_state_t *state, void *user_data) {
  vtap_state.state = cur_dance(state);
  switch (vtap_state.state) {
    case SINGLE_TAP: register_code(KC_V); break;
    case SINGLE_HOLD: register_code(KC_LALT); break;
    case DOUBLE_TAP: register_code(KC_LALT); register_code(KC_V); break;
    case DOUBLE_HOLD: register_code(KC_LALT); break;
    case DOUBLE_SINGLE_TAP: register_code(KC_V); unregister_code(KC_V); register_code(KC_V);
  }
}

void v_reset(qk_tap_dance_state_t *state, void *user_data) {
  switch (vtap_state.state) {
    case SINGLE_TAP: unregister_code(KC_V); break;
    case SINGLE_HOLD: unregister_code(KC_LALT); break;
    case DOUBLE_TAP: unregister_code(KC_LALT); unregister_code(KC_V); break;
    case DOUBLE_HOLD: unregister_code(KC_LALT);
    case DOUBLE_SINGLE_TAP: unregister_code(KC_V);
  }
  vtap_state.state = 0;
}

void l_finished(qk_tap_dance_state_t *state, void *user_data) {
  vtap_state.state = cur_dance(state);
  switch (vtap_state.state) {
    case SINGLE_TAP: register_code(KC_L); break;
    case SINGLE_HOLD: layer_on(2); break;
    case DOUBLE_TAP: layer_on(2); register_code(KC_ENT); break;
    case DOUBLE_HOLD: layer_on(2); break;
    case DOUBLE_SINGLE_TAP: register_code(KC_L); unregister_code(KC_L); register_code(KC_L);
  }
}

void l_reset(qk_tap_dance_state_t *state, void *user_data) {
  switch (vtap_state.state) {
    case SINGLE_TAP: unregister_code(KC_L); break;
    case SINGLE_HOLD: layer_off(2); break;
    case DOUBLE_TAP: layer_off(2); unregister_code(KC_L); break;
    case DOUBLE_HOLD: layer_off(2);
    case DOUBLE_SINGLE_TAP: unregister_code(KC_L);
  }
  vtap_state.state = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
  // V is V on tap, ALT on hold, Alt+V (paste) on double tap
  [TD_V_MOD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, v_finished, v_reset),

	// L is L on tap, FN2 on hold, Enter on double tap
  [TD_L_QFN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, l_finished, l_reset),

  // top row keys
  [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
  [TD_A_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_A, KC_TAB),
  [TD_P_BSP] = ACTION_TAP_DANCE_DOUBLE(KC_P, KC_BSPC),

  // bottom row punctuation keys
  [TD_B_COM] = ACTION_TAP_DANCE_DOUBLE(KC_B, KC_COMM),
  [TD_N_DOT] = ACTION_TAP_DANCE_DOUBLE(KC_N, KC_DOT),
  [TD_M_SLS] = ACTION_TAP_DANCE_DOUBLE(KC_M, KC_SLSH),

  // middle row punctuation keys
  [TD_J_MIN] = ACTION_TAP_DANCE_DOUBLE(KC_J, KC_MINS),
  [TD_H_EQL] = ACTION_TAP_DANCE_DOUBLE(KC_H, KC_EQL),
  [TD_K_SCL] = ACTION_TAP_DANCE_DOUBLE(KC_K, KC_SCLN),
};


