/*
 * LCD_int.h
 *
 *  Created on: Jun 4, 2022
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef HAL_LCD_LCD_INT_H_
#define HAL_LCD_LCD_INT_H_
typedef enum
{
	ES_OK,
	ES_NOK,
	ES_OUT_OF_RANGE,
	ES_NULL_POINTER
}ES_t;
ES_t LCD_enuInit(void);

ES_t LCD_enuSendData(u8 Copy_u8Data);

ES_t LCD_enuSendCommand(u8 Copy_u8Cmnd);

ES_t LCD_enuSendString(const char * Copy_pcString);

ES_t LCD_enuGoToPosition(u8 Copy_u8Row , u8 Copy_u8Column);

ES_t LCD_enuSendIntegerNum (s32 Copy_s32Num);

ES_t LCD_enuSendFloatNum (f32 Copy_f32Num);


#define LCD_ROW_0 				0X80

#define LCD_ROW_1				0XC0

#endif /* HAL_LCD_LCD_INT_H_ */
