#include "usart.h"

u8 pdata[1];
UART_HandleTypeDef UART_Handler;
void usart_Init(u32 bandRate)
{
	UART_Handler.Instance=USART3;
	UART_Handler.Init.BaudRate=bandRate;
	UART_Handler.Init.Mode=UART_MODE_TX_RX;
	UART_Handler.Init.Parity=UART_PARITY_NONE;
	UART_Handler.Init.StopBits=UART_STOPBITS_1;
	UART_Handler.Init.WordLength=UART_WORDLENGTH_8B;
	//UART_Handler.Init.HwFlowCtl=UART_HWCONTROL_NONE;
	HAL_UART_Init(&UART_Handler);
	HAL_UART_Receive_IT(&UART_Handler,pdata,sizeof(pdata));
}
void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
	GPIO_InitTypeDef GPIO_TypeDefInit;
	if(huart->Instance==USART3)
	{
		__HAL_RCC_GPIOB_CLK_ENABLE();
		__HAL_RCC_USART3_CLK_ENABLE();
		
		GPIO_TypeDefInit.Pin=GPIO_PIN_10|GPIO_PIN_11;
		GPIO_TypeDefInit.Mode=GPIO_MODE_AF_PP;
		GPIO_TypeDefInit.Pull=GPIO_PULLUP;
		GPIO_TypeDefInit.Speed=GPIO_SPEED_FREQ_HIGH;
		GPIO_TypeDefInit.Alternate=GPIO_AF7_USART3;
		HAL_GPIO_Init(GPIOB,&GPIO_TypeDefInit);
		/*配置中断并开启中断*/
		HAL_NVIC_EnableIRQ(USART3_IRQn);
		HAL_NVIC_SetPriority(USART3_IRQn,3,3);
	}
}

void USART3_IRQHandler(void)
{
	HAL_UART_IRQHandler(&UART_Handler);
	HAL_UART_Receive_IT(&UART_Handler,pdata,sizeof(pdata));
}
	
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	u8 rdata;
	if(huart->Instance==USART3)
	{
		rdata=(*(huart->pRxBuffPtr-1));
		//rdata=pdata[0];
		HAL_UART_Transmit(&UART_Handler,&rdata,sizeof(rdata),1000);
	}
}
