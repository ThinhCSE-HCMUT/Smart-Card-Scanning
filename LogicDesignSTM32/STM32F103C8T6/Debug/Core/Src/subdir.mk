################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/buzzer.c \
../Core/Src/fsm.c \
../Core/Src/global.c \
../Core/Src/lcd.c \
../Core/Src/led_rgb.c \
../Core/Src/main.c \
../Core/Src/scheduler.c \
../Core/Src/signal.c \
../Core/Src/stm32f1xx_hal_msp.c \
../Core/Src/stm32f1xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f1xx.c \
../Core/Src/wifi.c 

OBJS += \
./Core/Src/buzzer.o \
./Core/Src/fsm.o \
./Core/Src/global.o \
./Core/Src/lcd.o \
./Core/Src/led_rgb.o \
./Core/Src/main.o \
./Core/Src/scheduler.o \
./Core/Src/signal.o \
./Core/Src/stm32f1xx_hal_msp.o \
./Core/Src/stm32f1xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f1xx.o \
./Core/Src/wifi.o 

C_DEPS += \
./Core/Src/buzzer.d \
./Core/Src/fsm.d \
./Core/Src/global.d \
./Core/Src/lcd.d \
./Core/Src/led_rgb.d \
./Core/Src/main.d \
./Core/Src/scheduler.d \
./Core/Src/signal.d \
./Core/Src/stm32f1xx_hal_msp.d \
./Core/Src/stm32f1xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f1xx.d \
./Core/Src/wifi.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

