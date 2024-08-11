#include "startup_main.h"
#include "stm32f1xx_hal_uart.h"
#include "usart.h"

extern uint8_t rx_buffer[1];

void startup_main(void)
{
	HAL_UART_Receive_DMA(&huart1, rx_buffer, 1);

#if isRTOS==0    	//如果是裸机开发
	for(;;)  //等同于while(true)
	{

	}
#endif
}