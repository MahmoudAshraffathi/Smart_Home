/*
 * Flame.h
 *
 *  Created on: Oct 4, 2024
 *      Author: Mahmoud Ashraf
 */

#ifndef FLAME_H_
#define FLAME_H_

#include "../../MCAL/GPIO/gpio.h"
#define FLAME_PIN       PIN2_ID
#define FLAME_PORT     PORTD_ID


void Flame_Inti(void);

uint8 Flame_GetValue(void);

#endif /* FLAME_H_ */
