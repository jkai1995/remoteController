#ifndef __APP_VIBRATES_H
#define __APP_VIBRATES_H

#include "main.h"


class Vibrates 
{
public:
	u16 	period_us; //����
	float	amplitude ;  //��� 
////���캯��
	Vibrates (void);
	Vibrates (u16 per);
////��������
	~Vibrates(void);
////////�ӿں���
void set_vibrates (float ampli,u16 time_ms);
void set_vibrates (float ampli,u16 time_ms,u16 per);
private:
	void drive_vibrates (void);
};


#endif
