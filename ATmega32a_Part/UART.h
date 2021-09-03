#ifndef UART_H_
#define UART_H_

#include"Data_D_Types.h"
#include"BIT_MATH.h"
#include"DIO_int.h"

#define UDR_Register 	*((volatile u8*)0x2C)
#define UCSRA_Register 	*((volatile u8*)0x2B)
#define UCSRB_Register 	*((volatile u8*)0x2A)
#define UCSRC_Register 	*((volatile u8*)0x40)
#define UBRRH_Register 	*((volatile u8*)0x40)
#define UBRRL_Register 	*((volatile u8*)0x29)

void UART_Init(void);
void UART_SendCharacter(u8 character);
void UART_Send_Readings(u8*ptr);

#endif /* UART_H_ */
