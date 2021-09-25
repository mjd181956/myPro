#include "time.h"

/*定义tim结构体句柄*/
TIM_HandleTypeDef TIM_Handler;
void  time_Init(u16 arr,u16 psc)
{
	/*设置定时器结构体变量*/
	TIM_Handler.Instance=TIM2;
	TIM_Handler.Init.Period=arr;
	TIM_Handler.Init.CounterMode=TIM_COUNTERMODE_UP;
	TIM_Handler.Init.Prescaler=psc;
	HAL_TIM_Base_Init(&TIM_Handler);
	HAL_TIM_Base_Start_IT(&TIM_Handler);
	
}
void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htim)
{
	/*开启定时器 时钟和中断优先级*/
	if(htim->Instance==TIM2)
	{
		__HAL_RCC_TIM2_CLK_ENABLE();
		/*配置中断优先级 */
		HAL_NVIC_EnableIRQ(TIM2_IRQn);
		HAL_NVIC_SetPriority(TIM2_IRQn,1,2);
	}
}

/**
  *@函数功能：设置定时器中断函数
  *@函数名称：TIM2_IRQHandler
  *@参	  数：无
  *@返 回 值：无
  */
void TIM2_IRQHandler(void)
{
	/*调用hal库中的中断函数*/
	HAL_TIM_IRQHandler(&TIM_Handler);
}
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance==TIM2)
	{
		LED1=!LED1;
	}
}

