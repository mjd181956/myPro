#include "key.h"

void key_Init()
{
	GPIO_InitTypeDef GPIO_TypeDefInit;
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOE_CLK_ENABLE();
	/*����GPIOA*/
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
* �� �� ��         : KEY_Scan
* ��������		   : ����ɨ����
* ��    ��         : mode=0:���ΰ��°���
					 mode=1���������°���
* ��    ��         : 0��δ�а�������
					 KEY_UP_PRESS��KEY_UP������
					 KEY0_PRESS��KEY0������
					 KEY1_PRESS��KEY1������
					 KEY2_PRESS��KEY2������
*******************************************************************************/
u8 KEY_Scan(u8 mode)
{
	static u8 key=1;
	
	if(mode==1) //������������
		key=1;
	if(key==1&&(KEY_UP==1||KEY_1==0||KEY_2==0||KEY_3==0)) //����һ����������
	{
		delay_ms(10);  //����
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
	else if(KEY_UP==0&&KEY_1==1&&KEY_2==1&&KEY_3==1)    //�ް�������
		key=1;
	return 0;
}
