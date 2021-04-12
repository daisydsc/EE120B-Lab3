/*	Author: Daisy Cheng dchen213@ucr.edu
 *	Lab Section:021
 *	Assignment: Lab # 3 Exercise # 4
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
	DDRB = 0xFF; PORTB = 0x00;
	DDRC = 0xFF; PORTC = 0x00;

	unsigned char tempAupper = 0x00;
	unsigned char tempAlower = 0x00;
	unsigned char tempCupper = 0x00;
        unsigned char tempBlower = 0x00; 
  
    	while(1){
		tempAupper = PINA & 0xF0;
		tempAlower = PINA & 0x0F;
			
		tempCupper = tempAlower << 4;
		tempBlower = tempAupper >> 4;

		PORTB = tempBlower;
		PORTC = tempCupper;
	}
return 1;
}
