#ifndef __USART_H
#define __USART_H

#include "sys.h"

extern UART_HandleTypeDef UART_Handler;
void usart_Init(u32 bandRate);

#endif
