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
#define _DISCORD 1
#define _RGB 2
#define _LAYERS 3
#define _APPS 4
#define _LRPICK 5




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_MEDIA] = LAYOUT(
             KC_MPLY,
    LSA_T(KC_MPRV),    MO(_LAYERS),    KC_MNXT,
    LT(_RGB, KC_MUTE),    MO(_APPS),    KC_SYSTEM_POWER
  ),
  [_DISCORD] = LAYOUT(
             KC_F18,
    KC_F19, KC_F17,   LCTL(KC_F17),
    LCTL(KC_LEFT_BRACKET), TG(_DISCORD), LCTL(KC_RIGHT_BRACKET)
  ),
  [_RGB] = LAYOUT(
             RGB_TOG,
    LALT(KC_LSFT), KC_LSFT,   RGB_SAI,
    RGB_VAI, TG(_RGB), RGB_HUI
  ),
  [_LAYERS] = LAYOUT(
             TG(_RGB),
    TG(_DISCORD), _______,   _______,
    TG(_LRPICK), _______, QK_BOOT
  ),
  [_APPS] = LAYOUT(
             LCTL(KC_F18),
    LCTL(KC_F16), LCTL(KC_F15),   LCTL(KC_F14),
    LCTL(KC_F17), TG(_APPS), LCTL(KC_F19)
  ),
  [_LRPICK] = LAYOUT(
             KC_U,
    KC_E, KC_G,   KC_C,
    KC_X, TG(_LRPICK), KC_P
  ),
};

// Volume up/down on the encoder
bool encoder_update_user(uint8_t index, bool clockwise) {
  uint8_t current_layer = get_highest_layer(layer_state);
  if (current_layer == _RGB) {
    if (clockwise) {
      tap_code_delay(KC_BRIU, 10);
    } else {
      tap_code_delay(KC_BRID, 10);
    }
  } else if (current_layer == _LRPICK) {
    if (clockwise) {
      tap_code_delay(KC_RIGHT, 20);
    } else {
      tap_code_delay(KC_LEFT, 20);
    }
  } else {
    if (clockwise) {
      tap_code_delay(KC_VOLU, 10);
    } else {
      tap_code_delay(KC_VOLD, 10);
    }
  } return false;
}