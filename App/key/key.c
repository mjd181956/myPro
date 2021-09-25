#include "key.h"

void key_Init()
{
	GPIO_InitTypeDef GPIO_TypeDefInit;
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOE_CLK_ENABLE();
	/*设置GPIOA*/
	GPIO_TypeDefInit.Pin=GPIO_PIN_0;
	GPIO_TypeDefInit.Mode=GPIO_MODE_INPUT;
	GPIO_TypeDefInit.Pull=GPIO_PULLDOWN;
	HAL_GPIO_Init(GPIOA,&GPIO_TypeDefInit);
	
	GPIO_TypeDefInit.Pin=GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4;
	GPIO_TypeDefInit.Mode=GPIO_MODE_INPUT;
	GPIO_TypeDefInit.Pull=GPIO_PULLUP;
	HAL_GPIO_Init(GPIOE,&GPIO_TypeDefInit);
}


/*******************************************************************************
* 函 数 名         : KEY_Scan
* 函数功能		   : 按键扫描检测
* 输    入         : mode=0:单次按下按键
					 mode=1：连续按下按键
* 输    出         : 0：未有按键按下
					 KEY_UP_PRESS：KEY_UP键按下
					 KEY0_PRESS：KEY0键按下
					 KEY1_PRESS：KEY1键按下
					 KEY2_PRESS：KEY2键按下
*******************************************************************************/
u8 KEY_Scan(u8 mode)
{
	static u8 key=1;
	
	if(mode==1) //连续按键按下
		key=1;
	if(key==1&&(KEY_UP==1||KEY_1==0||KEY_2==0||KEY_3==0)) //任意一个按键按下
	{
		delay_ms(10);  //消抖
		key=0;
		if(KEY_UP==1)
			return KEY_UP_PRESS; 
		else if(KEY_1==0)
			return KEY1_PRESS; 
		else if(KEY_2==0)
			return KEY2_PRESS; 
		else if(KEY_3==0)
			return KEY3_PRESS; 
	}
	else if(KEY_UP==0&&KEY_1==1&&KEY_2==1&&KEY_3==1)    //无按键按下
		key=1;
	return 0;
}
