/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/
#ifndef _DIO_INT_H
#define _DIO_INT_H

#include "Data_D_Types.h"

/* Port Defines */
#define PORTA    0
#define PORTB    1
#define PORTC    2
#define PORTD    3

/* PIN Defines */
#define PIN0   0
#define PIN1   1
#define PIN2   2
#define PIN3   3
#define PIN4   4
#define PIN5   5
#define PIN6   6
#define PIN7   7

/* PIN Directions */
#define INPUT  0
#define OUTPUT 1

/* PIN Value Options */
#define HIGH   1
#define LOW    0

/* IO Pins */
void DIO_SetPinValue(u8 u8PortIdCopy , u8 u8PinIdCopy, u8 u8PinValCopy);

u8 DIO_GetPinValue(u8 u8PortIdCopy, u8 u8PinIdCopy);

void DIO_SetPinDirection (u8 u8PortIdCopy, u8 u8PinIdCopy, u8 u8PinDirCopy);

/* IO Ports */
void DIO_SetPortDirection (u8 u8PortId, u8 u8PortDir);

void DIO_SetPortValue     (u8 u8PortId, u8 u8PortVal);

#endif
