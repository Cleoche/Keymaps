/*
Copyright 2020 Álvaro "Gondolindrim" Volpato <alvaro.volpato@usp.br>

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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [0] = LAYOUT_all(
        KC_TILDE			 , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_KP_9, KC_KP_0 , KC_MINUS  , XXXXXXX, XXXXXXX, KC_F14 , KC_F13, // Headphone connect, Do Not Disturb
        KC_TAB  			 , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P    , KC_LBRC , KC_RBRC		  , KC_BSLS, KC_F15, // Safari
        KC_BSPC              , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN , KC_QUOT , KC_NO, KC_ENT ,     	 KC_F16, // Obsidian
		SC_LSPO, KC_NO  , KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT  , KC_SLSH , SC_RSPC, KC_UP  , KC_ESC,
        CTL_T(KC_MINUS)  , KC_LALT, CMD_T(KC_RIGHT),                            KC_SPC ,                   CMD_T(KC_EQUAL), MO(1)   ,        KC_LEFT, KC_DOWN, KC_RGHT 
	),
   [1] = LAYOUT_all(
    QK_BOOT  , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
	KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_VOLU, _______,
	_______, _______, _______,                            KC_MPLY,                            _______, _______,          KC_MPRV, KC_VOLD, KC_MNXT
	)
};