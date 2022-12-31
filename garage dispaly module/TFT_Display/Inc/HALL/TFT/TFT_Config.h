/*
 * TFT_Config.h
 *
 *  Created on: 4 Dec 2022
 *      Author: abano
 */

#ifndef HALL_TFT_TFT_CONFIG_H_
#define HALL_TFT_TFT_CONFIG_H_

#define WR_C_D_PIN				_GPIOA_PORT,GPIO_PIN_2
#define SPI_NO					SPI1

#define TFT_RESET_PIN			_GPIOA_PORT,GPIO_PIN_1
#define TFT_SCL_PIN				_GPIOA_PORT,GPIO_PIN_5
#define TFT_SDA_PIN				_GPIOA_PORT,GPIO_PIN_7
#define XPIXCELS				240
#define YPIXCELS				320

#endif /* HALL_TFT_TFT_CONFIG_H_ */
