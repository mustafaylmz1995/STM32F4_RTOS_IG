#include "stm32f4xx.h"                  // Device header

//Enable GPIO clock access
//Set the pin mode
//Set the output


#define greenLED		12
#define orangeLED		13
#define redLED			14
#define blueLED			15


#define RCC_baseAddr		0x40023800
#define AHB1_en_offset	0x30

#define GPIOD_baseAddr	0x40020C00
#define GPIO_OData			0x14


int main(void){
	
	
	*(uint32_t *)(RCC_baseAddr + AHB1_en_offset) = (1U<<3); // Because of Port D
	
	*(uint32_t *)(GPIOD_baseAddr) = ( ((1U)<< 2*greenLED) | ((1U)<< 2*orangeLED) | ((1U)<< 2*redLED) | ((1U)<< 2*blueLED) ); //GPIO output mode
	
	
	while(1){
	
	*(uint32_t *)(GPIOD_baseAddr + GPIO_OData) ^=( (1U<<greenLED) | (1U<<orangeLED) | (1U<<redLED) | (1U<<blueLED)  );
		
	
		for(int i = 0; i<7*1024*1024; i++){};
		
	}	
		
}

