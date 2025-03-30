################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/main.c \
../Application/syscalls.c \
../Application/sysmem.c 

OBJS += \
./Application/main.o \
./Application/syscalls.o \
./Application/sysmem.o 

C_DEPS += \
./Application/main.d \
./Application/syscalls.d \
./Application/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Application/%.o Application/%.su Application/%.cyclo: ../Application/%.c Application/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../Driver/inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application

clean-Application:
	-$(RM) ./Application/main.cyclo ./Application/main.d ./Application/main.o ./Application/main.su ./Application/syscalls.cyclo ./Application/syscalls.d ./Application/syscalls.o ./Application/syscalls.su ./Application/sysmem.cyclo ./Application/sysmem.d ./Application/sysmem.o ./Application/sysmem.su

.PHONY: clean-Application

