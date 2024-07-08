/*
 * PUSHBUTTON.c
 *
 * Created: 04-07-2024 12:55:04
 * Author : SRIDHAR
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

#define DIR_SW1		DDRB & (~(1<<PB0))			//	Direction of the PB0
#define DIR_SW2		DDRB & (~(1<<PB1))			//	Direction of the PB1

#define DIR_LED1	DDRB | (1<<PB6)				//	Direction of the PB6
#define DIR_LED2	DDRB | (1<<PB7)				//	Direction of the PB7

#define VAL_SW1		( ! (PINB & (1<<PB0)))		//	Assign the PB0 is the initially 0
#define VAL_SW2		( ! (PINB & (1<<PB1)))		//	Assign the PB1 is the initially 0

#define ON			1
#define OFF			0

int main(void)
{
	DDRB	=	DIR_SW1;
	DDRB	=	DIR_SW2;

	PORTB	=	PORTB | (1<<PB0);
	PORTB	=	PORTB | (1<<PB1);

	DDRB	=	DIR_LED1;
	DDRB	=	DIR_LED2;

	PORTB	=	PORTB & (~(1<<PB6));
	PORTB	=	PORTB & (~(1<<PB7));

    while (1) 
    {
		if (VAL_SW1 == ON)
		{
			PORTB	=	PORTB | (1<<PB6);
		}
		else if (VAL_SW1 == OFF)
		{
			PORTB	=	PORTB & (~(1<<PB6));
		}

		if (VAL_SW2 == ON)
		{
			PORTB	=	PORTB | (1<<PB7);
		}
		else if (VAL_SW2 == OFF)
		{
			PORTB	=	PORTB & (~(1<<PB7));
		}
    }
}