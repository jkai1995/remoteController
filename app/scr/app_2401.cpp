#include "app_2401.h"


OS_TCB NRF2401_TaskTCB;  //������ƿ�
CPU_STK NRF2401_TASK_STK[NRF2401_STK_SIZE];  //�����ջ	



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
	OS_ERR err;
	u8 rece_buf[32];
	

	SPI_GPIO_Init();

	
	while(NRF24L01_Check()); // �ȴ���⵽NRF24L01������Ż�����ִ��
	NRF24L01_RT_Init();

	rece_buf[1]=0xc9;					//��
	rece_buf[2]=0xcf;					//��
	rece_buf[3]=0xba;					//��
	rece_buf[4]=0xa3;					//��
	rece_buf[5]=0xb1;					//��
	rece_buf[6]=0xa6;					//��
	rece_buf[7]=0xc7;					//Ƕ
	rece_buf[8]=0xb6;					//Ƕ
	rece_buf[9]=0xb5;					//��
	rece_buf[10]=0xe7;				//��
	rece_buf[11]=0xd7;				//��
	rece_buf[12]=0xd3;				//��
	rece_buf[0]=12;						//һ��Ҫ����12���ֽڣ�rece_buf[0]������12������������
	SEND_BUF(rece_buf);

	while(1)
	{
//	rece_buf[1]=control_data_struct.cmd;		//����
//	rece_buf[2]=control_data_struct.lift;		//����
//	rece_buf[3]=control_data_struct.pitch;	//����
//	rece_buf[4]=control_data_struct.roll;		//����
//	rece_buf[5]=control_data_struct.yaw;		//ƫ��
//	rece_buf[0]=sizeof(control_data_struct);						//һ��Ҫ����5���ֽڣ�rece_buf[0]������5������������
	
		lode_send_data(rece_buf);
		
		
		SEND_BUF(rece_buf);
		
		if(NRF_IRQ==0)	 	// �������ģ����յ�����
		{		
			if(NRF24L01_RxPacket(rece_buf)==0)
			{			   
			}
		}
		
		OSTimeDlyHMSM(0,0,0,20,OS_OPT_TIME_PERIODIC,&err); //��ʱ15ms
	}
}




