#include "stepper.h"

void Stepper_RotateCW(void)  // Only One Step
{
	DIO_SetPinValue(PORTB,Step,HIGH);
	_delay_ms(1);
	DIO_SetPinValue(PORTB,Step,LOW);
	_delay_ms(1);
}


