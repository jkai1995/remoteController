#include "CReceiveSend.h"
#include "main.h"
#include "CLed.h"

static CReceiveSend _CRS;
CReceiveSend* CReceiveSend::_instance = NULL;

CReceiveSend* CReceiveSend::getInstance(void)
{
//	if(_instance == NULL)
//	{
//		_instance = new CReceiveSend();
//	}
	return _instance;
}

CReceiveSend::CReceiveSend(void)
{
	m_sendMsg.eDataDire = eDataSend;
	m_pTcb = NULL;
	if(getInstance() == NULL)
		_instance = this;
}

bool CReceiveSend::initCRS(OS_TCB *tcb)
{
	m_pTcb = tcb;

	if(NRF24L01_Check() == 0)
	{
		m_Nrf2401IsExist = true;
		NRF24L01_RT_Init();
	}
	else
	{
		m_Nrf2401IsExist = false;
	}

	return m_Nrf2401IsExist;
}

void CReceiveSend::sendData(u8 *data,u16 len )
{

	if(m_pTcb == NULL
	        ||m_Nrf2401IsExist == false)
	{
		return;
	}

	OS_ERR err;
	m_sendMsg.data = data;
	m_sendMsg.len = len;
	OSTaskQPost (m_pTcb,
	             &m_sendMsg,
	             sizeof(m_sendMsg),
	             OS_OPT_POST_FIFO,
	             &err);

}

void CReceiveSend::run(void)
{
	OS_ERR err;
	CPU_TS ts;
	OS_MSG_SIZE msg_size;
	SRSMessage *srMsg;
	while(1)
	{
		srMsg = (SRSMessage*)OSTaskQPend (MILISECON_TO_TICK(0),
		                                  OS_OPT_PEND_BLOCKING,
		                                  &msg_size,
		                                  &ts,
		                                  &err);

		if(err == OS_ERR_NONE)
		{
			if(srMsg->eDataDire == eDataSend)
			{
				if(SEND_BUF(srMsg->data) == TX_OK)
				{
					CLed::getInstance()->setledMode(CLed::ePowerOn);
				}
				else
				{
					CLed::getInstance()->setledMode(CLed::eTxFail);
				}
			}
		}
	}
}

