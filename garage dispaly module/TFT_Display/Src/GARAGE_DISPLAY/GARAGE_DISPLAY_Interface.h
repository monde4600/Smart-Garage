/*
 * GARAGE_DISPLAY_Interface.h
 *
 *  Created on: Dec 10, 2022
 *      Author: abano
 */

#ifndef GARAGE_DISPLAY_GARAGE_DISPLAY_INTERFACE_H_
#define GARAGE_DISPLAY_GARAGE_DISPLAY_INTERFACE_H_

typedef enum
{
 Location_Car_1=0,
 Location_Car_2,
 Location_Car_3,
 Location_Car_4,
 Location_Car_5,
 Location_Car_6,
 Location_Bike_1,
 Location_Bike_2,
 Location_Bike_3,
 Location_Bike_4
}Location_t;

typedef enum
{
 Location_BUSY=0,
 Location_EMPTY
}LO_State_t;

void GARAGE_DISPLAY_void_Init(void);
void GARAGE_DISPLAY_void_PositionDisplay(Location_t Copy_u8_Location , LO_State_t Copy_u8_State);


#endif /* GARAGE_DISPLAY_GARAGE_DISPLAY_INTERFACE_H_ */
