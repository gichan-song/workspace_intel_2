/*
 * LED_Shift_3.c
 *
 * Created: 2023-10-17 오전 11:56:18
 * Author : why
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "led.h"


int main(void)
{
    ledInit();
    uint8_t ledData = 0x01;
    /* Replace with your application code */
    while (1)
    {
	    for (int i =  0; i < 7; i++)
	    {
		    ledLeftShift(&ledData);
		    _delay_ms(300);
	    }
	    for (int i = 0; i < 7; i++)
	    {
		    ledRightShift(&ledData);
		    _delay_ms(300);
	    }
	    
    }
}

