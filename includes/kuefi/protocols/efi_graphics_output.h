#pragma once

#include "../efi_types.h"
#include "../efi_memory.h"

#define EFI_GRAPHICS_OUTPUT_PROTOCOL_GUID {0x9042a9de,0x23dc,0x4a38,{0x96,0xfb,0x7a,0xde,0xd0,0x80,0x51,0x6a}}

typedef struct _efi_graphics_output_protcol efi_graphics_output_protocol_t;

typedef struct {
	uint32_t rmask;
	uint32_t gmask;
	uint32_t bmask;
	uint32_t reserved_mask;
} efi_pixel_bitmask_t;

typedef enum {
	PixelRedGreenBlueReserved8BitPerColor,
	PixelBlueGreenRedReserved8BitPerColor,
	PixelBitMask,
	PixelBltOnly,
	PixelFormatMax
} efi_graphics_pixel_format_t;

typedef enum {
	EfiBltVideoFill,
	EfiBltVideoToBltBuffer,
	EfiBltBufferToVideo,
	EfiBltVideoToVideo,
	EfiGraphicsOutputBltOperationMax
} efi_graphics_output_blt_ops;

typedef struct {
	uint32_t version;
	uint32_t horiz_resolution;
	uint32_t vert_resolution;
	efi_graphics_pixel_format_t format;
	efi_pixel_bitmask_t pixel_info;
	uint32_t ppsl;
} efi_graphics_output_mode_info_t;

typedef struct {
	uint32_t max_mode;
	uint32_t mode;
	efi_graphics_output_mode_info_t *info;
	uintn_t size_of_info;
	efi_physical_addr_t fb_base;
	uintn_t fb_size;
} efi_graphics_output_protocol_mode_info_t;

typedef struct {
	uint8_t blue;
	uint8_t green;
	uint8_t red;
	uint8_t reserved;
} efi_graphics_output_blt_pixel;



typedef efi_status_t (EFIAPI *EFI_GRAPHICS_OUTPUT_PROTOCOL_QUERY_MODE) (IN efi_graphics_output_protocol_t *this, uint32_t mode_no, OUT uintn_t *info_size,  OUT efi_graphics_output_mode_info_t **info);
typedef efi_status_t (EFIAPI *EFI_GRAPHICS_OUTPUT_PROTOCOL_SET_MODE)(IN efi_graphics_output_protocol_t *this, IN uint32_t mode_no);
typedef efi_status_t (EFIAPI *EFI_GRAPHICS_OUTPUT_PROTOCOL_BLT) (IN efi_graphics_output_protocol_t *this, IN OUT efi_graphics_output_blt_pixel *blt_buffer OPTIONAL, IN efi_graphics_output_blt_ops blt_op, IN uintn_t src_x, IN uintn_t src_y, IN uintn_t dst_x, IN uintn_t dst_y, IN uintn_t width, IN uintn_t height, IN uintn_t delta OPTIONAL);


struct _efi_graphics_output_protcol {
	EFI_GRAPHICS_OUTPUT_PROTOCOL_QUERY_MODE query_mode;
	EFI_GRAPHICS_OUTPUT_PROTOCOL_SET_MODE set_mode;
	EFI_GRAPHICS_OUTPUT_PROTOCOL_BLT blt;
	efi_graphics_output_protocol_mode_info_t *mode;
};
