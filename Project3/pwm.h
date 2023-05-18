/*
 ================================================================================================
 Module		 : PWM

 Name        : pwm.c

 Author      : Hassan Sabry Ahmed Shahin

 Description : header file for PWM

 Date        : Apr 4, 2023
 ================================================================================================
 */

#ifndef PWM_H_
#define PWM_H_
#include "std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* Motor HW Ports and Pins Ids */

#define MOTOR_PWM_PORT_ID                 		  PORTB_ID
#define MOTOR_PWM_PIN_ID                     	  PIN3_ID


/*******************************************************************************
 *                               Functions Prototypes                              *
 *******************************************************************************/

void PWM_Timer0_Start(uint8 duty_cycle);


#endif /* PWM_H_ */
