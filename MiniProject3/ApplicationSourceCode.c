/*
 ================================================================================================
 Name        : Fan Controller system
 Author      : Omar Muhammad
 Description : Fan Controller system based on the analog signal received from temperature sensor
 Date        : 10/4/2022
 ================================================================================================
 */

#include "HAL/lcd.h"
#include "MCAL/adc.h"
#include "HAL/dcmotor.h"
#include "HAL/lm35_sensor.h"

int main(void)
{
	uint8 temp;
	boolean fanStatus = FALSE;

	/* Create configuration structure for ADC driver */
	ADC_ConfigType ADC_Config = {INTERNAL2_56,DIV_8};


	LCD_init(); /* initialize LCD driver */
	ADC_init(&ADC_Config); /* initialize ADC driver */
	DCMOTOR_init(); /* initialize DCMOTOR driver */

	/* Display this string "Fan is" only once on LCD at the first row*/
	LCD_moveCursor(0,4);
	LCD_displayString("Fan is");

	/* Display this string "Temp =" only once on LCD at the second row*/
	LCD_moveCursor(1,4);
	LCD_displayString("Temp =    C");

	while(1)
	{
		temp = LM35_getTemperature();

		/* Display the temperature value every time at same position */
		LCD_moveCursor(1,11);
		if(temp >= 120)
		{
			LCD_intgerToString(temp);
			DCMotor_Rotate(CW, 100);
			fanStatus = TRUE;
		}
		else
		{
			if(temp >= 90)
			{
				LCD_intgerToString(temp);
				DCMotor_Rotate(CW, 75);
				fanStatus = TRUE;
			}
			else if(temp >= 60)
			{
				LCD_intgerToString(temp);
				DCMotor_Rotate(CW, 50);
				fanStatus = TRUE;
			}
			else if(temp >= 30)
			{
				LCD_intgerToString(temp);
				DCMotor_Rotate(CW, 25);
				fanStatus = TRUE;
			}
			else
			{
				LCD_intgerToString(temp);
				DCMotor_Rotate(STOP, 0);
				/* In case the digital value is two or one digits print space in the next digit place */
				fanStatus = FALSE;
			}

			if(temp<100)
			{
				LCD_displayCharacter(' ');
			}
		}

		/* Display the fan status every time at same position */
		LCD_moveCursor(0,11);
		if(fanStatus)
		{
			LCD_displayString("ON ");
		}
		else
		{
			LCD_displayString("OFF");
		}

	}

	return 0;
}
