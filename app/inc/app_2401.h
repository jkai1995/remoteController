#ifndef __APP_2401_H
#define __APP_2401_H

#include "main.h"

/////////////////液晶屏任务信息//////////////////




#define NRF2401_STK_SIZE 		256  //任务堆栈大小	
extern OS_TCB NRF2401_TaskTCB;  //任务控制块
extern CPU_STK NRF2401_TASK_STK[NRF2401_STK_SIZE];  //任务堆栈	

OS_ERR NRF2401_task_create (void);
void NRF2401_task (void *p_arg);
#endif
