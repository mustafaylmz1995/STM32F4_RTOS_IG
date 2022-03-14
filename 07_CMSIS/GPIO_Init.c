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
  
  GPIOA->MODER  = MODER_SW1;
  GPIOA->PUPDR  = PUM_SW1;
  
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

void Blink(uint32_t L){
  
  LEDs Led = all;
  
  switch(L){
    case 1:
      Led = greenLED;
    break;
    case 2:
      Led = orangeLED;
    break;
    case 3:
      Led = redLED;
    break;
    case 4:
      Led = blueLED;
    break;
    default:
    break;
  }
  
  LED_On(Led);
  delay(1*ns2S);
  LED_Off(Led);
  delay(1*ns2S);

  
}


uint32_t SW1_Input(void){
  static uint32_t val = 0;
  
  if( (GPIOA->IDR & SW1) ){
    if(val == 3){
      val = 0;
    }else{
      val++;
    }
  }
  
  return val;
  
  
  
}


