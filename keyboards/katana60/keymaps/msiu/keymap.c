#include QMK_KEYBOARD_H
#include "msiu.h"

// Mod-Tap keys for cleaner code
#define SPC_LW LT(2, KC_SPC)
#define OSM_SFT OSM(MOD_LSFT)

enum katana_layers {
  _QWERTY,
  _DVORAK,
  _LOWER,
  _RAISE,
  _FUNC,
  _NUMB,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT( /* Base */
  KC_ESC,  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    TT(1),   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_PLUS,
  TAB_NUM, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_PGDN,          KC_PGUP, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_UP,            KC_UP,   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  OSM_SFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LEFT, KC_DOWN, KC_RGHT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  CTL_SFT, KC_HYPR, KC_LALT, KC_LGUI,                   SPC_LW,  MO(4),   KC_SPC,           MO(3),   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT
    ),
[_DVORAK] = LAYOUT(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    _______,          _______, KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    _______,
  _______, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    _______,          _______, KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH,
  _______, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    _______, _______, _______, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    _______,
  _______, _______, _______, _______,                   _______, _______, _______,          _______, _______, _______, _______, _______
    ),
[_LOWER] = LAYOUT(
  _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,          _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,            _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_HOME,  KC_DEL, KC_END,  _______, KC_PGDN, KC_PGUP, KC_HOME, KC_END , KC_MUTE,
  _______, _______, _______, _______,                   _______, _______, _______,          _______, _______, _______, _______, _______
    ),
[_RAISE] = LAYOUT(
  _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,          _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,            _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_HOME,  KC_DEL, KC_END,  _______, KC_PGDN, KC_PGUP, KC_HOME, KC_END , KC_MUTE,
  _______, _______, _______, _______,                   _______, _______, _______,          _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT
    ),
[_FUNC] = LAYOUT(
  _______, _______, _______, _______, _______, _______, _______, RESET,   _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, KC_UP,   _______, KC_PSCR, _______,
  _______, _______, _______, _______, _______, _______, P_WORK,           P_VIMA,  _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
  _______, _______, _______, _______, _______, _______, KC_HOME,  KC_DEL, KC_END,  _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______,                   _______, _______, _______,          _______, _______, _______, _______, _______
    ),
[_NUMB] = LAYOUT(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,          _______, _______, KC_7,    KC_8,    KC_9,    _______, _______,
  _______, _______, _______, _______, _______, _______, _______,          _______, _______, KC_4,    KC_5,    KC_6,    _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_1,    KC_2,    KC_3,    _______, _______,
  _______, _______, _______, _______,                   _______, _______, KC_0,             _______, _______, _______, _______, _______
    )
};


void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
