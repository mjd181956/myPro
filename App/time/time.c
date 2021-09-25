#include "time.h"

/*����tim�ṹ����*/
TIM_HandleTypeDef TIM_Handler;
void  time_Init(u16 arr,u16 psc)
{
	/*���ö�ʱ���ṹ�����*/
	TIM_Handler.Instance=TIM2;
	TIM_Handler.Init.Period=arr;
	TIM_Handler.Init.CounterMode=TIM_COUNTERMODE_UP;
	TIM_Handler.Init.Prescaler=psc;
	HAL_TIM_Base_Init(&TIM_Handler);
	HAL_TIM_Base_Start_IT(&TIM_Handler);
	
}
void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htim)
{
	/*������ʱ�� ʱ�Ӻ��ж����ȼ�*/
	if(htim->Instance==TIM2)
	{
		__HAL_RCC_TIM2_CLK_ENABLE();
		/*�����ж����ȼ� */
		HAL_NVIC_EnableIRQ(TIM2_IRQn);
		HAL_NVIC_SetPriority(TIM2_IRQn,1,2);
	}
}

/**
  *@�������ܣ����ö�ʱ���жϺ���
  *@�������ƣ�TIM2_IRQHandler
  *@��	  ������
  *@�� �� ֵ����
  */
void TIM2_IRQHandler(void)
{
	/*����hal���е��жϺ���*/
	HAL_TIM_IRQHandler(&TIM_Handler);
}
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance==TIM2)
	{
		LED1=!LED1;
	}
}

