#ifndef STEPPER_H_
#define STEPPER_H_

#define F_CPU 8000000UL

#include "Data_D_Types.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include <util/delay.h>

#define Step       5
#define Direction  6

void Stepper_RotateCW(void);

#endif /* STEPPER_H_ */
