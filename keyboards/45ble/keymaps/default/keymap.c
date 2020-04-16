#include "45ble.h"
#include "rgblight.h"

#define _BASE 0
#define _NUMERI 1
#define _ACCENTI 2
#define _WINDOWS 3
#define _SPECIALI 4
#define _RGBADJUST 5

// Status Variables
static uint8_t layer = _BASE;
static uint8_t caps  = 0;

// Used to check underglow status
extern rgblight_config_t rgblight_config;

enum custom_keycodes {
    MACRO_1 = SAFE_RANGE,
    MACRO_2,
    MACRO_3,
    MACRO_4,
	MACRO_5,
	MACRO_6,
	MACRO_7,
	MACRO_8,
	MACRO_9,
	MACRO_10,
	MACRO_11,
	MACRO_12,
	MACRO_13,
	MACRO_14,
	MACRO_15
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
		case MACRO_1:
			SEND_STRING(SS_RALT(";"));
			return false;
		case MACRO_2:
			SEND_STRING(SS_RALT("'"));
			return false;
	    case MACRO_3:
			SEND_STRING(SS_RALT("["));
			return false;
	    case MACRO_4:
			SEND_STRING(SS_RALT("]"));
			return false;
		case MACRO_5:
			SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_KP_2)SS_TAP(X_KP_5)SS_TAP(X_KP_3)SS_UP(X_LALT));
			return false;
		case MACRO_6:
			SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_KP_1)SS_TAP(X_KP_2)SS_TAP(X_KP_6)SS_UP(X_LALT));
			return false;
		case MACRO_7:
			SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_1)SS_TAP(X_KP_5)SS_UP(X_LALT));
			return false;
		case MACRO_8:
			SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_4)SS_TAP(X_KP_7)SS_UP(X_LALT));
			return false;
		case MACRO_9:
			SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_0)SS_TAP(X_KP_0)SS_UP(X_LALT));
			return false;
		case MACRO_10:
			SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_1)SS_TAP(X_KP_7)SS_UP(X_LALT));
			return false;
		case MACRO_11:
			SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_0)SS_TAP(X_KP_4)SS_UP(X_LALT));
			return false;
		case MACRO_12:
			SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_1)SS_TAP(X_KP_0)SS_UP(X_LALT));
			return false;
		case MACRO_13:
			SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_9)SS_TAP(X_KP_2)SS_UP(X_LALT));
			return false;
		case MACRO_14:
			SEND_STRING(SS_DOWN(X_LGUI)SS_DOWN(X_LSHIFT)SS_TAP(X_LEFT)SS_UP(X_LSHIFT)SS_UP(X_LGUI));
			return false;
		case MACRO_15:
			SEND_STRING(SS_DOWN(X_LGUI)SS_DOWN(X_LSHIFT)SS_TAP(X_RIGHT)SS_UP(X_LSHIFT)SS_UP(X_LGUI));
			return false;
        }
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_BASE] = KEYMAP(
		KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, 
		LT(1, KC_TAB), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_RBRC, 
		MT(MOD_LSFT, KC_CAPS), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, 
		KC_LCTL, KC_LALT, MO(1), KC_SPC, KC_SPC, MO(2), KC_DEL, KC_LEFT, KC_DOWN, KC_RGHT, 
		KC_BSPC, KC_MINS, KC_ENT, KC_GRV, KC_UP, KC_RSFT),

	[_NUMERI] = KEYMAP(
		KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, 
		KC_TRNS, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, 
		KC_TRNS, KC_NUBS, OUT_AUTO, OUT_USB, OUT_BT, KC_TRNS, MACRO_1, MACRO_2, MACRO_3, MACRO_4, KC_TRNS, 
		TG(3), KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_PGDN, KC_VOLU, 
		KC_PSCR, KC_HOME, KC_ENT, KC_TRNS, KC_PGUP, KC_TRNS),

	[_ACCENTI] = KEYMAP(
		KC_TRNS, MACRO_5, KC_TRNS, KC_LBRC, KC_TRNS, MACRO_6, KC_TRNS, KC_NUHS, KC_EQL, KC_SCLN, MACRO_7, 
		KC_TRNS, KC_QUOT, KC_TRNS, MACRO_8, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, 
		KC_TRNS, KC_TRNS, KC_PWR, KC_TRNS, KC_TRNS, KC_TRNS, KC_RSFT, TG(1), MO(4), MO(5), 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F12, KC_TRNS),

	[_WINDOWS] = KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_LGUI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	[_SPECIALI] = KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, MACRO_9, KC_TRNS, KC_TRNS, KC_TRNS, MACRO_10, MACRO_11, MACRO_12, KC_TRNS, 
		KC_TRNS, MACRO_13, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	[_RGBADJUST] = KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, RGB_TOG, RGB_MOD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

};

//// HSV COLORS
//HSV_WHITE 0, 0, 255
//HSV_RED 0, 255, 255
//HSV_CORAL 11, 176, 255
//HSV_ORANGE 28, 255, 255
//HSV_GOLDENROD 30, 218, 218
//HSV_GOLD 36, 255, 255
//HSV_YELLOW 43, 255, 255
//HSV_CHARTREUSE 64, 255, 255
//HSV_GREEN 85, 255, 255
//HSV_SPRINGGREEN 106, 255, 255
//HSV_TURQUOISE 123, 90, 112
//HSV_TEAL 128, 255, 128
//HSV_CYAN 128, 255, 255
//HSV_AZURE 132, 102, 255
//HSV_BLUE 170, 255, 255
//HSV_PURPLE 191, 255, 255
//HSV_MAGENTA 213, 255, 255
//HSV_PINK 234, 128, 255

void set_underglow(void) {
    if (layer == _BASE && caps == 0) {
        rgblight_disable_noeeprom();
        return;
    }

    if (!rgblight_config.enable) rgblight_enable_noeeprom();
    if (rgblight_config.mode != 1) rgblight_mode_noeeprom(1);

    switch (layer) {
    case _BASE:
        if (caps == 0) {
            // rgblight_disable_noeeprom();
        } else {
            rgblight_sethsv_at (0, 0, 80,0); // Bianco
        }
        break;
    case _NUMERI:
        if (caps == 0) {
            rgblight_sethsv (128, 255, 60); // Azzurro
        } else {
            rgblight_sethsv_at (0, 0, 80,0); // Bianco
        }
        break;
	case _ACCENTI:
        if (caps == 0) {
            rgblight_sethsv (234, 180, 60); // Rosa
        } else {
            rgblight_sethsv_at (0, 0, 80,0); // Bianco
		}
        break;
	case _WINDOWS:
        if (caps == 0) {
            rgblight_sethsv (20, 255, 60);  // Arancione
        } else {
            rgblight_sethsv_at (0, 0, 80,0); // Bianco
        }
        break;
    case _SPECIALI:
        if (caps == 0) {
            rgblight_sethsv (106, 255, 60);  // Verde
        } else {
            rgblight_sethsv_at (0, 0, 80,0); // Bianco
        }
        break;
    default:
        rgblight_disable_noeeprom();
        break;
    }
}

// Update layer and set underglow
uint32_t layer_state_set_user(uint32_t state) {
    int new_layer = biton32(state);
    if (layer != new_layer) {
        layer = new_layer;
        set_underglow();
    }
    return state;
}

// Update caps lock status and set underglow
void led_set_user(uint8_t usb_led) {
    int new_caps = usb_led & (1<<USB_LED_CAPS_LOCK);
    if (caps != new_caps) {
        caps = new_caps;
        set_underglow();
    }
}

