#ifndef __APP_2401_H
#define __APP_2401_H

#include "main.h"

/////////////////Һ����������Ϣ//////////////////




#define NRF2401_STK_SIZE 		256  //�����ջ��С	
extern OS_TCB NRF2401_TaskTCB;  //������ƿ�
extern CPU_STK NRF2401_TASK_STK[NRF2401_STK_SIZE];  //�����ջ	

OS_ERR NRF2401_task_create (void);
void NRF2401_task (void *p_arg);
#endif
