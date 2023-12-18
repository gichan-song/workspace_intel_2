/*
 * LED_Shift_1.c
 *
 * Created: 2023-10-17 오전 9:40:57
 * Author : why
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


#define LED_DDR DDRA
#define LED_PORT PORTA

int main(void)
{
	LED_DDR = 0xFF;
    uint8_t ledData = 0x01;
	int direction = 1;

    while (1) 
    {
		LED_PORT = ledData;
		
		if(direction == 1)
		{
			ledData <<= 1;
			if(ledData == 0x80)
			{
				direction = -1;
			}
		}
		else if(direction == -1)
		{
			ledData >>= 1;
			if(ledData == 0x01)
			{
				direction = 1;
			}
			
		}
		_delay_ms(500);	
    }
	
}

