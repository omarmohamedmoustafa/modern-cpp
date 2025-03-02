#include "GPIO.hpp"
#include "LED.hpp"
#include <stdint.h>

#define LED_PORT GPIOA_BASE
#define LED_PIN 0

void delay_ms(uint32_t ms)
{
    for (uint32_t i = 0; i < ms * 1000; i++)
    {
        __asm__ volatile("nop");
    }
}

int main()
{
    // Initialize the LED
    Led led(LED_PORT, LED_PIN);

    while (1)
    {
        led.led_toggle();
        delay_ms(500);
    }

    return 0;
}