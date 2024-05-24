/* Flash OS Routines (Automagically Generated)
 * Copyright (c) 2009-2015 ARM Limited
 */
#include "flash_blob.h"

static const uint32_t flash_code[] = {
    0xE00ABE00, 0x062D780D, 0x24084068, 0xD3000040, 0x1E644058, 0x1C49D1FA, 0x2A001E52, 0x4770D1F2,
    0x4770BA40, 0x4770BAC0, 0x47702000, 0x47702000, 0x482DB508, 0x492B2200, 0x60819200, 0x07C96A01,
    0x6A01D0FC, 0xD1FC07C9, 0x20006082, 0xF040BD08, 0x48254100, 0x6A016081, 0xD0FC07C9, 0x07C96A01,
    0x6081D1FC, 0x47704608, 0x2300B51F, 0x3102E9CD, 0x2404491D, 0x604860CC, 0xE01C9803, 0x93019300,
    0x9C019302, 0x0B01F812, 0x40A000E4, 0x43209C02, 0x98019002, 0x90011C40, 0xDBF22804, 0x60089802,
    0x1D009800, 0x28109000, 0x6A08DBE9, 0xD5FC0700, 0x38109803, 0x28009003, 0x60CBDCE0, 0x60C82008,
    0xB00460CB, 0xBD102000, 0x4604B570, 0xE0052300, 0x78265CD5, 0xD10342B5, 0x1C641C5B, 0xD3F7428B,
    0xBD704418, 0x8007FFFF, 0x4001F000, 0x00000000
};

const program_target_t flash_algo = {
    0x20000029,  // Init
    0x2000002D,  // UnInit
    0x20000031,  // EraseChip
    0x2000004F,  // EraseSector
    0x20000069,  // ProgramPage

    // BKPT : start of blob + 1
    // RSB  : address to access global/static data
    // RSP  : stack pointer
    {
        0x20000001,
        0x200000EC,
        0x200014F0
    },

    0x200000F0,  // mem buffer location
    0x20000000,  // location to write prog_blob in target RAM
    sizeof(flash_code),  // prog_blob size
    flash_code,  // address of prog_blob
    0x00001000,  // ram_to_flash_bytes_to_be_written
};
