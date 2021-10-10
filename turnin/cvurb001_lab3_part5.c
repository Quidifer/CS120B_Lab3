/*	Author: Christopher Vurbenova-Mouri
 *  Partner(s) Name: none
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *  
 *  Compile command: avr-gcc -mmcu=atmega1284 -I/usr/csshare/pkgs/simavr/ -Iheader/ -D_SIMULATE_ -Wall -g -Og -Wl,--undefined=_mmcu,--section-start=.mmcu=910000 -o build/objects/main.elf source/main.c
 *
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    DDRD = 0x00; PORTD = 0xFF; //inputs

    DDRB = 0xFE; PORTB = 0x01; // lowest bit input , rest output

    unsigned short weight = 0x00;
    while(1) {
        weight = (PIND << 1) + (PINB & 0x01);

        PORTB = 0x0;
        if (weight >= 70) {
            PORTB = (PORTB & 0xF0) | 0x02;
        }
        if (weight > 5 && weight < 70) {
            PORTB = (PORTB & 0xF0) | 0x04;
        }
    }
    return 1;
}
