#include "iwdg.h"

IWDG_HandleTypeDef IWDG_handler;

//初始化独立看门狗
//pre:分频数:IWDG_PRESCALER_4~IWDG_PRESCALER_256
//rlr:自动重装载值,0~0XFFF.
//时间计算(大概):Tout=((4*2^prer)*rlr)/32 (ms).
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
