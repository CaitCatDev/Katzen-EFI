#pragma once

#include <kuefi/efi.h>
#include <kuefi/protocols/efi_file.h>

efi_status_t kuefi_open_rootfs(efi_handle_t handle, efi_file_protocol_t **rootfs);
