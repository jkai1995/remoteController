#include "app_adc.h"


#define LEFT_X_AXIS  11  //���x�����ӦADͨ��11
#define LEFT_Y_AXIS  10
#define RIGHT_X_AXIS  9
#define RIGHT_Y_AXIS  8


void adc_task (void *p_arg);

OS_TCB ADC_TaskTCB;  //������ƿ�
CPU_STK ADC_TASK_STK[ADC_STK_SIZE];  //�����ջ	


//����������			 
//���ز��� : �������
OS_ERR adc_task_create (void)
{
	  OS_ERR err;
		OSTaskCreate((OS_TCB 	* )&ADC_TaskTCB,		
				 (CPU_CHAR	* )"Task2 adc", 		
                 (OS_TASK_PTR )adc_task, 			
                 (void		* )0,					
                 (OS_PRIO	  )ADC_TASK_PRIO,     
                 (CPU_STK   * )&ADC_TASK_STK[0],	
                 (CPU_STK_SIZE)ADC_STK_SIZE/10,	
                 (CPU_STK_SIZE)ADC_STK_SIZE,		
                 (OS_MSG_QTY  )0,					
                 (OS_TICK	  )0,  					
                 (void   	* )0,					
                 (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR,
                 (OS_ERR 	* )&err);	
									
		return err;
}	

ADC_ROCKER rocker;
float battery;
u16 a,b;
//�������		 
//������� p_arg �״�ִ�в�����ַ
void adc_task (void *p_arg)
{
	OS_ERR err;

	u8 unlock = 0;
	u8 lock = 0;
	Adc_Init();
	
	while(1)
	{

		
			
		rocker.left_x = Get_Adc(LEFT_X_AXIS);  //////�ɼ�ͨ��1
		rocker.left_y = Get_Adc(LEFT_Y_AXIS);////////�ɼ�ͨ��2
		rocker.right_x = Get_Adc(RIGHT_X_AXIS);/////�ɼ�ͨ��3

		rocker.right_y = Get_Adc(RIGHT_Y_AXIS);/////�ɼ�ͨ��4
		
				
		//battery = 2*3.3*Get_Adc(BATTERY)/4096;
		//battery = Get_Adc(13);
		control_data_struct.lift = rocker.left_y/6;
		control_data_struct.pitch = (rocker.right_y - 2032)/16;
		control_data_struct.roll = (rocker.right_x - 2019)/16;
		if(control_data_struct.lift >100)////////��ֹ����ʱ����仯
			control_data_struct.yaw = (rocker.left_x - 2068)/16;
		else
			control_data_struct.yaw = 0;
		
		
		
		///////////��������
		#if 1
		///////////////////
		if(control_data_struct.pitch >= 10)
		{
			control_data_struct.pitch -= 10;
		}
		else if(control_data_struct.pitch <= -10)
		{
			control_data_struct.pitch += 10;
		}
		else
		{
			control_data_struct.pitch = 0;
		}
		////////////////////////////
		if(control_data_struct.roll >= 10)
		{
			control_data_struct.roll -= 10;
		}
		else if(control_data_struct.roll <= -10)
		{
			control_data_struct.roll += 10;
		}
		else
		{
			control_data_struct.roll = 0;
		}
		//////////////////////////////
		if(control_data_struct.yaw >= 10)
		{
			control_data_struct.yaw -= 10;
		}
		else if(control_data_struct.yaw <= -10)
		{
			control_data_struct.yaw += 10;
		}
		else
		{
			control_data_struct.yaw = 0;
		}
		#endif
		///////////////
		
		
		/////////�޷�
		#if 1
		if(control_data_struct.roll>=125)
			control_data_struct.roll=125;
		else if(control_data_struct.roll<=-125)
			control_data_struct.roll=-125;		
		if(control_data_struct.yaw>=125)
			control_data_struct.yaw=125;
		else if(control_data_struct.yaw<=-125)
			control_data_struct.yaw=-125;	
		if(control_data_struct.pitch>=125)
			control_data_struct.pitch=125;
		else if(control_data_struct.pitch<=-125)
			control_data_struct.pitch=-125;
		#endif
		////////////////////
		
		
		
		
		
		
		
		
		
		if(rocker.left_y < 25 && rocker.left_x > 3600)
		{
			unlock++;
			
			if(unlock > 100 )
			{
				control_data_struct.cmd = 1;
				unlock = 160;
				vibrates_mode = 2;
			}
		}
		else
		{
			unlock = 0;
		}
		
		if(rocker.left_y < 25 && rocker.left_x < 450)
		{
			lock++;
			
			if(lock > 15 )
			{
				control_data_struct.cmd = 2;
				lock = 160;
				vibrates_mode = 1;
			}
		}
		else
		{
			lock = 0;
		}
		


		OSTimeDlyHMSM(0,0,0,10,OS_OPT_TIME_PERIODIC,&err); //��ʱ10ms
		 //OSTimeDly(2,OS_OPT_TIME_PERIODIC,&err);   //��ʱ10ms
	}
}




