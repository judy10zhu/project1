################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BitSet.c \
../IntHashSet.c \
../LinkedList.c \
../Node.c \
../dfa.c \
../hash.c \
../main.c \
../strdup.c \
../table.c \
../transition.c 

OBJS += \
./BitSet.o \
./IntHashSet.o \
./LinkedList.o \
./Node.o \
./dfa.o \
./hash.o \
./main.o \
./strdup.o \
./table.o \
./transition.o 

C_DEPS += \
./BitSet.d \
./IntHashSet.d \
./LinkedList.d \
./Node.d \
./dfa.d \
./hash.d \
./main.d \
./strdup.d \
./table.d \
./transition.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C Compiler'
	gcc -std=c99 -O0 -g3 -Wall -Werror -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


