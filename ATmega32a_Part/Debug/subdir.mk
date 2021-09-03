################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC.c \
../DIO_prog.c \
../IR.c \
../UART.c \
../Ultrasonic.c \
../main.c \
../stepper.c 

OBJS += \
./ADC.o \
./DIO_prog.o \
./IR.o \
./UART.o \
./Ultrasonic.o \
./main.o \
./stepper.o 

C_DEPS += \
./ADC.d \
./DIO_prog.d \
./IR.d \
./UART.d \
./Ultrasonic.d \
./main.d \
./stepper.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


