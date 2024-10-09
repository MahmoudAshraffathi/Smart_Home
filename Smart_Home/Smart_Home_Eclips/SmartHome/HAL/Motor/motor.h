/*
 * DC_MOTOR.h
 *
 *  Created on: Oct 4, 2024
 *      Author: Mahmoud Ashraf
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_
#include "../../MCAL/GPIO/gpio.h"
#include "../../MCAL/PWM/pwm.h"

#define IN1  PIN0_ID
#define IN2  PIN1_ID

typedef enum {
	CW ,
	A_CW ,
	Stop
}DCMotor_State ;

void DcMotor_Inti(void);
void DcMotor_Rotate(DCMotor_State state , uint8 speed);


#endif /* DC_MOTOR_H_ */
