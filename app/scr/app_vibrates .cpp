#include "app_vibrates.h"

Vibrates::Vibrates (void)
{
	period_us = 1000;
	amplitude = 0;
	TIM2_PWM_A1_Init();
	TIM_SetCompare2(TIM2,period_us*amplitude);
}

Vibrates::Vibrates (u16 per)
{
	period_us = per;
	amplitude = 0;
	TIM2_PWM_A1_Init();
	TIM_SetCompare2(TIM2,period_us*amplitude);
}


void Vibrates::drive_vibrates(void)
{
	TIM_SetAutoreload(TIM2,period_us-1); //设置周期
	TIM_SetCompare2(TIM2,period_us*amplitude);//设置音量
}

void Vibrates::set_vibrates (float ampli,u16 time_ms)
{
	amplitude = ampli;
	TIM_SetCompare2(TIM2,period_us*amplitude);
	delay_ms(time_ms);
	amplitude = 0;
	TIM_SetCompare2(TIM2,period_us*amplitude);
}

void Vibrates::set_vibrates (float ampli,u16 time_ms,u16 per)
{
	amplitude = ampli;
	period_us = per;
	TIM_SetAutoreload(TIM5,period_us-1); //设置周期
	TIM_SetCompare2(TIM2,period_us*amplitude);
	delay_ms(time_ms);
	amplitude = 0;
	TIM_SetCompare2(TIM2,period_us*amplitude);
}

