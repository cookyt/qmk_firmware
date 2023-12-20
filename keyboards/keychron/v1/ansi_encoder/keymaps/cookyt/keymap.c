/* Copyright 2021 @ Keychron (https://www.keychron.com)
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

#include "action_layer.h"
#include QMK_KEYBOARD_H

#include "action.h"
#include "encoder.h"
#include "send_string.h"
#include "quantum_keycodes.h"

enum layers{
    TYPING_BASE,
    TYPING_FN,
    PLAIN_BASE,
    PLAIN_FN
};

enum cookyt_custom_keycodes {
    CC_SSPC = SAFE_RANGE,  // Send 2 Spaces
    CC_CLFT,               // Ctrl+Left
    CC_CRGT,               // Ctrl+Right
    CC_NL,                 // Newline
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

#define LT1_SPC LT(TYPING_FN, KC_SPC)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Below macros should only fire on keydown, not keyup.
    if (!record->event.pressed) return true;

    switch (keycode) {
        case CC_SSPC: {
            SEND_STRING("  ");
            break;
        }
        case CC_CLFT: {
            SEND_STRING(SS_LCTL(SS_TAP(X_LEFT)));
            break;
        }
        case CC_CRGT: {
            SEND_STRING(SS_LCTL(SS_TAP(X_RIGHT)));
            break;
        }
        case CC_NL: {
            SEND_STRING(SS_TAP(X_END) SS_TAP(X_ENTER));
            break;
        }
    }
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    if (state == 1UL << TYPING_BASE) {
        rgb_matrix_sethsv_noeeprom(COOKYT_DEFAULT_HSV);
    } else if (state == 1UL << PLAIN_BASE) {
        rgb_matrix_sethsv_noeeprom(COOKYT_ALTERNATE_HSV);
    }
    return state;
}

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // The "Mac" keycodes are a plain-jane copy of Windows. I don't use Macs,
    // and it's nice to be able to disable the fancy stuff when playing a game.
    [TYPING_BASE] = LAYOUT_ansi_82(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_HOME,            KC_PAUS,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,  KC_BSLS,            KC_PGDN,
        KC_LCTL,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,             KC_END,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,
        KC_LCTL,  KC_LCMD,  KC_LALT,                                LT1_SPC,                                 KC_RALT,  MO(TYPING_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [TYPING_FN] = LAYOUT_ansi_82(
        _______,  QK_BOOT,  _______,  _______,  KC_END,   _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_HOME,  _______,    _______,  KC_DEL,             DT_UP,
        CC_SSPC,  KC_D,     CC_CRGT,  KC_WH_D,  _______,  _______,  KC_WH_U,  KC_PGUP,  KC_HOME,  CC_NL,    _______,  _______,    _______,  _______,            DT_DOWN,
        _______,  KC_END,   _______,  KC_PGDN,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  _______,  _______,              _______,            DT_PRNT,
        _______,            _______,  _______,  _______,  _______,  CC_CLFT,  _______,  _______,  _______,  _______,  _______,              _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,    _______,  KC_MPRV,  KC_MPLY,  KC_MNXT),

    [PLAIN_BASE] = LAYOUT_ansi_82(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_HOME,            KC_PAUS,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,  KC_BSLS,            KC_PGDN,
        KC_LCTL,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,             KC_END,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,
        KC_LCTL,  KC_LCMD,  KC_LALT,                                KC_SPC,                                 KC_RALT,  MO(PLAIN_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [PLAIN_FN] = LAYOUT_ansi_82(
        _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        KC_CAPS,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,            _______,
        _______,            _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,    _______,  _______,  _______,  _______),
};

// clang-format on

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [TYPING_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [TYPING_FN]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [PLAIN_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [PLAIN_FN]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)}
};
#endif // ENCODER_MAP_ENABLE
