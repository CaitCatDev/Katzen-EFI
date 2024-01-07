#pragma once

#include "../efi_types.h"
#include "../efi_time.h"

#define EFI_FILE_INFO_ID {0x09576e92,0x6d3f,0x11d2,{0x8e,0x39,0x00,0xa0,0xc9,0x69,0x72,0x3b}}
#define EFI_FILE_SYSTEM_INFO_ID {0x09576e93,0x6d3f,0x11d2,{0x8e,0x39,0x00,0xa0,0xc9,0x69,0x72,0x3b}}
#define EFI_FILE_SYSTEM_VOLUME_LABEL_ID {0xdb47d7d3,0xfe81,0x11d3,{0x9a,0x35,0x00,0x90,0x27,0x3f,0xC1,0x4d}}

#define EFI_FILE_PROTOCOL_REVISION 0x00010000
#define EFI_FILE_PROTOCOL_REVISION2  0x00020000
#define efi_file_protocol_t_LATEST_REVISION efi_file_protocol_t_REVISION2

#define EFI_FILE_MODE_READ 0x0000000000000001
#define EFI_FILE_MODE_WRITE 0x0000000000000002
#define EFI_FILE_MODE_CREATE 0x800000000000000

#define EFI_FILE_READ_ONLY 0x0000000000000001
#define EFI_FILE_HIDDEN 0x0000000000000002
#define EFI_FILE_SYSTEM 0x0000000000000004
#define EFI_FILE_RESERVED 0x0000000000000008
#define EFI_FILE_DIRECTORY 0x0000000000000010
#define EFI_FILE_ARCHIVE 0x0000000000000020
#define EFI_FILE_VALID_ATTR 0x0000000000000037

typedef struct {
	efi_event_t event;
	efi_status_t status;
	uintn_t buffer_size;
	void *buffer;
} efi_file_io_token_t;

typedef struct {
	uint64_t size;
	uint64_t file_size;
	uint64_t physical_size;
	efi_time_t create_time;
	efi_time_t access_time;
	efi_time_t modify_time;
	uint64_t attribute;
	char16 file_name[];
} efi_file_info_t;

typedef struct {
	uint64_t size;
	boolean_t read_only;
	uint64_t volume_size;
	uint64_t free_space;
	uint32_t block_size;
	char16 volume_label[];
} efi_file_system_info_t;

typedef struct {
	char16 *label;
} EFI_FILE_SYSTEM_VOLUME_LABEL;

typedef struct _efi_file_protocol efi_file_protocol_t;

typedef efi_status_t (EFIAPI *EFI_FILE_OPEN)(IN efi_file_protocol_t *this, OUT efi_file_protocol_t **new_handle, IN char16 *file_name, IN uint64_t mode, IN uint64_t attributes);
typedef efi_status_t (EFIAPI *EFI_FILE_CLOSE)(IN efi_file_protocol_t *this);
typedef efi_status_t (EFIAPI *EFI_FILE_DELETE)(IN efi_file_protocol_t *this);
typedef efi_status_t (EFIAPI *EFI_FILE_READ)(IN efi_file_protocol_t *this, IN OUT uintn_t *buffer_size, OUT void *buffer);
typedef efi_status_t (EFIAPI *EFI_FILE_WRITE)(IN efi_file_protocol_t *this, IN OUT uintn_t *buffer_size, IN void *buffer);
typedef efi_status_t (EFIAPI *EFI_FILE_OPEN_EX)(IN efi_file_protocol_t *this, OUT efi_file_protocol_t **new_handle, IN char16 *file_name, IN uint64_t mode, IN uint64_t attributes, IN OUT efi_file_io_token_t *token);
typedef efi_status_t (EFIAPI *EFI_FILE_READ_EX)(IN efi_file_protocol_t *this, IN OUT efi_file_io_token_t *token);
typedef efi_status_t (EFIAPI *EFI_FILE_WRITE_EX)(IN efi_file_protocol_t *this, IN OUT efi_file_io_token_t *token);
typedef efi_status_t (EFIAPI *EFI_FILE_FLUSH_EX)(IN efi_file_protocol_t *this, IN OUT efi_file_io_token_t *token);
typedef efi_status_t (EFIAPI *EFI_FILE_SET_POSITION)(IN efi_file_protocol_t *this, IN uint64_t pos);
typedef efi_status_t (EFIAPI *EFI_FILE_GET_POSITION)(IN efi_file_protocol_t *this, OUT uint64_t *pos);
typedef efi_status_t (EFIAPI *EFI_FILE_GET_INFO)(IN efi_file_protocol_t *this, IN efi_guid_t *info_type, IN OUT uintn_t *buffer_size, OUT void *buffer);
typedef efi_status_t (EFIAPI *EFI_FILE_SET_INFO)(IN efi_file_protocol_t *this, IN efi_guid_t *info_type, IN uintn_t buffer_size, IN void *buffer);
typedef efi_status_t (EFIAPI *EFI_FILE_FLUSH)(IN efi_file_protocol_t *this);


struct _efi_file_protocol {
	uint64_t revision;
	EFI_FILE_OPEN open;
	EFI_FILE_CLOSE close;
	EFI_FILE_DELETE delete;
	EFI_FILE_READ read;
	EFI_FILE_WRITE write;
	EFI_FILE_GET_POSITION get_position;
	EFI_FILE_SET_POSITION set_position;
	EFI_FILE_GET_INFO get_info;
	EFI_FILE_SET_INFO set_info;
	EFI_FILE_FLUSH flush;
	EFI_FILE_OPEN_EX open_ext; // Added for revision 2
	EFI_FILE_READ_EX read_ext; // Added for revision 2
	EFI_FILE_WRITE_EX write_ext; // Added for revision 2
	EFI_FILE_FLUSH_EX flush_ext; // Added for revision 2
};

