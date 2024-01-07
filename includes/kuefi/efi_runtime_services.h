#pragma once

#include "efi_memory.h"
#include "efi_types.h"
#include "efi_time.h"
#include "efi_table_header.h"

typedef enum {
	EfiResetCold,
	EfiResetWarm,
	EfiResetShutdown,
	EfiResetPlatformSpecific
} efi_reset_t;

typedef struct {
	uint64_t Length;
	union {
		efi_physical_addr_t DataBlock;
		efi_physical_addr_t ContinuationPointer;
	} u;
} efi_capsule_block_descriptor_t;

typedef struct {
	efi_guid_t CapsuleGuid;
	uint32_t HeaderSize;
	uint32_t Flags;
	uint32_t CapsuleImageSize;
} efi_capsule_header_t;

#define EFI_MEMORY_RANGE_CAPSULE_GUID \
   { 0xde9f0ec, 0x88b6, 0x428f, \
    { 0x97, 0x7a, 0x25, 0x8f, 0x1d, 0xe, 0x5e, 0x72 } }

#define CAPSULE_FLAGS_PERSIST_ACROSS_RESET 0x00010000
#define CAPSULE_FLAGS_POPULATE_SYSTEM_TABLE 0x00020000
#define CAPSULE_FLAGS_INITIATE_RESET 0x00040000

typedef struct {
	uint32_t CapsuleArrayNumber;
	void *CapsulePtr[1];
} efi_capsule_table_t;

typedef struct {
	efi_physical_addr_t Address;
	uint64_t Length;
} efi_memory_range_t;

typedef struct {
	efi_capsule_header_t Header;
	uint32_t OsRequestedMemoryType;
	uint64_t NumberOfMemoryRanges;
	efi_memory_range_t MemoryRanges[];
} efi_memory_range_capsule_t;

typedef struct {
	uint64_t FirmwareMemoryRequirement;
	uint64_t NumberOfMemoryRanges;
} efi_memory_range_capsule_result_t;

#define EFI_OPTIONAL_PTR 0x00000001

#define EFI_RUNTIME_SERVICES_SIGNATURE 0x56524553544e5552
#define EFI_RUNTIME_SERVICES_REVISION EFI_SPECIFICATION_VERSION

typedef efi_status_t (EFIAPI *EFI_GET_VARIABLE)(IN char16 *var_name, IN efi_guid_t *vendor_guid, OUT uint32_t *attributes OPTIONAL, IN OUT uintn_t *size, OUT void *data OPTIONAL);
typedef efi_status_t (EFIAPI *EFI_GET_NEXT_VARIABLE_NAME)(IN OUT uintn_t *VariableNameSize, IN OUT char16 *VariableName, IN OUT efi_guid_t *VendorGuid);
typedef efi_status_t (EFIAPI *EFI_SET_VARIABLE)(IN char16 *VariableName, IN efi_guid_t *VendorGuid, IN uint32_t Attributes, IN uintn_t DataSize, IN void *Data);
typedef efi_status_t (EFIAPI *EFI_QUERY_VARIABLE_INFO)(IN uint32_t Attributes, OUT uint64_t *MaximumVariableStorageSize, OUT uint64_t *RemainingVariableStorageSize, OUT uint64_t *MaximumVariableSize);

/*Time Functions*/
typedef efi_status_t (EFIAPI *EFI_GET_TIME)(OUT efi_time_t *time, OUT efi_time_capabilities *capabilities OPTIONAL);
typedef efi_status_t (EFIAPI *EFI_SET_TIME)(IN efi_time_t *time);
typedef efi_status_t (EFIAPI *EFI_GET_WAKEUP_TIME)(OUT boolean_t *enabled, OUT boolean_t *pending, OUT efi_time_t *time);
typedef efi_status_t (EFIAPI *EFI_SET_WAKEUP_TIME)(IN boolean_t enable, IN efi_time_t *time OPTIONAL);

/*VMA FUNCTIONS*/
typedef efi_status_t (EFIAPI *EFI_SET_VIRTUAL_ADDRESS_MAP)(IN uintn_t MemoryMapSize, IN uintn_t DescriptorSize, IN uint32_t DescriptorVersion, IN efi_memory_descriptor_t *VirtualMap);
typedef efi_status_t (EFIAPI *EFI_CONVERT_POINTER)(IN uintn_t DebugDisposition, IN void **Address);
typedef void (EFIAPI *EFI_RESET_SYSTEM)(IN efi_reset_t rest_type, IN efi_status_t ResetStatus, IN uintn_t DataSize, IN void *ResetData OPTIONAL);
typedef efi_status_t (EFIAPI *EFI_GET_NEXT_HIGH_MONO_COUNT)(OUT uint32_t *HightCount);

/*Capsule Functions*/
typedef efi_status_t (EFIAPI *EFI_UPDATE_CAPSULE)(IN efi_capsule_header_t **CapsuleHeaderArray, IN uintn_t CapsuleCount, IN efi_physical_addr_t ScatterGatherList OPTIONAL);
typedef efi_status_t (EFIAPI *EFI_QUERY_CAPSULE_CAPABILITIES)(IN efi_capsule_header_t **CapsuleHeaderArray, IN uintn_t CapsuleCount, OUT uint64_t *MaximumCapsuleSize, OUT efi_reset_t *ResetType);



typedef struct {
	efi_table_header_t hdr;

	/*
	 * Time Services
	 */
	EFI_GET_TIME get_time;
	EFI_SET_TIME set_time;
	EFI_GET_WAKEUP_TIME get_wakeup_time;
	EFI_SET_WAKEUP_TIME set_wakeup_time;

	/*
	 * VMA Services
	 */
	EFI_SET_VIRTUAL_ADDRESS_MAP set_virtual_address_map;
	EFI_CONVERT_POINTER convert_pointer;

	/*
	 * Variable Services
	 */
	EFI_GET_VARIABLE get_variable;
	EFI_GET_NEXT_VARIABLE_NAME get_next_variable_name;
	EFI_SET_VARIABLE set_variable;

	/*
	 * Misc Runtime Services
	 */
	EFI_GET_NEXT_HIGH_MONO_COUNT get_next_high_monotonic_count;
	EFI_RESET_SYSTEM reset_system;

	/*
	 * UEFI 2.0 Capsule Services
	 */
	EFI_UPDATE_CAPSULE update_capsule;
	EFI_QUERY_CAPSULE_CAPABILITIES query_capsule_capabilities;

	/* 
	 * UEFI 2.0 Misc Runtime Services 
	 */
	EFI_QUERY_VARIABLE_INFO query_variable_info;
} efi_runtime_services_t;
