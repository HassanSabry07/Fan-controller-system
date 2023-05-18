/*
 ================================================================================================
 Name        : Project3.c

 Author      : Hassan Sabry Ahmed Shahin

 Description : design a temperature-controlled fan using ATmega32 microcontroller,
  	  	  	   in which the fan is automatically turned ON or OFF according to the temperature.

 Date        : Apr 4, 2023
 ================================================================================================
 */


#include "lcd.h"
#include "motor.h"
#include "adc.h"


int main(void){

	/*local variable to display temperature on lcd*/
	uint8 temp;

	/* initialize LCD driver */
	LCD_init();

	/* initialize MOTOR driver */
	DcMotor_Init();

	/* initialize PWM */
	PWM_Timer0_Init(0);

	/* initialize ADC driver configuration with 2.56 volt and 8 prescaler*/
	ADC_ConfigType ADC_Config={Internal_Voltage,F_CPU_8};

	/* initialize ADC driver */
	ADC_init(&ADC_Config);

	/* Display the temperature value every time at same position */
	LCD_moveCursor(1,0);

	/* Display this string "Temp =   C" only once on LCD at the first row */
	LCD_displayString("Temp =    C");



	while(1)
	{

		temp = LM35_getTemperature();

		if(temp>=30){

			/* In case state was OFF print space in the next digit place to remove (F) letter */
			LCD_moveCursor(0,9);
			LCD_displayCharacter(' ');

			/* Display the FAN state every time at same position */
			LCD_moveCursor(0,0);
			LCD_displayString("FAN IS ON");

			/* Display the temperature value every time at same position */
			LCD_moveCursor(1,7);

			if(temp >= 30 &&temp<60)
			{
				/* Rotate motor clock wise and generate duty cycle 25% to get quarter motor speed */
				DcMotor_Rotate(CW,25);

				/*Display temp value on lcd according to temp sensor*/
				LCD_intgerToString(temp);

			}

			if(temp >= 60 &&temp<90)
			{
				/* Rotate motor clock wise and generate duty cycle 25% to get half motor speed */
				DcMotor_Rotate(CW,50);

				/*Display temp value on lcd according to temp sensor*/
				LCD_intgerToString(temp);


			}

			if(temp >= 90 &&temp<120)
			{
				/* Rotate motor clock wise and generate duty cycle 75% of motor speed */
				DcMotor_Rotate(CW,75);

				/*Display temp value on lcd according to temp sensor*/
				LCD_intgerToString(temp);

				if(temp<100){

					/* Display the temperature value every time at same position */
					LCD_moveCursor(1,7);

					/*Display temp value on lcd according to temp sensor*/
					LCD_intgerToString(temp);

					/* In case the digital value is two or one digits print space in the next digit place */
					LCD_displayCharacter(' ');
				}

			}
			if(temp >= 120)
			{
				/* Rotate motor clock wise and generate duty cycle 100% of motor speed */
				DcMotor_Rotate(CW,100);

				/*Display temp value on lcd according to temp sensor*/
				LCD_intgerToString(temp);


			}
		}


		/*temp is < 30 C */
		else
		{
			/*Stop the motor*/
			DcMotor_Rotate(Stop,0);

			/* Display the temperature value every time at same position */
			LCD_moveCursor(1,7);

			/*Display temp value on lcd according to temp sensor*/
			LCD_intgerToString(temp);

			if(temp<10){
				/* Display the temperature value every time at same position */
				LCD_moveCursor(1,7);

				/*Display temp value on lcd according to temp sensor*/
				LCD_intgerToString(temp);

				/* In case the digital value is two or one digits print space in the next digit place */
				LCD_displayCharacter(' ');
			}

			/* Display the FAN state every time at same position */
			LCD_moveCursor(0,0);
			LCD_displayString("FAN IS OFF");


		}
	}
}
