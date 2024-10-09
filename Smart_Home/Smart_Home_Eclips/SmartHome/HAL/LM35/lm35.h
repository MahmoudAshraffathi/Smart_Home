/*
 * Temp.h
 *
 *  Created on: Oct 4, 2024
 *      Author: Mahmoud Ashraf
 */

#ifndef TEMP_H_
#define TEMP_H_


#include "../../MCAL/ADC/adc.h"
#include "../../MCAL/GPIO/gpio.h"


#define PIN_SENSOR   PIN1_ID
#define SENSOR_MAX_VOLT_VALUE     1.5
#define SENSOR_MAX_TEMPERATURE    150
uint8 LM35_ReadTemp(void);


#endif /* TEMP_H_ */
