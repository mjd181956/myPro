#ifndef __IWDG_H
#define __IWDG_H

#include "sys.h"
void  iwdg_init(u8 pre,u16 rlr);
void feedDog(void);

#endif
