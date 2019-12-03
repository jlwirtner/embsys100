#include "stm32f401xe.h"

void delay(int value);

void delay(int value)
{
  while(value != 0) {
    value--;
  }
  return;
}

int main()
{
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
  
  GPIOA->MODER = GPIO_MODER_MODE5_0;
  GPIOA->ODR |= GPIO_ODR_OD5;
  
  delay(10000000);
  
  GPIOA->ODR &= ~GPIO_ODR_OD5;
  
  return 0;
}
