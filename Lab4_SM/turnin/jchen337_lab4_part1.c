/*	Author: jchen337
 *  Partner(s) Name: Matthew Fernandes
 *	Lab Section: 023
 *	Assignment: Lab #4  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum LED_States {LED_Start, LED0, LED1} next_state;

void Tick_LED() { 
	switch (next_state) { //Transitions
		case LED_Start:
			next_state = LED_Start;
			break;

		case LED0:
			if (PINA & 0x01) {
				next_state = LED1;
			}
			else {
				next_state = LED0;
			}
			break;

		case LED1:
			if (PINA & 0x01) {
				next_state = LED0;
			}
			else {
				next_state = LED1;
			}
			break;
	}
	switch (next_state) { //Actions
		case LED_Start:
			PORTB = 0x01;
			next_state = LED0;
			break;
		case LED0:
			PORTB = 0x01;
			next_state = LED0;
			break;
		case LED1:
			PORTB = 0x02;
			next_state = LED1;
			break;
	}
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	next_state = LED_Start;

    /* Insert your solution below */
    while (1) {
	Tick_LED();
    }
    return 1;
}
