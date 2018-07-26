#ifndef CRECEIVESEND_H
#define CRECEIVESEND_H




#ifdef __cplusplus
extern "C"
{
#endif
	
#include "nRF24L01_API.h"	
#include "stm32f4xx.h"
#include "includes.h"
//#include "stdio.h"
	
#ifdef __cplusplus
}
#endif

enum EDataDirection
{
	eDataReceive,
	eDataSend,
	eDataDirectionEnd,
};


//data receive and send
class CReceiveSend
{
public:
	struct SRSMessage
	{
		EDataDirection eDataDire;
		uint8_t *data;
		uint16_t len;
	};
	CReceiveSend(void);
	static CReceiveSend* getInstance(void);
	void sendData(u8 *data,u16 len);
	bool RSModuleIsExist(){return m_Nrf2401IsExist;}
	//void setTCB(OS_TCB *tcb);
	bool initCRS(OS_TCB *tcb);
	void run(void);
private:
		OS_TCB *m_pTcb;
		SRSMessage m_sendMsg; 
		bool m_Nrf2401IsExist;
		static CReceiveSend *_instance;
};



#endif
