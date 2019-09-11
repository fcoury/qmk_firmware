#include "austin.h"

void matrix_init_board(void){
    setPinOutput(A3);
    setPinOutput(A4);
    setPinOutput(F0);
}


void led_set_kb(uint8_t usb_led) {
    if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {
        writePinLow(A3);
    } else {
        writePinHigh(A3);
    }
    if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
        writePinLow(A4);
    } else {
        writePinHigh(A4);
    }
    if (IS_LED_ON(usb_led, USB_LED_SCROLL_LOCK)) {
        writePinLow(F0);
    } else {
        writePinHigh(F0);
    }
    led_set_user(usb_led);
}
