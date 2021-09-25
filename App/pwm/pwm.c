#include "pwm.h"

TIM_HandleTypeDef TIM14_Handler;
TIM_OC_InitTypeDef TIM_OC_typeDef1;
void Tim_pwm_init(u16 arr,u16 psc)
{
	TIM14_Handler.Instance=TIM14;
	TIM14_Handler.Init.Period=arr;
	TIM14_Handler.Init.Prescaler=psc;
	TIM14_Handler.Init.CounterMode=TIM_COUNTERMODE_UP;

	TIM14_Handler.Init.ClockDivision=TIM_CLOCKDIVISION_DIV1;
	/*使能PWM*/
	HAL_TIM_PWM_Init(&TIM14_Handler);
	
	TIM_OC_typeDef1.OCMode=TIM_OCMODE_PWM1;
	TIM_OC_typeDef1.Pulse=arr/2;            //设置比较值,此值用来确定占空比，默认比较值为自动重装载值的一半,即占空比为50%
	TIM_OC_typeDef1.OCPolarity=TIM_OCPOLARITY_LOW;
	

	/*配置pwm*/
	HAL_TIM_PWM_ConfigChannel(&TIM14_Handler,&TIM_OC_typeDef1,TIM_CHANNEL_1);
	
	/*开启pwm*/
	HAL_TIM_PWM_Start(&TIM14_Handler,TIM_CHANNEL_1);
}

void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef *htim)
{
	if(htim->Instance==TIM14)
	{

		GPIO_InitTypeDef GPIO_TypeDefInit;
		/*开启定时器时钟*/
		__HAL_RCC_TIM14_CLK_ENABLE();
		__HAL_RCC_GPIOF_CLK_ENABLE();
		/*设置GPIO引脚映射功能*/
		GPIO_TypeDefInit.Pin=GPIO_PIN_9;
		GPIO_TypeDefInit.Mode=GPIO_MODE_AF_PP;
		GPIO_TypeDefInit.Pull=GPIO_PULLUP;
		GPIO_TypeDefInit.Speed=GPIO_SPEED_FREQ_HIGH;
		GPIO_TypeDefInit.Alternate=GPIO_AF9_TIM14;
		HAL_GPIO_Init(GPIOF,&GPIO_TypeDefInit);
	}
}

void set_ARR(u32 pargram)
{
	TIM14->CCR1=pargram;
}
