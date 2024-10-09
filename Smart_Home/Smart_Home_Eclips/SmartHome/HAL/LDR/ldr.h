/*
 * LDR.h
 *
 *  Created on: Oct 4, 2024
 *      Author: Mahmoud Ashraf
 */

#ifndef LDR_H_
#define LDR_H_

#include "../../MCAL/ADC/adc.h"
#include "../../MCAL/GPIO/gpio.h"

#define LDR_SENSOR_CHANNAL_ID    PIN0_ID
#define LDR_SENSOR_MAX_VOLT_VALUE    2.56
#define LDR_SENSOR_MAX_LIGHT_INTENSITY    100


uint8 LDR_getLightIntensity(void);


#endif /* LDR_H_ */
