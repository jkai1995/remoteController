#ifndef __BSP_KEY_H
#define __BSP_KEY_H

#include "stm32f4xx_conf.h"

typedef enum 
{  
  KEY0 = 0,
	KEY1 = 1,
	KEY2 = 2,
	KEY3 = 3,
	KEY4 = 4,
	KEY_MAX ,
} Key_Def;



void Key_Init(void);
 u8 Get_Key(Key_Def key);

#endif

