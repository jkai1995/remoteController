#ifndef __CONTROL_DATA_H
#define __CONTROL_DATA_H

#include "main.h"

typedef struct
{
	u8 cmd; 		//����
	u16 lift;   //����
	s16 pitch;  //����
	s16 roll;   //����
	s16 yaw;    //ƫ��
} Control_Data_TypeDef; //ң������

extern Control_Data_TypeDef control_data_struct;


void lode_send_data (u8 buf[]);





#ifdef __cplusplus
extern "C"
{
#endif
/* c��������*/
#ifdef __cplusplus
}
#endif














#endif 
