/* 
 * File:   PIC_HC595_lib.h
 * Author: Alex Saucet
 *
 * Created on August 13, 2017, 5:39 PM
 */

#ifndef PIC_HC595_LIB_H
#define	PIC_HC595_LIB_H

#include <xc.h>
#include <stdint.h>

/****** CHANGE VALUES BELOW ******/
// System clock frequency
#define _XTAL_FREQ  8000000

// Define the pins used
#define HC595_SER           PORTAbits.RA0
#define HC595_RCLK          PORTAbits.RA1
#define HC595_SRCLK         PORTAbits.RA2
#define HC595_SRCLR         PORTAbits.RA3
#define HC595_SER_TRIS      TRISAbits.TRISA0
#define HC595_RCLK_TRIS     TRISAbits.TRISA1
#define HC595_SRCLK_TRIS    TRISAbits.TRISA2
#define HC595_SRCLR_TRIS    TRISAbits.TRISA3

/****** DO NOT CHANGE VALUES BELOW ******/
#define HC595_LSB_FIRST 0
#define HC595_MSB_FIRST 1

/**
 * Initialize HC595 module
 */
void HC595Init();

/**
 * Clear the output.
 */
void HC595Clear();

/**
 * Send a value to the HC595.
 * @param value
 */
void HC595SendValue(uint8_t value, uint8_t direction);

/**
 * Toggle the SRCLK pin of the HC595
 */
void HC595ToggleClk();

/**
 * Toggle the RCLK pin of the HC595 to register output
 */
void HC595TriggerOutput();

#endif	/* PIC_HC595_LIB_H */

