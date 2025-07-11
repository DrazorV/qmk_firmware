// Copyright 2024 yangzheng20003 (@yangzheng20003)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "rgb_record/rgb_record.h"
#include "config.h"
#include "eeprom_settings.h"
#include "eeprom.h"

enum layers {
    _BL = 0,
    _FL,
    _MBL,
    _MFL,
    _FBL,
};

// These macros must be defined in a shared file or directly here
uint8_t caps_lock_letter_list[26] = CAPS_LOCK_LETTER_LIST;
uint8_t number_list[14] = NUMBER_LIST;
uint8_t func_list[12] = FUNC_LIST;
bool process_record_user_mine(uint16_t keycode, keyrecord_t *record);
bool process_record_user_mfg(uint16_t keycode, keyrecord_t *record);


#define ______ HS_BLACK

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BL] = LAYOUT( /* Base */
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,   KC_MUTE,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_HOME,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_PGUP,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,   KC_PGDN,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,    KC_END,
        KC_LCTL,  KC_LCMD,  KC_LALT,                      KC_SPC,                                 KC_RALT,  MO(_FL),  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [_FL] = LAYOUT( /* Base */
        _______,  KC_MYCM,  KC_MAIL,  KC_WSCH,  KC_WHOM,  KC_MSEL,  KC_MPLY,  KC_MPRV,  KC_MNXT,  _______,  _______,  _______,  _______,  RGB_MOD,  _______,
        EE_CLR,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RGB_SPD,  RGB_SPI,  _______,  _______,
        _______,  _______,  HS_DIR,   KC_BT1,   KC_BT2,   KC_BT3,   KC_2G4,   KC_USB,   KC_INS,   _______,  KC_PSCR,  _______,  _______,  _______,  _______,
        _______,  _______, _______,  _______,  _______,   _______,  _______,  _______,  _______,  RGB_TOG,  _______,  _______,            _______,  _______,
        _______,            _______,  _______,  KC_CALC,  _______,  _______,  _______,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,  MO(_FBL), RGB_VAI,  _______,
        _______,   GU_TOGG,  _______,                     HS_BATQ,                                _______,  _______,  HS_CT_A,  RGB_SAI,  RGB_VAD,  RGB_SAD),

    [_MBL] = LAYOUT( /* Base */
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,   KC_MUTE,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_HOME,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_PGUP,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,   KC_PGDN,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,    KC_END,
        KC_LCTL,  KC_LALT,  KC_LCMD,                      KC_SPC,                                 KC_RCMD,  MO(_MFL), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [_MFL] = LAYOUT( /* Base */
        _______,  KC_BRID,  KC_BRIU,  KC_MCTL,  HS_SIRI,  _______,  _______,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  RGB_MOD,  _______,
        EE_CLR,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RGB_SPD,  RGB_SPI,  _______,  _______,
        _______,  _______,  HS_DIR,   KC_BT1,   KC_BT2,   KC_BT3,   KC_2G4,   KC_USB,   KC_INS,   _______,  KC_PSCR,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RGB_TOG,  _______,  _______,            _______,  _______,
        _______,            _______,  _______,  KC_CALC,  _______,  _______,  _______,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,  MO(_FBL), RGB_VAI,  _______,
        _______,  _______,  _______,                      HS_BATQ,                                _______,  _______,  HS_CT_A,  RGB_SAI,  RGB_VAD,  RGB_SAD),
    [_FBL] = LAYOUT( /* Base */
        QK_BOOT,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  BT_TEST,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,                      _______,                                _______,  _______,  _______,  _______,  _______,  _______)

};

	const uint16_t PROGMEM rgbrec_default_effects[RGBREC_CHANNEL_NUM][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
       HS_GREEN, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________,
       ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________,
       ________, ________, HS_GREEN, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________,
       ________, HS_GREEN, HS_GREEN, HS_GREEN, ________, ________, ________, ________, ________, ________, ________, ________,           ________, ________,
       ________,           ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, HS_GREEN, ________,
       ________, ________, ________,                     ________,                               ________, ________, ________, HS_GREEN, HS_GREEN, HS_GREEN),

    [1] = LAYOUT(
       ________, HS_RED,   HS_RED,   HS_RED,   ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________,
       ________, HS_RED,   HS_RED,   HS_RED,   HS_RED,   HS_RED,   ________, ________, ________, ________, ________, ________, ________, ________, ________,
       HS_RED,   HS_RED,   HS_RED,   HS_RED,   HS_RED,   ________, ________, ________, ________, ________, ________, ________, ________, ________, ________,
       ________, HS_RED,   HS_RED,   HS_RED,   ________, HS_RED,   ________, ________, ________, ________, ________, ________,           ________, ________,
       HS_RED,             ________, ________, ________, HS_RED,   ________, ________, ________, ________, ________, ________, ________, ________, ________,
       HS_RED,   ________, HS_RED,                       ________,                               ________, ________, ________, ________, ________, ________),

    [2] = LAYOUT(
       HS_BLUE,  ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________, ________,
       ________, HS_BLUE,  HS_BLUE,  HS_BLUE,  HS_BLUE,  HS_BLUE,  HS_BLUE,  HS_BLUE,  ________, ________, ________, ________, ________, ________, ________,
       ________, HS_BLUE,  HS_BLUE,  HS_BLUE,  HS_BLUE,  HS_BLUE,  ________, ________, ________, ________, ________, ________, ________, ________, ________,
       ________, HS_BLUE,  HS_BLUE,  HS_BLUE,  HS_BLUE,  HS_BLUE,  ________, ________, ________, ________, ________, ________,           ________, ________,
       ________,           ________, HS_BLUE,  HS_BLUE,  ________, ________, ________, ________, ________, ________, ________, ________, ________, ________,
       ________, ________, ________,                     ________,                               ________, ________, ________, ________, ________, ________),
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [1] = {ENCODER_CCW_CW(_______, _______)},
    [2] = {ENCODER_CCW_CW(_______, _______)},
    [3] = {ENCODER_CCW_CW(_______, _______)},
    [4] = {ENCODER_CCW_CW(_______, _______)},
};
#endif
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Call your own logic first
    if (!process_record_user_mine(keycode, record)) {
        return false;
    }

    // Then call manufacturer logic
    return process_record_user_mfg(keycode, record);
}

bool process_record_user_mine(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case AC_TOGG:
                autocorrect_toggle();
                return false;
        }
    }
    return true;
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (host_keyboard_led_state().caps_lock && user_config.caps_lock_ind) {
        HSV hsv = user_config.caps_lock_hs;
        hsv.v = user_config.caps_lock_br;
        RGB rgb = hsv_to_rgb(hsv);

        for (uint8_t i = 0; i < ARRAY_SIZE(caps_lock_letter_list); i++) {
            rgb_matrix_set_color(caps_lock_letter_list[i], rgb.r, rgb.g, rgb.b);
        }
    }

    if ((IS_LAYER_ON(_FL) || IS_LAYER_ON(_MFL)) && user_config.layer1_ind) {
        HSV hsv = user_config.layer1_hs;
        hsv.v = user_config.layer1_br;
        RGB rgb = hsv_to_rgb(hsv);

        for (uint8_t j = 0; j < ARRAY_SIZE(func_list); j++) {
            rgb_matrix_set_color(func_list[j], rgb.r, rgb.g, rgb.b);
        }
    }

    if ((IS_LAYER_ON(_FBL)) && user_config.layer2_ind) {
        HSV hsv = user_config.layer2_hs;
        hsv.v = user_config.layer2_br;
        RGB rgb = hsv_to_rgb(hsv);

        for (uint8_t j = 0; j < ARRAY_SIZE(number_list); j++) {
            rgb_matrix_set_color(number_list[j], rgb.r, rgb.g, rgb.b);
        }
    }

    return true;
}


void keyboard_post_init_user(void) {
    load_user_config();  // Load user config from EEPROM

    // DEBUG: Print all RGB Matrix LED indexes and their position
    for (uint8_t i = 0; i < DRIVER_LED_TOTAL; i++) {
        dprintf("LED %02d → x=%3d, y=%3d\n", i, g_led_config.point[i].x, g_led_config.point[i].y);
    }
}
