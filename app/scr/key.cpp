#include "key.h"

 u8  key_down = 0; //按键按下标志

void KEY_Scan(void)
{	 
	static u8 key_up=UNPRESSED;

 if(key_up == UNPRESSED && key_down == 0) ///////扫描是否有按键按下
	{
				(KEY_GET(KEY0)==PRESSED)?(key_down += 1) : (key_down += 0);
				(KEY_GET(KEY1)==PRESSED)?(key_down += 2) : (key_down += 0);
				(KEY_GET(KEY2)==PRESSED)?(key_down += 3) : (key_down += 0);
				(KEY_GET(KEY3)==PRESSED)?(key_down += 4) : (key_down += 0);	
		if(key_down > 0)
		  key_up = PRESSED;
	}
	else if(1               ////扫描按下以后是否抬起
				  &&KEY_GET(KEY0)==UNPRESSED
				  &&KEY_GET(KEY1)==UNPRESSED
				  &&KEY_GET(KEY2)==UNPRESSED
				  &&KEY_GET(KEY3)==UNPRESSED
				  )
	{
				key_up=UNPRESSED; 	
	}

}

u8 Get_key_value(void)
{
	u8 i = key_down;
	key_down = 0;
	return i;
}

OS_TCB KEY_TaskTCB;  //任务控制块
CPU_STK KEY_TASK_STK[KEY_STK_SIZE];  //任务堆栈	
//创建此任务			 
//返回参数 : 错误代码
OS_ERR key_task_create (void)
{
	  OS_ERR err;
		//创建TASK1任务
	OSTaskCreate((OS_TCB 	* )&KEY_TaskTCB,
				 (CPU_CHAR	* )"Task1 key", 		
                 (OS_TASK_PTR )key_task, 			
                 (void		* )0,					
                 (OS_PRIO	  )KEY_TASK_PRIO,     
                 (CPU_STK   * )&KEY_TASK_STK[0],	
                 (CPU_STK_SIZE)KEY_STK_SIZE/10,	
                 (CPU_STK_SIZE)KEY_STK_SIZE,		
                 (OS_MSG_QTY  )0,					
                 (OS_TICK	  )0,  					
                 (void   	* )0,					
                 (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR,
                 (OS_ERR 	* )&err);
									
		return err;
}	
//任务1的任务函数
void key_task(void *p_arg)
{
	u8 key,num;
	OS_ERR err;
		

	Key_Init();			//按键初始化

	
	while(1)
	{
		KEY_Scan();
		key = Get_key_value();
		key = key;
		num++;
		if(num==50) //每500msLED0闪烁一次
		{
			num = 0;
//			LEDTog(LED0);	
		}
		OSTimeDlyHMSM(0,0,0,10,OS_OPT_TIME_PERIODIC,&err);   //延时10ms
	}
}


