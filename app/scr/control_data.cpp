#include "control_data.h"

Control_Data_TypeDef control_data_struct;

//�򻺳���װ����Ҫ���͵�����
void lode_send_data (u8 buf[])
{
	
	buf[1]=control_data_struct.cmd;		//����
	control_data_struct.cmd = 0;
	buf[2]=control_data_struct.lift>>8;		//����
	buf[3]=control_data_struct.lift;		//����
	
	buf[4]=control_data_struct.pitch;	//����
	buf[5]=control_data_struct.roll;		//����
	buf[6]=control_data_struct.yaw;		//ƫ��
	
	buf[0]=7;						//һ��Ҫ����5���ֽڣ�buf[0]������6������������

}

//��ȡ�ѽ��յ�����
void lode_rece_data (u8 buf[])
{
	control_data_struct.lift = ((u16)buf[2]<<8) + buf[3];
}
