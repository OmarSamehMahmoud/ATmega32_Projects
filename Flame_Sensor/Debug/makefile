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
Flame_Sensor.lss \

FLASH_IMAGE += \
Flame_Sensor.hex \

EEPROM_IMAGE += \
Flame_Sensor.eep \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: Flame_Sensor.elf secondary-outputs

# Tool invocations
Flame_Sensor.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Flame_Sensor.map -mmcu=atmega32 -o "Flame_Sensor.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Flame_Sensor.lss: Flame_Sensor.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Flame_Sensor.elf  >"Flame_Sensor.lss"
	@echo 'Finished building: $@'
	@echo ' '

Flame_Sensor.hex: Flame_Sensor.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Flame_Sensor.elf  "Flame_Sensor.hex"
	@echo 'Finished building: $@'
	@echo ' '

Flame_Sensor.eep: Flame_Sensor.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Flame_Sensor.elf  "Flame_Sensor.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Flame_Sensor.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Flame_Sensor.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: Flame_Sensor.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm32 -Uflash:w:Flame_Sensor.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Flame_Sensor.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
