#pragma once

#include "./efi_types.h"
#include "./efi_system_table.h"

#define EFI_IMAGE_SUBSYSTEM_EFI_APPLICATION 10
#define EFI_IMAGE_SUBSYSTEM_EFI_BOOT_SERVICE_DRIVER 11
#define EFI_IMAGE_SUBSYSTEM_EFI_RUNTIME_DRIVER 12

#define EFI_IMAGE_MACHINE_IA32 0x014C
#define EFI_IMAGE_MACHINE_IA64 0x0200
#define EFI_IMAGE_MACHINE_EBC 0x0EBC
#define EFI_IMAGE_MACHINE_x64 0x8664
#define EFI_IMAGE_MACHINE_ARMTHUMB_MIXED 0x01C2
#define EFI_IMAGE_MACHINE_AARCH64 0xAA64
#define EFI_IMAGE_MACHINE_RISCV32 0x5032
#define EFI_IMAGE_MACHINE_RISCV64 0x5064
#define EFI_IMAGE_MACHINE_RISCV128 0x5128
#define EFI_IMAGE_MACHINE_LONGARCH32 0x6232
#define EFI_IMAGE_MACHINE_LONGARCH64 0x6264
