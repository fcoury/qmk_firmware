#pragma once

#include "quantum.h"
#include "outputselect.h"

#define KEYMAP( \
	K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, \
	K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110,       K112, K113, \
	K200,       K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, \
	K300, K301, K302,                   K306,                   K310, K311, K312, K313  \
) { \
	{ K000,  K001,  K002,  K003,  K004,  K005,  K006,  K007,  K008,  K009,  K010,  K011,  K012,  K013 }, \
	{ K100,  K101,  K102,  K103,  K104,  K105,  K106,  K107,  K108,  K109,  K110,  KC_NO, K112,  K113 }, \
	{ K200,  KC_NO, K202,  K203,  K204,  K205,  K206,  K207,  K208,  K209,  K210,  K211,  K212,  K213 }, \
	{ K300,  K301,  K302,  KC_NO, KC_NO, KC_NO, K306,  KC_NO, KC_NO, KC_NO, K310,  K311,  K312,  K313 }  \
}
