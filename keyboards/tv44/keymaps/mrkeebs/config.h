#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "../../config.h"

#ifdef BACKLIGHT_ENABLE
  #define BACKLIGHT_PIN B7
  #define BACKLIGHT_LEVELS 7
  #define BACKLIGHT_BREATHING
#endif

#define PERMISSIVE_HOLD
#endif
