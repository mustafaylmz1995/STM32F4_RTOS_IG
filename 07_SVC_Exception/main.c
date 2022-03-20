#include "stm32f4xx.h"                  // Device header

void SVC_Handler_C(unsigned int * svc_args);


int __svc(0x00) svc_service_add(int x, int y);
int __svc(0x01) svc_service_sub(int x, int y);
int __svc(0x02) svc_service_mul(int x, int y);
int __svc(0x03) svc_service_div(int x, int y);

int x, y, z;



int main(void){
		x = 1;
		y = 5;
		z = svc_service_add(x,y); 
	
		x = 9;
		y = 2;
		z = svc_service_sub(x,y); 
	
		x = 3;
		y = 4;
		z = svc_service_mul(x,y); 

		x = 12;
		y = 6;
		z = svc_service_div(x,y); 
	
}

__asm void SVC_Handler(void){
	
	TST LR, #4	//0b 0100 return process stack or main stack
	ITE	EQ	//if equal to zero 
	MRSEQ R0, MSP //cpy MSP to R0
	MRSNE	R0, PSP	//or not equal to 0 cpy PSP to R0 
	B	__cpp(SVC_Handler_C) //create c version of svc handler by _c
	
}

void SVC_Handler_C(unsigned int * svc_args){
		unsigned int svc_number;
		svc_number = ((char *)svc_args[6])[-2]; //stack frame (6. index is PC)
	
		switch(svc_number){
			case 0:
					svc_args[0] = svc_args[0] + svc_args[1];
			
				break;
			
			case 1:
					svc_args[0] = svc_args[0] - svc_args[1];
			
				break;

			case 2:
					svc_args[0] = svc_args[0] * svc_args[1];
			
				break;		

			case 3:
					svc_args[0] = svc_args[0] / svc_args[1];
			
				break;			
		
		}
}
