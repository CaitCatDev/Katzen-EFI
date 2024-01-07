#pragma once

#include "kuefi/efi_table_header.h"
#include "kuefi/protocols/efi_device_path.h"
typedef struct _efi_boot_services efi_boot_services_t;

#include "./efi_types.h"
#include "./efi_event.h"
#include "./efi_memory.h"
#include "./efi_system_table.h"
#include "./efi_table_header.h"

#include "./protocols/efi_device_path.h"


typedef enum {
   TimerCancel,
   TimerPeriodic,
   TimerRelative
} efi_timer_delay_t;

#define TPL_APPLICATION 4
#define TPL_CALLBACK 8
#define TPL_NOTIFY 16
#define TPL_HIGH_LEVEL 31

typedef enum {
   EFI_NATIVE_INTERFACE
} efi_interface_t;

typedef enum {
   AllHandles,
   ByRegisterNotify,
   ByProtocol
} efi_locate_search_t;

#define EFI_OPEN_PROTOCOL_BY_HANDLE_PROTOCOL   0x00000001
#define EFI_OPEN_PROTOCOL_GET_PROTOCOL         0x00000002
#define EFI_OPEN_PROTOCOL_TEST_PROTOCOL        0x00000004
#define EFI_OPEN_PROTOCOL_BY_CHILD_CONTROLLER  0x00000008
#define EFI_OPEN_PROTOCOL_BY_DRIVER            0x00000010
#define EFI_OPEN_PROTOCOL_EXCLUSIVE            0x00000020

typedef struct {
   efi_handle_t AgentHandle;
   efi_handle_t ControllerHandle;
   uint32_t Attributes;
   uint32_t OpenCount;
} efi_open_protocol_info_t;


#define EFI_BOOT_SERVICES_SIGNATURE 0x56524553544f4f42
#define EFI_BOOT_SERVICES_REVISION EFI_SPECIFICATION_VERSION

/*Event and TPL Functions*/
typedef efi_status_t (EFIAPI *EFI_CREATE_EVENT)(IN uint32_t Type, IN efi_tpl_t NotifyTpl, IN EFI_EVENT_NOTIFY OPTIONAL, IN void *NotifyContext OPTIONAL, OUT efi_event_t *Event);
typedef efi_status_t (EFIAPI *EFI_CREATE_EVENT_EX)(IN uint32_t Type, IN efi_tpl_t NotifyTpl, IN EFI_EVENT_NOTIFY OPTIONAL, IN void *NotifyContext OPTIONAL, OUT efi_event_t *Event);
typedef efi_status_t (EFIAPI *EFI_CLOSE_EVENT)(IN efi_event_t Event);
typedef efi_status_t (EFIAPI *EFI_SIGNAL_EVENT)(IN efi_event_t Event);
typedef efi_status_t (EFIAPI *EFI_WAIT_FOR_EVENT)(IN uintn_t NumberOfEvents, IN efi_event_t *Event, OUT uintn_t *Index);
typedef efi_status_t (EFIAPI *EFI_CHECK_EVENT)(IN efi_event_t Event);
typedef efi_status_t (EFIAPI *EFI_SET_TIMER)(IN efi_event_t Event, IN efi_timer_delay_t Type, IN uint64_t TriggerTime);
typedef efi_status_t (EFIAPI *EFI_RAISE_TPL)(IN efi_tpl_t NewTpl);
typedef efi_status_t (EFIAPI *EFI_RESTORE_TPL)(IN efi_tpl_t OldTpl);

/*Memory Allocation Functions*/
typedef efi_status_t (EFIAPI *EFI_ALLOCATE_PAGES)(IN efi_allocate_t Type, IN efi_memory_t MemoryType, IN uintn_t Pages, IN OUT efi_physical_addr_t *Memory);
typedef efi_status_t (EFIAPI *EFI_FREE_PAGES)(IN efi_physical_addr_t Memory, IN uintn_t Pages);
typedef efi_status_t (EFIAPI *EFI_GET_MEMORY_MAP)(IN OUT uintn_t *MemoryMapSize, OUT efi_memory_descriptor_t *MemoryMap, OUT uintn_t *MapKey, OUT uintn_t *DescriptorSize, OUT uint32_t *DescriptorVersion);
typedef efi_status_t (EFIAPI *EFI_ALLOCATE_POOL)(IN efi_memory_t PoolType, IN uintn_t Size, OUT void **Buffer);
typedef efi_status_t (EFIAPI *EFI_FREE_POOL)(IN void *Buffer);

/*Protocols Services Functions*/
typedef efi_status_t (EFIAPI *EFI_INSTALL_PROTOCOL_INTERFACE)(IN OUT efi_handle_t *Handle, IN efi_guid_t *Protocol, IN efi_interface_t, IN void *Interface);
typedef efi_status_t (EFIAPI *EFI_UNINSTALL_PROTOCOL_INTERFACE)(IN efi_handle_t *Handle, IN efi_guid_t *Protocol, IN void *Interface);
typedef efi_status_t (EFIAPI *EFI_REINSTALL_PROTOCOL_INTERFACE)(IN efi_handle_t *Handle, IN efi_guid_t *Protocol, IN void *OldInterface, IN void *NewInterface);
typedef efi_status_t (EFIAPI *EFI_REGISTER_PROTOCOL_NOTIFY)(IN efi_guid_t *Protocol, IN efi_event_t Event, OUT void **Registration);
typedef efi_status_t (EFIAPI *EFI_LOCATE_HANDLE)(IN efi_locate_search_t SearchType, IN efi_guid_t *Protocol, IN void *SearchKey, IN OUT uintn_t *BufferSize, OUT efi_handle_t *Buffer);
typedef efi_status_t (EFIAPI *EFI_HANDLE_PROTOCOL)(IN efi_handle_t Handle, IN efi_guid_t *Protocol, OUT void **Interface);
typedef efi_status_t (EFIAPI *EFI_LOCATE_DEVICE_PATH)(IN efi_guid_t *Protocol, IN OUT efi_device_path_protocol_t **DevicePath, OUT efi_handle_t *Device);
typedef efi_status_t (EFIAPI *EFI_OPEN_PROTOCOL)(IN efi_handle_t Handle, IN efi_guid_t *Protocol, OUT void **Interface OPTIONAL, IN efi_handle_t AgentHandle, IN efi_handle_t ControllerHandle, IN uint32_t Attributes);
typedef efi_status_t (EFIAPI *EFI_CLOSE_PROTOCOL)(IN efi_handle_t Handle, IN efi_guid_t *Protocol, IN efi_handle_t AgentHandle, IN efi_handle_t ControllerHandle);
typedef efi_status_t (EFIAPI *EFI_OPEN_PROTOCOL_INFORMATION)(IN efi_handle_t Handle, IN efi_guid_t *Protocol, OUT efi_open_protocol_info_t **EntryBuffer, OUT uintn_t *EntryCount);
typedef efi_status_t (EFIAPI *EFI_CONNECT_CONTROLLER)(IN efi_handle_t ControllerHandle, IN efi_handle_t *DriverImageHandle, IN efi_device_path_protocol_t *RemainingDevicePath, IN boolean_t Recursive);
typedef efi_status_t (EFIAPI *EFI_DISCONNECT_CONTROLLER)(IN efi_handle_t ControllerHandle, IN efi_handle_t DriverImageHandle, IN efi_handle_t ChildHandle OPTIONAL);
typedef efi_status_t (EFIAPI *EFI_PROTOCOLS_PER_HANDLE)(IN efi_handle_t Handle, OUT efi_guid_t ***ProtocolBuffer, OUT uintn_t *ProtocolBufferCount);
typedef efi_status_t (EFIAPI *EFI_LOCATE_HANDLE_BUFFER)(IN efi_locate_search_t SearchType, IN efi_guid_t *Protocol OPTIONAL, IN void *SearchKey OPTIONAL, OUT uintn_t *NoHandles, OUT efi_handle_t **Buffer);
typedef efi_status_t (EFIAPI *EFI_LOCATE_PROTOCOL)(IN efi_guid_t *Protocol, IN void *Registration OPTIONAL, OUT void **Interface);
typedef efi_status_t (EFIAPI *EFI_INSTALL_MULTIPLE_PROTOCOL_INTERFACES)(IN OUT efi_handle_t *Handle, ...);
typedef efi_status_t (EFIAPI *EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES)(IN OUT efi_handle_t *Handle, ...);

/*EFI Image Services*/
typedef efi_status_t (EFIAPI *EFI_IMAGE_LOAD)(IN boolean_t BootPolicy, IN efi_handle_t ParentImageHandle, IN efi_device_path_protocol_t *DevicePath OPTIONAL, IN void *SourceBuffer OPTIONAL, IN uintn_t SourceSize, OUT efi_handle_t *ImageHandle);
typedef efi_status_t (EFIAPI *EFI_IMAGE_START)(IN efi_handle_t ImageHandle, OUT uintn_t *ExitDataSize, OUT char16 **ExitData OPTIONAL);
typedef efi_status_t (EFIAPI *EFI_IMAGE_UNLOAD)(IN efi_handle_t ImageHandle);
typedef efi_status_t (EFIAPI *EFI_IMAGE_ENTRY_POINT)(IN efi_handle_t ImageHandle, IN efi_system_table_t *SystemTable);
typedef efi_status_t (EFIAPI *EFI_EXIT)(IN efi_handle_t ImageHandle, IN efi_status_t ExitStatus, IN uintn_t ExitDataSize, IN char16 *ExitData OPTIONAL);
typedef efi_status_t (EFIAPI *EFI_EXIT_BOOT_SERVICES)(IN efi_handle_t ImageHandle, IN uintn_t MapKey);

/*Miscellaneous Functions*/
typedef efi_status_t (EFIAPI *EFI_SET_WATCHDOG_TIMER)(IN uintn_t Timeout, IN uint64_t WatchdogCode, IN uintn_t DataSize, IN char16 *WatchdogData OPTIONAL);
typedef efi_status_t (EFIAPI *EFI_STALL)(IN uintn_t Microseconds);
typedef efi_status_t (EFIAPI *EFI_COPY_MEM)(IN void *Destination, IN void *Source, IN uintn_t Length);
typedef efi_status_t (EFIAPI *EFI_SET_MEM)(IN void *Buffer, IN uintn_t Size, IN uint8_t Value);
typedef efi_status_t (EFIAPI *EFI_GET_NEXT_MONOTONIC_COUNT)(OUT uint64_t *Count);
typedef efi_status_t (EFIAPI *EFI_INSTALL_CONFIGURATION_TABLE)(IN efi_guid_t *Guid, IN void *Table);
typedef efi_status_t (EFIAPI *EFI_CALCULATE_CRC32)(IN void *Data, IN uintn_t DataSize, OUT uint32_t *Crc32);

struct _efi_boot_services {
	efi_table_header_t hdr;

	/*
	 * TPL Services
	 * EFI 1.0+
	 */
	EFI_RAISE_TPL raise_tpl;
	EFI_RESTORE_TPL restore_tpl;

	/*
	 * Memory Services
	 * EFI 1.0+
	 */
	EFI_ALLOCATE_PAGES allocate_pages;
	EFI_FREE_PAGES free_pages;
	EFI_GET_MEMORY_MAP get_memory_map;
	EFI_ALLOCATE_POOL allocate_pool;
	EFI_FREE_POOL free_pool;

	/*
	 * Event & Timer Services
	 * EFI 1.0+
	 */
	EFI_CREATE_EVENT create_event;
	EFI_SET_TIMER set_timer;
	EFI_WAIT_FOR_EVENT wait_for_event;
	EFI_SIGNAL_EVENT signal_event;
	EFI_CLOSE_EVENT close_event;
	EFI_CHECK_EVENT check_event;
	
	/*
	 * Protocol Handler Services 
	 * EFI 1.0+
	 */
	EFI_INSTALL_PROTOCOL_INTERFACE install_protocol_interface;
	EFI_REINSTALL_PROTOCOL_INTERFACE reinstall_protocol_interface;
	EFI_UNINSTALL_PROTOCOL_INTERFACE uninstall_protocol_interface;
	EFI_HANDLE_PROTOCOL handle_protocol;
	void *Reserved;
	EFI_REGISTER_PROTOCOL_NOTIFY register_protocol_notify;
	EFI_LOCATE_HANDLE locate_handle;
	EFI_LOCATE_DEVICE_PATH locate_device_path;
	EFI_INSTALL_CONFIGURATION_TABLE install_configuration_table;

	/*
	 * Image Services
	 * EFI 1.0+
	 */
	EFI_IMAGE_LOAD load_image;
	EFI_IMAGE_START start_image;
	EFI_EXIT exit;
	EFI_IMAGE_UNLOAD unload_image;
	EFI_EXIT_BOOT_SERVICES exit_boot_services;

	/*
	 * Miscellaneous Services
	 * EFI 1.0+
	 */
	EFI_GET_NEXT_MONOTONIC_COUNT get_next_monotonic_count;
	EFI_STALL stall;
	EFI_SET_WATCHDOG_TIMER *set_watchdog_timer;

	/*
	 * Driver Support Services
	 * EFI 1.1+
	 */
	EFI_CONNECT_CONTROLLER connect_controller;
	EFI_DISCONNECT_CONTROLLER disconnect_controller;

	/*
	 * Open and Close Protocol Services
	 * EFI 1.1+
	 */
	EFI_OPEN_PROTOCOL open_protocol;
	EFI_CLOSE_PROTOCOL close_protocol;
	EFI_OPEN_PROTOCOL_INFORMATION open_protocol_information;

	/*
	 * Library Services
	 * EFI 1.1+
	 */
	EFI_PROTOCOLS_PER_HANDLE protocols_per_handle;
	EFI_LOCATE_HANDLE_BUFFER locate_handle_buffer;
	EFI_LOCATE_PROTOCOL locate_protocol;
	EFI_INSTALL_MULTIPLE_PROTOCOL_INTERFACES install_multiple_protocol_interfaces;
	EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES uninstall_multiple_protocol_interfaces;

	/*
	 * 32bit CRC Services
	 * EFI 1.1+
	 */
	EFI_CALCULATE_CRC32 calculate_crc32;

	/* 
	 * Miscellaneous 1.1 Services 
	 * EFI 1.1+
	 */
	EFI_COPY_MEM copy_mem;
	EFI_SET_MEM set_mem;
	EFI_CREATE_EVENT_EX create_event_ext;
};
