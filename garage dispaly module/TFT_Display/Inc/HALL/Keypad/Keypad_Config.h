/*
 * Keypad_Config.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef HAL_KEYPAD_KEYPAD_CONFIG_H_
#define HAL_KEYPAD_KEYPAD_CONFIG_H_

#define ROWS_N				4
#define COL_N				3

#define ROW_PORTS			{_GPIOC_PORT,_GPIOC_PORT,_GPIOC_PORT,_GPIOC_PORT}
#define ROW_PINS			{GPIO_PIN_4,GPIO_PIN_5,GPIO_PIN_6,GPIO_PIN_7}
#define COL_PORTS			{_GPIOC_PORT,_GPIOC_PORT,_GPIOC_PORT}
#define COL_PINS			{GPIO_PIN_1,GPIO_PIN_2,GPIO_PIN_3}

#define KEYPAD_DEBOUNCING_TIME		5
#define KEYS_VAL		{{'1','2','3'},\
						{'4','5','6'},\
						{'7','8','9'},\
						{'*','0','#'}}
#endif /* HAL_KEYPAD_KEYPAD_CONFIG_H_ */
