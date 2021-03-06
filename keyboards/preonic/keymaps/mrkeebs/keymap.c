/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"

enum layers {
    _BASE = 0, // Base
    _EXTR,     // Extra
    _CTRL      // Control
};

#define KC_CTAB MT(MOD_LCTL, KC_TAB)  // Control held, Tab pressed
#define KC_SLSF MT(MOD_RSFT, KC_SLSH)
#define KC_EXSP LT(_EXTR, KC_SPC)     // Extras layer held, Space pressed
#define KC_CTSP LT(_CTRL, KC_SPC)     // Control layer held, Space pressed

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   \  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_BASE] = LAYOUT_preonic_grid( \
  KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
  KC_CTAB, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,  \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_SLSF, \
  KC_LCTL, KC_LCTL, KC_LALT, KC_LGUI, KC_EXSP, KC_SPC,  KC_SPC,  KC_CTSP, KC_RGUI, KC_LEFT, KC_DOWN, KC_RGHT  \
),


[_EXTR] = LAYOUT_preonic_grid( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, KC_EQL,  KC_MINS, KC_SCLN, KC_QUOT, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______, KC_BSLS, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

[_CTRL] = LAYOUT_preonic_grid( \
  RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,  \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),


};

void encoder_update_user(uint8_t index, bool clockwise) {
  print("scroll |");
  if (IS_LAYER_ON(_BASE)) {
  print("BASE |");
    if (clockwise) {
  print("clockwise\n");
      register_mods(MOD_LCTL);
      register_mods(MOD_LALT);
      register_mods(MOD_LGUI);
      register_code(KC_EQL);
      unregister_code(KC_EQL);
      unregister_mods(MOD_LGUI);
      unregister_mods(MOD_LALT);
      unregister_mods(MOD_LCTL);
    } else {
  print("counter clockwise\n");
      register_mods(MOD_LCTL);
      register_mods(MOD_LALT);
      register_mods(MOD_LGUI);
      register_code(KC_MINUS);
      unregister_code(KC_MINUS);
      unregister_mods(MOD_LGUI);
      unregister_mods(MOD_LALT);
      unregister_mods(MOD_LCTL);
    }
  } else {
  print("NOT BASE |");
    if (clockwise) {
  print("clockwise\n");
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
  print("counter clockwise\n");
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
}

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   switch (keycode) {
//         case QWERTY:
//           if (record->event.pressed) {
//             set_single_persistent_default_layer(_QWERTY);
//           }
//           return false;
//           break;
//         case COLEMAK:
//           if (record->event.pressed) {
//             set_single_persistent_default_layer(_COLEMAK);
//           }
//           return false;
//           break;
//         case DVORAK:
//           if (record->event.pressed) {
//             set_single_persistent_default_layer(_DVORAK);
//           }
//           return false;
//           break;
//         case LOWER:
//           if (record->event.pressed) {
//             layer_on(_LOWER);
//             update_tri_layer(_LOWER, _RAISE, _ADJUST);
//           } else {
//             layer_off(_LOWER);
//             update_tri_layer(_LOWER, _RAISE, _ADJUST);
//           }
//           return false;
//           break;
//         case RAISE:
//           if (record->event.pressed) {
//             layer_on(_RAISE);
//             update_tri_layer(_LOWER, _RAISE, _ADJUST);
//           } else {
//             layer_off(_RAISE);
//             update_tri_layer(_LOWER, _RAISE, _ADJUST);
//           }
//           return false;
//           break;
//         case BACKLIT:
//           if (record->event.pressed) {
//             register_code(KC_RSFT);
//             #ifdef BACKLIGHT_ENABLE
//               backlight_step();
//             #endif
//             #ifdef __AVR__
//             PORTE &= ~(1<<6);
//             #endif
//           } else {
//             unregister_code(KC_RSFT);
//             #ifdef __AVR__
//             PORTE |= (1<<6);
//             #endif
//           }
//           return false;
//           break;
//       }
//     return true;
// };

// bool muse_mode = false;
// uint8_t last_muse_note = 0;
// uint16_t muse_counter = 0;
// uint8_t muse_offset = 70;
// uint16_t muse_tempo = 50;

// void encoder_update_user(uint8_t index, bool clockwise) {
//   if (muse_mode) {
//     if (IS_LAYER_ON(_RAISE)) {
//       if (clockwise) {
//         muse_offset++;
//       } else {
//         muse_offset--;
//       }
//     } else {
//       if (clockwise) {
//         muse_tempo+=1;
//       } else {
//         muse_tempo-=1;
//       }
//     }
//   } else {
//     if (clockwise) {
//       register_code(KC_PGDN);
//       unregister_code(KC_PGDN);
//     } else {
//       register_code(KC_PGUP);
//       unregister_code(KC_PGUP);
//     }
//   }
// }

// void dip_update(uint8_t index, bool active) {
//   switch (index) {
//     case 0:
//       if (active) {
//         layer_on(_ADJUST);
//       } else {
//         layer_off(_ADJUST);
//       }
//       break;
//     case 1:
//       if (active) {
//         muse_mode = true;
//       } else {
//         muse_mode = false;
//         #ifdef AUDIO_ENABLE
//           stop_all_notes();
//         #endif
//       }
//    }
// }

// void matrix_scan_user(void) {
//   #ifdef AUDIO_ENABLE
//     if (muse_mode) {
//       if (muse_counter == 0) {
//         uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
//         if (muse_note != last_muse_note) {
//           stop_note(compute_freq_for_midi_note(last_muse_note));
//           play_note(compute_freq_for_midi_note(muse_note), 0xF);
//           last_muse_note = muse_note;
//         }
//       }
//       muse_counter = (muse_counter + 1) % muse_tempo;
//     }
//   #endif
// }

// bool music_mask_user(uint16_t keycode) {
//   switch (keycode) {
//     case RAISE:
//     case LOWER:
//       return false;
//     default:
//       return true;
//   }
// }
