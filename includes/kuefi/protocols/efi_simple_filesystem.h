#pragma once

#include "../efi_types.h"
#include "./efi_file.h"

#define EFI_SIMPLE_FILE_SYSTEM_PROTOCOL_GUID {0x0964e5b22,0x6459,0x11d2,{0x8e,0x39,0x00,0xa0,0xc9,0x69,0x72,0x3b}}

#define EFI_SIMPLE_FILE_SYSTEM_PROTOCOL_REVISION 0x00010000

typedef struct _efi_simple_file_system_protocol efi_simple_file_system_protocol_t;

typedef efi_status_t (EFIAPI *EFI_SIMPLE_FILE_SYSTEM_PROTOCOL_OPEN_VOLUME)(IN efi_simple_file_system_protocol_t *this, OUT efi_file_protocol_t **root);

struct _efi_simple_file_system_protocol {
	uint64_t revision;
	EFI_SIMPLE_FILE_SYSTEM_PROTOCOL_OPEN_VOLUME open_volume;
};
