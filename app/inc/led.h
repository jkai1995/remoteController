#ifndef __LED_H
#define __LED_H

#include "main.h"

/////////////////led ucos task//////////
#define LED_STK_SIZE 		128  //任务堆栈大小	
extern OS_TCB LED_TaskTCB;  //任务控制块
extern CPU_STK LED_TASK_STK[LED_STK_SIZE];  //任务堆栈	

OS_ERR LED_task_create (void);//创建此任务		
void LED_task(void *p_arg);//任务1的任务函数



#endif 
