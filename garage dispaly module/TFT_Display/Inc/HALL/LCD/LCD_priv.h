/*
 * LCD_priv.h
 *
 *  Created on: Jun 4, 2022
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef HAL_LCD_LCD_PRIV_H_
#define HAL_LCD_LCD_PRIV_H_
typedef enum
{
	ES_OK,
	ES_NOK,
	ES_OUT_OF_RANGE,
	ES_NULL_POINTER
}ES_t;

static ES_t LCD_enuWriteNLatch(u8 Copy_u8Byte);

#define EIGHT_BIT			65
#define FOUR_BIT			56


#define LCD_ROW_0 				0X80
#define LCD_ROW_1				0XC0
#endif /* HAL_LCD_LCD_PRIV_H_ */
