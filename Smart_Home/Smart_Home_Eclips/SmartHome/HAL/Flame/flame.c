/*
 * Flame.c
 *
 *  Created on: Oct 4, 2024
 *      Author: Mahmoud Ashraf
 */

#include "../../HAL/Flame/flame.h"

void Flame_Inti(void) {
	GPIO_setupPinDirection(FLAME_PORT, FLAME_PIN, PIN_INPUT);

}

uint8 Flame_GetValue(void) {
	uint8 Flame_Value = 0;

	Flame_Value = GPIO_readPin(FLAME_PORT, FLAME_PIN);

	return Flame_Value;
}
