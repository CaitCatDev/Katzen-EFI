#include <kuefi/efi_types.h>
#include <kuefi/protocols/efi_simple_filesystem.h>

#include <kuefi/lib/kuefi.h>

efi_status_t kuefi_open_rootfs(efi_handle_t handle, efi_file_protocol_t **rootfs) {
	efi_status_t status = 0;
	efi_guid_t simple_fs_guid = EFI_SIMPLE_FILE_SYSTEM_PROTOCOL_GUID;
	efi_simple_file_system_protocol_t *efi_fs = (void *)0;

	GBS->handle_protocol(handle, &simple_fs_guid, (void**)&efi_fs);

	return efi_fs->open_volume(efi_fs, rootfs);
}
