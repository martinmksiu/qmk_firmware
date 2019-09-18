#include QMK_KEYBOARD_H
#include "msiu.h"

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _NUMB,
  _FUNC,
  _ADJUST
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT(
  TAB_NUM, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  CTL_SFT, KC_HYPR, KC_LALT, KC_LGUI, LOWER,      SPC_FNC,       RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),


[_LOWER] = LAYOUT(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PGDN, KC_PGUP, KC_HOME, KC_END , KC_MUTE,
  _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______
),


[_RAISE] = LAYOUT(
  KC_GRV,  KC_1,    KC_2,    KC_3,   KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  _______, KC_4,    KC_5,    KC_6,   KC_PLUS, KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
  _______, KC_7,    KC_8,    KC_9,   KC_MINS, KC_F11,  KC_F12,  KC_PGDN, KC_PGUP, KC_HOME, KC_END , KC_MUTE,
  _______, _______, _______, _______, _______,     _______,     _______, _______, _______, _______, _______
),


[_ADJUST] = LAYOUT(
  _______, RGB_TOG, RGB_MOD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, P_WORK,  P_VIMA,  _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, RESET
),

[_FUNC] = LAYOUT(
  _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______, KC_PSCR, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______
),

[_NUMB] = LAYOUT(
  _______, _______, _______, _______, _______, _______, _______, KC_7,    KC_8,    KC_9,    _______, KC_BSPC,
  _______, _______, _______, _______, _______, _______, _______, KC_4,    KC_5,    KC_6,    _______, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_1,    KC_2,    KC_3,    _______, _______,
  _______, _______, _______, _______, _______,     _______,      KC_0,    _______, _______, _______, _______
),
};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

