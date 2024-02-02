/* Copyright 2021 Jay Greco
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#include "bongo.h"

// NOTE:
// In order to get the slave oled to receive keypresses:
// See: https://zenn.dev/teppeis/articles/2021-05-qmk-fire-process-record-in-slave

// clang-format off
enum layers {
    _BASE,
    _VIA1,
    _VIA2
};

#define LT1_SPC LT(_VIA1, KC_SPC)
#define MO1 MO(_VIA1)
#define _none_ KC_NO

enum CookytKeycodes {
    CC_NEWLINE = SAFE_RANGE,
    CC_NL = CC_NEWLINE,

    CC_TAB,

    CC_WORD_RIGHT,
    CC_WRDR = CC_WORD_RIGHT,

    CC_WORD_LEFT,
    CC_WRDL = CC_WORD_LEFT,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_ansi(
              KC_ESC ,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  /**/,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,KC_INS ,KC_DEL ,
      /*                                                                                                                                    */
      _none_ ,KC_GRV ,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,KC_6   /**/,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_MINS,KC_EQL ,    KC_BSPC    ,KC_PAUS,
      /*                                                                                                                                    */
      KC_HOME,  KC_TAB  ,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   /**/,KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_LBRC,KC_RBRC,   KC_BSLS  ,_none_ ,
      /*                                                                                                                                    */
      KC_PGUP,   KC_LCTL   ,KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   /**/,KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_SCLN,KC_QUOT,      KC_ENT     ,KC_PGUP,
      /*                                                                                                                                    */
      KC_PGDN,     KC_LSFT     ,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   /**/,KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,   KC_RSFT   ,KC_UP  ,KC_PGDN,
      /*                                                                                                                                    */
      KC_END , KC_LCTL , KC_LGUI , KC_LALT ,MO1    ,     KC_SPC        /**/,      LT1_SPC        ,KC_RALT,KC_RGUI,KC_RCTL,KC_LEFT,KC_DOWN,KC_RGHT
    ),

    [_VIA1] = LAYOUT_ansi(
              _______,_none_ ,_none_ ,_none_ ,_none_ ,_none_ ,_none_ /**/,_none_ ,_none_ ,_none_ ,_none_ ,_none_ ,_none_ ,_none_ ,_none_ ,
      /*                                                                                                                                    */
      QK_BOOT,_none_ ,_none_ ,_none_ ,_none_ ,KC_END ,_none_ ,_none_ /**/,_none_ ,_none_ ,_none_ ,KC_HOME,_none_ ,_none_ ,    _______    ,QK_BOOT,
      /*                                                                                                                                    */
      _none_ ,  CC_TAB  ,_none_ ,CC_WRDR,KC_WH_D,_none_ ,_none_ /**/,KC_WH_U,KC_PGUP,KC_HOME,CC_NL  ,_none_ ,KC_ESC ,_none_ ,   _none_   ,_none_ ,
      /*                                                                                                                                    */
      _none_ ,   _______   ,KC_END ,_none_ ,KC_PGDN,_none_ ,_none_ /**/,KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,_none_ ,_none_ ,      _______    ,_none_ ,
      /*                                                                                                                                    */
      _none_ ,     _______     ,_none_ ,_none_ ,_none_ ,_none_ ,CC_WRDL/**/,_none_ ,_none_ ,_none_ ,_none_ ,_none_ ,   _______   ,_none_ ,_none_ ,
      /*                                                                                                                                    */
      _none_ , _______ , _______ , _______ ,_none_ ,     _______       /**/,      _none_         ,_______,_______,_______,_none_ ,_none_ ,_none_
    ),

    [_VIA2] = LAYOUT_ansi(
              QK_BOOT,_none_ ,_none_ ,_none_ ,_none_ ,_none_ ,_none_ /**/,_none_ ,_none_ ,_none_ ,_none_ ,_none_ ,_none_ ,_none_ ,_none_ ,
      /*                                                                                                                                    */
      _none_ ,_none_ ,_none_ ,_none_ ,_none_ ,_none_ ,_none_ ,_none_ /**/,_none_ ,_none_ ,_none_ ,_none_ ,_none_ ,_none_ ,    _none_     ,_none_ ,
      /*                                                                                                                                    */
      _none_ ,  _none_  ,_none_ ,_none_ ,_none_ ,_none_ ,_none_ ,_none_ /**/,_none_ ,_none_ ,_none_ ,_none_ ,_none_ ,_none_ ,   _none_   ,_none_ ,
      /*                                                                                                                                    */
      _none_ ,   _none_    ,_none_ ,_none_ ,_none_ ,_none_ ,_none_ /**/,_none_ ,_none_ ,_none_ ,_none_ ,_none_ ,_none_ ,      _none_     ,_none_ ,
      /*                                                                                                                                    */
      _none_ ,     _none_      ,_none_ ,_none_ ,_none_ ,_none_ ,_none_ /**/,_none_ ,_none_ ,_none_ ,_none_ ,_none_ ,   _none_    ,_none_ ,_none_ ,
      /*                                                                                                                                    */
      _none_ , _none_  , _none_  , _none_  ,_none_ ,     _none_        /**/,      _none_         ,_none_ ,_none_ ,_none_ ,_none_ ,_none_ ,_none_
    ),
};
// clang-format on
uint8_t current_wpm = 0;

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [_VIA1] = { ENCODER_CCW_CW(KC_NO, KC_NO),     ENCODER_CCW_CW(KC_NO, KC_NO) },
    [_VIA2] = { ENCODER_CCW_CW(KC_NO, KC_NO),     ENCODER_CCW_CW(KC_NO, KC_NO) }
};
#endif

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_left())
        return OLED_ROTATION_0;
    else
        return OLED_ROTATION_180;
}

static void render_status(void) {
    oled_set_cursor(0, 0);
    oled_write_P(PSTR("SNAP75 "), false);
    oled_write_P(PSTR("Layer "), false);
    switch (get_highest_layer(layer_state)) {
        case _VIA1:
            oled_write_P(PSTR("FN1 "), false);
            break;
        case _VIA2:
            oled_write_P(PSTR("FN2 "), false);
            break;
        default: // use BASE case as default
            oled_write_P(PSTR("Base"), false);
    }

    // Host Keyboard LED Status
    oled_set_cursor(0, 1);
    static led_t persistent_led_state = {0};
    led_t led_state = host_keyboard_led_state();

    // Only update if the LED state has changed
    // Otherwise, the OLED will not turn off if an LED is on.
    if (persistent_led_state.raw != led_state.raw) {
        persistent_led_state = led_state;

        oled_write_ln_P(PSTR(""), false);

        if (led_state.caps_lock) {
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
    uint8_t current_wpm = get_current_wpm();
    oled_write(get_u8_str(current_wpm, '0'), true);

    oled_set_cursor(8, 2);
    oled_write_P(PSTR("MAX "), false);
    static uint8_t max_wpm;
    max_wpm = MAX(max_wpm, current_wpm);
    oled_write(get_u8_str(max_wpm, '0'), true);
}

bool oled_task_user(void) {
    // Update wpm
    current_wpm = get_current_wpm();

    if (is_keyboard_master()) {
        render_status();
    } else {
        bongo_render(0, 0);
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bongo_process_record(record);
    switch (keycode) {
        case CC_NEWLINE:
        case CC_TAB:
        case CC_WORD_LEFT:
        case CC_WORD_RIGHT:
            break;
    }
    return true;
}

bool should_process_keypress(void) {
    return true;
}

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  //debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}
