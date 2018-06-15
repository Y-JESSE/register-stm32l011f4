#include "jesse_usart2.h"

int jesse_usart2_init(void)
{
	RCC->IOPENR 		|= (uint32_t)0x00000001;					/*!<port A clock enabled*/
	GPIOA->MODER		&= (uint32_t)0xFFC3FFFF;					/*!<clean mode10 mode9 bit*/
	GPIOA->MODER		|= (uint32_t)0x00240000;					/*!<alternate function mode,general purpose output mode*/
	GPIOA->OSPEEDR	&= (uint32_t)0xFFC3FFFF;					/*!<clean ospeed10 ospeed9 bit*/
	GPIOA->OSPEEDR	|= (uint32_t)0x00280000;					/*!<high speed*/
	GPIOA->OTYPER		&= (uint32_t)0xFFFFF9FF;					/*!<clean ot9 ot10 bit,output push-pull*/
	GPIOA->PUPDR		&= (uint32_t)0xFFC3FFFF;					/*!<clean pupd10 pupd9 bit*/
	GPIOA->PUPDR		|= (uint32_t)0x00140000;					/*!<pull-up*/
	GPIOA->AFR[1]		&= (uint32_t)0xFFFFF00F;					/*!<clean AFSEL10 AFSEL9 bit*/
	GPIOA->AFR[1]		|= (uint32_t)0x00000440;					/*!<AF4*/

	RCC->APB1ENR		|= (uint32_t)0x00020000;					/*!<USART2 clock enabled*/
	USART2->BRR			 = (uint16_t)SystemCoreClock/9600;/*!<Baud rate 9600*/
	USART2->CR1
	
}