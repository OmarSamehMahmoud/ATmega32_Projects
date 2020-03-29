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
Two_Interrupt_With_DIP_Switch.lss \

FLASH_IMAGE += \
Two_Interrupt_With_DIP_Switch.hex \

EEPROM_IMAGE += \
Two_Interrupt_With_DIP_Switch.eep \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: Two_Interrupt_With_DIP_Switch.elf secondary-outputs

# Tool invocations
Two_Interrupt_With_DIP_Switch.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Two_Interrupt_With_DIP_Switch.map -mmcu=atmega32 -o "Two_Interrupt_With_DIP_Switch.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Two_Interrupt_With_DIP_Switch.lss: Two_Interrupt_With_DIP_Switch.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Two_Interrupt_With_DIP_Switch.elf  >"Two_Interrupt_With_DIP_Switch.lss"
	@echo 'Finished building: $@'
	@echo ' '

Two_Interrupt_With_DIP_Switch.hex: Two_Interrupt_With_DIP_Switch.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Two_Interrupt_With_DIP_Switch.elf  "Two_Interrupt_With_DIP_Switch.hex"
	@echo 'Finished building: $@'
	@echo ' '

Two_Interrupt_With_DIP_Switch.eep: Two_Interrupt_With_DIP_Switch.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Two_Interrupt_With_DIP_Switch.elf  "Two_Interrupt_With_DIP_Switch.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Two_Interrupt_With_DIP_Switch.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Two_Interrupt_With_DIP_Switch.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: Two_Interrupt_With_DIP_Switch.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm32 -Uflash:w:Two_Interrupt_With_DIP_Switch.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Two_Interrupt_With_DIP_Switch.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
