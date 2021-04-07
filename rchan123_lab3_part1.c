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
	DDRA = 0x00; PORTA = 0x00;
	DDRB = 0x00; PORTB = 0x00;
	DDRC = 0xFF; PORTC = 0x00;
	/* Insert your solution below */
	unsigned char tmpA = 0x00;
	unsigned char tmpB = 0x00;
	unsigned char sum = 0x00;
	unsigned char bitA = 0;
	unsigned char bitB = 0;
	int i;
	while (1) {
		sum = 0x00;
		tmpA = PINA;
		tmpB = PINB;
		for(i = 0; i < 8; ++i){	
			bitA = (tmpA >> i) & 0x01;
			bitB = (tmpB >> i) & 0x01;
			sum += bitA + bitB;
		}
		PORTC = sum;	
	}
	return 0;
}
