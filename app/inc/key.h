#ifndef __KEY_H
#define __KEY_H

#include "main.h"

#define  PRESSED     0 //���� ����ʱ��ƽ
#define  UNPRESSED   1 //����̧��ʱ��ƽ

#define KEY_GET(x) Get_Key(x)

//ʹ�÷��� : KEY_Scan();���ڶ�ʱ�ж�ִ��
void KEY_Scan(void);


//Get_key_value();�ɷ��ذ�����Ϣ��
//��ⰴ��ʱ��������
//����ֵ   0��ʾû�а���
//         1,2,3,,,��ʾ��Ӧ��������
u8 Get_key_value(void);


/////////////////�������//////////////////
#define KEY_STK_SIZE 		128  //�����ջ��С	
extern OS_TCB KEY_TaskTCB;  //������ƿ�
extern CPU_STK KEY_TASK_STK[KEY_STK_SIZE];  //�����ջ	

OS_ERR key_task_create (void);//����������		
void key_task(void *p_arg);//����1��������



#endif
