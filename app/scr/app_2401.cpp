#include "app_2401.h"

#include "CReceiveSend.h"


OS_TCB NRF2401_TaskTCB;  //任务控制块
CPU_STK NRF2401_TASK_STK[NRF2401_STK_SIZE];  //任务堆栈	



OS_ERR NRF2401_task_create (void)
{
		OS_ERR err;
		OSTaskCreate((OS_TCB 	* )&NRF2401_TaskTCB,		
				 (CPU_CHAR	* )"Task3 NRF2401", 		
                 (OS_TASK_PTR )NRF2401_task, 			
                 (void		* )0,					
                 (OS_PRIO	  )NRF2401_TASK_PRIO,     
                 (CPU_STK   * )&NRF2401_TASK_STK[0],	
                 (CPU_STK_SIZE)NRF2401_STK_SIZE/10,	
                 (CPU_STK_SIZE)NRF2401_STK_SIZE,		
                 (OS_MSG_QTY  )0,					
                 (OS_TICK	  )0,  					
                 (void   	* )0,					
                 (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR,
                 (OS_ERR 	* )&err);	
									
		return err;
}

void NRF2401_task (void *p_arg)
{
	SPI_GPIO_Init();
	CReceiveSend * receiveSend = CReceiveSend::getInstance();
	receiveSend->initCRS(&NRF2401_TaskTCB);
	
	while(1)
	{
		receiveSend->run();
	}
}




