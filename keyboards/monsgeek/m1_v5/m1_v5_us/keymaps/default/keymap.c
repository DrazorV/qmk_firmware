// Copyright 2024 yangzheng20003 (@yangzheng20003)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    _BL = 0,
    _FL,
    _MBL,
    _MFL,
    _FBL,
};

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
        QK_BOOT,  KC_MYCM,  KC_MAIL,  KC_WSCH,  KC_WHOM,  KC_MSEL,  KC_MPLY,  KC_MPRV,  KC_MNXT,  _______,  _______,  _______,  _______,  RGB_MOD,  _______,
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

typedef union {
    uint32_t raw;
    struct {
        uint8_t wasd_act_as_directional : 1;
        uint8_t ctrl_act_as_menu : 1;
    };
} eeconfig_user_t;
eeconfig_user_t confinfo;

void eeconfig_init_user() {
    confinfo.raw = eeconfig_read_user();
    if (!confinfo.raw) {
        confinfo.wasd_act_as_directional = 0;
        confinfo.ctrl_act_as_menu        = 0;
    }
}

// TODO: cleanup
void rgb_matrix_hs_indicator_set(uint8_t index, RGB rgb, uint32_t interval, uint8_t times);

uint32_t hs_ct_time;
bool     process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_A: {
            if (confinfo.wasd_act_as_directional) {
                if (record->event.pressed) {
                    register_code16(KC_LEFT);
                } else {
                    unregister_code16(KC_LEFT);
                }
                return false;
            } else {
                return true;
            }
        } break;

        case KC_S: {
            if (confinfo.wasd_act_as_directional) {
                if (record->event.pressed) {
                    register_code16(KC_DOWN);
                } else {
                    unregister_code16(KC_DOWN);
                }
                return false;
            } else {
                return true;
            }
        } break;

        case KC_D: {
            if (confinfo.wasd_act_as_directional) {
                if (record->event.pressed) {
                    register_code16(KC_RGHT);
                } else {
                    unregister_code16(KC_RGHT);
                }
                return false;
            } else {
                return true;
            }
        } break;

        case KC_W: {
            if (confinfo.wasd_act_as_directional) {
                if (record->event.pressed) {
                    register_code16(KC_UP);
                } else {
                    unregister_code16(KC_UP);
                }
                return false;
            } else {
                return true;
            }
        } break;

        case KC_LEFT: {
            if (confinfo.wasd_act_as_directional) {
                if (record->event.pressed) {
                    register_code16(KC_A);
                } else {
                    unregister_code16(KC_A);
                }
                return false;
            } else {
                return true;
            }
        } break;

        case KC_DOWN: {
            if (confinfo.wasd_act_as_directional) {
                if (record->event.pressed) {
                    register_code16(KC_S);
                } else {
                    unregister_code16(KC_S);
                }
                return false;
            } else {
                return true;
            }
        } break;

        case KC_RGHT: {
            if (confinfo.wasd_act_as_directional) {
                if (record->event.pressed) {
                    register_code16(KC_D);
                } else {
                    unregister_code16(KC_D);
                }
                return false;
            } else {
                return true;
            }
        } break;

        case KC_UP: {
            if (confinfo.wasd_act_as_directional) {
                if (record->event.pressed) {
                    register_code16(KC_W);
                } else {
                    unregister_code16(KC_W);
                }
                return false;
            } else {
                return true;
            }
        } break;

        case KC_RCTL: {
            if (confinfo.ctrl_act_as_menu) {
                if (record->event.pressed) {
                    register_code16(KC_APP);
                } else {
                    unregister_code16(KC_APP);
                }
                return false;
            } else {
                return true;
            }
        } break;

        case HS_DIR: {
            if (record->event.pressed) {
                confinfo.wasd_act_as_directional = !confinfo.wasd_act_as_directional;
                RGB rgb_test_open;
                rgb_test_open = hsv_to_rgb((HSV){.h = 0, .s = 0, .v = RGB_MATRIX_VAL_STEP * 5});
                rgb_matrix_hs_indicator_set(0xFF, (RGB){rgb_test_open.r, rgb_test_open.g, rgb_test_open.b}, 250, 1);
                eeconfig_update_user(confinfo.raw);
            }
            return false;
        } break;

        case HS_CT_A: {
            if (record->event.pressed) {
                hs_ct_time = timer_read32();
            } else {
                hs_ct_time = 0;
            }
            return false;
        } break;

        case HS_SIRI: {
            if (record->event.pressed) {
                register_code(KC_LCMD);
                register_code(KC_SPC);
                wait_ms(20);
            } else {
                unregister_code(KC_SPC);
                unregister_code(KC_LCMD);
            }
            return false;
        } break;

        case KC_MCTL: {
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_UP);

            } else {
                unregister_code(KC_LCTL);
                unregister_code(KC_UP);
            }
            return false;
        } break;
    }

    return true;
}

void housekeeping_task_user(void) {
    if (timer_elapsed32(hs_ct_time) > 3000 && hs_ct_time) {
        confinfo.ctrl_act_as_menu = !confinfo.ctrl_act_as_menu;
        RGB rgb_test_open;
        rgb_test_open = hsv_to_rgb((HSV){.h = 0, .s = 0, .v = RGB_MATRIX_VAL_STEP * 5});
        rgb_matrix_hs_indicator_set(0xFF, (RGB){rgb_test_open.r, rgb_test_open.g, rgb_test_open.b}, 250, 1);
        eeconfig_update_user(confinfo.raw);
        hs_ct_time = 0;
    }
}