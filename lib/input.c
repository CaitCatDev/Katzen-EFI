#include "kuefi/efi_types.h"
#include <kuefi/lib/kuefi.h>
#include <kuefi/lib/io.h>

efi_status_t kuefi_wait_for_key() {
	efi_event_t key_ev = GST->conin->wait_for_key;
	uintn_t index;
	return GBS->wait_for_event(1, &key_ev, &index);
}
