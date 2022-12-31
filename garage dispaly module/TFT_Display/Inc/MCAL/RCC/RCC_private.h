/*
 * RCC_private.h
 *
 *  Created on: Dec 10, 2022
 *      Author: abano
 */

#ifndef MCAL_RCC_RCC_PRIVATE_H_
#define MCAL_RCC_RCC_PRIVATE_H_

#define RCC_BASE_ADD				0x40023800

#define HSI      			0
#define HSE      			1
#define PLL_CLOCK			2

#define RC_CLOCK			10
#define CRYSTAL_CLOCK		66



#define PLLRDY				25
#define PLLON				24
#define HSEBYP				18
#define HSERDY				17
#define HSEON				16
#define HSIRDY				1
#define HSION				0

#define PLLSRC				22

typedef struct{
	volatile u32 CR;
	volatile u32 PLLCFGR;
	volatile u32 CFGR;
	volatile u32 CIR;
	volatile u32 AHB_RSTR[2];
	volatile u32 Reserved_0[2];
	volatile u32 APB_RSTR[2];
	volatile u32 Reserved_7[2];
	volatile u32 AHB_ENR[2];
	volatile u32 Reserved_1[2];
	volatile u32 APB_ENR[2];
	volatile u32 Reserved_2[2];
	volatile u32 AHB_LPENR[2];
	volatile u32 Reserved_3[2];
	volatile u32 APB_LPENR[2];
	volatile u32 Reserved_4[2];
	volatile u32 BDCR;
	volatile u32 CSR;
	volatile u32 Reserved_5[2];
	volatile u32 SSCGR;
	volatile u32 PLLI2SCFGR;
	volatile u32 Reserved_6;
	volatile u32 DCKCFGR;
}RCC_t;

#define MRCC			((RCC_t*)RCC_BASE_ADD)


#endif /* MCAL_RCC_RCC_PRIVATE_H_ */
