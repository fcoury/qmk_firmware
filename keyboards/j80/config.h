/*
Copyright 2017 Luiz Ribeiro <luizribeiro@gmail.com>

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

#define VENDOR_ID       0x20A0
#define PRODUCT_ID      0x422F
// TODO: share these strings with usbconfig.h
// Edit usbconfig.h to change these.
#define MANUFACTURER    JER
#define PRODUCT         J80

/* matrix size */
#define MATRIX_ROWS 7
#define MATRIX_COLS 14

#define MATRIX_ROW_PINS { B1, B2, B3, B5, B6, B7, B0 }
#define MATRIX_COL_PINS { A1, A3, A4, A5, A6, C7, C6, C5, C4, C3, A0, C2, A2, A7 }
#define DIODE_DIRECTION COL2ROW

#define RGBLED_NUM 5

#define NO_UART 1
#define BOOTLOADHID_BOOTLOADER 1
