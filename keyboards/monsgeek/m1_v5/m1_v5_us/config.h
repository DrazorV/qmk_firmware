// Copyright 2024 yangzheng20003 (@yangzheng20003)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define USB_POWER_EN_PIN                    B1 // USB ENABLE pin
#define LED_POWER_EN_PIN                    A5 // LED ENABLE pin
#define HS_BAT_CABLE_PIN                    A7 // USB insertion detection pin
#define HS_LED_BOOSTING_PIN                 D2 // LED BOOSTING

#define BAT_FULL_PIN                        A15
#define BAT_FULL_STATE                      1

#define HS_RGB_INDICATOR_COUNT              99
#define HS_RGB_BAT_COUNT                    1

#define MD_BT1_NAME                         "M1 V5"
#define MD_BT2_NAME                         "M1 V5"
#define MD_BT3_NAME                         "M1 V5"
#define MD_DONGLE_PRODUCT                   "M1 V5"

/* Device Connection RGB Indicator Light Index And Color */
#define HS_RGB_BLINK_INDEX_BT1              48
#define HS_RGB_BLINK_INDEX_BT2              47
#define HS_RGB_BLINK_INDEX_BT3              46
#define HS_RGB_BLINK_INDEX_2G4              45
#define HS_RGB_BLINK_INDEX_USB              44

#define HS_LBACK_COLOR_BT1                  RGB_BLUE
#define HS_LBACK_COLOR_BT2                  RGB_BLUE
#define HS_LBACK_COLOR_BT3                  RGB_BLUE
#define HS_LBACK_COLOR_2G4                  RGB_RED
#define HS_LBACK_COLOR_USB                  RGB_WHITE

#define HS_PAIR_COLOR_BT1                   RGB_BLUE
#define HS_PAIR_COLOR_BT2                   RGB_BLUE
#define HS_PAIR_COLOR_BT3                   RGB_BLUE
#define HS_PAIR_COLOR_2G4                   RGB_RED
#define HS_PAIR_COLOR_USB                   RGB_WHITE

/* Battery */
#define BATTERY_CAPACITY_LOW                15
#define BATTERY_CAPACITY_STOP               0
#define RGB_MATRIX_BAT_INDEX_MAP            {25, 26, 27, 28, 29, 30, 31, 32, 33, 34}

/* Status Indicator Lamp */
#define HS_MATRIX_BLINK_INDEX_BAT           1
#define HS_RGB_INDEX_CAPS                   52
#define HS_RGB_INDEX_WIN_LOCK               79

#define HS_RGB_BLINK_INDEX_WIN              53
#define HS_RGB_BLINK_INDEX_MAC              54

#define SYSTEM_WIN_PIN                      C15
#define SYSTEM_MAC_PIN                      C14

/* UART */
#define SERIAL_DRIVER                       SD3
#define SD1_TX_PIN                          C10
#define SD1_RX_PIN                          C11

/* Encoder */
#define ENCODER_MAP_KEY_DELAY               1

/* SPI */
#define SPI_DRIVER                          SPIDQ
#define SPI_SCK_PIN                         B3
#define SPI_MOSI_PIN                        B5
#define SPI_MISO_PIN                        B4

/* Flash */
#define EXTERNAL_FLASH_SPI_SLAVE_SELECT_PIN C12
#define WEAR_LEVELING_LOGICAL_SIZE          (WEAR_LEVELING_BACKING_SIZE / 2)

/* RGB Matrix */
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES

/* WS2812 */
#define WS2812_SPI_DRIVER  SPIDM2
#define WS2812_SPI_DIVISOR 32

/* Battery Indicator */
#define RGB_MATRIX_BAT_VAL      150
#define IM_BAT_REQ_LEVEL1_VAL   50
#define IM_BAT_REQ_LEVEL1_COLOR 0x00, RGB_MATRIX_BAT_VAL, 0x00

#define IM_BAT_REQ_LEVEL2_VAL   30
#define IM_BAT_REQ_LEVEL2_COLOR 0x00, RGB_MATRIX_BAT_VAL, 0x00

#define IM_BAT_REQ_LEVEL3_COLOR RGB_MATRIX_BAT_VAL, 0x00, 0x00