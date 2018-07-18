#ifndef __CONTROL_DATA_H
#define __CONTROL_DATA_H

#include "main.h"

typedef struct
{
	u8 cmd; 		//ÃüÁî
	u16 lift;   //ÓÍÃÅ
	s16 pitch;  //¸©Ñö
	s16 roll;   //¹ö¶¯
	s16 yaw;    //Æ«º½
} Control_Data_TypeDef; //Ò£¿ØÃüÁî

extern Control_Data_TypeDef control_data_struct;


void lode_send_data (u8 buf[]);





#ifdef __cplusplus
extern "C"
{
#endif
/* cÓïÑÔÄÚÈİ*/
#ifdef __cplusplus
}
#endif














#endif 
