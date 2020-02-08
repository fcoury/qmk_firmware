#include QMK_KEYBOARD_H


#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
rgblight_config_t RGB_current_config;
#endif

extern uint8_t is_master;

enum custom_keycodes {
  _BASE,
  _FN,
  _MEDIA,
};

#define KC_TBCT MT(MOD_LCTL, KC_TAB)
#define KC_LRFN MO(_FN)
#define KC_LRMD LT(2, KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { \
[_BASE] = LAYOUT_ortho_4x12(
      KC_GESC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
      KC_TBCT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LRMD, \
      KC_LCTL, KC_LGUI, KC_LALT, KC_LRFN, KC_SPC,  KC_SPC,                    KC_SPC,  KC_LRMD, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
      ),

  [_FN] = LAYOUT_ortho_4x12( \
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
      _______, _______, _______, _______, _______, _______,                   _______, _______, KC_MINS, KC_EQL,  KC_QUOT, _______, \
      _______, _______, _______, _______, _______, _______,                   _______, _______, KC_LBRC, KC_RBRC, KC_PGUP, KC_BSLS, \
      _______, _______, _______, _______, _______, _______,                   _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
      ),

  [_MEDIA] = LAYOUT_ortho_4x12( \
      _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI,                   RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, \
      _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,                   _______, _______, KC_HOME, KC_END,  KC_UP,   _______, \
      _______, _______, _______, _______, _______, _______,                   _______, _______, KC_PGUP, KC_LEFT, KC_RGHT, _______, \
      _______, _______, _______, _______, _______, _______,                   _______, _______, KC_PGDN, KC_DOWN, KC_DOWN, _______ \
      ),

};

// define variables for reactive RGB
bool TOG_STATUS = false;

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    #ifdef RGBLIGHT_ENABLE
      rgblight_mode_noeeprom(RGB_current_config.mode);
    #endif
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      rgblight_init();
      RGB_current_config = rgblight_config;
    #endif
}
