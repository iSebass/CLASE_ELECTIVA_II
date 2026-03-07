#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "gpio.h"


int main(void)
{
    GPIO_PINMODE(DDRB, 0, OUTPUT);  
	GPIO_PINMODE(DDRD, 1, INPUT);
    while (1) 
    {
		if( GPIO_READ(PIND, 1) == 1  ){
			GPIO_TOGGLE(PORTB, PORTB0);
			_delay_ms(200);
		}
		
		
    }
}

