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
#include "action.h"
#include "keycodes.h"
#include "oled_driver.h"
#include QMK_KEYBOARD_H

#include "bongo.h"
#include "constants.h"
#include "keyboard.h"
#include "simple_oled_status.h"
#include "typehud.h"

// NOTE:
// In order to get the slave oled to receive keypresses:
// See:
// https://zenn.dev/teppeis/articles/2021-05-qmk-fire-process-record-in-slave

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_ansi(
              KC_ESC ,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  /**/,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,KC_INS ,KC_DEL ,
      /*                                                                                                                                    */
      KC_MPLY,KC_GRV ,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,KC_6   /**/,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_MINS,KC_EQL ,    KC_BSPC    ,KC_PAUS,
      /*                                                                                                                                    */
      KC_HOME,  KC_TAB  ,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   /**/,KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_LBRC,KC_RBRC,   KC_BSLS  ,KC_CAPS,
      /*                                                                                                                                    */
      KC_PGUP,   KC_LCTL   ,KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   /**/,KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_SCLN,CT_QUOT,      KC_ENT     ,KC_PSCR,
      /*                                                                                                                                    */
      KC_PGDN,     KC_LSFT     ,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   /**/,KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,   KC_RSFT   ,KC_UP  ,KC_PAUS,
      /*                                                                                                                                    */
      KC_END , KC_LCTL ,MO1    , KC_LALT , KC_LGUI ,     LT1_SPC       /**/,      LT1_ENT        ,KC_RALT,KC_RGUI,KC_RCTL,KC_LEFT,KC_DOWN,KC_RGHT
    ),

    [_VIA1] = LAYOUT_ansi(
              _______,_none_ ,_none_ ,_none_ ,_none_ ,_none_ ,_none_ /**/,_none_ ,_none_ ,_none_ ,_none_ ,_none_ ,_none_ ,_none_ ,_none_ ,
      /*                                                                                                                                    */
      QK_BOOT,_none_ ,_none_ ,_none_ ,_none_ ,KC_END ,_none_ ,_none_ /**/,_none_ ,_none_ ,_none_ ,KC_HOME,_none_ ,_none_ ,    _______    ,QK_BOOT,
      /*                                                                                                                                    */
      _none_ ,  CC_TAB  ,KC_DEL ,CC_WRDR,KC_WH_D,_none_ ,_none_ /**/,KC_WH_U,KC_PGUP,KC_HOME,CC_NL  ,_none_ ,KC_ESC ,_none_ ,   _none_   ,_none_ ,
      /*                                                                                                                                    */
      _none_ ,   _______   ,KC_END ,_none_ ,KC_PGDN,_none_ ,_none_ /**/,KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,_none_ ,_none_ ,      _______    ,_none_ ,
      /*                                                                                                                                    */
      _none_ ,     _______     ,_none_ ,CC_TABL,CC_TABR,_none_ ,CC_WRDL/**/,_none_ ,_none_ ,CC_TABL,CC_TABR,_none_ ,   _______   ,_none_ ,_none_ ,
      /*                                                                                                                                    */
      _none_ , _______ , _______ , _______ ,_______,     _______       /**/,      _______        ,_______,_______,_______,_none_ ,_none_ ,_none_
    ),

    [_VIA2] = LAYOUT_ansi(
              QK_CLR ,_none_ ,_none_ ,_none_ ,_none_ ,_none_ ,_none_ /**/,_none_ ,_none_ ,_none_ ,_none_ ,_none_ ,_none_ ,_none_ ,_none_ ,
      /*                                                                                                                                    */
      _none_ ,_none_ ,_none_ ,_none_ ,_none_ ,_none_ ,_none_ ,_none_ /**/,KC_7   ,KC_8   ,KC_9   ,_none_ ,_none_ ,_none_ ,    _none_     ,_none_ ,
      /*                                                                                                                                    */
      _none_ ,  _none_  ,_none_ ,_none_ ,_none_ ,_none_ ,_none_ ,/**/_none_ ,KC_4   ,KC_5   ,KC_6   ,_none_ ,_none_ ,_none_ ,   _none_   ,_none_ ,
      /*                                                                                                                                    */
      _none_ ,   _none_    ,_none_ ,_none_ ,_none_ ,_none_ ,_none_ /**/,_none_ ,KC_1   ,KC_2   ,KC_3   ,_none_ ,_none_ ,      _none_     ,_none_ ,
      /*                                                                                                                                    */
      _none_ ,     KC_LSFT     ,_none_ ,_none_ ,_none_ ,_none_ ,_none_ /**/,_none_ ,KC_0   ,KC_COMM,KC_DOT ,_none_ ,   KC_RSFT   ,_none_ ,_none_ ,
      /*                                                                                                                                    */
      _none_ , _none_  , _______ , _none_  ,_none_ ,     KC_SPC        /**/,      KC_ENT         ,_none_ ,_none_ ,_none_ ,_none_ ,_none_ ,_none_
    ),
};
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_VIA1] = { ENCODER_CCW_CW(KC_NO, KC_NO),     ENCODER_CCW_CW(KC_NO, KC_NO) },
    [_VIA2] = { ENCODER_CCW_CW(KC_NO, KC_NO),     ENCODER_CCW_CW(KC_NO, KC_NO) }
};
#endif
// clang-format on

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  oled_clear();

  if (!is_keyboard_master()) {
    typehud_init();
  }

  if (is_keyboard_left()) {
    return OLED_ROTATION_0;
  } else {
    return OLED_ROTATION_180;
  }
}

bool oled_task_user(void) {
  simple_oled_status_task();
  if (is_keyboard_master()) {
    simple_oled_status_render();
  } else {
    typehud_render();
    // bongo_render(0, 0);
  }
  return true;
}

#define CC_LCTL_KEYCODE(keydown, keycode)                                      \
  if (keydown)                                                                 \
    SEND_STRING_DELAY(SS_DOWN(X_LCTL) SS_DOWN(keycode), 10);                   \
  else                                                                         \
    SEND_STRING_DELAY(SS_UP(keycode) SS_UP(X_LCTL), 10);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  typehud_process_record(record);
  // bongo_process_record(record);

  bool keydown = record->event.pressed;
  switch ((enum CookytKeycodes)keycode) {
  case CC_NEWLINE:
    if (keydown)
      SEND_STRING_DELAY(SS_TAP(X_END) SS_LSFT("\n"), 10);
    break;

  case CC_TAB:
    if (keydown)
      SEND_STRING_DELAY("  ", 10);
    break;

  case CC_WORD_LEFT:
    CC_LCTL_KEYCODE(keydown, X_LEFT);
    break;

  case CC_WORD_RIGHT:
    CC_LCTL_KEYCODE(keydown, X_RIGHT);
    break;

  case CC_CHROME_TAB_LEFT:
    CC_LCTL_KEYCODE(keydown, X_PAGE_UP);
    break;

  case CC_CHROME_TAB_RIGHT:
    CC_LCTL_KEYCODE(keydown, X_PAGE_DOWN);
    break;
  }

  return true;
}

bool should_process_keypress(void) { return true; }

#include "rgblight_layers.inc"

void keyboard_post_init_user(void) {
  keyboard_post_init_RGBLIGHT_LAYERS();

  // Customise these values to desired behaviour
  // debug_enable = true;
  // debug_matrix=true;
  // debug_keyboard=true;
  // debug_mouse=true;
}

bool led_update_user(led_t led_state) {
  return led_update_RGBLIGHT_LAYERS(led_state);
}
layer_state_t default_layer_state_set_user(layer_state_t state) {
  return default_layer_state_set_RGBLIGHT_LAYERS(state);
}
layer_state_t layer_state_set_user(layer_state_t state) {
  return layer_state_set_RGBLIGHT_LAYERS(state);
}

#include "combos.inc"
