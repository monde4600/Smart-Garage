################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Inc/MCAL/SPI/SPI_prog.c 

OBJS += \
./Inc/MCAL/SPI/SPI_prog.o 

C_DEPS += \
./Inc/MCAL/SPI/SPI_prog.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/MCAL/SPI/%.o Inc/MCAL/SPI/%.su: ../Inc/MCAL/SPI/%.c Inc/MCAL/SPI/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F401VETx -c -I../Inc -I"F:/embided_deblom/NTI/ARM/INTERFACING/TFT_Display/Inc/HALL/TFT" -I"F:/embided_deblom/NTI/ARM/INTERFACING/TFT_Display/Inc/MCAL/SPI" -I"F:/embided_deblom/NTI/ARM/INTERFACING/TFT_Display/Inc/HALL/Keypad" -I"F:/embided_deblom/NTI/ARM/INTERFACING/TFT_Display/Inc/HALL/LCD" -I"F:/embided_deblom/NTI/ARM/INTERFACING/TFT_Display/Inc/HALL/LMARIX" -I"F:/embided_deblom/NTI/ARM/INTERFACING/TFT_Display/Inc/HALL/SSG" -I"F:/embided_deblom/NTI/ARM/INTERFACING/TFT_Display/Inc/LIB/00_STD_TYPES" -I"F:/embided_deblom/NTI/ARM/INTERFACING/TFT_Display/Inc/LIB/01_BIT_MATH" -I"F:/embided_deblom/NTI/ARM/INTERFACING/TFT_Display/Inc/LIB/02_Delay" -I"F:/embided_deblom/NTI/ARM/INTERFACING/TFT_Display/Inc/MCAL/GPIO" -I"F:/embided_deblom/NTI/ARM/INTERFACING/TFT_Display/Inc/MCAL/RCC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Inc-2f-MCAL-2f-SPI

clean-Inc-2f-MCAL-2f-SPI:
	-$(RM) ./Inc/MCAL/SPI/SPI_prog.d ./Inc/MCAL/SPI/SPI_prog.o ./Inc/MCAL/SPI/SPI_prog.su

.PHONY: clean-Inc-2f-MCAL-2f-SPI

