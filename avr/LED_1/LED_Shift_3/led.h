/*
 * led.h
 *
 * Created: 2023-10-17 오전 11:58:54
 *  Author: why
 */ 


#ifndef LED_H_
#define LED_H_

#include <avr/io.h>

#define LED_DDR DDRA
#define LED_PORT PORTA

void GPIO_Output(uint8_t data);		// 출력포트 함수
void ledInit();						// 출력에 대한 초기화 함수
void ledLeftShift(uint8_t *data);	// 왼쪽으로 시프트 함수
void ledRightShift(uint8_t *data);	// 오른쪽으로 시프트 함수


#endif /* LED_H_ */