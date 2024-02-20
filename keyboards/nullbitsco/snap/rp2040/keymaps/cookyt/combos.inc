// Combo configuration per: https://docs.qmk.fm/#/feature_combo

#include "process_combo.h"
#include "constants.h"
#include "progmem.h"

// clang-format off
const uint16_t PROGMEM kNum_1[] = {LT1_ENT,   KC_J,   /*KC_K,*/ /*KC_L,*/ /*KC_SCLN,*/ COMBO_END};
const uint16_t PROGMEM kNum_2[] = {LT1_ENT, /*KC_J,*/   KC_K,   /*KC_L,*/ /*KC_SCLN,*/ COMBO_END};
const uint16_t PROGMEM kNum_3[] = {LT1_ENT,   KC_J,     KC_K,   /*KC_L,*/ /*KC_SCLN,*/ COMBO_END};
const uint16_t PROGMEM kNum_4[] = {LT1_ENT, /*KC_J,*/ /*KC_K,*/   KC_L,   /*KC_SCLN,*/ COMBO_END};
const uint16_t PROGMEM kNum_5[] = {LT1_ENT,   KC_J,   /*KC_K,*/   KC_L,   /*KC_SCLN,*/ COMBO_END};
const uint16_t PROGMEM kNum_6[] = {LT1_ENT, /*KC_J,*/   KC_K,     KC_L,   /*KC_SCLN,*/ COMBO_END};
const uint16_t PROGMEM kNum_7[] = {LT1_ENT,   KC_J,     KC_K,     KC_L,   /*KC_SCLN,*/ COMBO_END};
const uint16_t PROGMEM kNum_8[] = {LT1_ENT, /*KC_J,*/ /*KC_K,*/ /*KC_L,*/   KC_SCLN,   COMBO_END};
const uint16_t PROGMEM kNum_9[] = {LT1_ENT,   KC_J,   /*KC_K,*/ /*KC_L,*/   KC_SCLN,   COMBO_END};
const uint16_t PROGMEM kNum_0[] = {LT1_ENT,   KC_J,     KC_K,     KC_L,     KC_SCLN,   COMBO_END};

#if 0
const uint16_t PROGMEM kSym_1[] = {LT1_ENT,   KC_U,   /*KC_I,*/ /*KC_O,*/ /*KC_P,*/ COMBO_END};
const uint16_t PROGMEM kSym_2[] = {LT1_ENT, /*KC_U,*/   KC_I,   /*KC_O,*/ /*KC_P,*/ COMBO_END};
const uint16_t PROGMEM kSym_3[] = {LT1_ENT,   KC_U,     KC_I,   /*KC_O,*/ /*KC_P,*/ COMBO_END};
const uint16_t PROGMEM kSym_4[] = {LT1_ENT, /*KC_U,*/ /*KC_I,*/   KC_O,   /*KC_P,*/ COMBO_END};
const uint16_t PROGMEM kSym_5[] = {LT1_ENT,   KC_U,   /*KC_I,*/   KC_O,   /*KC_P,*/ COMBO_END};
const uint16_t PROGMEM kSym_6[] = {LT1_ENT, /*KC_U,*/   KC_I,     KC_O,   /*KC_P,*/ COMBO_END};
const uint16_t PROGMEM kSym_7[] = {LT1_ENT,   KC_U,     KC_I,     KC_O,   /*KC_P,*/ COMBO_END};
const uint16_t PROGMEM kSym_8[] = {LT1_ENT, /*KC_U,*/ /*KC_I,*/ /*KC_O,*/   KC_P,   COMBO_END};
const uint16_t PROGMEM kSym_9[] = {LT1_ENT,   KC_U,   /*KC_I,*/ /*KC_O,*/   KC_P,   COMBO_END};
const uint16_t PROGMEM kSym_0[] = {LT1_ENT,   KC_U,     KC_I,     KC_O,     KC_P,   COMBO_END};
#endif  // 0

// clang-format on

combo_t key_combos[] = {
    COMBO(kNum_0, KC_0),
    COMBO(kNum_1, KC_1),
    COMBO(kNum_2, KC_2),
    COMBO(kNum_3, KC_3),
    COMBO(kNum_4, KC_4),
    COMBO(kNum_5, KC_5),
    COMBO(kNum_6, KC_6),
    COMBO(kNum_7, KC_7),
    COMBO(kNum_8, KC_8),
    COMBO(kNum_9, KC_9),

    // COMBO(kSym_0, LCTL(KC_0)),
    // COMBO(kSym_1, LCTL(KC_1)),
    // COMBO(kSym_2, LCTL(KC_2)),
    // COMBO(kSym_3, LCTL(KC_3)),
    // COMBO(kSym_4, LCTL(KC_4)),
    // COMBO(kSym_5, LCTL(KC_5)),
    // COMBO(kSym_6, LCTL(KC_6)),
    // COMBO(kSym_7, LCTL(KC_7)),
    // COMBO(kSym_8, LCTL(KC_8)),
    // COMBO(kSym_9, LCTL(KC_9)),
};
