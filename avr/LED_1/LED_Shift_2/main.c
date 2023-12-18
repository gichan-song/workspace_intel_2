/*
 * LED_Shift_2.c
 *
 * Created: 2023-10-17 오전 10:31:12
 * Author : why
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


#define LED_DDR DDRA
#define LED_PORT PORTA	// 매크로 상수

void GPIO_Output(uint8_t data);
void ledInit();
void ledLeftShift(uint8_t *data);
void ledRightShift(uint8_t *data);



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

void GPIO_Output(uint8_t data) //LED 출력에 대한 함수 선언
{
	LED_PORT = data;
}

void ledInit()
{
	LED_DDR = 0xFF;
}


void ledLeftShift(uint8_t *data)
{
	*data = (*data >> 7) | (*data << 1);
	GPIO_Output(*data);
}

void ledRightShift(uint8_t *data)
{
	*data = (*data << 7) | (*data >> 1);
	GPIO_Output(*data);
}