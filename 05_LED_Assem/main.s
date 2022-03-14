                AREA	|.text|, CODE, READONLY, ALIGN=4 
                THUMB
                EXPORT    __main

greenLED        EQU       12
orangeLED       EQU       13
redLED          EQU       14
blueLED         EQU       15
portD           EQU       3

RCC_baseAddr    EQU       0x40023800
AHB1_enOffset   EQU       0x30

GPIOD_baseAddr  EQU       0x40020C00
GPIOD_dir       EQU       0x00
GPIOD_outpData  EQU       0x14
  
Delay           EQU       0x400000
 

__main
  BL        GPIO_Init
  
Loop
  BL        LED_Blink
  MOVS      R0, #0x00
  BL        Wait
  B         Loop
  
GPIO_Init
;GPIO Clock 
  LDR       R1, =RCC_baseAddr
  LDR       R2, =AHB1_enOffset
  ORR       R1, R1, R2   
  LDR       R0, [R1]
  
  MOV       R2, #0x01
  LSL       R2, R2, #portD
  
  ORR       R0, R0, R2            ;Because of Port D
  STR       R0, [R1]
;GPIO Direction(2 bits for every pin so we need to shift 2 times)
  LDR       R1, =GPIOD_baseAddr
  LDR       R2, =GPIOD_dir
  ORR       R1, R1, R2        
  LDR       R0, [R1]

  MOV       R2, #0x01
  LSL       R2, R2, #greenLED
  LSL       R2, R2, #greenLED
  MOV       R3, R2  
  MOV       R2, #0x01
  LSL       R2, R2, #orangeLED
  LSL       R2, R2, #orangeLED
  ORR       R3, R3, R2
  MOV       R2, #0x01
  LSL       R2, R2, #redLED
  LSL       R2, R2, #redLED
  ORR       R3, R3, R2
  MOV       R2, #0x01
  LSL       R2, R2, #blueLED
  LSL       R2, R2, #blueLED
  ORR       R3, R3, R2

  ORR       R0, R0, R3
  STR       R0, [R1]

  BX        LR

LED_Blink
  LDR       R1, =GPIOD_baseAddr
  LDR       R2, =GPIOD_outpData
  ORR       R1, R1, R2        
  LDR       R0, [R1]
  
  MOV       R2, #0x01
  LSL       R2, R2, #greenLED
  MOV       R3, R2  
  MOV       R2, #0x01
  LSL       R2, R2, #orangeLED
  ORR       R3, R3, R2
  MOV       R2, #0x01
  LSL       R2, R2, #redLED
  ORR       R3, R3, R2
  MOV       R2, #0x01
  LSL       R2, R2, #blueLED
  ORR       R3, R3, R2
  
  EOR       R0, R0, R3
  STR       R0, [R1]
    
  BX        LR

Wait
  ADDS      R0, R0, #0x01
  CMP       R0, #Delay
  BLT       Wait
  BX        LR

  
	ALIGN
	END