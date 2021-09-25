#include "led.h"

void led_Init()
{
	GPIO_InitTypeDef GPIO_TypeDefInit;
	__HAL_RCC_GPIOF_CLK_ENABLE();
	
	GPIO_TypeDefInit.Pin=GPIO_PIN_9|GPIO_PIN_10;
	GPIO_TypeDefInit.Mode=GPIO_MODE_OUTPUT_PP;
	GPIO_TypeDefInit.Pull=GPIO_PULLUP;
	GPIO_TypeDefInit.Speed=GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOF,&GPIO_TypeDefInit);
	
	HAL_GPIO_WritePin(GPIOF,GPIO_PIN_9,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOF,GPIO_PIN_10,GPIO_PIN_SET);
}
