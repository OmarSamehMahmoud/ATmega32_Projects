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
USB_TO_TTL_Module.lss \

FLASH_IMAGE += \
USB_TO_TTL_Module.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: USB_TO_TTL_Module.elf secondary-outputs

# Tool invocations
USB_TO_TTL_Module.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,USB_TO_TTL_Module.map -mmcu=atmega32 -o "USB_TO_TTL_Module.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

USB_TO_TTL_Module.lss: USB_TO_TTL_Module.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S USB_TO_TTL_Module.elf  >"USB_TO_TTL_Module.lss"
	@echo 'Finished building: $@'
	@echo ' '

USB_TO_TTL_Module.hex: USB_TO_TTL_Module.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex USB_TO_TTL_Module.elf  "USB_TO_TTL_Module.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: USB_TO_TTL_Module.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 USB_TO_TTL_Module.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: USB_TO_TTL_Module.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm32 -cusbasp -Uflash:w:USB_TO_TTL_Module.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) USB_TO_TTL_Module.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
