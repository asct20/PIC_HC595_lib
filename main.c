/*
 * File:   main.c
 * Author: Alex Saucet
 *
 * Created on August 13, 2017, 5:39 PM
 */

// CONFIG1
#pragma config FOSC = INTOSCIO  // Oscillator Selection bits (INTRC oscillator; port I/O function on both RA6/OSC2/CLKO pin and RA7/OSC1/CLKI pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is digital I/O, MCLR internally tied to VDD)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = ON         // Low-Voltage Programming Enable bit (RB3/PGM pin has PGM function, Low-Voltage Programming enabled)
#pragma config CPD = OFF        // Data EE Memory Code Protection bit (Code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off)
#pragma config CCPMX = RB0      // CCP1 Pin Selection bit (CCP1 function on RB0)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// CONFIG2
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal External Switchover mode disabled)

#include <xc.h>
#include <stdint.h>

#include "PIC_HC595_lib.h"

#define _XTAL_FREQ  8000000     // System clock frequency

void init() {
    // Oscillator config
    OSCCONbits.SCS = 0b00;      // Oscillator mode defined by FOSC<2:0>
    OSCCONbits.IRCF = 0b111;    // Internal RC freq to 8 MHz
    OSCCONbits.IOFS = 1;        // Int freq is stable
    
    ANSEL = 0x00;               // Set all I/O to digital I/O
    
    HC595Init();
}

void main(void) {
    uint8_t count = 0x00;
    
    init();
    
    while (1) {
        HC595SendValue(count, HC595_LSB_FIRST);
        count++;
        __delay_ms(150);
    }
    
    return;
}

