/*
 * TFT_Prog.c
 *
 *  Created on: 4 Dec 2022
 *      Author: abano
 */




#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Delay_interface.h"
#include "GPIO_interface.h"
#include "SPI_interface.h"
#include "TFT_Config.h"
#include "TFT_Private.h"

static void HTFT_Void_SendCommand(u8 Copy_u8_Command)
{
	/*Set WR_C_D  To Low*/
	MGPIO_vWriteDataDIR(WR_C_D_PIN,LOW);
	SPI_u8SendRecive(SPI_NO, Copy_u8_Command);
}

static void HTFT_Void_SendData(u8 Copy_u8_Data)
{
	/*Set WR_C_D To High*/
	MGPIO_vWriteDataDIR(WR_C_D_PIN,HIGH);
	SPI_u8SendRecive(SPI_NO, Copy_u8_Data);

}

void HTFT_void_Init(void)
{
	MGPIO_vSetPinMode(WR_C_D_PIN		, _MODE_OUTPUT);
	MGPIO_vSetPinMode(TFT_RESET_PIN		, _MODE_OUTPUT);
	MGPIO_vSetPinMode(TFT_SCL_PIN		, _MODE_ALTF);
	MGPIO_vSetPinMode(TFT_SDA_PIN		, _MODE_ALTF);

	MGPIO_vSetPinAltFn(TFT_SCL_PIN,_ALTFN_5);
	MGPIO_vSetPinAltFn(TFT_SDA_PIN, _ALTFN_5);

	MGPIO_vSetPinOutSpeed(WR_C_D_PIN	, _OUTPUT_SPEED_VERY_HIGH);
	MGPIO_vSetPinOutSpeed(TFT_RESET_PIN	, _OUTPUT_SPEED_VERY_HIGH);
	MGPIO_vSetPinOutSpeed(TFT_SCL_PIN	, _OUTPUT_SPEED_VERY_HIGH);
	MGPIO_vSetPinOutSpeed(TFT_SDA_PIN	, _OUTPUT_SPEED_VERY_HIGH);

	SPI_vInit();

	MGPIO_vWriteDataDIR(TFT_RESET_PIN, HIGH);
	Delay_vUsIn16MHzint(100);
	MGPIO_vWriteDataDIR(TFT_RESET_PIN, LOW);
	Delay_vUsIn16MHzint(1);
	MGPIO_vWriteDataDIR(TFT_RESET_PIN, HIGH);
	Delay_vUsIn16MHzint(100);
	MGPIO_vWriteDataDIR(TFT_RESET_PIN, LOW);
	Delay_vUsIn16MHzint(100);
	MGPIO_vWriteDataDIR(TFT_RESET_PIN, HIGH);
	Delay_vMsIn16MHz(120);

	HTFT_Void_SendCommand(0X11);
	Delay_vMsIn16MHz(150);


////////////16Bit MOOD///////////////////////////

	HTFT_Void_SendCommand(0X3A);
	HTFT_Void_SendData(0X0);
	HTFT_Void_SendData(0X05);

	HTFT_Void_SendCommand(0X29);

}

void HTFT_void_DisplayImage(const u16* Copy_Pu16_Image)
{
	HTFT_Void_SendCommand(SETX_ADD);
	/*start*/
	HTFT_Void_SendData(0);
	HTFT_Void_SendData(0);
	/*end*/
	HTFT_Void_SendData((u8)((u16)(XPIXCELS-1)>>8));
	HTFT_Void_SendData((u8)(XPIXCELS-1));

	HTFT_Void_SendCommand(SETY_ADD);
		/*start*/
	HTFT_Void_SendData(0);
	HTFT_Void_SendData(0);
	/*end*/
	HTFT_Void_SendData((u8)((u16)(YPIXCELS-1)>>8));
	HTFT_Void_SendData((u8)(YPIXCELS-1));
	//
	HTFT_Void_SendCommand(DISPLAYE_NXT_DATA);

	u32 Local_u32_Iterator=0;
	u32 Local_u32_MAX=YPIXCELS*XPIXCELS;

	for(Local_u32_Iterator=0;Local_u32_Iterator<(Local_u32_MAX);Local_u32_Iterator++)
	{

		HTFT_Void_SendData((u8)(Copy_Pu16_Image[Local_u32_Iterator]>>8));
		HTFT_Void_SendData((u8)Copy_Pu16_Image[Local_u32_Iterator]);
	}


}


void HTFT_void_DisplayImageInLocation(u16 Copy_Au8_XPoints[2],u16 Copy_Au8_YPoints[2],const u16* Copy_Pu16_Image)
{
	HTFT_Void_SendCommand(SETY_ADD);

	HTFT_Void_SendData((u8)((Copy_Au8_YPoints[0])>>8));
	HTFT_Void_SendData((u8)(Copy_Au8_YPoints[0]));
	/*end*/
	HTFT_Void_SendData((u8)((Copy_Au8_YPoints[1]-1)>>8));
	HTFT_Void_SendData((u8)(Copy_Au8_YPoints[1]-1));

	HTFT_Void_SendCommand(SETX_ADD);
		/*start*/
	HTFT_Void_SendData((u8)(Copy_Au8_XPoints[0]>>8));
	HTFT_Void_SendData((u8)Copy_Au8_XPoints[0]);
	/*end*/
	HTFT_Void_SendData((u8)((Copy_Au8_XPoints[1]-1)>>8));
	HTFT_Void_SendData((u8)(Copy_Au8_XPoints[1]-1));
	HTFT_Void_SendCommand(DISPLAYE_NXT_DATA);

	u32 Local_u32_Iterator=0;
	u32 Local_u32_MAX=(Copy_Au8_YPoints[1]-Copy_Au8_YPoints[0])*(Copy_Au8_XPoints[1]-Copy_Au8_XPoints[0]);

	for(Local_u32_Iterator=0;Local_u32_Iterator<(Local_u32_MAX);Local_u32_Iterator++)
	{
		HTFT_Void_SendData((u8)(Copy_Pu16_Image[Local_u32_Iterator]>>8));
		HTFT_Void_SendData((u8)Copy_Pu16_Image[Local_u32_Iterator]);
	}

}


void HTFT_void_DisplayColorInLocation(u16 Copy_Au8_XPoints[2],u16 Copy_Au8_YPoints[2],u16 Copy_u16_Color)
{
	HTFT_Void_SendCommand(SETY_ADD);

	HTFT_Void_SendData((u8)((Copy_Au8_YPoints[0])>>8));
	HTFT_Void_SendData((u8)(Copy_Au8_YPoints[0]));
	/*end*/
	HTFT_Void_SendData((u8)((Copy_Au8_YPoints[1]-1)>>8));
	HTFT_Void_SendData((u8)(Copy_Au8_YPoints[1]-1));

	HTFT_Void_SendCommand(SETX_ADD);
		/*start*/
	HTFT_Void_SendData((u8)(Copy_Au8_XPoints[0]>>8));
	HTFT_Void_SendData((u8)Copy_Au8_XPoints[0]);
	/*end*/
	HTFT_Void_SendData((u8)((Copy_Au8_XPoints[1]-1)>>8));
	HTFT_Void_SendData((u8)(Copy_Au8_XPoints[1]-1));
	HTFT_Void_SendCommand(DISPLAYE_NXT_DATA);

	u32 Local_u32_Iterator=0;
	u32 Local_u32_MAX=(Copy_Au8_YPoints[1]-Copy_Au8_YPoints[0])*(Copy_Au8_XPoints[1]-Copy_Au8_XPoints[0]);

	for(Local_u32_Iterator=0;Local_u32_Iterator<(Local_u32_MAX);Local_u32_Iterator++)
	{
		HTFT_Void_SendData((u8)(Copy_u16_Color>>8));
		HTFT_Void_SendData((u8)Copy_u16_Color);
	}

}





void HTFT_void_DisplayHorizontalLine(u16 Copy_u16_X1,u16 Copy_u16_Y1,u16 Copy_u16_X2,u16 Copy_u16_Y2,u16 * color,u8 thickness)
{
	if(!(Copy_u16_Y2 - Copy_u16_Y1))
	{
		HTFT_Void_SendCommand(SETY_ADD);
							/*start*/
		HTFT_Void_SendData((u8)((Copy_u16_Y1)>>8));
		HTFT_Void_SendData((u8)(Copy_u16_Y1));
		/*end*/
		HTFT_Void_SendData((u8)((Copy_u16_Y1+thickness)>>8));
		HTFT_Void_SendData((u8)(Copy_u16_Y1+thickness));
		//
		HTFT_Void_SendCommand(SETX_ADD);
		/*start*/

		HTFT_Void_SendData((u8)(Copy_u16_X1>>8));
		HTFT_Void_SendData((u8)Copy_u16_X1);
		/*end*/
		HTFT_Void_SendData((u8)((Copy_u16_X2)>>8));
		HTFT_Void_SendData((u8)(Copy_u16_X2));
		HTFT_Void_SendCommand(DISPLAYE_NXT_DATA);
		for(u16 i =0 ;i<= (Copy_u16_X2-Copy_u16_X1+1)*(thickness+1) ;i++ )
		{
			HTFT_Void_SendData((u8)(*color>>8));
			HTFT_Void_SendData((u8)*color);
		}


	}

}
void HTFT_void_DisplayLine(u16 Copy_u16_X1,u16 Copy_u16_Y1,u16 Copy_u16_X2,u16 Copy_u16_Y2,u16 * color,u8 thickness)
{


	if((Copy_u16_Y2 - Copy_u16_Y1))
	{
		f64 Local_f32_Tilt = (Copy_u16_X2 - Copy_u16_X1)/(f64)(Copy_u16_Y2 - Copy_u16_Y1);
		u16 U_Newx;
		for(u16 i=Copy_u16_X1;i<=Copy_u16_X1+thickness;i++)
		{

			for(u16 j=0;j<=(Copy_u16_Y2-Copy_u16_Y1);j++ )
			{
				HTFT_Void_SendCommand(SETY_ADD);
					/*start*/
				HTFT_Void_SendData(((Copy_u16_Y1+j)>>8));
				HTFT_Void_SendData((Copy_u16_Y1+j));
				/*end*/
				HTFT_Void_SendData(((Copy_u16_Y1+j)>>8));
				HTFT_Void_SendData((Copy_u16_Y1+j));
				//
				HTFT_Void_SendCommand(SETX_ADD);
				/*start*/
				U_Newx=(j)*Local_f32_Tilt+i;

				HTFT_Void_SendData((u8)((U_Newx)>>8));
				HTFT_Void_SendData((u8)(U_Newx));
				/*end*/
				HTFT_Void_SendData((u8)((U_Newx)>>8));
				HTFT_Void_SendData((u8)(U_Newx));

				HTFT_Void_SendCommand(DISPLAYE_NXT_DATA);
				HTFT_Void_SendData((u8)(*color>>8));
				HTFT_Void_SendData((u8)*color);
			}


		}
	}


}


