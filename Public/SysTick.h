#ifndef __SYSTICK_H
#define __SYSTICK_H

#include "sys.h"

void SysTick_Init(u8 SYSCLK);
void delay_us(u32 us);
void delay_ms(u16 nms);


#endif
