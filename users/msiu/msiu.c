#include "msiu.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case P_WORK:
      if (record->event.pressed) {
        SEND_STRING("");
      } else {
      }
      break;
    case P_VIMA:
      if (record->event.pressed) {
        SEND_STRING("");
      } else {
      }
      break;
  }
  return true;
}
