/*
 * RCC_config.h
 *
 *  Created on: Dec 10, 2022
 *      Author: abano
 */

#ifndef MCAL_RCC_RCC_CONFIG_H_
#define MCAL_RCC_RCC_CONFIG_H_
/*
 * HSI
 * HSE
 * PLL_CLOCK
 */
#define SYS_CLOCK_SRC		HSE


#define PLL_CLOCK_SRC		HSE

/*
 * RC_CLOCK
 * CRYSTAL_CLOCK
 *
 */
#define HSE_CLOCK_SRC	CRYSTAL_CLOCK

#define AHP_PRESC		1

#define APB_PRESC		1

#endif /* MCAL_RCC_RCC_CONFIG_H_ */
