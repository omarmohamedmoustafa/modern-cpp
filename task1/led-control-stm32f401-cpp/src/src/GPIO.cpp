#include "GPIO.hpp"

Gpio::Gpio(unsigned int port, unsigned int pin, Mode mode)
    : pin(pin)
{

    MODER_r = (volatile unsigned int *)(port + 0x00);
    ODR_r = (volatile unsigned int *)(port + 0x14);
    BSRR_r = (volatile unsigned int *)(port + 0x18);

    // Enable GPIO Clock
    if (port == GPIOA_BASE)
        RCC_AHB1ENR |= (1 << 0);
    if (port == GPIOB_BASE)
        RCC_AHB1ENR |= (1 << 1);
    if (port == GPIOC_BASE)
        RCC_AHB1ENR |= (1 << 2);

    // Set Mode (2 bits per pin)
    *MODER_r &= ~(0b11 << (pin * 2));
    *MODER_r |= (mode << (pin * 2));
}

void Gpio::setHigh()
{
    *BSRR_r = (1 << pin);
}

void Gpio::setLow()
{
    *BSRR_r = (1 << (pin + 16));
}

void Gpio::toggle()
{
    *ODR_r ^= (1 << pin);
}