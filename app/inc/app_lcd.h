#ifndef __APP_LCD_H
#define __APP_LCD_H

#include "main.h"

/////////////////液晶屏任务信息//////////////////

#define LCD_STK_SIZE 		128  //任务堆栈大小	
extern OS_TCB LCD_TaskTCB;  //任务控制块
extern CPU_STK LCD_TASK_STK[LCD_STK_SIZE];  //任务堆栈	

OS_ERR lcd_task_create (void);
void lcd_task (void *p_arg);
#endif
