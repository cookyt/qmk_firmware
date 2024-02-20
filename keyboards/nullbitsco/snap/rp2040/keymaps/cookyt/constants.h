#pragma once

#include QMK_KEYBOARD_H

enum layers { _BASE, _VIA1, _VIA2 };

enum CookytKeycodes {
    CC_NEWLINE = SAFE_RANGE,
    CC_NL      = CC_NEWLINE,

    CC_TAB,

    CC_WORD_RIGHT,
    CC_WRDR = CC_WORD_RIGHT,

    CC_WORD_LEFT,
    CC_WRDL = CC_WORD_LEFT,

    CC_CHROME_TAB_LEFT,
    CC_TABL = CC_CHROME_TAB_LEFT,

    CC_CHROME_TAB_RIGHT,
    CC_TABR = CC_CHROME_TAB_RIGHT,
};

#define LT1_SPC LT(_VIA1, KC_SPC)
#define LT1_ENT LT(_VIA1, KC_ENT)
#define MO1 MO(_VIA2)
#define CT_QUOT LCTL_T(KC_QUOT)
#define _none_ KC_NO

#define QK_CLR QK_CLEAR_EEPROM
