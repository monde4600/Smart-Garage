/*
 * TFT_Interface.h
 *
 *  Created on: 4 Dec 2022
 *      Author: abano
 */

#ifndef HALL_TFT_TFT_INTERFACE_H_
#define HALL_TFT_TFT_INTERFACE_H_

void HTFT_void_Init(void);

void HTFT_void_DisplayImage(const u16* Copy_Pu16_Image);

void HTFT_void_DisplayImageInLocation(u16 Copy_Au8_XPoints[2],u16 Copy_Au8_YPoints[2],const u16* Copy_Pu16_Image);



void HTFT_void_DisplayColorInLocation(u16 Copy_Au8_XPoints[2],u16 Copy_Au8_YPoints[2],u16 Copy_u16_Color);


void HTFT_void_DisplayHorizontalLine(u16 Copy_u16_X1,u16 Copy_u16_Y1,u16 Copy_u16_X2,u16 Copy_u16_Y2,u16 * color,u8 thickness);


void HTFT_void_DisplayLine(u16 Copy_u16_X1,u16 Copy_u16_Y1,u16 Copy_u16_X2,u16 Copy_u16_Y2,u16 * color,u8 thickness );
#endif /* HALL_TFT_TFT_INTERFACE_H_ */
