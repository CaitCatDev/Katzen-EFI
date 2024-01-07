#include "../efi_types.h"

#define EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_GUID {0x387477c2,0x69c7,0x11d2, {0x8e,0x39,0x00,0xa0,0xc9,0x69,0x72,0x3b}}

typedef struct _efi_simple_text_output_protocol efi_simple_text_output_protocol_t;

typedef efi_status_t (EFIAPI *EFI_TEXT_RESET)(IN efi_simple_text_output_protocol_t *this, IN boolean_t ext_verify);
typedef efi_status_t (EFIAPI *EFI_TEXT_STRING)(IN efi_simple_text_output_protocol_t *this, char16 *string);
typedef efi_status_t (EFIAPI *EFI_TEXT_TEST_STRING)(IN efi_simple_text_output_protocol_t *this, char16 *string);
typedef efi_status_t (EFIAPI *EFI_TEXT_QUERY_MODE)(IN efi_simple_text_output_protocol_t *this, IN uintn_t mode_no, OUT uintn_t *cols, OUT uintn_t *rows);
typedef efi_status_t (EFIAPI *EFI_TEXT_SET_MODE)(IN efi_simple_text_output_protocol_t *this, IN uintn_t mode_no);
typedef efi_status_t (EFIAPI *EFI_TEXT_SET_ATTRIBUTE)(IN efi_simple_text_output_protocol_t *this, IN uintn_t attribute);
typedef efi_status_t (EFIAPI *EFI_TEXT_CLEAR_SCREEN)(IN efi_simple_text_output_protocol_t *this);
typedef efi_status_t (EFIAPI *EFI_TEXT_SET_CURSOR_POSITION)(IN efi_simple_text_output_protocol_t *this, IN uintn_t col, IN uintn_t row);
typedef efi_status_t (EFIAPI *EFI_TEXT_ENABLE_CURSOR)(IN efi_simple_text_output_protocol_t *this, IN boolean_t visible);

typedef struct {
	int32_t max_mode;
	int32_t mode;
	int32_t attribute;
	int32_t cursor_col;
	int32_t cursor_row;
	boolean_t cursor_visible;
} simple_text_output_mode_t;

struct _efi_simple_text_output_protocol {
	EFI_TEXT_RESET reset;
	EFI_TEXT_STRING output_string;
	EFI_TEXT_TEST_STRING test_string;
	EFI_TEXT_QUERY_MODE query_mode;
	EFI_TEXT_SET_MODE set_mode;
	EFI_TEXT_SET_ATTRIBUTE set_attribute;
	EFI_TEXT_CLEAR_SCREEN clear_screen;
	EFI_TEXT_SET_CURSOR_POSITION set_cursor_position;
	EFI_TEXT_ENABLE_CURSOR enable_cursor;
	simple_text_output_mode_t *mode;
};

/*EFI Attributes*/
#define EFI_BLACK                              0x00
#define EFI_BLUE                               0x01
#define EFI_GREEN                              0x02
#define EFI_CYAN                               0x03
#define EFI_RED                                0x04
#define EFI_MAGENTA                            0x05
#define EFI_BROWN                              0x06
#define EFI_LIGHTGRAY                          0x07
#define EFI_BRIGHT                             0x08
#define EFI_LIGHTBLUE                          0x09
#define EFI_LIGHTGREEN                         0x0A
#define EFI_LIGHTCYAN                          0x0B
#define EFI_LIGHTRED                           0x0C
#define EFI_LIGHTMAGENTA                       0x0D
#define EFI_YELLOW                             0x0E
#define EFI_WHITE                              0x0F


#define EFI_BACKGROUND_BLACK                   0x00
#define EFI_BACKGROUND_BLUE                    0x10
#define EFI_BACKGROUND_GREEN                   0x20
#define EFI_BACKGROUND_CYAN                    0x30
#define EFI_BACKGROUND_RED                     0x40
#define EFI_BACKGROUND_MAGENTA                 0x50
#define EFI_BACKGROUND_BROWN                   0x60
#define EFI_BACKGROUND_LIGHTGRAY               0x70
