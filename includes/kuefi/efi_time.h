#pragma once

#include "./efi_types.h"

typedef struct {
	uint16_t year;
	uint8_t month;
	uint8_t day;
	uint8_t hour;
	uint8_t minute;
	uint8_t second;
	uint8_t pad1;
	uint32_t nanosecond;
	int16_t time_zone;
	uint8_t daylight;
	uint8_t pad2;
} efi_time_t;

typedef struct {
	uint32_t resolution;
	uint32_t accuracy;
	boolean_t sets_to_zero;
} efi_time_capabilities;

#define EFI_TIME_ADJUST_DAYLIGHT 0x01
#define EFI_TIME_IN_DAYLIGHT 0x02


#define EFI_UNSPECIFIED_TIMEZONE 0x07FF
