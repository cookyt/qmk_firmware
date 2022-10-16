/* Copyright 2020 Purdea Andrei
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT_all(
        KC_ESC,      KC_F14,KC_F15,LCTL(KC_UP),KC_F9,  KC_F5, KC_F6,KC_MPRV,KC_MPLY,  KC_MNXT,KC_MUTE,KC_VOLD,KC_VOLU,  KC_F13,  KC_F14,  KC_F15,
        KC_NUBS,KC_1,  KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,  KC_9,  KC_0,  KC_MINS, KC_EQL,KC_BSPC,KC_BSPC,  KC_EJCT, KC_HOME, KC_PGUP,  KC_NUM,  KC_PEQL, KC_PSLS, KC_PAST,
        KC_TAB,    KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,  KC_O,  KC_P,  KC_LBRC, KC_RBRC,    KC_BSLS,  KC_DEL,  KC_END,  KC_PGDN,  KC_P7,   KC_P8,   KC_P9,   KC_PMNS,
        KC_CAPS,      KC_A,  KC_S,  KC_D,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,  KC_L,  KC_SCLN, KC_QUOT,KC_NUHS, KC_ENT,                              KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        KC_LSFT,KC_GRV,  KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,  KC_N,  KC_M,  KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,  KC_RSFT,           KC_UP,             KC_P1,   KC_P2,   KC_P3,   KC_PENT,
        KC_LCTL, KC_LALT, KC_LGUI, KC_NO,       KC_SPC,                      KC_RGUI, KC_RALT, MO(_FN),      KC_RCTL,  KC_LEFT, KC_DOWN, KC_RGHT,  KC_P0,   KC_P0,   KC_PDOT, KC_PENT
    ),
    [_FN] = LAYOUT_all(
        KC_ESC,        KC_F1, KC_F2, KC_F3, KC_F4,     KC_F5, KC_F6, KC_F7, KC_F8,      KC_F9, KC_F10, KC_F11, KC_F12,  KC_PSCR, KC_SCRL, KC_PAUS,
        KC_NUBS,KC_1,  KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,  KC_9,  KC_0,  KC_MINS, KC_EQL,KC_BSPC,KC_BSPC,  KC_INS,  KC_HOME, KC_PGUP,  KC_NUM,  KC_EQL,  KC_PSLS, KC_PAST,
        KC_TAB,    KC_Q,  KC_W,EEPROM_RESET,QK_BOOT,KC_T,KC_Y, KC_U,  KC_I,  KC_O,  KC_P,  KC_LBRC, KC_RBRC,    KC_BSLS,  KC_DEL,  KC_END,  KC_PGDN,  KC_P7,   KC_P8,   KC_P9,   KC_PMNS,
        KC_CAPS,      KC_A,  KC_S,DEBUG,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,  KC_L,  KC_SCLN, KC_QUOT,KC_NUHS, KC_ENT,                              KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        KC_LSFT,KC_GRV,  KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,  KC_N,  KC_M,  KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,  KC_RSFT,           KC_UP,             KC_P1,   KC_P2,   KC_P3,   KC_PENT,
        KC_LCTL, KC_LALT, KC_LGUI, KC_NO,       KC_SPC,                      KC_RGUI, KC_RALT, MO(_FN),      KC_RCTL,  KC_LEFT, KC_DOWN, KC_RGHT,  KC_P0,   KC_P0,   KC_PDOT, KC_PENT
    )
};