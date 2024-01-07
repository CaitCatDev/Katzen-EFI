#include <kuefi/lib/kuefi.h>

efi_system_table_t *GST;
efi_boot_services_t *GBS;
efi_runtime_services_t *GRS;
efi_handle_t *GHANDLE;

/* Init global variables used to avoid the need
 * to pass SYSTABLE and other tables to all
 * Functions
 */
void kuefi_global_init(efi_handle_t *img_handle, efi_system_table_t *sys_table) {
	GST = sys_table;
	GBS = sys_table->boot_services;
	GRS = sys_table->runtime_services;
	GHANDLE = img_handle;
}
