/*
 * app.c
 *
 *  Created on: Oct 4, 2024
 *      Author: Mahmoud Ashraf
 */

#include "app.h"
uint8 Flage = 0;
uint8 tempreture = 0;
uint8 Intensity = 0;
int main(void) {
	//void App_init(void);
	Buzzer_init();
	Flame_Inti();
	LEDS_Init();
	LCD_init();
	DcMotor_Inti();
	//====================Thanks Mohamed Tarek===============
	LCD_displayString("ENG MohamedTarek");
	LCD_displayStringRowColumn(1, 0, " Mahmoud Ashraf");
	_delay_ms(500);
	LCD_clearScreen();
	while (1) {
		//************************************************************
		/*Start coding*/
		//********************************************************
		//================= to avoid overwrite ==================
		if (Flame_GetValue() == 0) {
			if (Flage == 1) {
				LCD_clearScreen();
				Flage = 0;
			}
			Buzzer_Off();
			//================= to display ("FAN IS" , "Temp=" , "LDR=" )=================
			LCD_displayStringRowColumn(0, 4, "FAN IS");
			LCD_displayStringRowColumn(1, 0, "Temp=");    //write Value in col 5
			LCD_displayStringRowColumn(1, 8, "LDR=");    //write Value in col 12
			// ================to display temperature ===============
			tempreture = LM35_ReadTemp();
			LCD_moveCursor(1, 5);
			if (tempreture >= 150) {
				LCD_intgerToString(tempreture);
			} else {
				LCD_intgerToString(tempreture);
				/* In case the digital value is three or two or one digits print space in the next digit place */
				LCD_displayCharacter(' ');
			}
			// ================to display Intensity ===============
			Intensity = LDR_getLightIntensity();
			LCD_moveCursor(1, 12);
			if (Intensity >= 100) {
				LCD_intgerToString(Intensity);
				LCD_displayCharacter('%');
			} else if(Intensity < 10) {
				LCD_intgerToString(Intensity);
				/* In case the digital value is three or two or one digits print space in the next digit place */
				LCD_displayCharacter(' ');
				LCD_displayCharacter(' ');
				LCD_displayCharacter('%');
			}else{
				LCD_intgerToString(Intensity);
				LCD_displayCharacter(' ');
				LCD_displayCharacter('%');

			}
			//==================to control of DC_Motor===============
			if (tempreture >= 40) {
				DcMotor_Rotate(CW, 100);
				LCD_displayStringRowColumn(0, 12, "ON");
				LCD_displayCharacter(' ');
			} else if (tempreture >= 35 && tempreture < 40) {
				DcMotor_Rotate(CW, 75);
				LCD_displayStringRowColumn(0, 12, "ON");
				LCD_displayCharacter(' ');
			} else if (tempreture >= 30 && tempreture < 35) {
				DcMotor_Rotate(CW, 50);
				LCD_displayStringRowColumn(0, 12, "ON");
				LCD_displayCharacter(' ');
			} else if (tempreture >= 25 && tempreture < 30) {
				DcMotor_Rotate(CW, 25);
				LCD_displayStringRowColumn(0, 12, "ON");
				LCD_displayCharacter(' ');
			} else if (tempreture < 25) {
				DcMotor_Rotate(CW, 0);
				LCD_displayStringRowColumn(0, 12, "OFF");
			}
			//==================to Control of LEDS==================
			if (Intensity <= 15) {
				LED_On(LED1);
				LED_On(LED2);
				LED_On(LED3);

			} else if (Intensity >= 16 && Intensity <= 50) {
				LED_On(LED1);
				LED_On(LED2);
				LED_Off(LED3);
			} else if (Intensity >= 51 && Intensity <= 70) {
				LED_On(LED1);
				LED_Off(LED2);
				LED_Off(LED3);
			} else if (Intensity > 70) {
				LED_Off(LED1);
				LED_Off(LED2);
				LED_Off(LED3);
			}
			//======================================================
		} else {
			//============ to avoid Overwrite ======================
			if (Flage == 0) {
				LCD_clearScreen();
				Flage++;
			}
			LCD_displayStringRowColumn(0, 1, "critical alert! ");
			Buzzer_On();
		}

	}

	return 0;
}

/*void App_init(void) {
 Buzzer_init();
 Flame_Inti();
 LEDS_Init();
 LCD_init();
 DcMotor_Inti();

 }*/
