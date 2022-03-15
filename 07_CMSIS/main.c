#include "stm32f4xx.h"                  // Device header
#include "GPIO_Init.h"
#include "delay.h"


uint32_t sw_state;


int main(void){

  GPIO_Init();

  LED_On(5);
  
  
  while(1){
//    LED_On(SW1_Input());
//    delay(1*ns2S);
//    LED_Off(5);
//    delay(1*ns2S);
  }


}
