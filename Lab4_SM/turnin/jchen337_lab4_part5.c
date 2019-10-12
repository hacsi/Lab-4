/*	Author: jchen337
 *  Partner(s) Name: Matthew Fernandes
 *	Lab Section: 023
 *	Assignment: Lab #4  Exercise #5
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum Door_States {Initial, Wait, Get, Check} next_state;

void Door_Tick() {
	switch (next_state) { //Transitions
		case Initial:
			next_state = Initial;
			break;
		case Get:
			scanf("%c", comb);
			scanf("%c", comb);
			scanf("%c", comb);
			scanf("%c", comb);
			next_state = Check;
			break;
		case Check:
	}

	switch (next_state) { //Actions
		case Initial:
			PORTB = 0x01;
			next_state = Wait;
			break;
		case Get:
		case Check:
	}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRC = 0xFF; PORTC = 0x00;

	int comb[4];
	unsigned char i = 0;

	

    /* Insert your solution below */
    while (1) {
	
    }
    return 1;
}
