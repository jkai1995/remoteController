#ifndef CLED_H
#define CLED_H




#ifdef __cplusplus
extern "C"
{
#endif

#include "bsp_led.h"
#include "stm32f4xx.h"
#include "includes.h"
//#include "stdio.h"

#ifdef __cplusplus
}
#endif

///////////////led class
class CLed
{
public:
	enum ELedMod
	{
		ePowerOn,
		eTxFail,
		eLedModEnd,
	};
	CLed();
	void init(OS_TCB *tcb);
	static CLed * _instance;
	static CLed *getInstance();
	void run();

	void setledMode(ELedMod mod);
private:
	ELedMod m_eLedMod;
	OS_TCB *m_pTcb;
	void twinkle(u16 n,u16 tms);
};




#endif
