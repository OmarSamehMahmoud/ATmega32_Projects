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
LDR_With_7Segement.lss \

FLASH_IMAGE += \
LDR_With_7Segement.hex \

EEPROM_IMAGE += \
LDR_With_7Segement.eep \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: LDR_With_7Segement.elf secondary-outputs

# Tool invocations
LDR_With_7Segement.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,LDR_With_7Segement.map -mmcu=atmega32 -o "LDR_With_7Segement.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

LDR_With_7Segement.lss: LDR_With_7Segement.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S LDR_With_7Segement.elf  >"LDR_With_7Segement.lss"
	@echo 'Finished building: $@'
	@echo ' '

LDR_With_7Segement.hex: LDR_With_7Segement.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex LDR_With_7Segement.elf  "LDR_With_7Segement.hex"
	@echo 'Finished building: $@'
	@echo ' '

LDR_With_7Segement.eep: LDR_With_7Segement.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex LDR_With_7Segement.elf  "LDR_With_7Segement.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: LDR_With_7Segement.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 LDR_With_7Segement.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: LDR_With_7Segement.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm32 -Uflash:w:LDR_With_7Segement.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) LDR_With_7Segement.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
