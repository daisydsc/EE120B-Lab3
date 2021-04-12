/*	Author: Daisy Cheng dchen213@ucr.edu
 *	Lab Section:021
 *	Assignment: Lab # 3 Exercise # 1
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
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	
	unsigned char tempA = 0x00;
	unsigned char tempB = 0x00;
	unsigned char count = 0x00;

    while (1) {
	tempA = PINA;
	tempB = PINB;
	count = 0;
	int i;

	for (i = 0; i < 8; i++) {
	    if ((tempA >> i) & 0x01) {
		count += 1;
	    }
	    if ((tempB >> i) & 0x01) {
		count += 1;
	    }
	}

	PORTC = count;
    }
    return 1;
}
