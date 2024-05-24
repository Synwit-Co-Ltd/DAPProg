/* Flash OS Routines (Automagically Generated)
 * Copyright (c) 2009-2015 ARM Limited
 */
#include "flash_blob.h"

static const uint32_t flash_code[] = {
    0xE00ABE00, 0x062D780D, 0x24084068, 0xD3000040, 0x1E644058, 0x1C49D1FA, 0x2A001E52, 0x4770D1F2,
    0x4770BA40, 0x4770BA40, 0x4770BA40, 0x4770BA40, 0x4770BA40, 0x4770BAC0, 0x4770BAC0, 0x4770BAC0,
    0x4770BAC0, 0x4770BAC0, 0x2A01B510, 0xB672D12E, 0x492A2200, 0x68C8628A, 0x049B2301, 0x60C84318,
    0x23554827, 0x4B276203, 0x1E536243, 0xF3BF6283, 0xF3BF8F4F, 0xBF008F6F, 0xBF00BF00, 0x8F4FF3BF,
    0x8F6FF3BF, 0xBF00BF00, 0x6242BF00, 0x62026282, 0x6003481D, 0x08406948, 0x61480040, 0x07802001,
    0x11426881, 0x60814311, 0xF9ACF000, 0xBD102000, 0x47702000, 0x48154911, 0x20006088, 0xBF004A14,
    0x42901C40, 0xE000DBFB, 0x6988BF00, 0xD1FB07C0, 0x220168C8, 0x43100492, 0x200060C8, 0xB5104770,
    0xF916F000, 0xBD102000, 0x4613B510, 0x08C91DC9, 0x4619004A, 0xF91DF000, 0xBD102000, 0x4004A000,
    0x40000700, 0xFDFFFFFF, 0xE000E180, 0xFF00FFFF, 0x00002EE0, 0x250FB570, 0xD2092908, 0x008C6806,
    0x43AE40A5, 0x68056006, 0x431540A2, 0xE00A6005, 0x460C6846, 0x00A43C08, 0x43AE40A5, 0x68456046,
    0x431540A2, 0x24036045, 0x22010224, 0x1900408A, 0xD0032B00, 0x43116801, 0xBD706001, 0x43916801,
    0xBD706001, 0xB081B5FF, 0x460E4605, 0x4C654617, 0x03614865, 0x22011828, 0xD0112800, 0x1AC014CB,
    0x220FD00A, 0x42900392, 0x6888D110, 0x43102202, 0x4C5C6088, 0xE0093410, 0x43106888, 0xE0056088,
    0x22106888, 0x60884310, 0x34804C56, 0x22002301, 0x46204631, 0xFFAEF7FF, 0x40B02001, 0xD01E2F01,
    0x43816869, 0x99046069, 0xD01C2901, 0x31F91DE1, 0x4382680A, 0x990A600A, 0xD01A2901, 0x31FF1DE1,
    0x680A31FA, 0x600A4302, 0x9A0B2101, 0x2A010289, 0x1861D016, 0x4382680A, 0xB005600A, 0x6869BDF0,
    0x60694301, 0x1DE1E7DF, 0x680A31F9, 0x600A4302, 0x1DE1E7E1, 0x31FA31FF, 0x4382680A, 0xE7E3600A,
    0x680A1861, 0x600A4302, 0x6802E7E7, 0x408B2301, 0x6002431A, 0x68024770, 0x408B2301, 0x6002439A,
    0x68024770, 0x408B2301, 0x6002405A, 0x6B004770, 0x07C040C8, 0x47700FC0, 0x1A9B2310, 0x40DA4A2B,
    0x408A6803, 0x60034313, 0x23104770, 0x4A271A9B, 0x680340DA, 0x4393408A, 0x47706003, 0x1A9B2310,
    0x40DA4A22, 0x408A6803, 0x60034053, 0x23104770, 0x4A1E1A9B, 0x6B0040DA, 0x401040C8, 0x22014770,
    0x18080089, 0x47706402, 0x00892200, 0x64021808, 0x00894770, 0x6C011808, 0x1A512201, 0x47706401,
    0x1A9B2310, 0x40DA4A11, 0x6803B672, 0x4313408A, 0xB6626003, 0x23104770, 0x4A0C1A9B, 0xB67240DA,
    0x408A6803, 0x60034393, 0x4770B662, 0x1A9B2310, 0x40DA4A06, 0x6803B672, 0x4053408A, 0xB6626003,
    0x00004770, 0x400A0000, 0xBFFFC000, 0x0000FFFF, 0xB672B510, 0x4A1A0A80, 0x444A4918, 0x47906852,
    0x68C14818, 0x04922201, 0x60C14311, 0x2000B662, 0xB510BD10, 0x0852B672, 0x444B4B11, 0x4798689B,
    0x68C14810, 0x04922201, 0x60C14311, 0x2000B662, 0xB510BD10, 0x4B0CB672, 0x49084A09, 0x6812444A,
    0xD2022821, 0x47904618, 0x2842E006, 0x4618D202, 0xE0014790, 0x47904805, 0xBD10B662, 0x0B11FFAC,
    0x00000004, 0x4004A000, 0x00089241, 0x0008A241, 0x2501B570, 0x682807AD, 0x49A04CA1, 0x444C07C0,
    0x6021D001, 0x6828E028, 0x0F4006C0, 0x4A9DD007, 0xD0082801, 0xD0162803, 0xD1172804, 0x207DE015,
    0x60200200, 0x4898E012, 0x07806800, 0x6021D501, 0x6022E000, 0x68202106, 0xF938F000, 0x43482178,
    0x602008C0, 0x6022E002, 0x6021E000, 0x07806828, 0x6820D502, 0x602008C0, 0x6820498C, 0xF926F000,
    0xBD706060, 0x20014988, 0x60083940, 0x680A0781, 0x600A4302, 0xB5004770, 0xFFF4F7FF, 0x21014882,
    0x06006101, 0x68016041, 0x4391221C, 0x68016001, 0x68016001, 0x43912202, 0x68016001, 0x00490849,
    0xBD006001, 0x487AB510, 0x21036902, 0x438A02C9, 0x48786102, 0x438A6902, 0x4C756102, 0x3CF02300,
    0x210B2207, 0xF7FF4620, 0x2300FE55, 0x210C2207, 0xF7FF4620, 0x496CFE4F, 0x6A083940, 0x43104A6E,
    0x20006208, 0x00C9217D, 0x1C40BF00, 0xD3FB4288, 0x68014865, 0x43912202, 0x68416001, 0x40114A67,
    0x68416041, 0x43114A66, 0x68016041, 0x43912204, 0x68C16001, 0xD0FC2900, 0x22016801, 0x60014311,
    0xB510BD10, 0xF7FF4604, 0xF7FFFF9D, 0x2001FFBB, 0x60480781, 0x221C6808, 0x60084390, 0x22046808,
    0x60084310, 0x2C002202, 0x6808D003, 0x60084310, 0x6808E002, 0x60084390, 0x08406808, 0x60080040,
    0xB570BD10, 0xF7FF4604, 0x4849FF7D, 0x22036901, 0x439102D2, 0x48476101, 0x43916901, 0x4D446101,
    0x3DF02300, 0x210B2207, 0xF7FF4628, 0x2300FDF3, 0x210C2207, 0xF7FF4628, 0x483BFDED, 0x6A013840,
    0x3A204A3D, 0x62014311, 0x207D2100, 0xBF0000C0, 0x42811C49, 0x2101D3FB, 0x60410788, 0x221C6801,
    0x60014391, 0x220C6801, 0x60014311, 0x2C002202, 0x6801D003, 0x60014311, 0x6801E002, 0x60014391,
    0x08496801, 0x60010049, 0xB500BD70, 0xFF3AF7FF, 0x07882101, 0x68016041, 0x4391221C, 0x68016001,
    0x43112210, 0x68016001, 0x43112202, 0x68016001, 0x00490849, 0xBD006001, 0x2001B510, 0x68810780,
    0x43111142, 0x205A6081, 0xFEC3F7FF, 0xFF1AF7FF, 0xFEDEF7FF, 0x49154812, 0x68004448, 0xF836F000,
    0xFEB7F7FF, 0x48172105, 0x60C10409, 0xBF00BF00, 0xBF00BF00, 0xBF00BF00, 0x2103BF00, 0x60C10409,
    0x4811490C, 0x61086008, 0x3180490A, 0x48086008, 0x22056901, 0x43910312, 0xBD106101, 0x00B71B00,
    0x00000010, 0x016E3600, 0x400AA040, 0x000F4240, 0x400A0100, 0x400A0200, 0x00070022, 0xFCE0FE00,
    0x0006001E, 0x4004A000, 0x0000FFFF, 0x460BB530, 0x20004601, 0x24012220, 0x460DE009, 0x429D40D5,
    0x461DD305, 0x1B494095, 0x40954625, 0x46151940, 0x2D001E52, 0xBD30DCF1, 0x00000000, 0x110004C1,
    0x11000401, 0x11000451, 0x00B71B00, 0x0000000C
};

const program_target_t flash_algo = {
    0x20000049,  // Init
    0x200000B1,  // UnInit
    0x200000B5,  // EraseChip
    0x200000DF,  // EraseSector
    0x200000E9,  // ProgramPage

    // BKPT : start of blob + 1
    // RSB  : address to access global/static data
    // RSP  : stack pointer
    {
        0x20000001,
        0x20000678,
        0x20000E90
    },

    0x20000690,  // mem buffer location
    0x20000000,  // location to write prog_blob in target RAM
    sizeof(flash_code),  // prog_blob size
    flash_code,  // address of prog_blob
    0x00000400,  // ram_to_flash_bytes_to_be_written
};
