// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Define custom keycodes for your macros
enum custom_keycodes {
    MACRO_LOCK = SAFE_RANGE, // Win + L
    MACRO_SHOT1,             // Win + Ctrl + Shift + 1
    MACRO_SHOT2              // Win + Ctrl + Shift + 2
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        MACRO_LOCK, MACRO_SHOT1, MACRO_SHOT2
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MACRO_LOCK:
            if (record->event.pressed) {
                // Windows Key + L
                SEND_STRING(SS_LGUI("l"));
            }
            return false;

        case MACRO_SHOT1:
            if (record->event.pressed) {
                // Win + Ctrl + Shift + 1
                register_code(KC_LGUI);
                register_code(KC_LCTL);
                register_code(KC_LSFT);
                tap_code(KC_1);
                unregister_code(KC_LSFT);
                unregister_code(KC_LCTL);
                unregister_code(KC_LGUI);
            }
            return false;

        case MACRO_SHOT2:
            if (record->event.pressed) {
                // Win + Ctrl + Shift + 2
                register_code(KC_LGUI);
                register_code(KC_LCTL);
                register_code(KC_LSFT);
                tap_code(KC_2);
                unregister_code(KC_LSFT);
                unregister_code(KC_LCTL);
                unregister_code(KC_LGUI);
            }
            return false;
    }
    return true;
}