/*
 * LED_Flower.c
 *
 * Created: 2023-10-17 오전 11:31:45
 * Author : why
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

uint8_t ledArr[4] =
{
	0x18,		// 0001 1000
	0x24,		// 0010 0100
	0x42,		// 0100 0010
	0x81,		// 1000 0001
	
};

int main(void)
{
	DDRA = 0xFF;	// 출력 설정
	
    while (1) 
    {
		for (uint8_t i = 0; i < 3; i++)
		{
			PORTA = ledArr[i];
			_delay_ms(500);
		}
		for (uint8_t i = 0; i< 3; i++)
		{
			PORTA = ledArr[3-i];
			_delay_ms(500);
		}
		
    }
	return 0;
}

