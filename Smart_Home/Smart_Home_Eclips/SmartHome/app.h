/*
 * app.h
 *
 *  Created on: Oct 4, 2024
 *      Author: Mahmoud Ashraf
 */

#ifndef APP_H_
#define APP_H_
#include "HAL/BUZZER/Buzzer.h"
#include "HAL/Flame/flame.h"
#include "HAL/LCD/lcd.h"
#include "HAL/LDR/ldr.h"
#include "HAL/LED/led.h"
#include "HAL/LM35/lm35.h"
#include "HAL/Motor/motor.h"
#include <avr/delay.h>

void App_init(void);


#endif /* APP_H_ */
