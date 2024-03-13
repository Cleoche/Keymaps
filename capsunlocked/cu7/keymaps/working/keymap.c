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
#define _LAYERS 2
#define _DISCORD 3
#define _LRFLAG 4
#define _LRRATE 5





const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_MEDIA] = LAYOUT(
             KC_MPLY,
    LSA_T(KC_MPRV),    TG(_LAYERS),    KC_MNXT,
    LT(_DEV, KC_MUTE),    XXXXXXX,    KC_SYSTEM_POWER
  ),
  [_DEV] = LAYOUT(
             QK_BOOT,
    _______,    RGB_TOG,    _______,
    _______,    TO(_MEDIA),    _______
  ),
  [_LAYERS] = LAYOUT(
             QK_BOOT,
    TG(_DISCORD),    _______,    _______,
    TG(_LRFLAG),    TO(_MEDIA),    _______
  ),
  [_DISCORD] = LAYOUT(
             LCTL(KC_F17),
    KC_F18,    KC_F19,    KC_F17,
    LCTL(KC_LBRC),    TO(_MEDIA),    LCTL(KC_RBRC)
  ),
  [_LRFLAG] = LAYOUT(
             XXXXXXX,
    KC_X,    KC_U,    KC_P,
    MO(_LRRATE),    TO(_MEDIA),    XXXXXXX
  ),
  [_LRRATE] = LAYOUT(
             KC_0,
    KC_1,    KC_2,    KC_3,
    RGB_SAI,    KC_4,    KC_5
  )
};

// Volume up/down on the encoder
bool encoder_update_user(uint8_t index, bool clockwise) {
  uint8_t current_layer = get_highest_layer(layer_state);
  if (current_layer == _DEV) {
    if (clockwise) {
      tap_code_delay(KC_BRIU, 10);
    } else {
      tap_code_delay(KC_BRID, 10);
    }
  } else if (current_layer == _LRFLAG) {
    if (clockwise) {
      tap_code_delay(KC_RGHT, 20);
    } else {
      tap_code_delay(KC_LEFT, 20);
    }
  } else {
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
  } return false;
}