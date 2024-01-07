#pragma once

#include "../efi_types.h"

/*EFI KEY SHIFT STATES*/
#define EFI_SHIFT_STATE_VALID 0x80000000
#define EFI_RIGHT_SHIFT_PRESSED 0x00000001
#define EFI_LEFT_SHIFT_PRESSED 0x00000002
#define EFI_RIGHT_CONTROL_PRESSED 0x00000004
#define EFI_LEFT_CONTROL_PRESSED 0x00000008
#define EFI_RIGHT_ALT_PRESSED 0x00000010
#define EFI_LEFT_ALT_PRESSED 0x00000020
#define EFI_RIGHT_LOGO_PRESSED 0x00000040
#define EFI_LEFT_LOGO_PRESSED 0x00000080
#define EFI_MENU_KEY_PRESSED 0x00000100
#define EFI_SYS_REQ_PRESSED 0x00000200

/*EFI KEY TOGGLE STATE*/
typedef uint8_t efi_key_toggle_state_t;

#define EFI_TOGGLE_STATE_VALID 0x80
#define EFI_KEY_STATE_EXPOSED 0x40
#define EFI_SCROLL_LOCK_ACTIVE 0x01
#define EFI_NUM_LOCK_ACTIVE 0x02
#define EFI_CAPS_LOCK_ACTIVE 0x04

typedef struct efi_key_state_t {
	uint32_t key_shift_state;
	efi_key_toggle_state_t key_toggle_state;
} efi_key_state_t;

typedef struct {
	uint16_t scancode;
	char16 unicode;
} efi_input_key_t;

typedef struct {
	efi_input_key_t key;
	efi_key_state_t key_state;
} efi_key_data_t;

typedef efi_status_t (EFIAPI *EFI_KEY_NOTIFY_FUNCTION)(IN efi_key_data_t *key_data);

/*
 * EFI SIMPLE TEXT INPUT PROTOCOL
 */
#define EFI_SIMPLE_TEXT_INPUT_PROTOCOL_GUID {0x387477c1,0x69c7,0x11d2,{0x8e,0x39,0x00,0xa0,0xc9,0x69,0x72,0x3b}}

typedef struct _efi_simple_text_input_protocol efi_simple_text_input_protocol_t;

typedef efi_status_t (EFIAPI *EFI_INPUT_RESET)(IN efi_simple_text_input_protocol_t *this, IN boolean_t ext_verify);
typedef efi_status_t (EFIAPI *EFI_INPUT_READ_KEY)(IN efi_simple_text_input_protocol_t *this, OUT efi_input_key_t *key);

struct _efi_simple_text_input_protocol {
	EFI_INPUT_RESET reset;
	EFI_INPUT_READ_KEY read_key;
	efi_event_t wait_for_key;
};


/*
 * EFI SIMPLE TEXT INPUT EXT PROTOCOL
 */
#define EFI_SIMPLE_TEXT_INPUT_EX_PROTOCOL_GUID {0xdd9e7534, 0x7762, 0x4698, {0x8c, 0x14, 0xf5, 0x85, 0x17, 0xa6, 0x25, 0xaa}}


typedef struct _efi_simple_text_input_ex_protocol efi_simple_text_input_ex_protocol_t;

typedef efi_status_t (EFIAPI *EFI_INPUT_RESET_EX)(IN efi_simple_text_input_ex_protocol_t *this, IN boolean_t ext_verify);
typedef efi_status_t (EFIAPI *EFI_INPUT_READ_KEY_EX)(IN efi_simple_text_input_ex_protocol_t *this, OUT efi_key_data_t *key_data);
typedef efi_status_t (EFIAPI *EFI_SET_STATE)(IN efi_simple_text_input_ex_protocol_t *this, IN efi_key_toggle_state_t *key_toggle);
typedef efi_status_t (EFIAPI *EFI_REGISTER_KEYSTROKE_NOTIFY)(IN efi_simple_text_input_ex_protocol_t *this, IN efi_key_data_t *key_data, IN EFI_KEY_NOTIFY_FUNCTION notify_function, OUT void **notify_handle);
typedef efi_status_t (EFIAPI *EFI_UNREGISTER_KEYSTROKE_NOTIFY)(IN efi_simple_text_input_ex_protocol_t *this, IN void *notifcation_handle);


struct _efi_simple_text_input_ex_protocol {
	EFI_INPUT_RESET_EX reset;
	EFI_INPUT_READ_KEY_EX read_key_ext;
	efi_event_t wait_for_key;
	EFI_SET_STATE set_state;
	EFI_REGISTER_KEYSTROKE_NOTIFY register_key_notify;
	EFI_UNREGISTER_KEYSTROKE_NOTIFY unregister_key_notify;
};
