################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Sources/Keyboard/Keyboard_Source.cpp 

OBJS += \
./Sources/Keyboard/Keyboard_Source.o 

CPP_DEPS += \
./Sources/Keyboard/Keyboard_Source.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/Keyboard/%.o: ../Sources/Keyboard/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


