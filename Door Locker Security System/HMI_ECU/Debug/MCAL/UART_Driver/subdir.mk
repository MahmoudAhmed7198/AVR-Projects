################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/UART_Driver/uart.c 

OBJS += \
./MCAL/UART_Driver/uart.o 

C_DEPS += \
./MCAL/UART_Driver/uart.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/UART_Driver/%.o: ../MCAL/UART_Driver/%.c MCAL/UART_Driver/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

