#define RCC_BASE 0x40023800
#define RCC_AHB1ENR (*((unsigned int*)(RCC_BASE + 0x30)))

#define ENABLE_AHB1 0x1

#define GPIOA_BASE 0x40020000
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE)))
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14)))

#define ODR5 0x20

#define MODE5_OUTPUT 0x400

void setupUserLED(){
  RCC_AHB1ENR |= ENABLE_AHB1;
  GPIOA_MODER |= MODE5_OUTPUT;
}

void turnOnUserLED() {
  GPIOA_ODR |= ODR5;
}

void turnOffUserLED() {
  GPIOA_ODR &= ~ODR5;
}