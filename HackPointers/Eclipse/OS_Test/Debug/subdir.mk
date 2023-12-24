################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MDIO_program.c \
../MGIE_pogram.c \
../MTIM_program.c \
../OS_program.c \
../main.c 

OBJS += \
./MDIO_program.o \
./MGIE_pogram.o \
./MTIM_program.o \
./OS_program.o \
./main.o 

C_DEPS += \
./MDIO_program.d \
./MGIE_pogram.d \
./MTIM_program.d \
./OS_program.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


