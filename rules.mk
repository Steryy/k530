# project specific files
# SRC = ../../../drivers/led/sn32/matrix_sn32f24xx.c
# SRC += config_led.c

SRC += os_detection.c
# MCU name
MCU = SN32F248BF
# Build Options
#   comment out to disable the options.
#
LTO_ENABLE = yes
# BACKLIGHT_ENABLE = no
# MAGIC_ENABLE = yes
# MAGIC_KEYCODE_ENABLE = yes
# BOOTMAGIC_ENABLE = yes # Virtual DIP switch configuration
# MOUSEKEY_ENABLE = no    # Mouse keys
# EXTRAKEY_ENABLE = yes   # Audio control and System control
# CONSOLE_ENABLE = no     # Console for debug
# COMMAND_ENABLE = no     # Commands for debug and configuration
# SLEEP_LED_ENABLE = no   # Breathing sleep LED during USB suspend
# NKRO_ENABLE = yes       # USB Nkey Rollover
# AUDIO_ENABLE = no
# RGBLIGHT_ENABLE = no
# SERIAL_LINK_ENABLE = no
# WAIT_FOR_USB = no
# CUSTOM_MATRIX = lite
# KEYBOARD_SHARED_EP = yes
# EEPROM_DRIVER = i2c
# EEPROM_DRIVER = wear_leveling
# EEPROM_DRIVER = legacy_stm32_flash
# WEAR_LEVELING_DRIVER = sn32_flash
DIP_SWITCH_ENABLE = yes
# DEFERRED_EXEC_ENABLE = yes
# Custom RGB matrix handling
# RGB_MATRIX_ENABLE = yes
# RGB_MATRIX_DRIVER = SN32F24xB
