/*
Copyright 2018 Ryan "Izzy" Bales

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0002
#define MANUFACTURER    ProD
#define PRODUCT         Chicory40
#define DESCRIPTION     40% Wireless Keyboard

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 11

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
*/
#define MATRIX_ROW_PINS { F4, F1, F0, E6 }
#define MATRIX_COL_PINS { D6, D7, B4, B5, B6, C6, C7, E2, F7, F6, F5 }
#define UNUSED_PINS

/* COL2ROW, ROW2COL, or CUSTOM_MATRIX */
#define DIODE_DIRECTION COL2ROW

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCING_DELAY 5

/* key combination for magic key command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

// Bluetooth Pins
#define AdafruitBleResetPin D5
#define AdafruitBleCSPin    D4
#define AdafruitBleIRQPin   D2

// Tested:
// D5, D2, D3 *
// D5, D3, D2 *
// D5, D4, D3 *
// D5, D3, D4 *
// D5, D4, D2 -> no/slow typing
// D5, D2, D4 *

// D4, D2, D3 *
// D4, D3, D2 *
// D4, D5, D3 *
// D4, D3, D5 *
// D4, D5, D2 *
// D4, D2, D5 *

// D5
// D3
// D2
