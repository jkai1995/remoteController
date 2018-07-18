#ifndef __APP_VIBRATES_H
#define __APP_VIBRATES_H

#include "main.h"


class Vibrates 
{
public:
	u16 	period_us; //周期
	float	amplitude ;  //振幅 
////构造函数
	Vibrates (void);
	Vibrates (u16 per);
////析构函数
	~Vibrates(void);
////////接口函数
void set_vibrates (float ampli,u16 time_ms);
void set_vibrates (float ampli,u16 time_ms,u16 per);
private:
	void drive_vibrates (void);
};


#endif
