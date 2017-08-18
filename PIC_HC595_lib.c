#include "PIC_HC595_lib.h"


/**
 * Initialize HC595 module
 */
void HC595Init() {
    HC595_SER = 0;
    HC595_RCLK = 0;
    HC595_SRCLK = 0;
    HC595_SRCLR = 1;
    
    HC595_SER_TRIS = 0;
    HC595_RCLK_TRIS = 0;
    HC595_SRCLK_TRIS = 0;
    HC595_SRCLR_TRIS = 0;
}

/**
 * Clear the output.
 */
void HC595Clear() {
    HC595SendValue(0x00, HC595_LSB_FIRST);
}

/**
 * Send a value to the HC595.
 * @param value
 */
void HC595SendValue(uint8_t value, uint8_t direction) {
    for (int i=0 ; i<8 ; i++) {
        if (direction == HC595_MSB_FIRST) {
            HC595_SER = (value >> i) & 0x01;
        } else {
            HC595_SER = (value << i) & 0x80 ? 1 : 0;
        }
        HC595ToggleClk();
    }
    HC595TriggerOutput();
}

/**
 * Toggle the SRCLK pin of the HC595
 */
void HC595ToggleClk() {
    HC595_SRCLK = 1;
    __delay_us(500);
    HC595_SRCLK = 0;
    __delay_us(500);
}

/**
 * Toggle the RCLK pin of the HC595 to register output
 */
void HC595TriggerOutput() {
    HC595_RCLK = 1;
    __delay_us(500);
    HC595_RCLK = 0;
}
