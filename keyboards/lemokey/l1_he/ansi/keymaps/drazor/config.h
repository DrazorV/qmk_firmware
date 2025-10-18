//
// Created by DrazorV on 18/1/2025.
//

#ifndef CONFIG_H
#define CONFIG_H

#define EECONFIG_USER_DATA_SIZE 15
#define CAPS_LOCK_LETTER_LIST \
{ 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 63, 64, 65, 66, 67, 68, 69 }
#define NUMBER_LIST \
{ 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 42, 43 }
#define FUNC_LIST \
{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}

#define DYNAMIC_KEYMAP_LAYER_COUNT 6

// #ifdef SNLED27351_CURRENT_TUNE
// #undef SNLED27351_CURRENT_TUNE
// #endif

//  #define SNLED27351_CURRENT_TUNE \
//     { 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40 }


#ifdef RGB_MATRIX_ENABLE
    // Startup values, when none have been set
    #define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_RIVERFLOW
    #define RGB_MATRIX_DEFAULT_HUE 7                          // Sets the default hue value, if none has been set
    #define RGB_MATRIX_DEFAULT_SAT 248                        // Sets the default saturation value, if none has been set
    #define RGB_MATRIX_DEFAULT_SPD 127                        // Sets the default animation speed, if none has been set
    #define ENABLE_RGB_MATRIX_STARLIGHT
    #define ENABLE_RGB_MATRIX_STARLIGHT_DUAL_HUE
    #define ENABLE_RGB_MATRIX_STARLIGHT_DUAL_SAT
    #define ENABLE_RGB_MATRIX_RIVERFLOW

#endif //RGB_MATRIX_ENABLE

#endif // CONFIG_H
