#include "CLed.h"
#include "main.h"

static CLed led;
CLed* CLed::_instance = NULL;


CLed::CLed()
{
	m_eLedMod = ePowerOn;
	m_pTcb = NULL;
	if(_instance == NULL)
	{
		_instance = this;
	}
}

CLed *CLed::getInstance()
{
	return _instance;
}

void CLed::init(OS_TCB *tcb)
{
	m_pTcb = tcb;

	LED_Init();
}

void CLed::run()
{
	OS_ERR err;
	CPU_TS ts;

	while(1)
	{
		OSTaskSemPend(MILISECON_TO_TICK(1000),
		              OS_OPT_PEND_BLOCKING,
		              &ts,
		              &err);

		if(m_eLedMod == ePowerOn)
		{
			twinkle(1,1000);
		}
		else if(m_eLedMod == eTxFail)
		{
			m_eLedMod = ePowerOn;
			twinkle(2,100);
			
		}

	}
}

void CLed::setledMode(ELedMod mod)
{
	if(mod >= eLedModEnd)
		return;
	m_eLedMod = mod;

	if(m_pTcb == NULL)
		return;

	OS_ERR err;
	OSTaskSemSet(m_pTcb,0,&err);
	OSTaskSemPost(m_pTcb,
	              OS_OPT_POST_FIFO,
	              &err);
}

void CLed::twinkle(u16 n,u16 tms)
{
	OS_ERR err;
	for(int i = 0; i < n; i++)
	{
		LEDTog(LED0);
		LEDTog(LED1);
		LEDTog(LED2);
		OSTimeDly(MILISECON_TO_TICK(tms),OS_OPT_TIME_DLY,&err);//MILISECON_TO_TICK(tms)
	}
}


