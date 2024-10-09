/*
 * interrupt.c
 *
 *  Created on: Oct 4, 2024
 *      Author: Mahmoud Ashraf
 */


#include "pwm.h"

void PWM_Timer0_Start(uint8 duty_cycle) {
	/*mapping from 0% ---> 100 % to 0 ---> 255*/
	uint8 mod_duty_cycle = (uint8) ((uint16)255 * duty_cycle / 100);
	/*select operation mode in (Fast PWM)*/
	SET_BIT(TCCR0, WGM00);
	SET_BIT(TCCR0, WGM01);
	/*define counter initialization*/
	TCNT0 = 0;
	/*define comperation value initialization*/
	OCR0 = mod_duty_cycle;
	/*select comperation  mode (Non-inverting mode )*/
	SET_BIT(TCCR0, COM01);
	CLEAR_BIT(TCCR0, COM00);
	/*Select Prescaler as 1024*/
	SET_BIT(TCCR0, CS00);
	CLEAR_BIT(TCCR0, CS01);
	SET_BIT(TCCR0, CS02);
	/*select OCO as output pin For PWM*/
	GPIO_setupPinDirection(PORTB_ID, PIN3_ID, PIN_OUTPUT);
}

