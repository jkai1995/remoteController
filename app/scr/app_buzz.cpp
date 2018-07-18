#include "app_buzz.h"


OS_TCB BUZZ_TaskTCB;  //������ƿ�
CPU_STK BUZZ_TASK_STK[BUZZ_STK_SIZE];  //�����ջ	

u8 buzz_mode=0;
u8 vibrates_mode = 0;

OS_ERR BUZZ_task_create (void)
{
		OS_ERR err;
		OSTaskCreate((OS_TCB 	* )&BUZZ_TaskTCB,		
				 (CPU_CHAR	* )"Task3 BUZZ", 		
                 (OS_TASK_PTR )BUZZ_task, 			
                 (void		* )0,					
                 (OS_PRIO	  )BUZZ_TASK_PRIO,     
                 (CPU_STK   * )&BUZZ_TASK_STK[0],	
                 (CPU_STK_SIZE)BUZZ_STK_SIZE/10,	
                 (CPU_STK_SIZE)BUZZ_STK_SIZE,		
                 (OS_MSG_QTY  )0,					
                 (OS_TICK	  )0,  					
                 (void   	* )0,					
                 (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR,
                 (OS_ERR 	* )&err);	
									
		return err;
}

u16 low_half_per[7]={1911,1702,1516,1431,1275,1136,1012};
u16 hig_half_per[7]={477,425,379,357,318,284,253};
float volume[7] = {0.01,0.01,0.01,0.01,0.01,0.01,0.01};

void BUZZ_task (void *p_arg)
{
	OS_ERR err;
	Buzz buzz;///������
	Vibrates vibrates;///�𶯵��
	buzz.play(hig_half_per,volume,100,4);
	while(1)
	{
		if(buzz_mode == 1) //����
		{
			buzz.play(hig_half_per+5,volume,100,1);
			OSTimeDlyHMSM(0,0,1,0,OS_OPT_TIME_PERIODIC,&err); //��ʱ15ms
		}
		
		if(vibrates_mode == 1)//����
		{
			vibrates.set_vibrates(0.3,200);
			vibrates_mode = 0;
		}
		else if(vibrates_mode == 2)//����
		{
			vibrates.set_vibrates(0.3,200);
			vibrates_mode = 0;
		}
		OSTimeDlyHMSM(0,0,0,5,OS_OPT_TIME_PERIODIC,&err); //��ʱ15ms

	}
}




Buzz::Buzz(void)
{
	TIM5_PWM_Init(1000-1,84-1);
	
	per_us = 1000;
}

void Buzz::set_buzz(u16 const h_pe,float const vo)
{
	half_per_us = h_pe;     //������
	per_us = 2*half_per_us; //����
	volume = vo;            //����
	drive_buzz();
}


void Buzz::drive_buzz(void)
{
	TIM_SetAutoreload(TIM5,per_us-1); //��������
	TIM_SetCompare1(TIM5,per_us*volume);//��������
}

void Buzz::play (u16 const *pt_halfper,float const *pt_vo,u16 const Rhy,u8 const num)//���������� ���� ����ʱ��   �켸��
{
	OS_ERR err;
	u8 i;
	for(i = 0; i < num; i++)
	{
		set_buzz(*(pt_halfper + i),*(pt_vo + i));
		OSTimeDlyHMSM(0,0,0,Rhy,OS_OPT_TIME_PERIODIC,&err); //��ʱ15ms
	}
	set_buzz(1000,0);
}



