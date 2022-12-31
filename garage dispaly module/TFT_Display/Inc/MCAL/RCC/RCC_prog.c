/*
 * RCC_prog.c
 *
 *  Created on: Dec 10, 2022
 *      Author: abano
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_config.h"
#include "RCC_private.h"
#include "RCC_interface.h"
void MRCC_vInitSystemCLK(void)
{
#if SYS_CLOCK_SRC == HSE
	#if HSE_CLOCK_SRC == CRYSTAL_CLOCK
	CLR_BIT(MRCC->CR,HSEBYP);
	#elif HSE_CLOCK_SRC == RC_CLOCK
	SET_BIT(MRCC->CR,HSEBYP);
	#else
		#error"wrong config";
	#endif
	SET_BIT(MRCC->CR,HSEON);
	while(!GET_BIT(MRCC->CR,HSERDY));
	MRCC->CFGR |= HSE;
	while(!(MRCC->CFGR & HSE));
#elif  SYS_CLOCK_SRC == PLL_CLOCK
	#if PLL_CLOCK_SRC == HSE
		#if HSE_CLOCK_SRC == CRYSTAL_CLOCK
			CLR_BIT(MRCC->CR,HSEBYP);
		#elif HSE_CLOCK_SRC == RC_CLOCK
			SET_BIT(MRCC->CR,HSEBYP);
		#else
			#error"wrong config";
		#endif
		SET_BIT(MRCC->CR,HSEON);
		while(!GET_BIT(MRCC->CR,HSERDY));
	#elif PLL_CLOCK_SRC == HSI
		SET_BIT(MRCC->CR,HSION);
		while(!GET_BIT(MRCC->CR,HSIRDY));

	#else
		#error"wrong config";
	#endif
	MRCC->PLLCFGR &= ~(1<<PLLSRC);
	MRCC->PLLCFGR |= (PLL_CLOCK_SRC<<PLLSRC);
	SET_BIT(MRCC->CR,PLLON);
	while(!GET_BIT(MRCC->CR,PLLRDY));
	MRCC->CFGR |= PLL_CLOCK;
	while(!(MRCC->CFGR & HSE));
#elif SYS_CLOCK_SRC == HSI
	SET_BIT(MRCC->CR,HSION);
	while(!GET_BIT(MRCC->CR,HSIRDY));
	MRCC->CFGR |= HSI;
#else
	#error"wrong config";
#endif

}

void MRCC_vEnableClock(BusName_t BusName , u8 Copy_u8PerNum )
{
	if(BusName == AHB1 ||BusName == AHB2)
	{
		SET_BIT(MRCC->AHB_ENR[BusName],Copy_u8PerNum);
	}
	else if(BusName == APB1 ||BusName == APB2)
	{
		SET_BIT(MRCC->APB_ENR[BusName-APB1],Copy_u8PerNum);
	}
}

void MRCC_vDisableClock(BusName_t BusName , u8 Copy_u8PerNum )
{
	if(BusName == AHB1 ||BusName == AHB2)
	{
		CLR_BIT(MRCC->AHB_ENR[BusName],Copy_u8PerNum);
	}
	else if(BusName == APB1 ||BusName == APB2)
	{
		CLR_BIT(MRCC->APB_ENR[BusName-APB1],Copy_u8PerNum);
	}
}
