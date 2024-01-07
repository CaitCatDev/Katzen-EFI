#pragma once

/*TODO: look at making our own standard int fallbacks for none c99 code*/

#include <stdint.h>
#include <stdbool.h>

/* Define UEFI Types as laid out here
 * https://uefi.org/specs/UEFI/2.10/02_Overview.html
 */

/*Chars*/
typedef char char8;
typedef short char16;

typedef bool boolean_t;

/* HACK: Just assume 64bit for now*/
typedef uint64_t uintn_t;
typedef int64_t intn_t;

/*"Non" ints*/
typedef uintn_t efi_tpl_t;
typedef uint64_t efi_lba_t;
typedef uintn_t efi_status_t;

typedef void *efi_handle_t;
typedef void *efi_event_t;

typedef struct {
	uint32_t data1;
	uint16_t data2;
	uint16_t data3;
	uint8_t data4[8];
} efi_guid_t;

#define IN /*data is passed to function*/
#define OUT /*data is returned from function*/
#define OPTIONAL /*data is optional and can be NULL to not pass*/

/*TODO: setup EFIAPI*/
#define EFIAPI 
