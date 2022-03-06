#include "stm32f4xx.h"                  // Device header

#define greenLED		12
#define orangeLED		13
#define redLED			14
#define blueLED			15

void GPIO_Init(void);
uint32_t getTicks(void);
void waitSecond(uint32_t sec);


uint32_t ticks = 0U;
uint32_t _ticks = 0U;


void greenLEDON(void);
void greenLEDOFF(void);
void orangeLEDON(void);
void orangeLEDOFF(void);
void redLEDON(void);
void redLEDOFF(void);
void blueLEDON(void);
void blueLEDOFF(void);

void greenMain(void);
void orangeMain(void);

int main(void){
	
	GPIO_Init();
	
	uint8_t volatile start = 0U;
	
	start ? orangeMain() : greenMain();
	
	
	while(1){
		
	}
		
}

void GPIO_Init(void){
	
	
	RCC->AHB1ENR = RCC_AHB1ENR_GPIODEN;
	GPIOD->MODER = ( ((1U)<< 2*greenLED) | ((1U)<< 2*orangeLED) | ((1U)<< 2*redLED) | ((1U)<< 2*blueLED) ); //GPIO output mode
	
	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock / 1000U); //every ms
	__enable_irq();	
	
}


void SysTick_Handler(void){	
	++ticks;	
}

uint32_t getTicks(void){
	__disable_irq();
	_ticks = ticks;
	__enable_irq();
	
	return _ticks;
}

void waitSecond(uint32_t sec){
	sec *=1000U; //seconds to miliseconds
	uint32_t temp = getTicks();
	
	while( sec  != (getTicks() - temp)){}
	
}

void greenLEDON(void)		{	GPIOD->ODR |=	(1U<<greenLED); 	}
void greenLEDOFF(void)	{	GPIOD->ODR &=~(1U<<greenLED);		}
void orangeLEDON(void)	{	GPIOD->ODR |=	(1U<<orangeLED);	}
void orangeLEDOFF(void)	{	GPIOD->ODR &=~(1U<<orangeLED);	}
void redLEDON(void)			{	GPIOD->ODR |=	(1U<<redLED); 		}
void redLEDOFF(void)		{	GPIOD->ODR &=~(1U<<redLED);			}
void blueLEDON(void)		{	GPIOD->ODR |=	(1U<<blueLED); 		}
void blueLEDOFF(void)		{	GPIOD->ODR &=~(1U<<blueLED);		}


void greenMain(void){
	while(1){
		greenLEDON();
		waitSecond(1);
		greenLEDOFF();
		waitSecond(1);
		
	}
	
}


void orangeMain(void){
	while(1){
		orangeLEDON();
		waitSecond(1);
		orangeLEDOFF();
		waitSecond(1);
		
	}
	
}

