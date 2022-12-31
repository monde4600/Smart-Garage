/*
 * GARAGE_DISPLAY_Prog.c
 *
 *  Created on: Dec 10, 2022
 *      Author: abano
 */
#include "STD_TYPES.h"
#include "TFT_Interface.h"
#include "GARAGE_DISPLAY_Config.h"
#include "GARAGE_DISPLAY_Interface.h"
#include "TFT_Interface.h"
#include "Image.h"
#include "IMAGE_1.h"

void GARAGE_DISPLAY_void_Init(void)
{
	HTFT_void_Init();
	HTFT_void_DisplayImage(Image);
}
void GARAGE_DISPLAY_void_PositionDisplay(Location_t Copy_u8_Location , LO_State_t Copy_u8_State)
{

	u16 X_points[2] = {0,0};
	u16 Y_points[2] = {0,0};
	const u16 * Image_Selection= Image_B;
	switch(Copy_u8_Location)
	{
	case Location_Car_1:
		X_points[0]=LOCATION1_X0;
		X_points[1]=LOCATION1_X1;
		Y_points[0]=LOCATION1_Y0;
		Y_points[1]=LOCATION1_Y1;
		Image_Selection= Image_c1;
		break;
	case Location_Car_2:
		X_points[0]=LOCATION2_X0;
		X_points[1]=LOCATION2_X1;
		Y_points[0]=LOCATION2_Y0;
		Y_points[1]=LOCATION2_Y1;
		Image_Selection= Image_c1;
		break;
	case Location_Car_3:
		X_points[0]=LOCATION3_X0;
		X_points[1]=LOCATION3_X1;
		Y_points[0]=LOCATION3_Y0;
		Y_points[1]=LOCATION3_Y1;
		Image_Selection= Image_c1;
		break;
	case Location_Car_4:
		X_points[0]=LOCATION4_X0;
		X_points[1]=LOCATION4_X1;
		Y_points[0]=LOCATION4_Y0;
		Y_points[1]=LOCATION4_Y1;
		Image_Selection= Image_c2;
		break;
	case Location_Car_5:
		X_points[0]=LOCATION5_X0;
		X_points[1]=LOCATION5_X1;
		Y_points[0]=LOCATION5_Y0;
		Y_points[1]=LOCATION5_Y1;
		Image_Selection= Image_c2;
		break;
	case Location_Car_6:
		X_points[0]=LOCATION6_X0;
		X_points[1]=LOCATION6_X1;
		Y_points[0]=LOCATION6_Y0;
		Y_points[1]=LOCATION6_Y1;
		Image_Selection= Image_c2;
		break;
	case Location_Bike_1:
		X_points[0]=LOCATION7_X0;
		X_points[1]=LOCATION7_X1;
		Y_points[0]=LOCATION7_Y0;
		Y_points[1]=LOCATION7_Y1;
		Image_Selection= Image_B;
		break;
	case Location_Bike_2:
		X_points[0]=LOCATION8_X0;
		X_points[1]=LOCATION8_X1;
		Y_points[0]=LOCATION8_Y0;
		Y_points[1]=LOCATION8_Y1;
		Image_Selection= Image_B;
		break;
	case Location_Bike_3:
		X_points[0]=LOCATION9_X0;
		X_points[1]=LOCATION9_X1;
		Y_points[0]=LOCATION9_Y0;
		Y_points[1]=LOCATION9_Y1;
		Image_Selection= Image_B;
		break;
	case Location_Bike_4:
		X_points[0]=LOCATION10_X0;
		X_points[1]=LOCATION10_X1;
		Y_points[0]=LOCATION10_Y0;
		Y_points[1]=LOCATION10_Y1;
		Image_Selection= Image_B;
		break;
	default:
		break;
	}

	if(Copy_u8_State == Location_BUSY)
		HTFT_void_DisplayImageInLocation(X_points,Y_points, Image_Selection);
	else
		HTFT_void_DisplayColorInLocation(X_points,Y_points,0x5acb);
}
