#include "bsp_led.h"

static GPIO_TypeDef* LED_PORT[LED_MAX]={ GPIOB, GPIOE,GPIOA};
static const u16 LED_PIN[LED_MAX]={GPIO_Pin_6, GPIO_Pin_4,GPIO_Pin_12};

void LED_Init(void)
{
  	GPIO_InitTypeDef  GPIO_InitStructure;
	  u8 i;

  	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE|RCC_AHB1Periph_GPIOB|RCC_AHB1Periph_GPIOA, ENABLE);
	
	for(i = 0;i < LED_MAX; i++)
	{
  	GPIO_InitStructure.GPIO_Pin = LED_PIN[i];       
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  	GPIO_Init(LED_PORT[i], &GPIO_InitStructure);
	}
	
	LEDOff(LED0);
	LEDOff(LED1);
	LEDOff(LED2);

}

void LEDOff(Led_Def Led)//LEDÃð
{
  	LED_PORT[Led]->BSRRL=LED_PIN[Led];
}

void LEDOn(Led_Def Led)//LEDÁÁ
{
  	LED_PORT[Led]->BSRRH=LED_PIN[Led];  
}

void LEDTog(Led_Def Led)//LED×´Ì¬·­×ª
{
  	LED_PORT[Led]->ODR^=LED_PIN[Led];
}

unsigned char isLEDOn(Led_Def Led)
{
	return (LED_PORT[Led]->ODR&LED_PIN[Led]==0)?(0):(1);
}

