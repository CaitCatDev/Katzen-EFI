#pragma once

#include "../efi_types.h"

typedef struct {
	uint64_t res_x;
	uint64_t res_y;
	uint64_t res_z;
	boolean_t left_button;
	boolean_t right_button;
} efi_simple_pointer_mode_t;

typedef struct {
	int32_t res_x;
	int32_t res_y;
	int32_t res_z;
	boolean_t left_button;
	boolean_t right_button;
} efi_simple_pointer_state_t;

#define EFI_SIMPLE_POINTER_PROTOCOL_GUID {0x31878c87,0xb75,0x11d5,{0x9a,0x4f,0x00,0x90,0x27,0x3f,0xc1,0x4d}}

typedef struct _efi_simple_pointer_protocol efi_simple_pointer_protocol_t;

typedef efi_status_t (EFIAPI *EFI_SIMPLE_POINTER_RESET)(IN efi_simple_pointer_protocol_t *this, IN boolean_t ext_verify);
typedef efi_status_t (EFIAPI *EFI_SIMPLE_POINTER_GET_STATE)(IN efi_simple_pointer_protocol_t *this, efi_simple_pointer_state_t *state);


struct _efi_simple_pointer_protocol {
	EFI_SIMPLE_POINTER_RESET reset;
	EFI_SIMPLE_POINTER_GET_STATE get_state;
	efi_event_t wait_for_input;
	efi_simple_pointer_mode_t *Mode;
};
