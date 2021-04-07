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
	DDRC = 0xFF; PORTC = 0x00;
	/* Insert your solution below */
	unsigned char tmpA = 0x00;
	unsigned char tmpC = 0x00;
	unsigned char lowFuel = 0x00;
	while (1) {
		tmpA = PINA & 0x7F;
		tmpC = 0x00;
		if(tmpA > 12){
			tmpC = tmpC | 0x01;
		}
		if(tmpA > 9){
			tmpC = tmpC | 0x02;
		}
		if(tmpA > 6){
			tmpC = tmpC | 0x04;
		}
		if(tmpA > 4){
			tmpC = tmpC | 0x08;
		}
		if(tmpA > 2){
			tmpC = tmpC | 0x10;
		}
		if(tmpA > 0){
			tmpC = tmpC | 0x20;
		}
		if(tmpA <= 4){
			lowFuel = 0x40;
		}
		else{
			lowFuel = 0x00;
		}
		// if a person is in the seat (PA5), and not fastened (!PA6)
		// 	and key is in ignition (PA4), PC7 is 1
		tmpC = (((tmpA >> 4) & 0x07) == 0x03)? tmpC | 0x80 : tmpC;
		PORTC = tmpC | lowFuel;
	}
	return 0;
}
