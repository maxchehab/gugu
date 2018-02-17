// Simple program to flash led on pin 1 at port a
#define __AVR_ATmega128__
#include <avr/io.h>
#include <util/delay.h>

#define FOSC 16000000 // Clock Speed
#define BAUD 9600
#define MYUBRR FOSC / 16 / BAUD - 1

int main()
{
    // Set the pin 1 at port a as output
    DDRA |= (1 << PA1);

    while (1)
    {
        // Turn led on by setting corresponding bit high in the PORTA register.
        PORTA |= (1 << PA1);

        _delay_ms(500);

        // Turn led off by setting corresponding bit low in the PORTA register.
        PORTA &= ~(1 << PA1);

        _delay_ms(500);
    }
}