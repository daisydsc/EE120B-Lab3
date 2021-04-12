/*	Author: Daisy Cheng dchen213@ucr.edu
 *	Lab Section:021
 *	Assignment: Lab # 3 Exercise # 3
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
	DDRC = 0xFF; PORTC = 0x00;

	unsigned char tempA = 0x00;
	unsigned char tempC = 0x00; 
	unsigned char beltLight = 0x00;
  
    	while (1) {
		tempC = 0x00;
		tempA = PINA & 0x0F;
		beltLight = (PINA & 0x70) >> 4; 	

	if (tempA >= 13) {
		tempC = 0x3F;
	}
	else if (tempA >= 10) {
                tempC = 0x3E;
        }
	else if (tempA >= 7) {
                tempC = 0x3C;
        }
	else if (tempA >= 5) {
                tempC = 0x38;
        }
	else if (tempA >= 3) {
                tempC = 0x70;
        }
	else if (tempA >= 1) {
                tempC = 0x60;
        }
	else {
		tempC = 0x40;
	}

	if (beltLight == 0x03) {
		tempC = tempC | 0x80;
	}
	
	PORTC = tempC;
    }
return 1;
}
