#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "../../config.h"

#ifdef BACKLIGHT_ENABLE
    #define BACKLIGHT_PIN B2
    #define BACKLIGHT_LEVELS 7
#endif

#define PERMISSIVE_HOLD

#define USB_MAX_POWER_CONSUMPTION 50
#endif
