#pragma once

#include "../efi_types.h"

#define EFI_BLOCK_IO_PROTOCOL_GUID {0x964e5b21,0x6459,0x11d2,{0x8e,0x39,0x00,0xa0,0xc9,0x69,0x72,0x3b}}

typedef struct _efi_block_io_protocol efi_block_io_protocol_t;

typedef struct {
	uint32_t id;
	boolean_t removable;
	boolean_t present;
	boolean_t logical_part;
	boolean_t read_only;
	boolean_t write_caching;
	uint32_t block_size;
	uint32_t ioalign;

	efi_lba_t last_block;

	/*Revision 2.0+*/
	efi_lba_t lowest_aligned_lba;
	uint32_t logical_blocks_per_physical_block;
	
	/*Revision 3.0+*/
	uint32_t optimal_transfer_length_granularity;
} efi_block_io_media_t;

typedef efi_status_t (EFIAPI *EFI_BLOCK_RESET)(IN efi_block_io_protocol_t *this, IN boolean_t ext_verify);
typedef efi_status_t (EFIAPI *EFI_BLOCK_READ)(IN efi_block_io_protocol_t *this, IN uint32_t mediaid, IN efi_lba_t lba, IN uintn_t buffer_size, OUT void *buffer);
typedef efi_status_t (EFIAPI *EFI_BLOCK_WRITE)(IN efi_block_io_protocol_t *this, IN uint32_t mediaid, IN efi_lba_t lba, IN uintn_t buffer_size, IN void *buffer);
typedef efi_status_t (EFIAPI *EFI_BLOCK_FLUSH)(IN efi_block_io_protocol_t *this);

struct _efi_block_io_protocol {
	uint64_t revision;
	efi_block_io_media_t *media;
	EFI_BLOCK_RESET reset;
	EFI_BLOCK_READ read_blocks;
	EFI_BLOCK_WRITE write_blocks;
	EFI_BLOCK_FLUSH flush_blocks;
};
