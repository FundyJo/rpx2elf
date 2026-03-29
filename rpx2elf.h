// Copyright (C) 2015       Hykem <hykem@hotmail.com>
// Licensed under the terms of the GNU GPL, version 3
// http://www.gnu.org/licenses/gpl-3.0.txt

#ifndef RPX2ELF_H
#define RPX2ELF_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "zlib.h"

// Type definitions
typedef unsigned long long u64;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef long long sint64_t;
typedef int sint32_t;
typedef short sint16_t;
typedef char sint8_t;

typedef u64 uint64_t;
typedef u32 uint32_t;
typedef u16 uint16_t;
typedef u8 uint8_t;

// RPL/RPX specific flags and section types
#define SHF_RPL_ZLIB 		0x08000000

#define SHT_PROGBITS        0x00000001
#define SHT_SYMTAB          0x00000002
#define SHT_STRTAB          0x00000003
#define SHT_RELA            0x00000004
#define SHT_NOBITS          0x00000008

#define SHT_RPL_EXPORTS     0x80000001
#define SHT_RPL_IMPORTS     0x80000002
#define SHT_RPL_CRCS        0x80000003
#define SHT_RPL_FILEINFO 	0x80000004

// ELF program header constants
#define PT_LOAD             0x00000001

#define PF_X                0x00000001
#define PF_W                0x00000002
#define PF_R                0x00000004

// ELF structures
typedef struct {
	uint8_t  e_ident[0x10];
	uint16_t e_type;
	uint16_t e_machine;
	uint32_t e_version;
	uint32_t e_entry;
	uint32_t e_phoff;
	uint32_t e_shoff;
	uint32_t e_flags;
	uint16_t e_ehsize;
	uint16_t e_phentsize;
	uint16_t e_phnum;
	uint16_t e_shentsize;
	uint16_t e_shnum;
	uint16_t e_shstrndx;
} Elf32_Ehdr;

typedef struct {
	uint32_t sh_name;
	uint32_t sh_type;
	uint32_t sh_flags;
	uint32_t sh_addr;
	uint32_t sh_offset;
	uint32_t sh_size;
	uint32_t sh_link;
	uint32_t sh_info;
	uint32_t sh_addralign;
	uint32_t sh_entsize;
} Elf32_Shdr;

typedef struct {
	uint32_t p_type;
	uint32_t p_offset;
	uint32_t p_vaddr;
	uint32_t p_paddr;
	uint32_t p_filesz;
	uint32_t p_memsz;
	uint32_t p_flags;
	uint32_t p_align;
} Elf32_Phdr;

typedef struct {
	uint32_t st_name;
	uint32_t st_value;
	uint32_t st_size;
	uint8_t  st_info;
	uint8_t  st_other;
	uint16_t st_shndx;
} Elf32_Sym;

typedef struct {
	uint32_t r_offset;
	uint32_t r_info;
	sint32_t r_addend;
} Elf32_Rela;

// RPL file information structure
typedef struct {
	uint32_t magic_version;
	uint32_t mRegBytes_Text;
	uint32_t mRegBytes_TextAlign;
	uint32_t mRegBytes_Data;
	uint32_t mRegBytes_DataAlign;
	uint32_t mRegBytes_LoaderInfo;
	uint32_t mRegBytes_LoaderInfoAlign;
	uint32_t mRegBytes_Temp;
	uint32_t mTrampAdj;
	uint32_t mSDABase;
	uint32_t mSDA2Base;
	uint32_t mSizeCoreStacks;
	uint32_t mSrcFileNameOffset;
	uint32_t mFlags;
	uint32_t mSysHeapBytes;
	uint32_t mTagsOffset;
} Rpl_Fileinfo;

// Utility function declarations
u8 be8(u8 *p);
u16 be16(u8 *p);
u32 be32(u8 *p);
u64 be64(u8 *p);

u16 se16(u16 i);
u32 se32(u32 i);
u64 se64(u64 i);

int inflate_data(u8 *in, u32 in_len, u8 *out, u32 out_len);

// Conversion function
int convert_rpl(FILE *in, FILE *out);

#endif // RPX2ELF_H