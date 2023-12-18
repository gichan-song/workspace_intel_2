/*
 * Button.c
 *
 * Created: 2023-10-19 오전 10:58:16
 *  Author: why
 */ 

 #include "Button.h"

 void Button_init(Button *button, volatile uint8_t *ddr,
 volatile uint8_t *pin, uint8_t pinNum)

 {
	button->ddr = ddr;
	button->pin = pin;
	button->btnPin = pinNum;
	button->preState = RELEASED;				// 최초(초기화)에 안누른 상태
	*button->ddr &= ~(1 << button ->btnPin);	// 버튼을 입력으로 설정
 };
 uint8_t Button_getState(Button *button)
 {
	uint8_t curState = *button->pin & (1 << *button->pin);	//버튼 상태

	if ((curState == PUSHED) && (button->preState == RELEASED))	// 안누른 상태에서 누르면
	{
		_delay_ms(10);
		button->preState = PUSHED;	// 버튼을 누른 상태로 변환
		return ACT_PUSH;			// 버튼이 눌렸음을 반환
	}
	else if((curState != PUSHED) && (button->preState) == PUSHED)
	{
		_delay_ms(10);
		button->preState = RELEASED;
		return ACT_RELEASED;
	}
	return NO_ACT;
 };