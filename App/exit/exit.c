#include "exit.h"
#include "key.h"

void exit_Init(void)
{
	/*定义结构体*/
	GPIO_InitTypeDef GPIO_TypeDefInit;
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOE_CLK_ENABLE();
	
	/*设置GPIOA*/
	GPIO_TypeDefInit.Pin=GPIO_PIN_0;
	GPIO_TypeDefInit.Mode=GPIO_MODE_IT_RISING;
	GPIO_TypeDefInit.Pull=GPIO_PULLDOWN;
	HAL_GPIO_Init(GPIOA,&GPIO_TypeDefInit);
	
	GPIO_TypeDefInit.Pin=GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4;
	GPIO_TypeDefInit.Mode=GPIO_MODE_IT_FALLING;
	GPIO_TypeDefInit.Pull=GPIO_PULLUP;
	HAL_GPIO_Init(GPIOE,&GPIO_TypeDefInit);
	/*使能中断，配置中断优先级*/	
	HAL_NVIC_SetPriority(EXTI0_IRQn,3,0);
	HAL_NVIC_EnableIRQ(EXTI0_IRQn);
	
	/*使能中断，配置中断优先级*/
	HAL_NVIC_SetPriority(EXTI2_IRQn,3,1);
	HAL_NVIC_EnableIRQ(EXTI2_IRQn);
	
	/*使能中断，配置中断优先级*/
	HAL_NVIC_SetPriority(EXTI3_IRQn,3,2);
	HAL_NVIC_EnableIRQ(EXTI3_IRQn);
	
	/*使能中断，配置中断优先级*/
	HAL_NVIC_SetPriority(EXTI4_IRQn,3,3);
	HAL_NVIC_EnableIRQ(EXTI4_IRQn);
}

void EXTI0_IRQHandler(void)
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_0);
}

void EXTI2_IRQHandler(void)
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_2);
}

void EXTI3_IRQHandler(void)
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_3);
}

void EXTI4_IRQHandler(void)
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_4);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	delay_ms(100);
	switch(GPIO_Pin)
	{
		case GPIO_PIN_0:
			if(KEY_UP==1)
			{
				LED1=!LED1;
				LED2=!LED1;
			}
			break;
		case GPIO_PIN_2:
			if(KEY_1==0)
			{
				LED1=!LED1;
			}
			break;
		case GPIO_PIN_3:
			if(KEY_2==0)
			{
				LED2=!LED2;
			}
			break;
		case GPIO_PIN_4:
			if(KEY_3==0)
			{
				LED1=!LED1;
				LED2=!LED2;
			}
			break;
			
	}
}






