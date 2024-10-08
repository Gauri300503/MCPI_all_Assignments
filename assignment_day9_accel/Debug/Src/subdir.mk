################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/accel.c \
../Src/i2c.c \
../Src/i2c_lcd.c \
../Src/itm.c \
../Src/main.c \
../Src/spi.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/system_stm32f4xx.c 

OBJS += \
./Src/accel.o \
./Src/i2c.o \
./Src/i2c_lcd.o \
./Src/itm.o \
./Src/main.o \
./Src/spi.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/system_stm32f4xx.o 

C_DEPS += \
./Src/accel.d \
./Src/i2c.d \
./Src/i2c_lcd.d \
./Src/itm.d \
./Src/main.d \
./Src/spi.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DB_G473E_ZEST1S -DSTM32G473QETx -DSTM32G4 -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/accel.cyclo ./Src/accel.d ./Src/accel.o ./Src/accel.su ./Src/i2c.cyclo ./Src/i2c.d ./Src/i2c.o ./Src/i2c.su ./Src/i2c_lcd.cyclo ./Src/i2c_lcd.d ./Src/i2c_lcd.o ./Src/i2c_lcd.su ./Src/itm.cyclo ./Src/itm.d ./Src/itm.o ./Src/itm.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/spi.cyclo ./Src/spi.d ./Src/spi.o ./Src/spi.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su ./Src/system_stm32f4xx.cyclo ./Src/system_stm32f4xx.d ./Src/system_stm32f4xx.o ./Src/system_stm32f4xx.su

.PHONY: clean-Src

