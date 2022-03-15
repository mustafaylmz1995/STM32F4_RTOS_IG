/****************************************************
 *  GPIO_Init.h                                         
 *  Created on: 14-Mart-2022 15:46:06                      
 *  Implementation of the Class GPIO_Init      
 *  Original author: mustafa                     
 ****************************************************/

#if !defined (__GPIO_INIT_H__)
#define __GPIO_INIT_H__


#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f4xx.h" 
#include "delay.h"

typedef unsigned int uint32_t;


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

void GPIO_Init(void);

void LED_On(uint8_t L);
void LED_Off(uint8_t L);


uint32_t SW1_Input(void);




#ifdef __cplusplus
}
#endif


#endif /*!defined(__GPIO_INIT_H__)*/
