/*
 ================================================================================================
 Module		 : PWM

 Name        : pwm.c

 Author      : Hassan Sabry Ahmed Shahin

 Description : source file for PWM

 Date        : Apr 4, 2023
 ================================================================================================
 */


#include <avr/io.h>
#include "std_types.h"
#include "gpio.h"
#include "pwm.h"


void PWM_Timer0_Init(uint8 duty_cycle)
{

	/*Set Timer Initial value*/
	TCNT0 = 0;

	/*Set Compare Value*/
	OCR0  = duty_cycle;

	/*set PB3/OC0 as output pin --> pin where the PWM signal is generated from MC.*/
	GPIO_setupPinDirection(MOTOR_PWM_PORT_ID,MOTOR_PWM_PIN_ID,PIN_OUTPUT);

	/* Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}

void PWM_Timer0_Set_Duty_Cycle(uint8 duty_cycle){

	/*Set Timer Initial value*/
	TCNT0 = 0;

	/*Set Compare Value*/
	OCR0=(uint8)(((uint32)duty_cycle*255)/100);

}

