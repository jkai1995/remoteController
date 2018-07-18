#ifndef __MAIN_H
#define __MAIN_H

#include "priority.h"

#ifdef __cplusplus
extern "C"
{
#endif
	/////////////////////////////////////////
	///////////////////////////////////c”Ô—‘ø‚//////////////
#include "stm32f4xx.h"
#include "stm32f4xx_conf.h"

/////////ucosiii//////////
#include "includes.h"
#include "os_app_hooks.h"

//////sys////
#include "delay.h"
#include "sys.h" 
#include "usart.h"
//#include "timer.h"
//#include "spi.h"
//////bsp/////
#include "bsp_led.h"
#include "bsp_key.h"
#include "lcd.h"
#include "cfont.h" 
#include "pwm.h"
#include "adc.h"
#include "nRF24L01_API.h"

#include "spi.h"
//////////////////////////////////////


//////////////////////¥•√˛∆¡///////////
#include "touch.h" 




#ifdef __cplusplus
}
#endif


	/////////////////////////////////////////
	///////////////////////////////////c++ø‚//////////////
#include "app_adc.h"
#include "app_lcd.h"
#include "app_2401.h"
#include "app_buzz.h"
#include "key.h"
#include "led.h"
#include "app_vibrates.h"
#include "control_data.h"
#endif


