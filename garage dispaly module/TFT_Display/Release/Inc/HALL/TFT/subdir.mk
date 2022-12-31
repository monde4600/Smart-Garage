################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Inc/HALL/TFT/TFT_Prog.c 

OBJS += \
./Inc/HALL/TFT/TFT_Prog.o 

C_DEPS += \
./Inc/HALL/TFT/TFT_Prog.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/HALL/TFT/%.o Inc/HALL/TFT/%.su: ../Inc/HALL/TFT/%.c Inc/HALL/TFT/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DSTM32 -DSTM32F4 -DSTM32F401VETx -c -I../Inc -I"F:/embided_deblom/NTI/ARM/INTERFACING/TFT_Display/Inc/MCAL/GPIO" -I"F:/embided_deblom/NTI/ARM/INTERFACING/TFT_Display/Inc/MCAL/RCC" -I"F:/embided_deblom/NTI/ARM/INTERFACING/TFT_Display/Inc/MCAL/SPI" -I"F:/embided_deblom/NTI/ARM/INTERFACING/TFT_Display/Src/GARAGE_DISPLAY" -I"F:/embided_deblom/NTI/ARM/INTERFACING/TFT_Display/Inc/HALL/TFT" -I../Inc -I"F:/embided_deblom/NTI/ARM/INTERFACING/TFT_Display/Inc/MCAL/SPI" -I"F:/embided_deblom/NTI/ARM/INTERFACING/TFT_Display/Inc/HALL/Keypad" -I"F:/embided_deblom/NTI/ARM/INTERFACING/TFT_Display/Inc/HALL/LCD" -I"F:/embided_deblom/NTI/ARM/INTERFACING/TFT_Display/Inc/HALL/LMARIX" -I"F:/embided_deblom/NTI/ARM/INTERFACING/TFT_Display/Inc/HALL/SSG" -I"F:/embided_deblom/NTI/ARM/INTERFACING/TFT_Display/Inc/LIB/00_STD_TYPES" -I"F:/embided_deblom/NTI/ARM/INTERFACING/TFT_Display/Inc/LIB/01_BIT_MATH" -I"F:/embided_deblom/NTI/ARM/INTERFACING/TFT_Display/Inc/LIB/02_Delay" -I"F:/embided_deblom/NTI/ARM/INTERFACING/TFT_Display/Inc/MCAL/GPIO" -I"F:/embided_deblom/NTI/ARM/INTERFACING/TFT_Display/Inc/MCAL/RCC" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Inc-2f-HALL-2f-TFT

clean-Inc-2f-HALL-2f-TFT:
	-$(RM) ./Inc/HALL/TFT/TFT_Prog.d ./Inc/HALL/TFT/TFT_Prog.o ./Inc/HALL/TFT/TFT_Prog.su

.PHONY: clean-Inc-2f-HALL-2f-TFT

