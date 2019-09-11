#pragma once

#include "quantum.h"

#define KNO KC_NO

#define LAYOUT_default( \
  K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E, K0F, K10, K11, K12, \
  K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, K1E, K1F, K20, K21, K22, K23, K24, K25, \
  K26, K27, K28, K29, K2A, K2B, K2C, K2D, K2E, K2F, K30, K31, K32, K33, K34, K35, K36, K37, K38, \
  K39, K3A, K3B, K3C, K3D, K3E, K3F, K40, K41, K42, K43, K44, K45, K46, K47, K48, K49, K4A, K4B, \
  K4C, K4D, K4E, K4F, K50, K51, K52, K53, K54, K55, K56, K57, K58, K59, K5A, K5B, K5C, K5D, K5E, \
  K5F, K60, K61, K62, K63, K64, K65, K66, K67, K68, K69, K6A, K6B, K6C, K6D, K6E, K6F, K70, K71  \
) { \
  {  K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E, K0F, K10, K11, K12  }, \
  {  K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, K1E, K1F, K20, K21, K22, K23, K24, K25  }, \
  {  K26, K27, K28, K29, K2A, K2B, K2C, K2D, K2E, K2F, K30, K31, K32, K33, K34, K35, K36, K37, K38  }, \
  {  K39, K3A, K3B, K3C, K3D, K3E, K3F, K40, K41, K42, K43, K44, K45, K46, K47, K48, K49, K4A, K4B  }, \
  {  K4C, K4D, K4E, K4F, K50, K51, K52, K53, K54, K55, K56, K57, K58, K59, K5A, K5B, K5C, K5D, K5E  }, \
  {  K5F, K60, K61, K62, K63, K64, K65, K66, K67, K68, K69, K6A, K6B, K6C, K6D, K6E, K6F, K70, K71  }, \
}

typedef union {
    uint8_t raw;
    struct {
        bool    enable :1;
        bool    breathing : 1;
        uint8_t level  :6;
    };
} backlight_config_t;

// Backlighting
extern backlight_config_t kb_backlight_config;
extern bool kb_backlight_breathing;
void backlight_init_ports(void);
void backlight_set(uint8_t level);
bool is_breathing(void);
void breathing_enable(void);
void breathing_disable(void);
void load_custom_config(void);
void save_backlight_config_to_eeprom(void);
