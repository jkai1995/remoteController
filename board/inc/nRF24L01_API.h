#ifndef __nRF24L01_API_H
#define __nRF24L01_API_H


#ifdef __cplusplus
extern "C"
{
#endif
	

#include "nRF24L01.h"
#define uchar unsigned char
#define uint unsigned int

#define NRF_CSN   PBout(5)  //Ƭѡ�źţ��������  
#define NRF_CE   	PBout(4)  // �������
#define NRF_MOSI  PBout(3)  // MOSI ����������� ���������ʳ�ʼ��PC_CR2�Ĵ�����
#define NRF_SCK   PDout(6)  //���ͽ���ģʽѡ���������
#define NRF_IRQ   PAin(15)  //IRQ������������,��������
#define NRF_MISO  PDin(3)  // MISO


//void delay_us(uchar num);
void delay_150us(void);
uchar SPI_RW(uchar byte);
uchar NRF24L01_Write_Reg(uchar reg,uchar value);
uchar NRF24L01_Read_Reg(uchar reg);
uchar NRF24L01_Read_Buf(uchar reg,uchar *pBuf,uchar len);
uchar NRF24L01_Write_Buf(uchar reg, uchar *pBuf, uchar len);
uchar NRF24L01_RxPacket(uchar *rxbuf);
uchar NRF24L01_TxPacket(uchar *txbuf);
uchar NRF24L01_Check(void);
void NRF24L01_RT_Init(void);
uchar SEND_BUF(uchar *buf);

#ifdef __cplusplus
}
#endif

#endif
