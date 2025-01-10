/* Copyright 2020 Simone Messaggi
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};

//TAP dance declarations
enum {
    TD_OGRAVE, //0x0F2
    TD_AGRAVE, //0x0E0
    TD_UGRAVE, //0x0F9
    TD_EGRAVE, //0x0E8
    TD_EACUTE, //0x0E9
    TD_IGRAVE, //0x0EC
};

//TAP dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for normal char, twice for accented
    [TD_OGRAVE] = ACTION_TAP_DANCE_DOUBLE(KC_L, UC(0x0F2)),
    [TD_AGRAVE] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, UC(0x0E0)),
    [TD_UGRAVE] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, UC(0x0F9)),
    [TD_EGRAVE] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, UC(0x0E8)),
    [TD_EACUTE] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, UC(0x0E9)),
    [TD_IGRAVE] = ACTION_TAP_DANCE_DOUBLE(KC_EQL, UC(0x0EC)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_A,    KC_1,    MO(_FN),
            TD(TD_OGRAVE),   KC_SPC
    ),
    [_FN] = LAYOUT(
        QMKBEST, QMKURL,  _______,
            RESET,    XXXXXXX
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QMKBEST:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("QMK is the best thing ever!");
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case QMKURL:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING("https://qmk.fm/\n");
            } else {
                // when keycode QMKURL is released
            }
            break;
    }
    return true;
}

/*
void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool led_update_user(led_t led_state) {
    return true;
}
*/
