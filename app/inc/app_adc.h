#ifndef __APP_ADC_H
#define __APP_ADC_H

#include "main.h"

typedef struct 
{
	u16 left_x;
	u16 left_y;
	u16 right_x;
	u16 right_y;
}ADC_ROCKER;

/////////////////ADC转换任务信息//////////////////

#define ADC_STK_SIZE 		256  //任务堆栈大小	
extern OS_TCB ADC_TaskTCB;  //任务控制块
extern CPU_STK ADC_TASK_STK[ADC_STK_SIZE];  //任务堆栈	

extern  ADC_ROCKER rocker;
extern float battery;
OS_ERR adc_task_create (void);
void adc_task (void *p_arg);
#ifdef __cplusplus
extern "C"
{
#endif
/* c语言内容*/
#ifdef __cplusplus
}
#endif



#endif 
