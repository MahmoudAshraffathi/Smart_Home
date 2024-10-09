/*
 * LDR.c
 *
 *  Created on: Oct 4, 2024
 *      Author: Mahmoud Ashraf
 */

#include "ldr.h"


uint8 LDR_getLightIntensity(void){
	uint16 ADC_Value = 0 ;
	uint8 LDR_Value_Intensity = 0 ;
	ADC_init();
	ADC_Value = ADC_readChannel(LDR_SENSOR_CHANNAL_ID);
	LDR_Value_Intensity = (uint8)(((uint32)ADC_Value*LDR_SENSOR_MAX_LIGHT_INTENSITY*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*LDR_SENSOR_MAX_VOLT_VALUE));
	return(LDR_Value_Intensity);
}
