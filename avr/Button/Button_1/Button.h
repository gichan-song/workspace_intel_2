/*
 * Button.h
 *
 * Created: 2023-10-19 오전 10:58:30
 *  Author: why
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define LED_DDR		DDRA
#define LED_PORT	PORTA
#define BUTTON_DDR	DDRC
#define BUTTON_PIN	PINC
#define BUTTON_ON	0
#define BUTTON_OFF	1

enum {PUSHED, RELEASED};
enum {NO_ACT, ACT_PUSH, ACT_RELEASED};

// 내가 만든 데이터 type
typedef struct _button{				// _button 이라는 구조체 선언
	volatile uint8_t *ddr;			// DDRx을 가리키기 위한 포인터 변수
	volatile uint8_t *pin;			// 버튼 DDR
	uint8_t btnPin;
	uint8_t preState;
}Button;

void Button_init(Button *button, volatile uint8_t *ddr, 
					volatile uint8_t *pin, uint8_t pinNum);
uint8_t Button_getState(Button *button);



#endif /* BUTTON_H_ */