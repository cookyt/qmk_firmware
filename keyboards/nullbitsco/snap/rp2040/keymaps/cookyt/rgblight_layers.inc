#include QMK_KEYBOARD_H

#include "caps_word.h"
#include "constants.h"

/*
Order of the LEDs: Looking down at the down at the keyboard (ESC is top-left):
LEFT              RIGHT
+----------+----------+
|   9   8  |  7   6   |
| 0        |        5 |
|   1   2  |  3   4   |
+----------+-----------
*/

#define LEFT_RIGHT_COLORS(color_left, color_right)  \
    {0, 3, color_left},                             \
    {3, 5, color_right},                            \
    {8, 2, color_left}

const rgblight_segment_t PROGMEM rgblight_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {2, 2, HSV_RED}
);

#define MY_RGB_TEAL  0x0b, 0xff, 0x6d
#define MY_RGB_BLUE  0xdd, 0xf7, 0xff

#define MY_HSV_TEAL  255*144/360, (255*.700), (255*.800)
#define MY_HSV_BLUE  255*194/360, (255*.133), (255*.750)

const rgblight_segment_t PROGMEM rgblight_base_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    LEFT_RIGHT_COLORS(MY_HSV_TEAL, MY_HSV_BLUE)
);

const rgblight_segment_t PROGMEM rgblight_nav_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    LEFT_RIGHT_COLORS(HSV_CHARTREUSE, HSV_ORANGE)
);

const rgblight_segment_t PROGMEM rgblight_num_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    LEFT_RIGHT_COLORS(HSV_PURPLE, HSV_MAGENTA)
);

// Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    rgblight_base_layer,
    rgblight_nav_layer,
    rgblight_num_layer,

    // Should be the last layer so that it always applies on top of existing
    // colors.
    rgblight_capslock_layer
);

void keyboard_post_init_RGBLIGHT_LAYERS(void) {
    rgblight_layers = my_rgb_layers;
}

bool led_update_RGBLIGHT_LAYERS(led_t led_state) {
    rgblight_set_layer_state(3, led_state.caps_lock || is_caps_word_on());
    return true;
}

layer_state_t default_layer_state_set_RGBLIGHT_LAYERS(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _BASE));
    return state;
}

layer_state_t layer_state_set_RGBLIGHT_LAYERS(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _VIA1));
    rgblight_set_layer_state(2, layer_state_cmp(state, _VIA2));
    return state;
}

