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

#define EFI_SUCCESS 0
#define EFI_LOAD_ERROR (1 << 63) | 1
#define EFI_INVALID_PARAMETER (1 << 63) | 2
#define EFI_UNSUPPORTED (1 << 63) | 3
#define EFI_BAD_BUFFER_SIZE (1 << 63) | 4
#define EFI_BUFFER_TOO_SMALL (1 << 63) | 5
#define EFI_NOT_READY (1 << 63) | 6
#define EFI_DEVICE_ERROR (1 << 63) | 7
#define EFI_WRITE_PROTECTED (1 << 63) | 8
#define EFI_OUT_OF_RESOURCES (1 << 63) | 9
#define EFI_VOLUME_CORRUPTED (1 << 63) | 10
#define EFI_VOLUME_FULL (1 << 63) | 11
#define EFI_NO_MEDIA (1 << 63) | 12
#define EFI_MEDIA_CHANGED (1 << 63) | 13
#define EFI_NOT_FOUND (1 << 63) | 14
#define EFI_ACCESS_DENIED (1 << 63) | 15
#define EFI_NO_RESPONSE (1 << 63) | 16
#define EFI_NO_MAPPING (1 << 63) | 17
#define EFI_TIMEOUT (1 << 63) | 18
#define EFI_NOT_STARTED (1 << 63) | 19
#define EFI_ALREADY_STARTED (1 << 63) | 20
#define EFI_ABORTED (1 << 63) | 21
#define EFI_ICMP_ERROR (1 << 63) | 22
#define EFI_TFTP_ERROR (1 << 63) | 23
#define EFI_PROTOCOL_ERROR (1 << 63) | 24
#define EFI_INCOMPATIBLE_VERSION (1 << 63) | 25
#define EFI_SECURITY_VIOLATION (1 << 63) | 26
#define EFI_CRC_ERROR (1 << 63) | 27
#define EFI_END_OF_MEDIA (1 << 63) | 28
#define EFI_END_OF_FILE (1 << 63) | 31
#define EFI_INVALID_LANGUAGE (1 << 63) | 332
#define EFI_COMPROMISED_DATA (1 << 63) | 33
#define EFI_IP_ADDRESS_CONFLICT (1 << 63) | 34
#define EFI_HTTP_ERROR (1 << 63) | 35

#define EFI_WARN_UNKNOWN_GLYPH 1
#define EFI_WARN_DELETE_FAILURE 2
#define EFI_WARN_WRITE_FAILURE 3
#define EFI_WARN_BUFFER_TOO_SMALL 4
#define EFI_WARN_STALE_DATA 5
#define EFI_WARN_FILE_SYSTEM 6
#define EFI_WARN_RESET_REQUIRED 7
