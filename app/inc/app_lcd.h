#ifndef __APP_LCD_H
#define __APP_LCD_H

#include "main.h"

/////////////////Һ����������Ϣ//////////////////

#define LCD_STK_SIZE 		128  //�����ջ��С	
extern OS_TCB LCD_TaskTCB;  //������ƿ�
extern CPU_STK LCD_TASK_STK[LCD_STK_SIZE];  //�����ջ	

OS_ERR lcd_task_create (void);
void lcd_task (void *p_arg);
#endif
