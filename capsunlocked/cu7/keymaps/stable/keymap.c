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
#define _DEV 2
#define _LAYERS 3
#define _LRFLAG 4
#define _LRRATE 5





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
    TO(_LRFLAG),    TO(_MEDIA),    _______
  ),
  [_LRFLAG] = LAYOUT(
             XXXXXXX,
    KC_X,    KC_U,    KC_P,
    MO(_LRRATE),    TO(_MEDIA),    XXXXXXX
  ),
  [_LRRATE] = LAYOUT(
             KC_0,
    KC_1,    KC_2,    KC_3,
    _______,    KC_4,    KC_5
  )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [_MEDIA] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
  [_DISCORD] = { ENCODER_CCW_CW(LCTL(KC_LBRC), LCTL(KC_RBRC)) },
  [_DEV] = { ENCODER_CCW_CW(KC_BRID, KC_BRIU) },
  [_LAYERS] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
  [_LRFLAG] = { ENCODER_CCW_CW(KC_LEFT, KC_RIGHT) },
  [_LRRATE] = { ENCODER_CCW_CW(_______, _______) },
};
#endif