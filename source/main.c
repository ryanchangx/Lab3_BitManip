/*	Author: rchan123
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
	/* Insert DDR and PORT initializations */
	DDRB = 0x06; PORTB = 0x00;
	DDRD = 0x00; PORTD = 0x00;
	/* Insert your solution below */
	unsigned char tmpB = 0x00;
	int weight = 0;
	while (1) {
		// [PD7 - PD0 PB0]
		// if (weight >= 70), then airbag enabled (PB1 = 1)
		// else if(weight > 5), 
		// 	then airbag disabled: (PB1 = 1)
		// 	AND disabled icon: (PB2 = 1);
		// else then nothing is set
		PORTB = 0x00;
		tmpB = 0x00;
		weight = (PIND << 1) | (PINB & 0x01);
		if(weight >= 70){
			tmpB = tmpB | 0x02;
		}
		else if(weight > 5){
			tmpB = tmpB | 0x04;
		}
		PORTB = PORTB | tmpB;
	}
	return 0;
}
