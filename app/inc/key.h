#ifndef __KEY_H
#define __KEY_H

#include "main.h"

#define  PRESSED     0 //按键 按下时电平
#define  UNPRESSED   1 //按键抬起时电平

#define KEY_GET(x) Get_Key(x)

//使用方法 : KEY_Scan();放在定时中断执行
void KEY_Scan(void);


//Get_key_value();可返回按键信息，
//检测按下时的跳变沿
//返回值   0表示没有按键
//         1,2,3,,,表示对应按键按下
u8 Get_key_value(void);


/////////////////按键检测//////////////////
#define KEY_STK_SIZE 		128  //任务堆栈大小	
extern OS_TCB KEY_TaskTCB;  //任务控制块
extern CPU_STK KEY_TASK_STK[KEY_STK_SIZE];  //任务堆栈	

OS_ERR key_task_create (void);//创建此任务		
void key_task(void *p_arg);//任务1的任务函数



#endif
