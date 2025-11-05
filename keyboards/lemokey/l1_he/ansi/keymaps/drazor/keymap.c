/* Copyright 2025 @ Lemokey (https://www.keychron.com)
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
#include "lemokey_common.h"
#include "config.h"
#include "eeprom_settings.h"
#include "eeprom.h"

// clang-format off
enum layer_names {
    BASE = 0,
    FN,
    NUM,
    L3,
    L4,
    L5
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_ansi_86(
                  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,   TG(NUM),
                  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  TG(L3),
        MC_0,     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  TG(L4),
        MC_1,     KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,   TG(L5),
        MC_2,     KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        MC_3,     KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                       KC_RALT,  MO(FN),   KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RIGHT),

    [FN] = LAYOUT_ansi_86(
                  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  AC_TOGG,
                  _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_HOME,
        KC_F17,   RGB_TOG,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_INS,
        KC_F18,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  KC_END,
        KC_F19,   _______,            PROF1,      PROF2,    PROF3,  _______,  BAT_LVL,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        KC_F20,   _______,  _______,  _______,                                _______,                      _______,  _______,  _______,  _______,  _______,  _______),

    [NUM] = LAYOUT_ansi_86(
                  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,      _______,         _______,  _______,
                  _______,  KC_KP_1,  KC_KP_2,  KC_KP_3,  KC_KP_4,  KC_KP_5,  KC_KP_6,  KC_KP_7,  KC_KP_8,  KC_KP_9,  KC_KP_0,  KC_KP_MINUS,  KC_KP_PLUS,      _______,  _______,
        KC_MPRV,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_KP_SLASH,  KC_KP_ASTERISK,  _______,  _______,
        KC_MPLY,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                       _______,  _______,
        KC_MNXT,  _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,             _______,
        KC_MSTP,  _______,  _______,  _______,                                _______,                      _______,  _______,  _______,  _______,             _______,  _______),

    [L3] = LAYOUT_ansi_86(
                  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
                  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        MC_4,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        MC_5,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
        MC_6,  _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        MC_7,  _______,  _______,  _______,                                _______,                      _______,  _______,  _______,  _______,  _______,  _______),

    [L4] = LAYOUT_ansi_86(
                  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
                  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        MC_8,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        MC_9,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
        MC_10,  _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        MC_11,  _______,  _______,  _______,                                _______,                      _______,  _______,  _______,  _______,  _______,  _______),

    [L5] = LAYOUT_ansi_86(
                  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
                  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        MC_12,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        MC_13,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
        MC_14,  _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        MC_15,  _______,  _______,  _______,                                _______,                      _______,  _______,  _______,  _______,  _______,  _______),
    };

// clang-format on
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][1][2] = {
    [BASE] = {ENCODER_CCW_CW(KC_MS_WH_DOWN, KC_MS_WH_UP)},
    [FN]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [NUM]  = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [L3]   = {ENCODER_CCW_CW(RGB_HUD, RGB_HUI)},
    [L4]   = {ENCODER_CCW_CW(RGB_SAD, RGB_SAI)},
    [L5]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
};
#endif // ENCODER_MAP_ENABLE

// clang-format on
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case AC_TOGG:
                autocorrect_toggle();
                return false;
        }
    }

    if (!process_record_lemokey_common(keycode, record)) {
        return false;
    }

    return true;
}

uint8_t caps_lock_letter_list[27] = CAPS_LOCK_LETTER_LIST;
uint8_t number_list[14] = NUMBER_LIST;
uint8_t func_list[12] = FN_LIST;
uint8_t macros[4] = MACRO_KEYS;

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (host_keyboard_led_state().caps_lock && user_config.br > 0) {
        HSV hsv = user_config.caps_lock_hs;
        hsv.v = user_config.br;
        RGB rgb = hsv_to_rgb(hsv);

        for (uint8_t i = 0; i < ARRAY_SIZE(caps_lock_letter_list); i++) {
            rgb_matrix_set_color(caps_lock_letter_list[i], rgb.r, rgb.g, rgb.b);
        }
    }

    if (IS_LAYER_ON(FN) && user_config.br > 0) {
        HSV hsv = user_config.fn_hs;
        hsv.v = user_config.br;
        RGB rgb = hsv_to_rgb(hsv);

        for (uint8_t j = 0; j < ARRAY_SIZE(func_list); j++) {
            rgb_matrix_set_color(func_list[j], rgb.r, rgb.g, rgb.b);
        }
        for (uint8_t j = 0; j < ARRAY_SIZE(macros); j++) {
            rgb_matrix_set_color(macros[j], rgb.r, rgb.g, rgb.b);
        }
    }

    if (IS_LAYER_ON(NUM)) {
        for (uint8_t j = 0; j < ARRAY_SIZE(number_list); j++) {
            rgb_matrix_set_color(number_list[j], 255, 0, 0);
        }

        rgb_matrix_set_color(14, 255, 0, 0);
        for (uint8_t j = 0; j < ARRAY_SIZE(macros); j++) {
            rgb_matrix_set_color(macros[j], 255, 0, 0);
        }
    }

    if (IS_LAYER_ON(L3)) {
        rgb_matrix_set_color(29, 0, 255, 0);
        for (uint8_t j = 0; j < ARRAY_SIZE(macros); j++) {
            rgb_matrix_set_color(macros[j], 0, 255, 0);
        }
    }

    if (IS_LAYER_ON(L4)) {
        rgb_matrix_set_color(45, 0, 0, 255);
        for (uint8_t j = 0; j < ARRAY_SIZE(macros); j++) {
            rgb_matrix_set_color(macros[j], 0, 0, 255);
        }
    }

    if (IS_LAYER_ON(L5)) {
        rgb_matrix_set_color(60, 255, 255, 255);
        for (uint8_t j = 0; j < ARRAY_SIZE(macros); j++) {
            rgb_matrix_set_color(macros[j], 255, 255, 255);
        }
    }

    return false;
}

void keyboard_post_init_user(void) {
    eeconfig_read_user_datablock(&user_config);
}
