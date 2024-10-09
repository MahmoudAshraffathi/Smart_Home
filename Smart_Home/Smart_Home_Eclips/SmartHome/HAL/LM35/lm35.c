/*
 * Temp.c
 *
 *  Created on: Oct 4, 2024
 *      Author: Mahmoud Ashraf
 */
#include "lm35.h"

uint8 LM35_ReadTemp(void){
uint8 Temp_Value = 0 ;
uint8 ADC_Value = 0 ;
ADC_init();
ADC_Value = ADC_readChannel(PIN_SENSOR);
Temp_Value  = (uint8)(((uint32)ADC_Value*SENSOR_MAX_TEMPERATURE*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));

return (Temp_Value);
}
