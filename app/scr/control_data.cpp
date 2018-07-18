#include "control_data.h"

Control_Data_TypeDef control_data_struct;

//向缓冲区装载需要发送的数据
void lode_send_data (u8 buf[])
{
	
	buf[1]=control_data_struct.cmd;		//命令
	control_data_struct.cmd = 0;
	buf[2]=control_data_struct.lift>>8;		//油门
	buf[3]=control_data_struct.lift;		//油门
	
	buf[4]=control_data_struct.pitch;	//俯仰
	buf[5]=control_data_struct.roll;		//滚动
	buf[6]=control_data_struct.yaw;		//偏航
	
	buf[0]=7;						//一共要发送5个字节，buf[0]必须是6！！！！！！

}

//读取已接收的数据
void lode_rece_data (u8 buf[])
{
	control_data_struct.lift = ((u16)buf[2]<<8) + buf[3];
}
