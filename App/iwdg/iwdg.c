#include "iwdg.h"

IWDG_HandleTypeDef IWDG_handler;

//��ʼ���������Ź�
//pre:��Ƶ��:IWDG_PRESCALER_4~IWDG_PRESCALER_256
//rlr:�Զ���װ��ֵ,0~0XFFF.
//ʱ�����(���):Tout=((4*2^prer)*rlr)/32 (ms).
void  iwdg_init(u8 pre,u16 rlr)
{
	IWDG_handler.Instance=IWDG;
	IWDG_handler.Init.Prescaler=pre;
	IWDG_handler.Init.Reload=rlr;
	HAL_IWDG_Init(&IWDG_handler);
}

void feedDog(void)
{
	HAL_IWDG_Refresh(&IWDG_handler);
}
