################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Node.c \
../dfa.c \
../main.c \
../state.c \
../transition.c 

OBJS += \
./Node.o \
./dfa.o \
./main.o \
./state.o \
./transition.o 

C_DEPS += \
./Node.d \
./dfa.d \
./main.d \
./state.d \
./transition.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


