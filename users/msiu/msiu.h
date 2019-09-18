#pragma once

#include "quantum.h"

enum custom_keycodes {
  P_WORK = SAFE_RANGE,
  P_VIMA,
  NEW_SAFE_RANGE  //use "NEW_SAFE_RANGE" for keymap specific codes
};

// Commonly used combo
#define CTL_ESC LCTL_T(KC_ESC)
#define SPC_FNC LT(_FUNC, KC_SPC)
#define TAB_NUM LT(_NUMB, KC_TAB)
#define CTL_SFT MT(MOD_LCTL | MOD_LSFT, _______)
