#include "app_lcd.h"
#include "includes.h"
#include "os_app_hooks.h"
OS_TCB LCD_TaskTCB;  //������ƿ�
CPU_STK LCD_TASK_STK[LCD_STK_SIZE];  //�����ջ	



OS_ERR lcd_task_create (void)
{
		OS_ERR err;
		OSTaskCreate((OS_TCB 	* )&LCD_TaskTCB,//������ƿ�		
				 (CPU_CHAR	* )"Task3 lcd",///��������֣���Ҫ̫������� 		
                 (OS_TASK_PTR )lcd_task, ///�����ִ�к����������涨��			
                 (void		* )0,					
                 (OS_PRIO	  )LCD_TASK_PRIO, ///���ȼ������ȼ���h�ļ�����    
                 (CPU_STK   * )&LCD_TASK_STK[0],///��ջ������	
                 (CPU_STK_SIZE)LCD_STK_SIZE/10,	///��ջ�������ٽ�����
                 (CPU_STK_SIZE)LCD_STK_SIZE,	///��ջ�Ĵ�С	
                 (OS_MSG_QTY  )0,					
                 (OS_TICK	  )0,  					
                 (void   	* )0,					
                 (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR,
                 (OS_ERR 	* )&err);	
									
		return err;
}


/////��������
void lcd_task (void *p_arg)
{
	OS_ERR err;
	u8 str[20];
	CPU_SR_ALLOC();

	LCD_Init();			//LCD��ʼ��	
	TIM2_PWM_B10_Init();
	TIM_SetCompare3(TIM2,200);
	OS_CRITICAL_ENTER();//�����ٽ���
	tp_dev.init();				//��������ʼ��
  OS_CRITICAL_EXIT();	//�˳��ٽ���	
	BACK_COLOR = RED;
	POINT_COLOR = BLACK;
	u8 last_t_f = 0;
	u16 lx,ly;
	u16 rantime;
	while(1)
	{
		
			
//////		TIM3_time_start();
//////		BACK_COLOR = BLACK;
//////		POINT_COLOR = WHITE;
//////	//	sprintf((char *)str,"lef_x:%8d",rocker.left_x);// ��14���ַ�
//////		LCD_ShowString(0,0,168,24,24,str);		//��ʾһ���ַ���,12/16/24���� 1206/1608/2412
//////		
//////			run_time_us = TIM3_time_over();
//////		sprintf((char *)str,"lef_y:%8d",rocker.left_y);// ��14���ַ�
//////		LCD_ShowString(0,24,168,24,24,str);		//��ʾһ���ַ���,12/16/24���� 1206/1608/2412
//////		sprintf((char *)str,"rig_x:%8d",rocker.right_x);// ��14���ַ�
//////		LCD_ShowString(0,48,168,24,24,str);		//��ʾһ���ַ���,12/16/24���� 1206/1608/2412
//////		sprintf((char *)str,"rig_y:%8d",rocker.right_y);// ��14���ַ�
//////		LCD_ShowString(0,72,168,24,24,str);	
//////		
//////		sprintf((char *)str,"c_lif:%8d",control_data_struct.lift);// ��14���ַ�
//////		LCD_ShowString(0,120,168,24,24,str);	
//////		sprintf((char *)str,"c_pit:%8d",control_data_struct.pitch);// ��14���ַ�
//////		LCD_ShowString(0,144,168,24,24,str);	
//		sprintf((char *)str,"c_rol:%8d",x);// ��14���ַ�
//		LCD_ShowString(0,168,168,24,24,str);	
		
//		sprintf((char *)str,"c_yaw:%8d",control_data_struct.yaw);// ��14���ַ�
//		LCD_ShowString(0,192,168,24,24,str);
	
//////		
//////	
//OS_CRITICAL_ENTER();//�����ٽ���
rantime = run_time_us;


		sprintf((char *)str,"pr_ti:%8d",rantime);// ��14���ַ�
		LCD_ShowString(0,240,168,24,24,str);	
		
//////	

		tp_dev.scan(0);
		
		//LCD_Fill(430,0,479,30,BROWN);
		sprintf((char *)str,"Clear");// ��14���ַ�
		LCD_ShowString(415,3,479,30,24,str);
		
		
		//OS_CRITICAL_EXIT();	//�˳��ٽ���	
		if(tp_dev.sta&0x80)////����а���
		{
			last_t_f++;
			if(last_t_f >2)
				last_t_f=2;
			
			POINT_COLOR = WHITE;
		///	LCD_Draw_Circle(tp_dev.x[0],tp_dev.y[0],20);
			LCD_Fast_DrawPoint(tp_dev.x[0],tp_dev.y[0],WHITE);
			
			if(last_t_f == 2)
			LCD_DrawLine(lx,ly,tp_dev.x[0],tp_dev.y[0]);
			
			lx = tp_dev.x[0];
			ly = tp_dev.y[0];
			
			
			if(tp_dev.x[0]>410&&tp_dev.y[0]<30)
			{
				LCD_Clear(BLACK);//����
				
				
			}
			
			if(tp_dev.x[0]>440)
				TIM_SetCompare3(TIM2,tp_dev.y[0]);
			///473  12 
		}
		else
		{
			last_t_f = 0;
		}


		OSTimeDlyHMSM(0,0,0,25,OS_OPT_TIME_PERIODIC,&err); //��ʱ25ms
	}
}




