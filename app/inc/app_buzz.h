#ifndef __APP_BUZZ_H
#define __APP_BUZZ_H

#include "main.h"

/////////////////Һ����������Ϣ//////////////////

#define BUZZ_STK_SIZE 		256  //�����ջ��С	
extern OS_TCB BUZZ_TaskTCB;  //������ƿ�
extern CPU_STK BUZZ_TASK_STK[BUZZ_STK_SIZE];  //�����ջ	

extern u8 buzz_mode;
extern u8 vibrates_mode;

class Buzz
{
public:
//���캯��
	Buzz(void);
//��������
	~Buzz(void);
//���ʽӿ�
	void play (u16 const *pt_halfper,float const *pt_vo,u16 const Rhy,u8 const num);
private:
	u16 fre_hz;      //Ƶ��
	u16   per_us;		 //���� ΢��
  u16   half_per_us;		 //������ ΢�� 
	float volume;		 //����

	void set_buzz(u16 const h_pe,float const vo); //���÷����� �����ڣ�us�� ����(%)
	void drive_buzz(void);
};





OS_ERR BUZZ_task_create (void);
void BUZZ_task (void *p_arg);
#endif
