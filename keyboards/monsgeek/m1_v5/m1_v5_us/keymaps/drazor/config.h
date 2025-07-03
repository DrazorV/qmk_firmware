// Offset for your logic starts *after* all official usage
#define USER_CONFIG_SIZE 16  // Adjust this to match actual bytes used
#define EECONFIG_USER_CONFIG_OFFSET (EECONFIG_USER_DATA_SIZE)
#define USER_CONFIG_EEPROM_ADDR ((uint32_t)EECONFIG_USER_DATABLOCK + EECONFIG_USER_CONFIG_OFFSET)

#define CAPS_LOCK_LETTER_LIST { 20, 21, 22, /* ... */ }
#define NUMBER_LIST           { 1, 2, 3, /* ... */ }
#define FUNC_LIST             { 10, 11, 12, /* ... */ }
