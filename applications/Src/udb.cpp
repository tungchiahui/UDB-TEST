#include "udb.h"
//USART_Debuger

uint8_t rx_buffer[1];

Udp_rc_t udp_rc;

extern "C"
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if(huart->Instance == USART1)
	{
		udb.rx.Data_Analysis(rx_buffer);
	}
}


bool UDB::RX::Data_Analysis(uint8_t *msg_data,int16_t bool_num,int16_t int8_num,int16_t int16_num,int16_t int32_num,int16_t fp32_num,int16_t total_size)
{
	static uint8_t SUMCRC_FLAG;
	static uint8_t buffer[7];
	static int16_t rx_cnt;
	static uint8_t finded_flag;
	if(*msg_data == 0xA5)
	{
		finded_flag = 1;
	}
	if(finded_flag == 1)
	{
		buffer[rx_cnt++] = *msg_data;
		if((rx_cnt == (total_size+3)))
		{
			finded_flag = 0;
			rx_cnt = 0;
			SUMCRC_FLAG = udb.checksum.__SUMCRC(buffer+1,total_size);
			if((buffer[total_size+2] == 0x5A)&&(SUMCRC_FLAG == buffer[total_size+1]))
			{
				udp_rc.ch[0] = udb.convert.Bytes2Short(buffer[1],buffer[2]);
				udp_rc.ch[1] = udb.convert.Bytes2Short(buffer[3],buffer[4]);
				
				return true;
			}
		}
	}
	return false;
}


uint8_t UDB::CHECKSUM::__SUMCRC(uint8_t *puchMsg, uint16_t usDataLen)
{
    int16_t i = 0;
		uint8_t uchSUMCRC = 0x00;
    for (; i < usDataLen; i++)
    {
			uchSUMCRC += puchMsg[i];
    }
    return uchSUMCRC;
}

int16_t UDB::CONVERT::Bytes2Short(uint8_t DH,uint8_t DL)
{
	int16_t result = (int16_t)((int16_t)DH << 8 | DL);
	return result;
}






#ifndef __cplusplus   //如果在C++使用，则不启用
#include <stdio.h>
/******************************************************************************************/
/* 加入以下代码, 支持printf函数, 而不需要选择use MicroLIB */

#if 1
#if (__ARMCC_VERSION >= 6010050)                    /* 使用AC6编译器时 */
__asm(".global __use_no_semihosting\n\t");          /* 声明不使用半主机模式 */
__asm(".global __ARM_use_no_argv \n\t");            /* AC6下需要声明main函数为无参数格式，否则部分例程可能出现半主机模式 */

#else
/* 使用AC5编译器时, 要在这里定义__FILE 和 不使用半主机模式 */
#pragma import(__use_no_semihosting)

struct __FILE
{
    int handle;
    /* Whatever you require here. If the only file you are using is */
    /* standard output using printf() for debugging, no file handling */
    /* is required. */
};

#endif

/* 不使用半主机模式，至少需要重定义_ttywrch\_sys_exit\_sys_command_string函数,以同时兼容AC6和AC5模式 */
int _ttywrch(int ch)
{
    ch = ch;
    return ch;
}

/* 定义_sys_exit()以避免使用半主机模式 */
void _sys_exit(int x)
{
    x = x;
}

char *_sys_command_string(char *cmd, int len)
{
    return NULL;
}

/* FILE 在 stdio.h里面定义. */
FILE __stdout;

/* 重定义fputc函数, printf函数最终会通过调用fputc输出字符串到串口 */
int fputc(int ch, FILE *f)
{
    while ((USART1->SR & 0X40) == 0);               /* 等待上一个字符发送完成 */

    USART1->DR = (uint8_t)ch;                       /* 将要发送的字符 ch 写入到DR寄存器 */
    return ch;
}
#endif
/***********************************************END*******************************************/
#endif
