#include "includes/kuefi/efi.h"
#include "includes/kuefi/protocols/efi_device_path.h"
#include "includes/kuefi/protocols/efi_loaded_image.h"
#include "includes/kuefi/protocols/efi_block_io.h"
#include "kuefi/efi_boot_services.h"
#include "kuefi/efi_memory.h"
#include "kuefi/efi_types.h"

#include <kuefi/protocols/efi_graphics_output.h>
#include <kuefi/protocols/efi_simple_filesystem.h>
#include <kuefi/protocols/efi_file.h>

#include <kuefi/lib/io.h>
#include <kuefi/lib/kuefi.h>

#define NULL (void *)0


efi_status_t EFIAPI efi_main(efi_handle_t image_handle, efi_system_table_t *sys_table) {
	efi_guid_t gop_guid = EFI_GRAPHICS_OUTPUT_PROTOCOL_GUID;
	uintn_t mode_size = 0;
	uint32_t best_mode = 0, best_vert = 0, best_horiz = 0;
	efi_graphics_output_mode_info_t *mode_info;
	efi_graphics_output_protocol_t *gop;	

	kuefi_global_init(image_handle, sys_table);

	GBS->locate_protocol(&gop_guid, NULL, (void**)&gop);

	for(uint32_t i = 0; i < gop->mode->max_mode; i++) {
		gop->query_mode(gop, i, &mode_size, &mode_info);
		if(mode_info->horiz_resolution >= best_horiz && mode_info->vert_resolution >= best_vert) {
			best_mode = i;
		}
	}
	
	gop->set_mode(gop, best_mode);
	gop->query_mode(gop, best_mode, &mode_size, &mode_info);

	for(uint32_t x = 0; x < gop->mode->info->horiz_resolution; x++) {
		for(uint32_t y = 0; y < gop->mode->info->vert_resolution; y++) {
			((uint32_t*)gop->mode->fb_base)[y * gop->mode->info->horiz_resolution + x] = 0x282a36;
		}
	}

	kuefi_printf((char16*)u"Press any key to exit\r\n");


	kuefi_wait_for_key();

	return 0;
}
