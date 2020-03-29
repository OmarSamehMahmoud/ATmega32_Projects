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
Pot_Control_Buzzer_Tone.lss \

FLASH_IMAGE += \
Pot_Control_Buzzer_Tone.hex \

EEPROM_IMAGE += \
Pot_Control_Buzzer_Tone.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: Pot_Control_Buzzer_Tone.elf secondary-outputs

# Tool invocations
Pot_Control_Buzzer_Tone.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Pot_Control_Buzzer_Tone.map -mmcu=atmega32 -o "Pot_Control_Buzzer_Tone.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Pot_Control_Buzzer_Tone.lss: Pot_Control_Buzzer_Tone.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Pot_Control_Buzzer_Tone.elf  >"Pot_Control_Buzzer_Tone.lss"
	@echo 'Finished building: $@'
	@echo ' '

Pot_Control_Buzzer_Tone.hex: Pot_Control_Buzzer_Tone.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Pot_Control_Buzzer_Tone.elf  "Pot_Control_Buzzer_Tone.hex"
	@echo 'Finished building: $@'
	@echo ' '

Pot_Control_Buzzer_Tone.eep: Pot_Control_Buzzer_Tone.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Pot_Control_Buzzer_Tone.elf  "Pot_Control_Buzzer_Tone.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Pot_Control_Buzzer_Tone.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Pot_Control_Buzzer_Tone.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Pot_Control_Buzzer_Tone.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
