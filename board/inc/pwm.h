#ifndef _PWM_H
#define _PWM_H
#include "stm32f4xx_conf.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK STM32F407������
//��ʱ�� ��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2014/6/16
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	

void TIM14_PWM_Init(u32 arr,u32 psc);

void TIM2_PWM_Base_Init(u32 arr,u32 psc);
void TIM2_PWM_B10_Init(void);//lcd back light
void TIM2_PWM_A1_Init(void);//vibrates motor

void TIM5_PWM_Init(u32 arr,u32 psc);//buzzer

void TIM9_PWM_Init(u32 arr,u32 psc);

void TIM12_PWM_Init(u32 arr,u32 psc);

void TIM1_PWM_Init(u32 arr,u32 psc);


void TIM3_Int_Init(u16 arr,u16 psc);
extern u16 run_time_us; 
void TIM3_time_start (void);
u16 TIM3_time_over (void);
#endif
