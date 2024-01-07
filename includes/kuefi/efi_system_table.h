#pragma once

#include "./efi_types.h"
#include "./efi_table_header.h"
#include "kuefi/efi_config_table.h"

typedef struct _efi_system_table efi_system_table_t;

#include "./protocols/efi_simple_text_out.h"
#include "./protocols/efi_simple_text_input.h"
#include "./efi_runtime_services.h"
#include "./efi_boot_services.h"
#include "./efi_config_table.h"

#define EFI_SYSTEM_TABLE_SIGNATURE 0x5453595320494249
#define EFI_2_100_SYSTEM_TABLE_REVISION ((2<<16) | (100))
#define EFI_2_90_SYSTEM_TABLE_REVISION ((2<<16) | (90))
#define EFI_2_80_SYSTEM_TABLE_REVISION ((2<<16) | (80))
#define EFI_2_70_SYSTEM_TABLE_REVISION ((2<<16) | (70))
#define EFI_2_60_SYSTEM_TABLE_REVISION ((2<<16) | (60))
#define EFI_2_50_SYSTEM_TABLE_REVISION ((2<<16) | (50))
#define EFI_2_40_SYSTEM_TABLE_REVISION ((2<<16) | (40))
#define EFI_2_31_SYSTEM_TABLE_REVISION ((2<<16) | (31))
#define EFI_2_30_SYSTEM_TABLE_REVISION ((2<<16) | (30))
#define EFI_2_20_SYSTEM_TABLE_REVISION ((2<<16) | (20))
#define EFI_2_10_SYSTEM_TABLE_REVISION ((2<<16) | (10))
#define EFI_2_00_SYSTEM_TABLE_REVISION ((2<<16) | (00))
#define EFI_1_10_SYSTEM_TABLE_REVISION ((1<<16) | (10))
#define EFI_1_02_SYSTEM_TABLE_REVISION ((1<<16) | (02))
#define EFI_SPECIFICATION_VERSION EFI_SYSTEM_TABLE_REVISION
#define EFI_SYSTEM_TABLE_REVISION EFI_2_100_SYSTEM_TABLE_REVISION

struct _efi_system_table {
	efi_table_header_t hdr;
	char16 *firmware_vendor;
	uint32_t firmware_revision;
	/*Con In*/
	efi_handle_t console_in_handle;
	efi_simple_text_input_protocol_t *conin;
	/*Con Out*/
	efi_handle_t console_out_handle;
	efi_simple_text_output_protocol_t *conout;
	/*Stderr*/
	efi_handle_t stderr_handle;
	efi_simple_text_output_protocol_t *stderr;
	/*Services*/
	efi_runtime_services_t *runtime_services;
	efi_boot_services_t *boot_services;
	
	/*Config Table*/
	uintn_t table_entries;
	efi_configuration_table_t *config_table;
};
