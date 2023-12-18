/*
 * Button.c
 *
 * Created: 2023-10-19 오전 9:37:33
 * Author : why
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRA = 0xff;	// LED 포트 출력 설정 - 방향
	DDRC &= ~(1<<PINC0);
    
	uint8_t ledData = 0x01;		// 8개 중에서 첫번째만 ON
	uint8_t buttonData;			// 버튼 눌렀을 때 받아올 변수

	int flag = 0;

	PORTA = 0x00;				// 최초 전원인가시 LED는 꺼진 상태

    while (1) 
    {
		buttonData = PINC;		// 현재 상태의 포트C를 읽음
		if ((buttonData & (1 << PINC0)) == 0)
		{
			_delay_ms(5);		// DeBounce 코드
			if ((buttonData & (1 << PINC0)) == 0)
			{
				PORTA = ledData;
				ledData = (ledData >> 7) | (ledData << 1);
				_delay_ms(200);
			}
		}
		//if ((buttonData & (1 << PINC0)) == 0)
		//{
			//PORTA = ledData;
			//ledData = (ledData >> 7) | (ledData << 1);
			//_delay_ms(200);
		//}
		
		if ((buttonData & (1 << PINC1)) == 0)
		{
			PORTA = ledData;
			ledData = (ledData >> 1) | (ledData << 7);
			_delay_ms(200);
		}

		//if ((buttonData & (1 << 0)) & (buttonData & (1 << 1)) == 0)
		//{
			//PORTA = 0xff;
		//}
    }
}

