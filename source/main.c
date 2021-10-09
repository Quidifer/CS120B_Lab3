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

    unsigned char fuel_level = 0x00;
    while(1) {
        fuel_level = 0x00;
        PORTC = 0x00;

        fuel_level = PORTA;

        switch (fuel_level) {
            case 1:
            case 2:
                PORTC = 0x20;
                break;
            case 3:
            case 4:
                PORTC = 0x30;
                break;
            case 5:
            case 6:
                PORTC = 0x38;
                break;
            case 7:
            case 8:
            case 9:
                PORTC = 0x3C;
                break;
            case 10:
            case 11:
            case 12:
                PORTC = 0x3E;
                break;
            case 13:
            case 14:
            case 15:
                PORTC = 0x3F;
                break;
        }

        if (fuel_level <= 4) {
            
        }
    }
    return 1;
}
