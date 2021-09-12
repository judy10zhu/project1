################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DFA.c \
../Node.c \
../State.c \
../Transition.c \
../main.c 

OBJS += \
./DFA.o \
./Node.o \
./State.o \
./Transition.o \
./main.o 

C_DEPS += \
./DFA.d \
./Node.d \
./State.d \
./Transition.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C Compiler'
	gcc -std=c99 -O0 -g3 -Wall -Werror -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


