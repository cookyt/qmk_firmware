CUSTOM_MATRIX = lite

UART_DRIVER_REQUIRED = yes

DEFAULT_FOLDER = nullbitsco/snap/avr

# Project specific files
SRC +=  common/nb_leds.c \
        common/remote_kb.c \
        matrix.c
