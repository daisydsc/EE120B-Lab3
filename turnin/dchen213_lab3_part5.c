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
	DDRD = 0x00; PORTD = 0xFF;
	DDRB = 0xFE; PORTB = 0x01;
 
  	unsigned char weight = 0x00;
	unsigned char tempB = 0x00;
	unsigned char tempBout = 0x00;
    	while(1){
		tempBout = 0x00;
		tempB = PINB & 0x01;
		weight = ((PIND << 1) & 0xFE) + tempB;

		if(weight >= 70){
			tempBout += 0x02;
		}
		else if (weight > 5) {
			tempBout += 0x04;
		}
	PORTB = tempBout;
	}
return 1;
}
