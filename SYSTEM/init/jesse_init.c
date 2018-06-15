#include "jesse_init.h"

static int start(void)
{
	return 0;
}
_INIT_EXPORT(start,"0");

static int board_start(void)
{
	return 0;
}
_INIT_EXPORT(board_start,"0.end");

static int board_end(void)
{
	return 0;
}
_INIT_EXPORT(board_end,"1.end");

static int end(void)
{
	return 0;
}
_INIT_EXPORT(end,"3.end");



void jesse_init_board_function(void)
{
	const _fn_init *fn_ptr;
	for(fn_ptr = &__init_board_start;fn_ptr<&__init_board_end;fn_ptr++)
	{
		(*fn_ptr)();
	}
}

void jesse_init_function(void)
{
	const _fn_init *fn_ptr;
	for(fn_ptr = &__init_board_end;fn_ptr<&__init_end;fn_ptr++)
	{
		(*fn_ptr)();
	}
}

void jesse_show_information(void)
{
	#ifdef CONSOLE
		mlt_printf(CONSOLE,"Programmer:JESSE\r\n");
		mlt_printf(CONSOLE,"project   :UPS\r\n");
	#endif 
}



int $Sub$$main(void)
{
	extern int $Super$$main(void);
	
	jesse_init_board_function();
	jesse_show_information();
	jesse_init_function();
	
	$Super$$main();
	
	return 0;
}

uint32_t SystemCoreClock = 0;
void SystemInit(void)
{
  RCC->CR 				|= (uint32_t)0x00000100; /*!< Set MSION bit */
  RCC->CFGR 			&= (uint32_t)0x88FF400C; /*!< Reset SW[1:0], HPRE[3:0], PPRE1[2:0], PPRE2[2:0], MCOSEL[2:0] and MCOPRE[2:0] bits */
  RCC->CR 				&= (uint32_t)0xFEF6FFF6; /*!< Reset HSION, HSIDIVEN, HSEON, CSSON and PLLON bits */
  RCC->CRRCR 			&= (uint32_t)0xFFFFFFFE; /*!< Reset HSI16ON  bit */
  RCC->CR 				&= (uint32_t)0xFFFBFFFF; /*!< Reset HSEBYP bit */
  RCC->CFGR 			&= (uint32_t)0xFF02FFFF; /*!< Reset PLLSRC, PLLMUL[3:0] and PLLDIV[1:0] bits */
  RCC->CIER 			 = (uint32_t)0x00000000; /*!< Disable all clock interrupt  */
	
	RCC->APB1ENR		|= (uint32_t)0x10000000; /*!< Power interface clock enabled*/
	PWR->CR					&= (uint32_t)0xFFFFEFFF; 
	 
	RCC->CR					|= (uint32_t)0x00000001; /*!<HSI16 enabled*/
	
	RCC->CFGR				&= (uint32_t)0xFFFFFF0F; /*!<Clean HCLK bit*/
	RCC->CFGR   		|= (uint32_t)0x00000070; /*!<HCLK:SYSCLK not divided*/
	RCC->CFGR				&= (uint32_t)0xFFFFF8FF; /*!<Clean PCLK1 bit*/
	RCC->CFGR   		|= (uint32_t)0x00000B00; /*!<PCLK1:HCLK not divided*/
	RCC->CFGR   		&= (uint32_t)0xFFFFC7FF; /*!<Clean PCLK2 bit*/
	RCC->CFGR   		|= (uint32_t)0x0000D000; /*!<PCLK2:HCLK not divided*/
	RCC->CFGR   		&= (uint32_t)0xFFFFFFFC; /*!<Clean SW bit*/
	RCC->CFGR   		|= (uint32_t)0x00000001; /*!<HSI16 oscillator used as system clock*/
	
	RCC->APB1ENR		&= (uint32_t)0xEFFFFFFF; /*!< Power interface clock disabled*/
	
	SystemCoreClock	 = (uint32_t)16000000U;
}









