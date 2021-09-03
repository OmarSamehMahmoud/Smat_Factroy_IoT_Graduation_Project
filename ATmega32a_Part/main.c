#include "Ultrasonic.h"
#include "IR.h"
#include "ADC.h"
#include "stepper.h"
#include "UART.h"
#include "DIO_int.h"

volatile u8 Factory_Status;
volatile u8 Sensor_Readings_Tx[14];

ISR(INT0_vect)
{
	DIO_SetPinValue(PORTD,PIN7,HIGH); // Buzzer On Because of Fire On Factory
	Sensor_Readings_Tx[11]=1; // Factory is Firing :(

}

int main (void)
{
	DIO_SetPinDirection(PORTB,PIN0,INPUT);  // B0: Ultrasonic1 Echo
	DIO_SetPinDirection(PORTB,PIN1,INPUT);  // B1: Ultrasonic2 Echo
	DIO_SetPinDirection(PORTB,PIN2,INPUT);  // B2: Ultrasonic3 Echo
	DIO_SetPinDirection(PORTB,PIN4,INPUT);  // B4: Ultrasonic5 Echo

	DIO_SetPinDirection(PORTC,PIN0,OUTPUT);  // C0: Ultrasonic1 Trigger
	DIO_SetPinDirection(PORTC,PIN1,OUTPUT);  // C1: Ultrasonic2 Trigger
	DIO_SetPinDirection(PORTC,PIN2,OUTPUT);  // C2: Ultrasonic3 Trigger
	DIO_SetPinDirection(PORTC,PIN3,OUTPUT);  // C3: Ultrasonic4 Trigger
	DIO_SetPinDirection(PORTC,PIN4,OUTPUT);  // C4: Ultrasonic5 Trigger
	DIO_SetPinDirection(PORTC,PIN5,INPUT);  // C5: Ultrasonic4 Echo

	DIO_SetPinDirection(PORTD,PIN0,OUTPUT);  // D0: LED
	DIO_SetPinDirection(PORTD,PIN3,OUTPUT);  // D3: LED
	DIO_SetPinDirection(PORTD,PIN4,OUTPUT);  // D4: LED
	DIO_SetPinDirection(PORTD,PIN5,OUTPUT);  // D5: LED
	DIO_SetPinDirection(PORTD,PIN6,OUTPUT);  // D6: LED

	DIO_SetPinDirection(PORTD,PIN0,INPUT);  //  D0: Rx ( input )
	DIO_SetPinDirection(PORTD,PIN1,OUTPUT); //  D1: Tx ( output )

	DIO_SetPinDirection(PORTD,PIN2,INPUT);  // D2: Input (INT0 : EXternal Interrupt 0) Flame
	DIO_SetPinDirection(PORTD,PIN7,OUTPUT); // D7: Buzzer For Flame Sensor

	DIO_SetPinDirection(PORTA,PIN2,INPUT); // A2 : Input : IR_Sensor
	DIO_SetPinDirection(PORTA,PIN3,INPUT); // A3 : Input : IR_Sensor
	DIO_SetPinDirection(PORTA,PIN4,INPUT); // A4 : Input : IR_Sensor
	DIO_SetPinDirection(PORTA,PIN5,INPUT); // A5 : Input : IR_Sensor
	DIO_SetPinDirection(PORTA,PIN6,INPUT); // A6 : Input : IR_Sensor
	DIO_SetPinDirection(PORTA,PIN7,INPUT); // A7 : Input : IR_Sensor

	DIO_SetPinDirection(PORTC,PIN7,OUTPUT);  // C7: LED Indicator of IR Sensors

	DIO_SetPinDirection(PORTA,PIN1,INPUT); // A1 : Input : LDR_Sensor
	DIO_SetPinDirection(PORTB,PIN3,OUTPUT);  // B3: Factory_LED_Intensity

	DIO_SetPinDirection(PORTA,PIN0,INPUT); // A0 : Input : LM35_Sensor
	DIO_SetPinDirection(PORTC,PIN6,OUTPUT);  // C6: Fan_Control

    SET_BIT(GICR,PIN6); // Prephral Interrupt Enable ( PIE ) of INT0
	SET_BIT(MCUCR,PIN0);  // bit0 = 1 & bit1 = 1 means:         (page: 64)
	SET_BIT(MCUCR,PIN1);  // ExternaL Interrupt 0 happen on : Rising Edge

	DIO_SetPinDirection(PORTB,PIN5,OUTPUT);  // B5: Stepper Step
	DIO_SetPinDirection(PORTB,PIN6,OUTPUT);  // B6: Stepper Direction

	DIO_SetPinValue(PORTB,PIN6,LOW); // Move Clock Wise ( Forward )

	Ultrasonic_init(); // Ultrasonic Init

	ADC_init();  // ADC Init

	LED_Init(); // Timer0 Init for LED Intensity

	UART_Init(); // UART Init

	SET_BIT(SREG,PIN7); // SREG Pin7 to Enable the Global Interrupt Enable page 8

	u16 i;  // For Loop Counter

	DIO_SetPinValue(PORTD,PIN7,LOW); // Buzzer OFF

	u8 Break_Flag=0;

     while(1)
	{
      LDR();
      Check_All_UltraSonic();
      UART_Send_Readings(Sensor_Readings_Tx);
 	  for(i=0;i<1600;i++)   // 200*2 msec = 400 msec = one revolution
 	     	 {
 	     	 	Stepper_RotateCW();
 	     	 	Check_All_IR();
 	     	 	while(Factory_Status!=0)
 	     	 		{
 	     	 		   if(Sensor_Readings_Tx[11]==1)
 	     	 		   {
 	     	 			   Break_Flag=1;
 	     	 			   break;
 	     	 		   }
 	     	 		}
 	     	 	if(Break_Flag==1)
 	     	 	{
 	     	 		break;
 	     	 	}
 	     	 }
 	 if(Break_Flag==1)
 		 {
 		    UART_Send_Readings(Sensor_Readings_Tx); // For Emergency of Firing
 		    for(i=0;i<12;i++)  // Delay For 1 Sec Until Firing is End
 		    {
 		    	_delay_ms(5000);
 		    }
 		    Break_Flag=0;
 		 }
 	  Check_All_IR();
 	  Check_All_UltraSonic();
 	  LDR();
 	  Check_All_IR();
 	  UART_Send_Readings(Sensor_Readings_Tx);
 	  // Fan();
 	  _delay_ms(5000);
 	  UART_Send_Readings(Sensor_Readings_Tx);
 	  DIO_SetPinValue(PORTD,PIN7,LOW); // Buzzer OFF
	}

	return 0;
}
