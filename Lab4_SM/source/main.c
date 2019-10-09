/*	Author: jchen337
 *  Partner(s) Name: Matthew Fernandes
 *	Lab Section:
 *	Assignment: Lab #4  Exercise #2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum States {Initial, Wait, Inc, Dec, Reset} next_state;

void Tick() { 
	switch (next_state) { //Transitions
		case Initial:
			next_state = Initial;
			break;
		case Reset:
		case Inc:
		case Dec:
		case Wait:
			if (PINA & 0x01) {
				next_state = Inc;
				break;
			}
			else if (PINA & 0x02) {
				next_state = Dec;
				break;
			}
			else if (PINA & 0x03) {
				next_state = Reset;
				break;
			}
			else {
				next_state = Wait;
				break;
			}
			
	}
	switch (next_state) { //Actions
		case Initial:
			PORTC = 0x07;
			next_state = Wait;
			break;
		case Wait:
			next_state = Wait;
			break;
		case Inc:
			if (PORTC >= 9) {
				PORTC = 0x09;
				next_state = Wait;
				break;
			}
			else {
				PORTC = PORTC + 0x01;
				next_state = Wait;
				break;
			}
		case Dec:
			if (PORTC <= 0) {
				PORTC = 0x00;
				next_state = Wait;
				break;
			}
			else {
				PORTC = PORTC - 0x01;
				next_state = Wait;
				break;
			}
		case Reset:
			PORTC = 0x00;
			next_state = Wait;
	}
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	next_state = Initial;

    /* Insert your solution below */
    while (1) {
	Tick();
    }
    return 1;
}
