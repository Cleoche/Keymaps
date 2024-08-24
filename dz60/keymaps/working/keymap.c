#include QMK_KEYBOARD_H

enum safe {DC_MUTE = SAFE_RANGE, DC_DEAF, SYS_DND};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch(keycode) {
		case DC_MUTE:
			tap_code(KC_F18);
			return false;
			break;
		case DC_DEAF:
			tap_code(KC_F19);
			return false;
			break;
		case SYS_DND:
			tap_code(KC_F13);
			return false;
			break;
	}
	return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	LAYOUT_60_ansi(
		QK_BOOT, XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, XXXXXXX,           XXXXXXX,
		XXXXXXX,           XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    DC_MUTE, DC_DEAF,    XXXXXXX, XXXXXXX, XXXXXXX,
		XXXXXXX,          XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    SYS_DND, XXXXXXX, XXXXXXX,
		XXXXXXX,          XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, XXXXXXX,  XXXXXXX,          XXXXXXX,
		XXXXXXX, XXXXXXX,          XXXXXXX,                   XXXXXXX,                             XXXXXXX, XXXXXXX,          XXXXXXX,   XXXXXXX)
};
