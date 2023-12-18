/*
 * Button_1.c
 *
 * Created: 2023-10-19 오전 10:56:30
 * Author : why
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "Button.h"


int main(void)
{
	LED_DDR = 0xff;
	Button btnOn;
	Button btnOff;

	Button_init(&btnOn, &BUTTON_DDR, &BUTTON_PIN, BUTTON_ON);
	Button_init(&btnOff, &BUTTON_DDR, &BUTTON_PIN, BUTTON_OFF);
    /* Replace with your application code */
    while (1) 
    {
		if (Button_getState(&btnOn) == ACT_RELEASED)
		{
			LED_PORT = 0xff;
		}
		if (Button_getState(&btnOff) == ACT_RELEASED)
		{
			LED_PORT = 0x00;
		}
    }
}

