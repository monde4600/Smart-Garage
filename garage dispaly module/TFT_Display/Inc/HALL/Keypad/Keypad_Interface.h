/*
 * Keypad_Interface.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef HAL_KEYPAD_KEYPAD_INTERFACE_H_
#define HAL_KEYPAD_KEYPAD_INTERFACE_H_

void H_KEYPAD_void_Init(void);
u8 H_KEYPAD_u8_GetPressedKey(u8*);

#define KEPAD_NOTPRESSED		0XFF
#endif /* HAL_KEYPAD_KEYPAD_INTERFACE_H_ */
