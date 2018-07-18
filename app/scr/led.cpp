#include "led.h"



OS_TCB LED_TaskTCB;  //������ƿ�
CPU_STK LED_TASK_STK[LED_STK_SIZE];  //�����ջ	
//����������			 
//���ز��� : �������
OS_ERR LED_task_create (void)
{
	  OS_ERR err;
		//����TASK1����
	OSTaskCreate((OS_TCB 	* )&LED_TaskTCB,
				 (CPU_CHAR	* )"Task1 LED", 		
                 (OS_TASK_PTR )LED_task, 			
                 (void		* )0,					
                 (OS_PRIO	  )LED_TASK_PRIO,     
                 (CPU_STK   * )&LED_TASK_STK[0],	
                 (CPU_STK_SIZE)LED_STK_SIZE/10,	
                 (CPU_STK_SIZE)LED_STK_SIZE,		
                 (OS_MSG_QTY  )0,					
                 (OS_TICK	  )0,  					
                 (void   	* )0,					
                 (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR,
                 (OS_ERR 	* )&err);
									
		return err;
}	
//����1��������
void LED_task(void *p_arg)
{
	OS_ERR err;

	 LED_Init();

	while(1)
	{
		LEDTog(LED0);
		LEDTog(LED1);
		LEDTog(LED2);
		OSTimeDlyHMSM(0,0,1,0,OS_OPT_TIME_PERIODIC,&err);   //��ʱ100ms
	}
}


