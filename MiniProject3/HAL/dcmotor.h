/******************************************************************************
 *
 * Module: DC-Motor
 *
 * File Name: dcmotor.h
 *
 * Description: Header file for the DC-motor driver
 *
 * Author: Omar Muhammad
 *
 *******************************************************************************/

#ifndef DCMOTOR_H_
#define DCMOTOR_H_

#include "../MCAL/std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* DC-Motor HW Ports and Pins Ids */
#define DCMOTOR_INT1_PORT_ID                 PORTB_ID
#define DCMOTOR_INT1_PIN_ID                  PIN0_ID
#define DCMOTOR_INT2_PORT_ID                 PORTB_ID
#define DCMOTOR_INT2_PIN_ID                  PIN1_ID

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum
{
	STOP,CW,A_CW
}DcMotor_State;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Initialize the DC-Motor:
 * 1. Setup the direction for the two motor pins through the GPIO driver.
 * 2. Stop the DC-Motor at the beginning through the GPIO driver .
 */
void DCMOTOR_init(void);

/*
 * Description :
 * 1. Rotate the DC Motor clockwise (CW), anti-clockwise (A_CW), or
 *    stop the motor based on the state input state value.
 * 2. Send the required duty cycle to the PWM driver based on the
 *    required speed value.
 */

void DCMotor_Rotate(DcMotor_State state, uint8 speed);

#endif /* DCMOTOR_H_ */
