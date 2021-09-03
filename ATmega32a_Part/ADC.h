/*
 * ADC.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: sameh
 */

#ifndef ADC_H_
#define ADC_H_

#include "Data_D_Types.h"
#include "BIT_MATH.h"
#include<avr/io.h>
#include "DIO_int.h"
#include "DIO_reg.h"

void ADC_init(void);
char ADC_GetResult(char ch);
void LED_Init(void);
void Fan(void);
void LDR(void);

#endif /* ADC_H_ */
