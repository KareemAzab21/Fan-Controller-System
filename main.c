/*
 * main.c
 *
 *  Created on: May 25, 2022
 *      Author: lenovo
 */
#include "avr/io.h"
#include "adc.h"
#include "lcd.h"
#include "dcmotor.h"
#include "lm35_sensor.h"


int main(void){
	SREG|=(1<<7);
	ADC_ConfigType Configurations = {INTERNAL_VOLT,F_CPU_8};
	ADC_init(&Configurations);
	LCD_init();
	LCD_moveCursor(0,3);
	LCD_displayString("FAN is OFF");
	LCD_moveCursor(1,3);
	LCD_displayString("Temp =    C");
	DcMotor_Init();
	uint8 temp;
	while(1)
	{
		temp=LM35_getTemperature();
		LCD_moveCursor(0,3);
		if(temp >= 120)
		{
			LCD_displayString("FAN is ON ");
			DcMotor_Rotate(DC_MOTOR_CW,100);
		}
		else if(temp >= 90)
		{
			LCD_displayString("FAN is ON ");
			DcMotor_Rotate(DC_MOTOR_CW,75);
		}
		else if(temp >= 60)
		{
			LCD_displayString("FAN is ON ");
			DcMotor_Rotate(DC_MOTOR_CW,50);
		}
		else if(temp >= 30)
		{
			LCD_displayString("FAN is ON ");
			DcMotor_Rotate(DC_MOTOR_CW,25);
		}
		else
		{ +
			LCD_displayString("FAN is OFF");
			DcMotor_Rotate(DC_MOTOR_STOP,0);
		}

		LCD_moveCursor(1,10);
		if(temp >= 100)
		{
					LCD_intgerToString(temp);
		}
		else
		{
			LCD_intgerToString(temp);
			LCD_displayCharacter(' ');
		}

	}


	return 0;
}


