################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Driver.cpp \
../GrahamScan.cpp \
../Point.cpp \
../PointStack.cpp 

OBJS += \
./Driver.o \
./GrahamScan.o \
./Point.o \
./PointStack.o 

CPP_DEPS += \
./Driver.d \
./GrahamScan.d \
./Point.d \
./PointStack.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g -Wall -std=c++11 -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


