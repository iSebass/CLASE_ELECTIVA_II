#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    //CONFIGURAR PB0..PB3 COMO SALIDA
	DDRB = 255;
	
	PORTB = 0xFF;
	
	PORTB &= ~( (1<<6) | (1<<3) | (1<<0) );
	
    while (1) 
    {
		
    }
}

