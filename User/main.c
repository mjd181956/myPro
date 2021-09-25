#include "main.h"
#include "sys.h"
#include "SysTick.h"
#include "led.h"
#include "pwm.h"
int main(void)
{
	//u8 data=0x00;
	u8 dir=1;/*设置极性*/
	u32 compar=0;
	/*系统配置*/
	HAL_Init();
	stm32_Clock_Init(336,8,2,7);
	SysTick_Init(168);
	led_Init();
	Tim_pwm_init(500-1,84-1);
	while(1)
	{
		delay_ms(8);
		if(dir)compar++;
		else compar--;
		if(compar>400) dir=0;
		if(compar==10) dir=1;
		set_ARR(compar);
	}
}
