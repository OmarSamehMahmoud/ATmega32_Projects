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
I2C.lss \

FLASH_IMAGE += \
I2C.hex \

EEPROM_IMAGE += \
I2C.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: I2C.elf secondary-outputs

# Tool invocations
I2C.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,I2C.map -mmcu=atmega32 -o "I2C.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

I2C.lss: I2C.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S I2C.elf  >"I2C.lss"
	@echo 'Finished building: $@'
	@echo ' '

I2C.hex: I2C.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex I2C.elf  "I2C.hex"
	@echo 'Finished building: $@'
	@echo ' '

I2C.eep: I2C.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex I2C.elf  "I2C.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: I2C.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 I2C.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) I2C.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
