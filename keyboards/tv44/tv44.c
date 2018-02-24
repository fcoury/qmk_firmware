#include "tv44.h"

#ifdef BACKLIGHT_ENABLE
uint8_t led_counter = 0;
uint8_t led_level = 0;

void bl_set(void) {
	led_counter++;
	if (led_counter > 7) {
		led_counter = 0;
	}

    if (led_counter < led_level) {
        // output high
        DDRB |= (1<<2);
        PORTB |= (1<<2);
    } else {
        // Hi-Z
        DDRB &= ~(1<<2);
        PORTB &= ~(1<<2);
    }
}

void backlight_init_ports(void)
{
    DDRB &= ~(1<<2);
    PORTB &= ~(1<<2);

    backlight_init();
}

void backlight_set(uint8_t level)
{
	led_level = level;
}
#endif

void matrix_init_kb(void) {
	// put your keyboard start-up code here
	// runs once when the firmware starts up
	#ifdef BACKLIGHT_ENABLE
		backlight_init_ports();
	#endif

	matrix_init_user();
}

void matrix_scan_kb(void) {
	// put your looping keyboard code here
	// runs every cycle (a lot)

	matrix_scan_user();
	#ifdef BACKLIGHT_ENABLE
		bl_set();
	#endif
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
	// put your per-action keyboard code here
	// runs for every action, just before processing by the firmware

	return process_record_user(keycode, record);
}

void led_set_kb(uint8_t usb_led) {
	// put your keyboard LED indicator (ex: Caps Lock LED) toggling code here

	led_set_user(usb_led);
}
