#ifndef __KEY_H
#define __KEY_H

#include "sys.h"
#include "SysTick.h"

#define KEY_UP_PRESS	0x01
#define KEY1_PRESS		0x02
#define KEY2_PRESS		0x03
#define KEY3_PRESS		0x04


#define KEY_UP		PAin(0)
#define KEY_1		PEin(2)
#define KEY_2 		PEin(3)
#define KEY_3		PEin(4)

void key_Init(void);
u8 KEY_Scan(u8 mode);
#endif
