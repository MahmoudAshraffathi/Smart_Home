/*
 * interrupt.h
 *
 *  Created on: Oct 4, 2024
 *      Author: Mahmoud Ashraf
 */

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include <avr/interrupt.h>
#include "../../MCAL/common_macros.h"
#include "../../MCAL/GPIO/gpio.h"


void PWM_Timer0_Start(uint8 duty_cycle);


#endif /* INTERRUPT_H_ */
