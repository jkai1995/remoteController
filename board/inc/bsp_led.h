#ifndef __BSP_LED_H
#define __BSP_LED_H

#include "stm32f4xx_conf.h"

typedef enum 
{
	LED0 = 0,
  LED1 ,
	LED2 ,
	LED_MAX ,
} Led_Def;



void LED_Init(void);
void LEDOn(Led_Def Led);
void LEDOff(Led_Def Led);
void LEDTog(Led_Def Led);

#endif 

