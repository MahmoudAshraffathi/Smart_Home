/*
 * DC_MOTOR.c
 *
 *  Created on: Oct 4, 2024
 *      Author: Mahmoud Ashraf
 */

#include "../../HAL/Motor/motor.h"

void DcMotor_Inti(void){
	GPIO_setupPinDirection(PORTB_ID,IN1,PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID,IN2,PIN_OUTPUT);
	PWM_Timer0_Start(0);
}

void DcMotor_Rotate( DCMotor_State state , uint8 speed){
	switch (state) {
		case CW:
			GPIO_writePin(PORTB_ID,IN1,LOGIC_HIGH);
			GPIO_writePin(PORTB_ID,IN2,LOGIC_LOW);
			PWM_Timer0_Start(speed);
			break;
		case A_CW:
			GPIO_writePin(PORTB_ID,IN1,LOGIC_LOW);
			GPIO_writePin(PORTB_ID,IN2,LOGIC_HIGH);
			PWM_Timer0_Start(speed);
			break;
		case Stop:
			GPIO_writePin(PORTB_ID,IN1,LOGIC_LOW);
			GPIO_writePin(PORTB_ID,IN2,LOGIC_LOW);
			PWM_Timer0_Start(0);
			break;
		default:
			break;
	}

}
