/****************************************************
 *  delay.c                                         
 *  Created on: 14-Mart-2022 15:43:06                       
 *  Implementation of the Class delay       
 *  Original author: mustafa                     
 ****************************************************/
#include "delay.h"

void delay(int time){
  int volatile delay=0;
  
  while(delay<time)
    ++delay;
}
