/*
 * BUZZER.c
 *
 *  Created on: Oct 4, 2024
 *      Author: Mahmoud Ashraf
 */

#include "../../HAL/BUZZER/Buzzer.h"


void Buzzer_init(void){
	GPIO_setupPinDirection(PORTD_ID,PIN3_ID,PIN_OUTPUT);
	GPIO_writePin(PORTD_ID,PIN3_ID,LOGIC_LOW);
}


void Buzzer_On(void){
	GPIO_writePin(PORTD_ID,PIN3_ID,LOGIC_HIGH);
}


void Buzzer_Off(void){
	GPIO_writePin(PORTD_ID,PIN3_ID,LOGIC_LOW);
}

