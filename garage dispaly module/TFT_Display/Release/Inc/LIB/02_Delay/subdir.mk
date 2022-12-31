################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Inc/LIB/02_Delay/Delay_Program.c 

OBJS += \
./Inc/LIB/02_Delay/Delay_Program.o 

C_DEPS += \
./Inc/LIB/02_Delay/Delay_Program.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/LIB/02_Delay/%.o Inc/LIB/02_Delay/%.su: ../Inc/LIB/02_Delay/%.c Inc/LIB/02_Delay/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DSTM32 -DSTM32F4 -DSTM32F401VETx -c -I../Inc -I"F:/embided_deblom/NTI/ARM/INTERFACING/TFT_Display/Inc/MCAL/GPIO" -I"F:/embided_deblom/NTI/ARM/INTERFACING/TFT_Display/Inc/MCAL/RCC" -I"F:/embided_deblom/NTI/ARM/INTERFACING/TFT_Display/Inc/MCAL/SPI" -I"F:/embided_deblom/NTI/ARM/INTERFACING/TFT_Display/Src/GARAGE_DISPLAY" -I"F:/embided_deblom/NTI/ARM/INTERFACING/TFT_Display/Inc/HALL/TFT" -I../Inc -I"F:/embided_deblom/NTI/ARM/INTERFACING/TFT_Display/Inc/MCAL/SPI" -I"F:/embided_deblom/NTI/ARM/INTERFACING/TFT_Display/Inc/HALL/Keypad" -I"F:/embided_deblom/NTI/ARM/INTERFACING/TFT_Display/Inc/HALL/LCD" -I"F:/embided_deblom/NTI/ARM/INTERFACING/TFT_Display/Inc/HALL/LMARIX" -I"F:/embided_deblom/NTI/ARM/INTERFACING/TFT_Display/Inc/HALL/SSG" -I"F:/embided_deblom/NTI/ARM/INTERFACING/TFT_Display/Inc/LIB/00_STD_TYPES" -I"F:/embided_deblom/NTI/ARM/INTERFACING/TFT_Display/Inc/LIB/01_BIT_MATH" -I"F:/embided_deblom/NTI/ARM/INTERFACING/TFT_Display/Inc/LIB/02_Delay" -I"F:/embided_deblom/NTI/ARM/INTERFACING/TFT_Display/Inc/MCAL/GPIO" -I"F:/embided_deblom/NTI/ARM/INTERFACING/TFT_Display/Inc/MCAL/RCC" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Inc-2f-LIB-2f-02_Delay

clean-Inc-2f-LIB-2f-02_Delay:
	-$(RM) ./Inc/LIB/02_Delay/Delay_Program.d ./Inc/LIB/02_Delay/Delay_Program.o ./Inc/LIB/02_Delay/Delay_Program.su

.PHONY: clean-Inc-2f-LIB-2f-02_Delay

