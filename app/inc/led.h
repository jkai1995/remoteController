#ifndef __LED_H
#define __LED_H

#include "main.h"

/////////////////�������//////////////////
#define LED_STK_SIZE 		128  //�����ջ��С	
extern OS_TCB LED_TaskTCB;  //������ƿ�
extern CPU_STK LED_TASK_STK[LED_STK_SIZE];  //�����ջ	

OS_ERR LED_task_create (void);//����������		
void LED_task(void *p_arg);//����1��������



#endif 
