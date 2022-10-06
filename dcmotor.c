/*
 * dcmotor.c
 *
 *  Created on: May 25, 2022
 *      Author: lenovo
 */

#include "dcmotor.h"
#include "gpio.h"


void DcMotor_Init(void)
{
	GPIO_setupPinDirection(PORTB_ID,PIN0_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID,PIN1_ID,PIN_OUTPUT);
	GPIO_writePin(PORTB_ID,PIN0_ID,LOGIC_LOW);
	GPIO_writePin(PORTB_ID,PIN1_ID,LOGIC_LOW);
}


void DcMotor_Rotate(DcMotor_State state)
{
	if(state == DC_MOTOR_CW)
	{
		GPIO_writePin(PORTB_ID,PIN0_ID,LOGIC_LOW);
		GPIO_writePin(PORTB_ID,PIN1_ID,LOGIC_HIGH);

	}
	else if(state == DC_MOTOR_ACW)
	{
		GPIO_writePin(PORTB_ID,PIN0_ID,LOGIC_HIGH);
		GPIO_writePin(PORTB_ID,PIN1_ID,LOGIC_LOW);

	}
	else if(state == DC_MOTOR_STOP)
	{
		GPIO_writePin(PORTB_ID,PIN0_ID,LOGIC_LOW);
		GPIO_writePin(PORTB_ID,PIN1_ID,LOGIC_LOW);

	}

}
