#pragma once

#include "./efi_types.h"

typedef struct _efi_table_header {
	uint64_t signature;
	uint32_t revision;
	uint32_t header_size;
	uint32_t crc32;
	uint32_t reserved;
} efi_table_header_t;
