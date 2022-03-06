#include "stm32f4xx.h"                  // Device header

//Enable GPIO clock access
//Set the pin mode
//Set the output


#define greenLED		12
#define orangeLED		13
#define redLED			14
#define blueLED			15






int main(void){

//PERIPH_BASE           0x40000000UL
//AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000UL)
//RCC_BASE              (AHB1PERIPH_BASE + 0x3800UL)
//#define RCC_baseAddr		0x40023800
	
//In RCC struct AHB1ENR
//#define AHB1_en_offset	0x30

//RCC_AHB1ENR_GPIODEN_Pos            (3U)                                
//RCC_AHB1ENR_GPIODEN_Msk            (0x1UL << RCC_AHB1ENR_GPIODEN_Pos)   /*!< 0x00000008 */
//RCC_AHB1ENR_GPIODEN                RCC_AHB1ENR_GPIODEN_Msk 
	
//	*(uint32_t *)(RCC_baseAddr + AHB1_en_offset) = (1U<<3); // Because of Port D
	RCC->AHB1ENR = RCC_AHB1ENR_GPIODEN;
	
	
	
//PERIPH_BASE           0x40000000UL
//AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000UL)
//GPIOD_BASE            (AHB1PERIPH_BASE + 0x0C00UL)
//#define GPIOD_baseAddr	0x40020C00

//MODER address offset 0x00

//	*(uint32_t *)(GPIOD_baseAddr) = ( ((1U)<< 2*greenLED) | ((1U)<< 2*orangeLED) | ((1U)<< 2*redLED) | ((1U)<< 2*blueLED) ); //GPIO output mode
	GPIOD->MODER = ( ((1U)<< 2*greenLED) | ((1U)<< 2*orangeLED) | ((1U)<< 2*redLED) | ((1U)<< 2*blueLED) ); //GPIO output mode
	
	while(1){
	
		
//  __IO uint32_t ODR;      /*!< GPIO port output data register,        Address offset: 0x14      */		
//#define GPIO_OData			0x14

		
//	*(uint32_t *)(GPIOD_baseAddr + GPIO_OData) ^=( (1U<<greenLED) | (1U<<orangeLED) | (1U<<redLED) | (1U<<blueLED)  );
		GPIOD->ODR ^= ( (1U<<greenLED) | (1U<<orangeLED) | (1U<<redLED) | (1U<<blueLED)  );
	
		for(int i = 0; i<7*1024*1024; i++){};
		
	}	
		
}

