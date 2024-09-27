#include "simple_oled_status.h"

#include "constants.h"
#include "oled/oled_driver.h"
#include "pico/platform.h"
#include "wpm.h"

static uint8_t gCurrentWpm = 0;
static uint8_t gMaxWpm = 0;

void simple_oled_status_task(void) {
  gCurrentWpm = get_current_wpm();
  gMaxWpm = MAX(gMaxWpm, gCurrentWpm);
}

void simple_oled_status_render(void) {
    oled_set_cursor(0, 0);
    oled_write_P(PSTR("SNAP75 "), false);
    oled_write_P(PSTR("Layer "), false);
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("Base"), false);
            break;
        case _VIA1:
            oled_write_P(PSTR("FN1 "), false);
            break;
        case _VIA2:
            oled_write_P(PSTR("FN2 "), false);
            break;
        default:
            oled_write_P(PSTR("???"), true);
    }

    // Host Keyboard LED Status
    oled_set_cursor(0, 1);
    static led_t persistent_led_state = {0};
    led_t        led_state            = host_keyboard_led_state();

    // Only update if the LED state has changed
    // Otherwise, the OLED will not turn off if an LED is on.
    if (persistent_led_state.raw != led_state.raw) {
        persistent_led_state = led_state;

        oled_write_ln_P(PSTR(""), false);

        if (led_state.caps_lock || is_caps_word_on()) {
            oled_set_cursor(0, 1);
            oled_write_P(PSTR("CAPS"), false);
        }

        if (led_state.num_lock) {
            oled_set_cursor(5, 1);
            oled_write_P(PSTR("NUM"), true);
        }

        if (led_state.scroll_lock) {
            oled_set_cursor(9, 1);
            oled_write_P(PSTR("SCR"), false);
        }
    }

    // WPM and max WPM
    oled_set_cursor(0, 2);
    oled_write_P(PSTR("WPM "), false);
    oled_write(get_u8_str(gCurrentWpm, '0'), true);

    oled_set_cursor(8, 2);
    oled_write_P(PSTR("MAX "), false);
    oled_write(get_u8_str(gMaxWpm, '0'), true);
}
