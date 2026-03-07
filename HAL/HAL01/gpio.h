#ifndef GPIO_H
#define GPIO_H

#include <avr/io.h>
#include <stdint.h>

/* =========================
   Constantes de uso general
   ========================= */
#define INPUT   0
#define OUTPUT  1

#define LOW     0
#define HIGH    1

/* =========================
   Configuración de pin
   ========================= */
#define GPIO_PINMODE(ddr, pin, mode)        \
    do {                                    \
        if((mode) == OUTPUT)                \
            (ddr) |= (1U << (pin));         \
        else                                \
            (ddr) &= ~(1U << (pin));        \
    } while(0)

/* =========================
   Escritura y lectura de pin
   ========================= */
#define GPIO_WRITE(port, pin, value)        \
    do {                                    \
        if((value) == HIGH)                 \
            (port) |= (1U << (pin));        \
        else                                \
            (port) &= ~(1U << (pin));       \
    } while(0)

#define GPIO_TOGGLE(port, pin)              \
    do {                                    \
        (port) ^= (1U << (pin));            \
    } while(0)

#define GPIO_READ(pinreg, pin)              \
    (((pinreg) & (1U << (pin))) ? HIGH : LOW)

/* =========================
   Configuración de puerto
   ========================= */
#define GPIO_PORTMODE(ddr, mode)            \
    do {                                    \
        if((mode) == OUTPUT)                \
            (ddr) = 0xFF;                   \
        else                                \
            (ddr) = 0x00;                   \
    } while(0)

#define GPIO_PORT_WRITE(port, value)        \
    do {                                    \
        (port) = (value);                   \
    } while(0)

#define GPIO_PORT_READ(pinreg)              \
    (pinreg)

/* =========================
   Configuración por nibble
   ========================= */
#define GPIO_NIBBLE_LOW_MODE(ddr, mode)     \
    do {                                    \
        if((mode) == OUTPUT)                \
            (ddr) |= 0x0F;                  \
        else                                \
            (ddr) &= 0xF0;                  \
    } while(0)

#define GPIO_NIBBLE_HIGH_MODE(ddr, mode)    \
    do {                                    \
        if((mode) == OUTPUT)                \
            (ddr) |= 0xF0;                  \
        else                                \
            (ddr) &= 0x0F;                  \
    } while(0)

/* =========================
   Escritura de nibbles
   ========================= */
#define GPIO_WRITE_LOW_NIBBLE(port, value)  \
    do {                                    \
        (port) = ((port) & 0xF0) | ((value) & 0x0F); \
    } while(0)

#define GPIO_WRITE_HIGH_NIBBLE(port, value) \
    do {                                    \
        (port) = ((port) & 0x0F) | (((value) & 0x0F) << 4); \
    } while(0)

/* =========================
   Lectura de nibbles
   ========================= */
#define GPIO_READ_NIBBLE_LOW(pinreg)        \
    ((pinreg) & 0x0F)

#define GPIO_READ_NIBBLE_HIGH(pinreg)       \
    (((pinreg) >> 4) & 0x0F)

#endif