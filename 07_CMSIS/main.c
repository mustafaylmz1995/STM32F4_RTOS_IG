#include "stm32f4xx.h"                  // Device header
#include "GPIO_Init.h"
#include "delay.h"


//uint32_t sw_state;

#define LED1        (1U<<12)	//PD12  greenLED
#define LED2        (1U<<13)	//PD13  orangeLED
#define LED3        (1U<<14)	//PD14  redLED
#define LED4        (1U<<15)	//PD15  blueLED

#define MODER_LED1  (1U<<24)
#define MODER_LED2  (1U<<26)
#define MODER_LED3  (1U<<28)
#define MODER_LED4  (1U<<30)

#define SW1         (1U<<0)	  //PA0 userSwitch
#define MODER_SW1   (0U<<0) 
#define PUM         (1U)      //Pull-Up mode
#define PDM         (2U)      //Pull-Down mode
#define PUM_SW1     (PUM<<0)
#define PDM_SW1     (PDM<<0)




int main(void){
  /*
  GPIO_Init();
  
  while(1){
		sw_state = SW1_Input();
		
		switch(sw_state){			
			case 1:
				Blink(1);
			break;
			case 2:
				Blink(2);
			break;
			case 3:
				Blink(3);
			break;
      case 4:
        Blink(4);
			default:
				Blink(5);
			break;
			
		}
		
	}
  */
  
  
  
  
  RCC->AHB1ENR  = RCC_AHB1ENR_GPIODEN | RCC_AHB1ENR_GPIOAEN;
  GPIOD->MODER  = (MODER_LED1 | MODER_LED2 | MODER_LED3 | MODER_LED4);
  
  GPIOA->MODER  = MODER_SW1;
  GPIOA->PUPDR  = PUM_SW1;
  
  GPIOD->ODR |= LED1;
  
  
  
}

