#include<avr/interrupt.h>
#include"UART.h"

extern volatile u8 Sensor_Readings_Tx[14]={0};
extern volatile u8 Factory_Status=0;  // 0: Factory ON -- 1: Factory Off

void UART_Init(void)
{
	UCSRA_Register=0b11000000;  // The RXC Flag can be used to generate a Receive Complete interrupt ( page: 158 ) -- Enable Normal Tx
	UCSRB_Register=0b10010000; // Rx enable -- Rx ISR Enable -- Z2:0 means 8 bit
	UCSRC_Register=0b10000110;  // no parity -- 1 stop bit -- 8 bit data
	UBRRL_Register=51; // 51: 9600 bps
	UBRRH_Register=0;
}

void UART_SendCharacter(u8 character)
{
	while(GET_BIT(UCSRA,PIN5)==0); // UDRE: USART Data Register Empty , The UDRE Flag indicates if the transmit buffer (UDR) is ready to receive new data.
	// when it equal zero that mean that means the register is full of data and can't send now

	UDR=character;

	while(GET_BIT(UCSRA,PIN6)==0);  // Donot leave untill the Transmission Complete

}

void UART_Send_Readings(u8*ptr)
{
	u8 i;
	for(i=0;i<13;i++)
	{
		UART_SendCharacter(Sensor_Readings_Tx[i]);
	}
}

ISR(USART_RXC_vect)
{
	Factory_Status=UDR_Register;
}
