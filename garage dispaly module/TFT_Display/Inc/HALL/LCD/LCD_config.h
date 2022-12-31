/*
 * LCD_config.h
 *
 *  Created on: Jun 4, 2022
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_

/*			LCD MODE [  EIGHT_BIT     FOUR_BIT  ]      */
#define LCD_MODE 			EIGHT_BIT

/*				Control Pins				*/
#define RS_GRP				_GPIOC_PORT
#define RS_PIN				GPIO_PIN_7

#define RW_GRP				_GPIOC_PORT
#define RW_PIN				GPIO_PIN_6

#define EN_GRP				_GPIOC_PORT
#define EN_PIN				GPIO_PIN_5

/* 					Data PIN			*/

#define D7_GRP				_GPIOA_PORT
#define D7_PIN				GPIO_PIN_7


#define D6_GRP				_GPIOA_PORT
#define D6_PIN				GPIO_PIN_6


#define D5_GRP				_GPIOA_PORT
#define D5_PIN				GPIO_PIN_5


#define D4_GRP				_GPIOA_PORT
#define D4_PIN				GPIO_PIN_4


#define D3_GRP				_GPIOA_PORT
#define D3_PIN				GPIO_PIN_3


#define D2_GRP				_GPIOA_PORT
#define D2_PIN				GPIO_PIN_2


#define D1_GRP				_GPIOA_PORT
#define D1_PIN				GPIO_PIN_1


#define D0_GRP				_GPIOA_PORT
#define D0_PIN				GPIO_PIN_0





#endif /* HAL_LCD_LCD_CONFIG_H_ */
