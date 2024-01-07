#pragma once

#include "../efi_types.h"
#include "../efi_system_table.h"
#include "./efi_device_path.h"
#include "../efi_memory.h"

#define EFI_LOADED_IMAGE_PROTOCOL_GUID \
  {0x5B1B31A1,0x9562,0x11d2,\
    {0x8E,0x3F,0x00,0xA0,0xC9,0x69,0x72,0x3B}}

typedef struct {
	uint32_t revision;
	efi_handle_t parent_handle;
	efi_system_table_t *sys_table;

	// Source location of the image
	efi_handle_t dev_handle;
	efi_device_path_protocol_t *file_path;
	void *reserved;

	// Image’s load options
	uint32_t load_options_size;
	void *load_options;
	
	// Location where image was loaded
	void *image_base;
	uint64_t image_size;
	efi_memory_t image_code_type;
	efi_memory_t image_data_type;
	EFI_IMAGE_UNLOAD unload;
} efi_loaded_image_protocol_t;
