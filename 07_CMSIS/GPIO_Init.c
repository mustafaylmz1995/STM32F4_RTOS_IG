/****************************************************
 *  GPIO_Init.c                                         
 *  Created on: 14-Mart-2022 15:46:06                      
 *  Implementation of the Class GPIO_Init      
 *  Original author: mustafa                     
 ****************************************************/
 
 
 
#include "GPIO_Init.h"


void GPIO_Init(void){
 
  RCC->AHB1ENR  = RCC_AHB1ENR_GPIODEN | RCC_AHB1ENR_GPIOAEN;
  GPIOD->MODER  = (MODER_LED1 | MODER_LED2 | MODER_LED3 | MODER_LED4);
  
  GPIOA->MODER  |= MODER_SW1;
  GPIOA->PUPDR  |= PDM_SW1;
	
	SYSCFG->EXTICR[1] = 0x00; //PA  
	EXTI->IMR 				= EXTI_IMR_IM0;
	EXTI->FTSR				=	EXTI_FTSR_TR0;
	NVIC->ICPR
	
	
}


void LED_On(LEDs L){

  switch(L){    
    case greenLED:
      GPIOD->ODR |= LED1;
    break;
    case orangeLED:
      GPIOD->ODR |= LED2;
    break;
    case redLED:
      GPIOD->ODR |= LED3;
    break;
    case blueLED:
      GPIOD->ODR |= LED4;
    break;
    case all:
      GPIOD->ODR |= LED1;
      GPIOD->ODR |= LED2;
      GPIOD->ODR |= LED3;
      GPIOD->ODR |= LED4;
    break;
    case none:
      GPIOD->ODR = 0U;
    default:

    break;
  }
  
  
}

void LED_Off(LEDs L){
  
  switch(L){
    case greenLED:
      GPIOD->ODR &= ~LED1;
    break;
    case orangeLED:
      GPIOD->ODR &= ~LED2;
    break;
    case redLED:
      GPIOD->ODR &= ~LED3;
    break;
    case blueLED:
      GPIOD->ODR &= ~LED4;
    break;
    case all:
      GPIOD->ODR &= ~LED1;
      GPIOD->ODR &= ~LED2;
      GPIOD->ODR &= ~LED3;
      GPIOD->ODR &= ~LED4;
    break;
    case none:
      GPIOD->ODR = 0xFFFFFFFFU;
    
    default:

    break;
  }
  
}



/*
To generate the interrupt, the interrupt line should be configured and enabled. This is done 
by programming the two trigger registers with the desired edge detection and by enabling 
the interrupt request by writing a ‘1’ to the corresponding bit in the interrupt mask register. 
When the selected edge occurs on the external interrupt line, an interrupt request is 
generated. The pending bit corresponding to the interrupt line is also set. This request is 
reset by writing a ‘1’ in the pending register.
*/
/*
To configure the 23 lines as interrupt sources, use the following procedure:
• Configure the mask bits of the 23 interrupt lines (EXTI_IMR)
• Configure the Trigger selection bits of the interrupt lines (EXTI_RTSR and EXTI_FTSR)
• Configure the enable and mask bits that control the NVIC IRQ channel mapped to the 
external interrupt controller (EXTI) so that an interrupt coming from one of the 23 lines 
can be correctly acknowledged.
*/

/*
eXTI0[3:0] BITS IN THE SYSCFG_exticr1 register

*/



uint32_t SW1_Input(void){
  static uint32_t val = 0;
  
  if( (GPIOA->IDR & SW1) ){
    if(val == 5){
      val = 0;
    }else{
      val++;
    }
  }
  
  return val;
  
  
  
}


