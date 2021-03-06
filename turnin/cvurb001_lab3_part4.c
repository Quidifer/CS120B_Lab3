/*	Author: Christopher Vurbenova-Mouri
 *  Partner(s) Name: none
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
    DDRA = 0x00; PORTA = 0xFF; //inputs

    DDRC = 0xFF; PORTC = 0x00; //outputs
    DDRB = 0xFF; PORTB = 0x00;

    while(1) {
        PORTB = (PORTB & 0xF0) | ((PINA & 0xF0) >> 4);
        PORTC = ((PINA & 0x0F) << 4) | (PORTC & 0x0F);
    }
    return 1;
}
