/*	Author: jchen337
 *  Partner(s) Name: Matthew Fernandes
 *	Lab Section:
 *	Assignment: Lab #4  Exercise #3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum Door_States {Initial, Wait, PPress, PRelease, YPress, YRelease, LockPress, LockRelease} next_state;

void Door_Tick() { 
	switch (next_state) { //Transitions
		case Initial:
			next_state = Initial;
			break;
		case Wait:
			if (PINA == 0x04) {
				next_state = PPress;
				break;
			}
			else if (PINA = 0x80) {
				next_state = LockPress;
				break;
			}
			else {
				next_state = Wait;
				break;
			}
		case PPress:
			if (PINA == 0x04) {
				next_state = PPress;
				break;
			}
			else if (PINA == 0x00) {
				next_state = PRelease;
				break;
			}
			else {
				next_state = Wait;
				break;
			}
		case PRelease:
			if (PINA == 0x02) {
				next_state = YPress;
				break;
			}
			else if (PINA == 0x00) {
				next_state = PRelease;
				break;
			}
			else {
				next_state = Wait;
				break;
			}
		case YPress:
		case YRelease:
		case LockPress:
			if (PINA == 0x80) {
				next_state = LockPress;
				break;
			}
			else {
				next_state = LockRelease;
				break;
			}
		case LockRelease:
			next_state = Wait;
			break;			
	}
	switch (next_state) { //Actions
		case Initial:
			PORTB = 0x01;
			next_state = Wait;
			break;
		case Wait:
			next_state = Wait;
			break;
		case PPress:
			next_state = PPress;
			break;
		case PRelease:
			next_state = PRelease;
			break;
		case YPress:
		case YRelease:
		case LockPress:
			PORTB = 0x00;
			next_state = LockPress;
			break;
		case LockRelease:
			PORTB = 0x00;
			next_state = LockRelease;
			break;

	}
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRC = 0xFF; PORTC = 0x00;
	next_state = Initial;

    /* Insert your solution below */
    while (1) {
	Tick();
    }
    return 1;
}
