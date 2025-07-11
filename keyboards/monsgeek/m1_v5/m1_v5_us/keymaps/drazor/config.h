// -------------------------
// EEPROM Config Definitions
// -------------------------

// Total size your config struct uses — adjust if fields are added
#define USER_CONFIG_SIZE 16

// Start your block *after* all manufacturer-defined data
#define EECONFIG_USER_CONFIG_OFFSET (EECONFIG_USER_DATA_SIZE)

// Final EEPROM address offset
#define USER_CONFIG_EEPROM_ADDR ((uint32_t)EECONFIG_USER_DATABLOCK + EECONFIG_USER_CONFIG_OFFSET)

// -------------------------
// LED Index Lists (customize as needed)
// -------------------------

#define CAPS_LOCK_LETTER_LIST { 40,41,42,43,44,45,46,47,48,49,53,54,55,56,57,58,59,60,61,65,66,67,68,69,70,71 }
#define NUMBER_LIST           { 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 50, 51}
#define FUNC_LIST             { 10, 11, 12 , 13, 14, 15, 16, 17, 18, 19, 20, 21 }
