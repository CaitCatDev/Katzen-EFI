#pragma once

#include "../efi.h"
#include "kuefi/efi_boot_services.h"
#include "kuefi/efi_runtime_services.h"
#include "kuefi/efi_system_table.h"
#include "kuefi/efi_types.h"


extern efi_system_table_t *GST;
extern efi_boot_services_t *GBS;
extern efi_runtime_services_t *GRS;
extern efi_handle_t *GApp;


void kuefi_global_init(efi_handle_t *img_handle, efi_system_table_t *sys_table);
