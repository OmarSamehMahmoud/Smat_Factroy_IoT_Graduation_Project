################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Omar_Test_Project.lss \

FLASH_IMAGE += \
Omar_Test_Project.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: Omar_Test_Project.elf secondary-outputs

# Tool invocations
Omar_Test_Project.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Omar_Test_Project.map -mmcu=atmega32 -o "Omar_Test_Project.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Omar_Test_Project.lss: Omar_Test_Project.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Omar_Test_Project.elf  >"Omar_Test_Project.lss"
	@echo 'Finished building: $@'
	@echo ' '

Omar_Test_Project.hex: Omar_Test_Project.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Omar_Test_Project.elf  "Omar_Test_Project.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Omar_Test_Project.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Omar_Test_Project.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: Omar_Test_Project.elf
	@echo 'Invoking: AVRDude'
	C:\IMT_SDK_Win_64\WinAVR\bin\avrdude -pm32 -cusbasp -Uflash:w:Omar_Test_Project.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Omar_Test_Project.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
