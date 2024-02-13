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
