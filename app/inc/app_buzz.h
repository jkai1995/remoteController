#ifndef __APP_BUZZ_H
#define __APP_BUZZ_H

#include "main.h"

/////////////////液晶屏任务信息//////////////////

#define BUZZ_STK_SIZE 		256  //任务堆栈大小	
extern OS_TCB BUZZ_TaskTCB;  //任务控制块
extern CPU_STK BUZZ_TASK_STK[BUZZ_STK_SIZE];  //任务堆栈	

extern u8 buzz_mode;
extern u8 vibrates_mode;

class Buzz
{
public:
//构造函数
	Buzz(void);
//析构函数
	~Buzz(void);
//访问接口
	void play (u16 const *pt_halfper,float const *pt_vo,u16 const Rhy,u8 const num);
private:
	u16 fre_hz;      //频率
	u16   per_us;		 //周期 微秒
  u16   half_per_us;		 //半周期 微秒 
	float volume;		 //音量

	void set_buzz(u16 const h_pe,float const vo); //设置蜂鸣器 半周期（us） 音量(%)
	void drive_buzz(void);
};





OS_ERR BUZZ_task_create (void);
void BUZZ_task (void *p_arg);
#endif
