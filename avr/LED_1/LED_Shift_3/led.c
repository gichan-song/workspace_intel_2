/*
 * led.c
 *
 * Created: 2023-10-17 오전 11:58:31
 *  Author: why
 */ 

 #include "led.h"

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