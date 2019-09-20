#include QMK_KEYBOARD_H
#include "msiu.h"

// Layer shorthand

enum xd75_layers {
  _QWERTY,
  _DVORAK,
  _LOWER,
  _RAISE,
  _NUMB,
  _FUNC,
  _ADJUST
};

#define _QW 0
#define _DV 1
#define _LW 2
#define _RS 3
#define _FN 4
#define _PW 5

enum xd75_keycodes {
  QWERTY = NEW_SAFE_RANGE,
  DVORAK,
};

// Shortcuts
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define PSC_DKT SCMD(KC_4)
#define PSC_CLB C(S(G(KC_4)))
#define OSM_SFT OSM(MOD_LSFT)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | `      | 1      | 2      | 3      | 4      | 5      | -      | =      | \      | 6      | 7      | 8      | 9      | 0      | DEL    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | TAB    | Q      | W      | E      | R      | T      | 7      | 8      | 9      | Y      | U      | I      | O      | P      | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | CTLESC | A      | S      | D      | F      | G      | 4      | 5      | 6      | H      | J      | K      | L      | ;      | '      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | LSHIFT | Z      | X      | C      | V      | B      | 1      | 2      | 3      | N      | M      | ,      | .      | /      | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------+--------|
 * | CTLSF  | HYPER  | LALT   | LGUI   | LOWER  | FN     | 0      | PW     | .      | SPACE  | RAISE  | LEFT   | DOWN   | UP     | RIGHT  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_QWERTY] = { /* QWERTY */
  { KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_PLUS, KC_MINS, KC_ASTR, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL   },
  { KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_7,    KC_8,    KC_9   , KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC  },
  { CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_4,    KC_5,    KC_6   , KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT  },
  { OSM_SFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_1,    KC_2,    KC_3   , KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT   },
  { CTL_SFT, KC_HYPR, KC_LALT, KC_LGUI, MO(_LW), SPC_FNC, KC_0,    MO(_PW), KC_DOT , KC_SPC,  MO(_RS), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  },
 },

 /* Dvorak */

  [_DVORAK] = { /* Dvorak */
   { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
   { _______, KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    _______, _______, _______, KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    _______  },
   { _______, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    _______, _______, _______, KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH  },
   { _______, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    _______, _______, _______, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    _______  },
   { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
  },


/* LOWERED
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        | F1     | F2     | F3     | F4     | F5     |        |        |        | F6     | F7     | F8     | F9     | F10    | DEL    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | ~      | !      | @      | #      | $      | %      |        | VOLU   |        | ^      | &      | *      | (      | )      | DEL    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | F1     | F2     | F3     | F4     | F5     | PREV   | PLAY   | NEXT   | F6     | _      | +      | {      | }      | |      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        | F7     | F8     | F9     | F10    | F11    |        | VOLD   |        | F12    | PAGEDW | PAGEUP | HOME   | END    | MUTE   |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        |        |        | MUTE   |        | PLAY   |        | PREV   | VOLD   | VOLU   | NEXT   |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_LOWER] = { /* LOWERED */
  { _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, _______, _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______   },
  { KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, KC_VOLU, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______   },
  { _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_MPRV, KC_MPLY, KC_MNXT, KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE   },
  { _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______, KC_VOLD, _______, KC_F12,  KC_PGDN, KC_PGUP, KC_HOME, KC_END , KC_MUTE   },
  { _______, _______, _______, _______, _______, _______, _______, KC_MUTE, _______, KC_MPLY, _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT   },
 },

/* RAISED
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        | F1     | F2     | F3     | F4     | F5     |        |        |        | F6     | F7     | F8     | F9     | F10    | DEL    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | `      | 1      | 2      | 3      | 4      | 5      |        | VOLU   |        | 6      | 7      | 8      | 9      | 0      |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | F1     | F2     | F3     | F4     | F5     | PREV   | PLAY   | NEXT   | F6     | -      | =      | [      | ]      | \      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | F7     | F8     | F9     | F10    | F11    |        | VOLD   |        | F12    | PAGEUP | PAGEDW | HOME   | END    | MUTE   |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        | MUTE   |        | PLAY   |        | PREV   | VOLD   | VOLU   | NEXT   |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_RAISE] = { /* RAISED */
  { _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, _______, _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL    },
  { KC_GRV , KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, KC_VOLU, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL    },
  { _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_MPRV, KC_MPLY, KC_MNXT, KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS   },
  { _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______, KC_VOLD, _______, KC_F12,  KC_PGDN, KC_PGUP, KC_HOME, KC_END , KC_MUTE   },
  { _______, _______, _______, _______, _______, _______, _______, KC_MUTE, _______, KC_MPLY, _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT   },
 },

/* FUNCTION */

 [_FUNC] = { /* FUNCTION */
  { RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, BL_TOGG, BL_INC,  BL_DEC,  _______, _______, _______, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UP  , _______, KC_PSCR, _______  },
  { _______, _______, PSC_DKT, TO(_DV), TO(_QW), _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______  },
  { _______, _______, PSC_CLB, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
 },
 
/* PASSWORD */

 [_PW] = { /* FUNCTION */
  { _______, _______, _______, _______, _______, _______, _______, RESET,   _______, _______, _______, _______, _______, _______, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, P_WORK,  P_VIMA,  _______, _______, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
 },
};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
  }
  return true;
}
