/*
 * LMATRIX_Prog.c
 *
 *  Created on: Nov 25, 2022
 *      Author: abano
 */

#include"STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "LMATRIX_config.h"
#include "Delay_interface.h"

const u8 MATRIX_Au8_ROW [2][ROW_NUM] = {ROW_GROUPS,ROW_PINS};
const u8 MATRIX_Au8_COL	[2][COL_NUM] = {COL_GROUPS,COL_PINS};

void H_LMATRIX_void_Init(void)
{
	for(u8 i=0;i<COL_NUM;i++)
	{
		MGPIO_vSetPinMode(MATRIX_Au8_COL[0][i], MATRIX_Au8_COL[1][i], _MODE_OUTPUT);
		MGPIO_vSetPinOutPutType(MATRIX_Au8_COL[0][i], MATRIX_Au8_COL[1][i], PUSH_PULL);
		MGPIO_vWriteData(MATRIX_Au8_COL[0][i], MATRIX_Au8_COL[1][i], HIGH);
	}
	for(u8 i=0;i<ROW_NUM;i++)
	{
		MGPIO_vSetPinMode(MATRIX_Au8_ROW[0][i], MATRIX_Au8_ROW[1][i], _MODE_OUTPUT);
		MGPIO_vWriteData(MATRIX_Au8_ROW [0][i], MATRIX_Au8_ROW[1][i], LOW);
	}
}

void H_LMATRIX_void_Display(u32* Copy_Au32_DiplayMatrix)
{
	for(int i=0;i<COL_NUM;i++)
	{
		for(int j=0;j<ROW_NUM;j++)
		{
			MGPIO_vWriteDataDIR(MATRIX_Au8_ROW[0][j], MATRIX_Au8_ROW[1][j],GET_BIT(Copy_Au32_DiplayMatrix[i],j));
		}
		MGPIO_vWriteDataDIR(MATRIX_Au8_COL[0][i], MATRIX_Au8_COL[1][i], LOW);
		Delay_vUsIn16MHzint(90);
		MGPIO_vWriteDataDIR(MATRIX_Au8_COL[0][i], MATRIX_Au8_COL[1][i], HIGH);
	}
}
