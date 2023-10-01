################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_Program.c \
../DIO_Program.c \
../TIMER1_FAST_PWM_SERVO_MOTOR_Program.c 

OBJS += \
./ADC_Program.o \
./DIO_Program.o \
./TIMER1_FAST_PWM_SERVO_MOTOR_Program.o 

C_DEPS += \
./ADC_Program.d \
./DIO_Program.d \
./TIMER1_FAST_PWM_SERVO_MOTOR_Program.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


