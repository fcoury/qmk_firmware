#include QMK_KEYBOARD_H

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

int cur_dance (qk_tap_dance_state_t *state);

//for the x tap dance. Put it here so it can be used in any keymap
void x_finished (qk_tap_dance_state_t *state, void *user_data);
void x_reset (qk_tap_dance_state_t *state, void *user_data);

enum {
  TD_Q_ESC = 0,
  TD_A_TAB,
  TD_P_BSP,
  TD_B_COM,
  TD_N_DOT,
  TD_M_SLS,
  TD_H_EQL,
  TD_J_MIN,
  TD_K_SCL,
  TD_L_QUO,
  TD_V_MOD,
};

enum custom_key_codes {
  KC_ATAB = 0,
};

#define KC_QESC TD(TD_Q_ESC)
#define KC_ATAB TD(TD_A_TAB)
#define KC_PBSP TD(TD_P_BSP)
#define KC_BCOM TD(TD_B_COM)
#define KC_NDOT TD(TD_N_DOT)
#define KC_MSLS TD(TD_M_SLS)
#define KC_JMIN TD(TD_J_MIN)
#define KC_HEQL TD(TD_H_EQL)
#define KC_KSCL TD(TD_K_SCL)
#define KC_LQUO TD(TD_L_QUO)
#define KC_VMOD TD(TD_V_MOD)
#define KC_ZSFT MT(MOD_LSFT, KC_Z)
#define KC_XGUI MT(MOD_LCTL, KC_X)
#define KC_CGUI MT(MOD_LGUI, KC_C)
#define KC_VALT MT(MOD_LALT, KC_V)
#define KC_GRSF MT(MOD_RSFT, KC_GRV)
#define KC_LENT LT(1, KC_ENT)
#define KC_LBSP LT(2, KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT_ortho_3x10(
    KC_QESC, KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_ATAB, KC_S,    KC_D,    KC_F,    KC_G,    KC_HEQL, KC_JMIN, KC_KSCL, KC_L   , KC_LENT,
    KC_ZSFT, KC_XGUI, KC_CGUI, KC_VMOD, KC_LBSP, KC_SPC,  KC_BCOM, KC_NDOT, KC_MSLS, KC_GRSF
  ),

  [1] = LAYOUT_ortho_3x10(
    _______, _______, _______, _______, _______, _______, _______, KC_UP  , KC_UP,   KC_BSPC,
    _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_RGHT, _______,
    _______, _______, _______, _______, _______, _______, RESET,   KC_DOWN, KC_DOWN, KC_BSLS
  ),

  [2] = LAYOUT_ortho_3x10(
    KC_1,    KC_2,    KC_3,    KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   ,
    KC_TAB , _______, _______, _______, _______, KC_EQL , KC_MINS, KC_SCLN, KC_QUOT, _______,
    _______, _______, _______, _______, _______, _______, KC_COMM, KC_LBRC, KC_RBRC, KC_BSLS
  ),

};

// redefines Alt+A as Alt+TAB, and Opt+A as Alt+A for Select All
#define MOD_MASK_LALT   (MOD_BIT(KC_LALT))
#define MOD_MASK_LGUI   (MOD_BIT(KC_LGUI))

uint16_t key_timer;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_ATAB:
      if (record->event.pressed) {
        key_timer = timer_read();
        register_code(KC_RCTL);
      } else {
        unregister_code(KC_RCTL);
        if (timer_elapsed(key_timer) < TAPPING_TERM) {
          if (get_mods() & MOD_MASK_LALT) {
            SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_TAB));
          } else if (get_mods() & MOD_MASK_LGUI) {
            SEND_STRING(SS_UP(X_LGUI) SS_DOWN(X_LALT) SS_TAP(X_A) SS_UP(X_LALT));
          } else {
            SEND_STRING(SS_TAP(X_A));
            return true;
          }
        }
      };
      return false;
  }
  return true;
}

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

qk_tap_dance_action_t tap_dance_actions[] = {
  // V is V on tap, ALT on hold, Alt+V (paste) on double tap
  [TD_V_MOD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, v_finished, v_reset),

  // top row keys
  [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
  [TD_A_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_A, KC_TAB),
  [TD_P_BSP] = ACTION_TAP_DANCE_DOUBLE(KC_P, KC_BSPC),

  // bottom row punctuation keys
  [TD_B_COM] = ACTION_TAP_DANCE_DOUBLE(KC_B, KC_COMM),
  [TD_N_DOT] = ACTION_TAP_DANCE_DOUBLE(KC_N, KC_DOT),
  [TD_M_SLS] = ACTION_TAP_DANCE_DOUBLE(KC_M, KC_SLSH),

  // middle row punctioation keys
  [TD_H_EQL] = ACTION_TAP_DANCE_DOUBLE(KC_H, KC_EQL),
  [TD_J_MIN] = ACTION_TAP_DANCE_DOUBLE(KC_J, KC_MINS),
  [TD_K_SCL] = ACTION_TAP_DANCE_DOUBLE(KC_K, KC_SCLN),
  [TD_L_QUO] = ACTION_TAP_DANCE_DOUBLE(KC_L, KC_QUOT),
};

