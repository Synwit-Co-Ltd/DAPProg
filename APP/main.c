#include <stdio.h>
#include <string.h>

#include "SWM341.h"

#include "SWD_host.h"
#include "SWD_flash.h"

#include "algo/SWM181xC.c"
uint32_t Flash_Sect_Size = 4096;
uint32_t Flash_Page_Size = 256;
uint32_t Flash_Start_Addr = 0x00000000;

#include "../doc/bin2array/SWM181_stdperiph_lib.c"

uint8_t Target_SWM181 = 1;

uint8_t buff[1024] = {0};

void SerialInit(void);
void SWM181_SWD_Read(uint32_t addr, uint8_t buff[], uint32_t size);

int main(void)
{	
	uint32_t val;
	
	SystemInit();
	
	SerialInit();
	
	swd_init_debug();
	
	swd_read_dp(0x00, &val);
	printf("\n\nIDCODE: %08X\n\n", val);
	
	target_flash_init(Flash_Start_Addr);
	
	for(uint32_t addr = 0; addr < sizeof(SWM181_stdperiph_lib); addr += Flash_Sect_Size)
	{
		target_flash_erase_sector(Flash_Start_Addr + addr);
	}
	
	printf("After erase:\r\n");
	for(uint32_t addr = 0; addr < sizeof(SWM181_stdperiph_lib); addr += 1024)
	{
		if(Target_SWM181)
			SWM181_SWD_Read(Flash_Start_Addr + addr, buff, 1024);
		else
			swd_read_memory(Flash_Start_Addr + addr, buff, 1024);
		for(uint32_t i = 0; i < 1024; i++) printf("%02X ", buff[i]);
		printf("\r\n\r\n\r\n");
	}
	
	for(uint32_t addr = 0; addr < sizeof(SWM181_stdperiph_lib); addr += Flash_Page_Size)
	{
		target_flash_program_page(Flash_Start_Addr + addr, &SWM181_stdperiph_lib[addr], Flash_Page_Size);
	}
	
	printf("After write:\r\n");
	for(uint32_t addr = 0; addr < sizeof(SWM181_stdperiph_lib); addr += 1024)
	{
		if(Target_SWM181)
			SWM181_SWD_Read(Flash_Start_Addr + addr, buff, 1024);
		else
			swd_read_memory(Flash_Start_Addr + addr, buff, 1024);
		for(uint32_t i = 0; i < 1024; i++) printf("%02X ", buff[i]);
		
		if(Target_SWM181 && (addr == 0))
			if(*((uint32_t *)&buff[36]) == (sizeof(SWM181_stdperiph_lib) + 4095) / 4096 * 4096)
				*((uint32_t *)&buff[36]) = *((uint32_t *)&SWM181_stdperiph_lib[36]);
		
		uint32_t cmp_size = sizeof(SWM181_stdperiph_lib) - addr;
		if(memcmp(&SWM181_stdperiph_lib[addr], buff, cmp_size > 1024 ? 1024 : cmp_size) == 0)
			printf("\r\nPass\r\n\r\n\r\n");
		else
			printf("\r\nFail\r\n\r\n\r\n");
	}
	
	target_flash_uninit();
	
	while(1)
	{
		
	}
}


/* SWM181 Flash 无法直接读，只能通过读写 Flash 控制器寄存器进行读写 */
#define FLASH_CR	0x44000000
#define FLASH_GO	0x44000004   // 命令执行寄存器
#define FLASH_SR	0x44000008
#define FLASH_AR	0x44000014
#define FLASH_DR	0x44000018

#define FLASH_CR_LEN(len)		(len << 0)   // 0表示写256字节（1页）
#define FLASH_CR_CMD(cmd)		(cmd << 8)
#define FLASH_CR_FIFO_CLR   	(1   <<23)

#define FLASH_CMD_READ_STATL	0x02
#define FLASH_CMD_READ_STATH	0x03
#define FLASH_CMD_READ_DATA 	0x04
#define FLASH_CMD_WRITE_PAGE	0x09
#define FLASH_CMD_ERASE_SECT	0x0A
#define FLASH_CMD_ERASE_CHIP	0x0D
#define FLASH_CMD_WRITE_EN  	0x12
#define FLASH_CMD_WRITE_DIS 	0x13

#define FLASH_SR_WRIP      		(1 << 0)
#define FLASH_SR_WREN      		(1 << 1)
#define FLASH_SR_BUSY      		(1 <<16)
#define FLASH_SR_FIFO_EMPTY		(1 <<21)
#define FLASH_SR_FIFO_FULL 		(1 <<23)

void SWM181_SWD_Read(uint32_t addr, uint8_t buff[], uint32_t size)
{
	uint32_t val;
	
	do {		
		swd_read_word(FLASH_SR, &val);
	} while(val & FLASH_SR_BUSY);
	
	swd_write_word(FLASH_CR, FLASH_CR_FIFO_CLR);
	swd_write_word(FLASH_CR, FLASH_CR_CMD(FLASH_CMD_READ_DATA) | FLASH_CR_LEN(0));	// 连续读
	swd_write_word(FLASH_AR, addr);
	swd_write_word(FLASH_GO, 1);
    for(int i = 0; i < (size+3)/4; i++)
	{
		do {
			swd_read_word(FLASH_SR, &val);
		} while(val & FLASH_SR_FIFO_EMPTY);
		
		swd_read_word(FLASH_DR, &val);
		buff[i*4 + 0] = (val >>  0);
		buff[i*4 + 1] = (val >>  8);
		buff[i*4 + 2] = (val >> 16);
		buff[i*4 + 3] = (val >> 24);
	}
    
	swd_write_word(FLASH_GO, 0);
    swd_write_word(FLASH_CR, FLASH_CR_FIFO_CLR);
}


void SerialInit(void)
{
	UART_InitStructure UART_initStruct;
	
	PORT_Init(PORTM, PIN0, PORTM_PIN0_UART0_RX, 1);	//GPIOM.0配置为UART0输入引脚
	PORT_Init(PORTM, PIN1, PORTM_PIN1_UART0_TX, 0);	//GPIOM.1配置为UART0输出引脚
 	
 	UART_initStruct.Baudrate = 115200;
	UART_initStruct.DataBits = UART_DATA_8BIT;
	UART_initStruct.Parity = UART_PARITY_NONE;
	UART_initStruct.StopBits = UART_STOP_1BIT;
	UART_initStruct.RXThreshold = 3;
	UART_initStruct.RXThresholdIEn = 0;
	UART_initStruct.TXThreshold = 3;
	UART_initStruct.TXThresholdIEn = 0;
	UART_initStruct.TimeoutTime = 10;
	UART_initStruct.TimeoutIEn = 0;
 	UART_Init(UART0, &UART_initStruct);
	UART_Open(UART0);
}

/****************************************************************************************************************************************** 
* 函数名称:	fputc()
* 功能说明: printf()底层输出函数
* 输    入: int ch	要输出的字符
*			FILE *f
* 输    出: 无
* 注意事项: 无
******************************************************************************************************************************************/
int fputc(int ch, FILE *f)
{
	UART_WriteByte(UART0, ch);
	
	while(UART_IsTXBusy(UART0));
 	
	return ch;
}
