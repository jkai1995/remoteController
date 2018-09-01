#ifndef __nRF24L01_API_H
#define __nRF24L01_API_H


#ifdef __cplusplus
extern "C"
{
#endif
	

#include "nRF24L01.h"
#define uchar unsigned char
#define uint unsigned int

#define NRF_CSN   PBout(5)  //片选信号，推挽输出  
#define NRF_CE   	PBout(4)  // 推完输出
#define NRF_MOSI  PBout(3)  // MOSI 主机推挽输出 （根据速率初始化PC_CR2寄存器）
#define NRF_SCK   PDout(6)  //发送接收模式选择推挽输出
#define NRF_IRQ   PAin(15)  //IRQ主机数据输入,上拉输入
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
