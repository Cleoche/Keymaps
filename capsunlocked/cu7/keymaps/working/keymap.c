/*
Copyright 2021 CapsUnlocked

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H
#include "midi.h"

extern MidiDevice midi_device;

#define _MEDIA 0
#define _DISCORD 1
#define _DEV 2
#define _LAYERS 3
#define _LR1 4

enum midi_cc_keycodes_LTRM {MIDI_CC1 = SAFE_RANGE, MIDI_SENDU, MIDI_SENDD, MIDI_NEXT, MIDI_PREV, MIDI_SNXT, MIDI_SPRV, MIDI_ANULL, MIDI_HIDE};
static uint8_t current_MIDI_ccNumber = 1;
static uint8_t lbound = 1;
static uint8_t ubound = 13;
static uint8_t bounds[3][2] = {{1, 13}, {14, 17}, {18, 25}};
static uint8_t section = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MIDI_CC1:
      if (record->event.pressed) {
        current_MIDI_ccNumber = 1;
      } else {}
      return false;
      break;
    case MIDI_SENDU:
      if (record->event.pressed) {
        midi_send_cc(&midi_device, 0, 2 * current_MIDI_ccNumber, 1);
      } else {}
      return false;
      break;
    case MIDI_SENDD:
      if (record->event.pressed) {
        midi_send_cc(&midi_device, 0, 2 * current_MIDI_ccNumber, 127);
      } else {}
      return false;
      break;
    default:
      break;
    case MIDI_NEXT:
      if (record->event.pressed) {
        if (current_MIDI_ccNumber < ubound) {
          current_MIDI_ccNumber ++;
        } else {
          current_MIDI_ccNumber = lbound;
        }
      } else {}
      return false;
      break;
    case MIDI_PREV:
      if (record->event.pressed) {
        if (current_MIDI_ccNumber > lbound) {
        current_MIDI_ccNumber --;
        } else {
          current_MIDI_ccNumber = ubound;
        }
      } else {}
      return false;
      break;
    case MIDI_SNXT:
      if (record->event.pressed) {
        if (section < 2) {
          section ++;
        } else {
          section = 0;
        }
        lbound = bounds[section][0];
        ubound = bounds[section][1];
        current_MIDI_ccNumber = lbound;
        midi_send_cc(&midi_device, 0, 2* section + 109, 1);
      } else {}
      return false;
      break;
    case MIDI_SPRV:
      if (record->event.pressed){
        if (section > 0) {
          section --;
        } else {
          section = 2;
        }
        lbound = bounds[section][0];
        ubound = bounds[section][1];
        current_MIDI_ccNumber = lbound;
        midi_send_cc(&midi_device, 0, 2* section + 109, 1);
      } else {}
      return false;
      break;
    case MIDI_ANULL:
      if (record->event.pressed) {
        midi_send_cc(&midi_device, 0, 2 * current_MIDI_ccNumber - 1, 1);
      } else {}
      return false;
      break;
    case MIDI_HIDE:
      if (record->event.pressed) {
        midi_send_cc(&midi_device, 0, 2* section + 110, 1);
      } else {}
      return false;
      break;
  }
  return true;
}



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_MEDIA] = LAYOUT(
             KC_MPLY,
    LSA_T(KC_MPRV),    TG(_LAYERS),    LT(_DISCORD, KC_MNXT),
    LT(_DEV, KC_MUTE),    XXXXXXX,    KC_SYSTEM_POWER
  ),
  [_DISCORD] = LAYOUT(
             LCTL(KC_F17),
    LT(_LAYERS, KC_F18),    KC_F19,    KC_F17,
    LT(_DEV, KC_MPRV),    TO(_MEDIA),    KC_MNXT
  ),
  [_DEV] = LAYOUT(
             QK_BOOT,
    _______,    RGB_TOG,    _______,
    _______,    TO(_MEDIA),    _______
  ),
  [_LAYERS] = LAYOUT(
             TO(_DEV),
    TO(_DISCORD),    _______,    _______,
    TO(_LR1),    TO(_MEDIA),    _______
  ),
  [_LR1] = LAYOUT(
             MIDI_ANULL,
    MIDI_PREV,    MIDI_HIDE,    MIDI_NEXT,
    MIDI_SPRV,    TO(_MEDIA),    MIDI_SNXT
  )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [_MEDIA] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
  [_DISCORD] = { ENCODER_CCW_CW(LCTL(KC_LBRC), LCTL(KC_RBRC)) },
  [_DEV] = { ENCODER_CCW_CW(KC_BRID, KC_BRIU) },
  [_LAYERS] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
  [_LR1] = { ENCODER_CCW_CW(MIDI_SENDD, MIDI_SENDU) },
};

#endif