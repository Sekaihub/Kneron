#ifndef _GPT_H_
#define _GPT_H_

#define ENTRY_COUNT		4
#define GPT_PAGE_SIZE		ENTRY_COUNT * 128

typedef u16 efi_char16_t;

typedef struct {
	u8 b[16];
} efi_guid_t __aligned(8);

typedef union _gpt_entry_attributes {
	struct {
		u64 required_to_function:1;
		u64 no_block_io_protocol:1;
		u64 legacy_bios_bootable:1;
		u64 reserved:45;
		u64 type_guid_specific:16;
	} fields;
	unsigned long long raw;
} __packed gpt_entry_attributes;

#define PARTNAME_SZ     (72 / sizeof(efi_char16_t))
typedef struct _gpt_entry {
	efi_guid_t partition_type_guid;
	efi_guid_t unique_partition_guid;
	__le64 starting_lba;
	__le64 ending_lba;
	gpt_entry_attributes attributes;
	efi_char16_t partition_name[PARTNAME_SZ];
} __packed gpt_entry;
#endif /* _GPT_H_ */
