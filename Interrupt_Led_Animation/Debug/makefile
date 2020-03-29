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
Interrupt_Led_Animation.lss \

FLASH_IMAGE += \
Interrupt_Led_Animation.hex \

EEPROM_IMAGE += \
Interrupt_Led_Animation.eep \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: Interrupt_Led_Animation.elf secondary-outputs

# Tool invocations
Interrupt_Led_Animation.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Interrupt_Led_Animation.map -mmcu=atmega32 -o "Interrupt_Led_Animation.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Interrupt_Led_Animation.lss: Interrupt_Led_Animation.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Interrupt_Led_Animation.elf  >"Interrupt_Led_Animation.lss"
	@echo 'Finished building: $@'
	@echo ' '

Interrupt_Led_Animation.hex: Interrupt_Led_Animation.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Interrupt_Led_Animation.elf  "Interrupt_Led_Animation.hex"
	@echo 'Finished building: $@'
	@echo ' '

Interrupt_Led_Animation.eep: Interrupt_Led_Animation.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Interrupt_Led_Animation.elf  "Interrupt_Led_Animation.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Interrupt_Led_Animation.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Interrupt_Led_Animation.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: Interrupt_Led_Animation.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm32 -Uflash:w:Interrupt_Led_Animation.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Interrupt_Led_Animation.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
