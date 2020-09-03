#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _NUMB,
    _DEBUG,
};

#define TG_NUM TG(_NUMB)
#define SEVDEB LT(_DEBUG, KC_7)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_ortho_4x4(
        SEVDEB,  KC_8,    KC_9,    KC_BSPC,
        KC_4,    KC_5,    KC_6,    TG_NUM,
        KC_1,    KC_2,    KC_3,    KC_ENT,
        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),
    [_NUMB] = LAYOUT_ortho_4x4(
        _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______,
        KC_0,    _______, _______, _______
    ),
    [_DEBUG] = LAYOUT_ortho_4x4(
        _______, _______, _______, RESET,
        RGB_TOG,  RGB_HUI,  RGB_SAI,  RGB_VAI,
        RGB_MOD,  RGB_HUD,  RGB_SAD,  RGB_VAD,
        BL_STEP,  _______,  _______,  _______
    )
};

