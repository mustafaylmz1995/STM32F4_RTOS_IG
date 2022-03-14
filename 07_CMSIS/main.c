#include "stm32f4xx.h"                  // Device header
#include "GPIO_Init.h"
#include "delay.h"


uint32_t sw_state;

int main(void){

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


}

