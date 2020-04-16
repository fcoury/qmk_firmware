#pragma once

#include "quantum.h"

#define _x_ KC_NO

#define LAYOUT( \
  K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E, \
  K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, K1E, \
  K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B,      K2D, K2E, \
  K30,      K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, K3E, \
  K40, K41, K42,                K46,                K4A, K4B, K4C, K4D, K4E  \
){ \
  { K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E }, \
  { K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, K1E }, \
  { K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, _x_, K2D, K2E }, \
  { K30, _x_, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, K3E }, \
  { K40, K41, K42, _x_, _x_, _x_, K46, _x_, _x_, _x_, K4A, K4B, K4C, K4D, K4E }, \
}

#define LAYOUT_split( \
  k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c, k0d, k0e, k4e,  \
  k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, k2c, k1e,  \
  k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, k1d, k2e,  \
  k30, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, k3c, k3d, k3e,  \
  k40, k41, k42, k46, k49, k4b, k4c, k4d \
){ \
  { k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c, k0d, k0e },  \
  { k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, k1d, k1e },  \
  { k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, k2c, _x_, k2e },  \
  { k30, _x_, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, k3c, k3d, k3e },  \
  { k40, k41, k42, _x_, _x_, _x_, k46, _x_, _x_, k49, _x_, k4b, k4c, k4d, k4e },  \
}
