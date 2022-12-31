################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/GARAGE_DISPLAY/GARAGE_DISPLAY_Prog.c 

OBJS += \
./Src/GARAGE_DISPLAY/GARAGE_DISPLAY_Prog.o 

C_DEPS += \
./Src/GARAGE_DISPLAY/GARAGE_DISPLAY_Prog.d 


# Each subdirectory must supply rules for building sources it contributes
Src/GARAGE_DISPLAY/%.o Src/GARAGE_DISPLAY/%.su: ../Src/GARAGE_DISPLAY/%.c Src/GARAGE_DISPLAY/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DSTM32 -DSTM32F4 -DSTM32F401VETx -c -I../Inc -I"F:/embided_deblom/NTI/ARM/INTERFACING/TFT_Display/Inc/MCAL/GPIO" -I"F:/embided_deblom/NTI/ARM/INTERFACING/TFT_Display/Inc/MCAL/RCC" -I"F:/embided_deblom/NTI/ARM/INTERFACING/TFT_Display/Inc/MCAL/SPI" -I"F:/embided_deblom/NTI/ARM/INTERFACING/TFT_Display/Src/GARAGE_DISPLAY" -I"F:/embided_deblom/NTI/ARM/INTERFACING/TFT_Display/Inc/HALL/TFT" -I../Inc -I"F:/embided_deblom/NTI/ARM/INTERFACING/TFT_Display/Inc/MCAL/SPI" -I"F:/embided_deblom/NTI/ARM/INTERFACING/TFT_Display/Inc/HALL/Keypad" -I"F:/embided_deblom/NTI/ARM/INTERFACING/TFT_Display/Inc/HALL/LCD" -I"F:/embided_deblom/NTI/ARM/INTERFACING/TFT_Display/Inc/HALL/LMARIX" -I"F:/embided_deblom/NTI/ARM/INTERFACING/TFT_Display/Inc/HALL/SSG" -I"F:/embided_deblom/NTI/ARM/INTERFACING/TFT_Display/Inc/LIB/00_STD_TYPES" -I"F:/embided_deblom/NTI/ARM/INTERFACING/TFT_Display/Inc/LIB/01_BIT_MATH" -I"F:/embided_deblom/NTI/ARM/INTERFACING/TFT_Display/Inc/LIB/02_Delay" -I"F:/embided_deblom/NTI/ARM/INTERFACING/TFT_Display/Inc/MCAL/GPIO" -I"F:/embided_deblom/NTI/ARM/INTERFACING/TFT_Display/Inc/MCAL/RCC" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-GARAGE_DISPLAY

clean-Src-2f-GARAGE_DISPLAY:
	-$(RM) ./Src/GARAGE_DISPLAY/GARAGE_DISPLAY_Prog.d ./Src/GARAGE_DISPLAY/GARAGE_DISPLAY_Prog.o ./Src/GARAGE_DISPLAY/GARAGE_DISPLAY_Prog.su

.PHONY: clean-Src-2f-GARAGE_DISPLAY

