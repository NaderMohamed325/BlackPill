################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Mcal/GPIO.c 

OBJS += \
./Mcal/GPIO.o 

C_DEPS += \
./Mcal/GPIO.d 


# Each subdirectory must supply rules for building sources it contributes
Mcal/%.o Mcal/%.su Mcal/%.cyclo: ../Mcal/%.c Mcal/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F401RCTx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Mcal

clean-Mcal:
	-$(RM) ./Mcal/GPIO.cyclo ./Mcal/GPIO.d ./Mcal/GPIO.o ./Mcal/GPIO.su

.PHONY: clean-Mcal

