/*******************************************************************************
FILE NAME   : main.c
DESCRIPTION : Where all the magic begins.
	      

Copyright   : David Allegre
            : 2015
	    : All Rights Reserved
*******************************************************************************/
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "nucleoboard.h"
#include "hw_init.h"
#include "print.h"

char clr_scrn[] = { 27, 91, 50, 74, 0 };              // esc[2J
/* Public variables ----------------------------------------------------------*/
__IO uint32_t timer;
PRINT_DEFINEBUFFER();           /* required for lightweight sprintf */
/* Private prototype ---------------------------------------------------------*/
void delay(uint32_t time);

int sqrAsm(int value);

int div2Asm(int value);

int swapCharAsm(char* a, char* b);

char * myCstr;

/*******************************************************************************
Function Name   : main
Description     : 
Parameters      :
Return value    :               */
void main() {
uint8_t foo;

  foo = 10;
  Hw_init();

  PrintString(clr_scrn); /* Clear entire screen */
  // Change [My name] to your name      //
  PrintString("Joshua Lee Wirtner's Nucleo STM32F401 is ... alive!!!\n");
  RETAILMSG(1, ("Programming Assignment #1: Built %s %s.\r\n\r\n",
              __DATE__,
              __TIME__));  

  //int value = 1024;
  char message[50] = "\0";
  
  myCstr = message;
  //char a = 'A';
  //char b = 'A';
  
  int check = -1;
  
  while (foo) {
    
    
    GPIO_ToggleBits(GPIO_PORT_LD2, GPIO_PIN_LD2);
    
    //check = swapCharAsm(&a,&b);
    //sprintf(message, "char1: %c\nchar2: %c\nidentical(0: yes, 1: no): %d\n", a, b, check);
    
    //PrintString(message);
    
    sprintf(myCstr, "Current foo: %d\n", foo);
    foo = div2Asm(foo);
    
    delay(1000);
    GPIO_ToggleBits(GPIO_PORT_LD2, GPIO_PIN_LD2);
    
    delay(1000);
    //foo--;
  }
  while (1) {
    // loop forever
    asm("nop");
  }
}


void delay(uint32_t time) {
  
  timer = time;
  while(timer) {}
}
void SystemInit(void) {
  // System init is called from the assembly .s file
  // We will configure the clocks in hw_init
  asm("nop");
}
  