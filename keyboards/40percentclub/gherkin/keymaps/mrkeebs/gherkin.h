#pragma once

#include "quantum.h"

#define LAYOUT_south_ortho_3x10( \
	 K45,   K44,   K43,   K42,   K41,   K40,   K35,   K34,   K33,   K32 , \
	 K31,   K30,   K25,   K24,   K23,   K22,   K21,   K20,   K15,   K14 , \
	 K13,   K12,   K11,   K10,   K05,   K04,   K03,   K02,   K01,   K00   \
) { \
	{ K00,   K01,   K02,   K03,   K04,   K05 }, \
	{ K10,   K11,   K12,   K13,   K14,   K15 }, \
	{ K20,   K21,   K22,   K23,   K24,   K25 }, \
	{ K30,   K31,   K32,   K33,   K34,   K35 }, \
	{ K40,   K41,   K42,   K43,   K44,   K45 }  \
}
