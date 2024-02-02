/* Copyright 2021
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "uart.h"

#if defined(MCU_KINETIS)
static SerialConfig serialConfig = {SERIAL_DEFAULT_BITRATE};
#elif defined(WB32F3G71xx) || defined(WB32FQ95xx)
static SerialConfig serialConfig = {SERIAL_DEFAULT_BITRATE, SD1_WRDLEN, SD1_STPBIT, SD1_PARITY, SD1_ATFLCT};
#elif defined(MCU_RP)
static SIOConfig sioConfig = {}; // XXX
#else
static SerialConfig serialConfig = {SERIAL_DEFAULT_BITRATE, SD1_CR1, SD1_CR2, SD1_CR3};
#endif

void uart_init(uint32_t baud) {
    static bool is_initialised = false;

    if (!is_initialised) {
        is_initialised = true;

#if !defined(CHIBIOS_UART_USE_SIO)
#    if defined(MCU_KINETIS)
        serialConfig.sc_speed = baud;
#    elif !defined(CHIBIOS_UART_USE_SIO)
        serialConfig.speed = baud;
#    endif

#    if defined(USE_GPIOV1)
        palSetLineMode(SD1_TX_PIN, SD1_TX_PAL_MODE);
        palSetLineMode(SD1_RX_PIN, SD1_RX_PAL_MODE);
#    else
        palSetLineMode(SD1_TX_PIN, PAL_MODE_ALTERNATE(SD1_TX_PAL_MODE) | PAL_OUTPUT_TYPE_PUSHPULL | PAL_OUTPUT_SPEED_HIGHEST);
        palSetLineMode(SD1_RX_PIN, PAL_MODE_ALTERNATE(SD1_RX_PAL_MODE) | PAL_OUTPUT_TYPE_PUSHPULL | PAL_OUTPUT_SPEED_HIGHEST);
#    endif
        sdStart(&SERIAL_DRIVER, &serialConfig);
#endif
        (void)sioConfig;
    }
}

void uart_write(uint8_t data) {
#if !defined(CHIBIOS_UART_USE_SIO)
    sdPut(&SERIAL_DRIVER, data);
#endif
}

uint8_t uart_read(void) {
    msg_t res = 0;
#if !defined(CHIBIOS_UART_USE_SIO)
    res = sdGet(&SERIAL_DRIVER);
#endif

    return (uint8_t)res;
}

void uart_transmit(const uint8_t *data, uint16_t length) {
#if !defined(CHIBIOS_UART_USE_SIO)
    sdWrite(&SERIAL_DRIVER, data, length);
#endif
}

void uart_receive(uint8_t *data, uint16_t length) {
#if !defined(CHIBIOS_UART_USE_SIO)
    sdRead(&SERIAL_DRIVER, data, length);
#endif
}

bool uart_available(void) {
    bool ret = false;
#if !defined(CHIBIOS_UART_USE_SIO)
    ret = !sdGetWouldBlock(&SERIAL_DRIVER);
#endif
    return ret;
}
