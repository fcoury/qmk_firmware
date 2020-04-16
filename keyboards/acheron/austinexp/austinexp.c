#include "austinexp.h"

#define CAPS_LOCK_LED_PORT GPIOA
#define CAPS_LOCK_LED_BIT 3

#define NUM_LOCK_LED_PORT GPIOA
#define NUM_LOCK_LED_BIT 4

#define SCROLL_LOCK_LED_PORT GPIOF
#define SCROLL_LOCK_LED_BIT 0

#define LED_INIT_DELAY 500


void physical_led_init(void)
{

palSetPad(NUM_LOCK_LED_PORT, NUM_LOCK_LED_BIT);
chThdSleepMilliseconds(LED_INIT_DELAY);
palClearPad(NUM_LOCK_LED_PORT, NUM_LOCK_LED_BIT);

palSetPad(CAPS_LOCK_LED_PORT, CAPS_LOCK_LED_BIT);
chThdSleepMilliseconds(LED_INIT_DELAY);
palClearPad(CAPS_LOCK_LED_PORT, CAPS_LOCK_LED_BIT);

palSetPad(SCROLL_LOCK_LED_PORT, SCROLL_LOCK_LED_BIT);
chThdSleepMilliseconds(LED_INIT_DELAY);
palClearPad(SCROLL_LOCK_LED_PORT, SCROLL_LOCK_LED_BIT);

}

void matrix_init_board(void){
physical_led_init();
}


void led_set_kb(uint8_t usb_led) {
    if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {
        palSetPad(NUM_LOCK_LED_PORT, NUM_LOCK_LED_BIT);
	  
    } else {
        palClearPad(NUM_LOCK_LED_PORT, NUM_LOCK_LED_BIT);
    }
    if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
        palSetPad(CAPS_LOCK_LED_PORT, CAPS_LOCK_LED_BIT);
    } else {
        palClearPad(CAPS_LOCK_LED_PORT, CAPS_LOCK_LED_BIT);
    }
    if (IS_LED_ON(usb_led, USB_LED_SCROLL_LOCK)) {
        palSetPad(SCROLL_LOCK_LED_PORT, CAPS_LOCK_LED_BIT);
    } else {
        palClearPad(SCROLL_LOCK_LED_PORT, CAPS_LOCK_LED_BIT);
    }
    led_set_user(usb_led);
}
