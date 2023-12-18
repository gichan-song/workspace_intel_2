/*
 * LED_1.c
 *
 * Created: 2023-10-10 오후 2:06:34
 * Author : why
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

//
//int main(void)
//{
    //DDRA = 0xff;		//16진수로 표현 a포트 전체를 출력 설정
	//DDRB = 0b00000001; //2진수로 표현 b포트 중 0번 비트만 출력으로 설정 나머지는 입력으로 설정
	//
    //while (1) 
    //{	
		//
		//if(porta==0x00)
		//{
			//porta=0x01;
			//_delay_ms(50);
		//}
		//porta = (porta<<1);
		//_delay_ms(50);
//
		//if(porta==0x80)
		//{
			//porta=0x00;
			//
		//}	
		//
	//
	//}
	//
	//
//}

int main(void)
{
	//DDRA= 0b11111111;
	
	//while(1)
	//{
		//PORTA = 0b10000000;
		//_delay_ms(1);
		//PORTA = 0b01000000;
		//_delay_ms(1);
		//PORTA = 0b00100000;
		//_delay_ms(1);
		//PORTA = 0b00010000;
		//_delay_ms(1);
		//PORTA = 0b00001000;
		//_delay_ms(1);
		//PORTA = 0b00000100;
		//_delay_ms(1);
		//PORTA = 0b00000010;
		//_delay_ms(1);
		//PORTA = 0b00000001;
		//_delay_ms(1);
	//}
	
	DDRA = 0xff;		// 0b11111111
	PORTA = 0x01;
	
	uint8_t LED = 0x01;
	
	for (int i = 0; i < 8; i++)
	{
		PORTA = LED;	
		LED = (LED << 1) | 1;
		_delay_ms(500);
	}
	
	for (int i = 0; i < 8; i++)
	{
		PORTA = LED;
		LED = LED << i;
		
	}
	while(1)
	{
		
	}
}


