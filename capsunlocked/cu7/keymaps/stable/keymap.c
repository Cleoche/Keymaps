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
#define _MEDIA 0
#define _DEV 1





const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_MEDIA] = LAYOUT(
             KC_MPLY,
    LSA_T(KC_MPRV),    MO(_DEV),    KC_MNXT,
    KC_MUTE,    XXXXXXX,    KC_SYSTEM_POWER
  ),
  [_DEV] = LAYOUT(
             QK_BOOT,
    RGB_HUI,    _______,    RGB_HUD,
    RGB_SAI,    TO(_MEDIA),    RGB_SAD
  ) 
};

// Volume up/down on the encoder
bool encoder_update_user(uint8_t index, bool clockwise) {
  uint8_t current_layer = get_highest_layer(layer_state);
  if (current_layer == _DEV) {
    if (clockwise) {
      tap_code_delay(KC_PAUSE, 10);
    } else {
      tap_code_delay(KC_SCROLL_LOCK, 10);
    }
  } else {
    if (clockwise) {
      tap_code(KC_KB_VOLUME_UP);
    } else {
      tap_code(KC_KB_VOLUME_DOWN);
    }
  } return false;
}