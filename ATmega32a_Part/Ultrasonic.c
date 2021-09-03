#include"Ultrasonic.h"

volatile u32 count;
volatile u16 Timer1Overflow=0;
volatile u16 Distance; // range 0:400 cm  ( distance=(34300*TIMER)/2 = 17150*TIMER )
volatile u8 Sensor_Readings_Tx[14];

void Ultrasonic_init(void)
{
// Timer1 Init :
	 SET_BIT(TIMSK,PIN2);  //Timer1 Overflow Interrupt Enable  (PIE)

	 TCCR1A=0; // Set all bits to zero Normal operation
	 CLR_BIT(TCCR1B,PIN3); // normal mode ( mode 0 ) : 107
	 CLR_BIT(TCCR1B,PIN4); // normal mode ( mode 0 ) : 107

	 SET_BIT(TCCR1B,PIN0); // page: 108
	 CLR_BIT(TCCR1B,PIN1); // clk/1
	 CLR_BIT(TCCR1B,PIN2); // (No prescaling)

	 CLR_BIT(TCCR1B,PIN5); // Reserved BIT must be zero

	 CLR_BIT(TCCR1B,PIN7); // no need noise canceller

	 TCNT1=0;         // Clear timer1 counter ( 16 bit = TCNTL & TCNTH )  page: 109

}

void Check_All_UltraSonic(void)
{
	 DIO_SetPinValue(PORTC,PIN0,HIGH); // C0: HIGH ( Connected with Trigger pin on Ultrasonic1 )
	 _delay_us(10);                    // at least 10us pulse on trigger
	 DIO_SetPinValue(PORTC,PIN0,LOW); // C0 : LOW
	 while(DIO_GetPinValue(PORTB,PIN0)!=1);
	 TCNT1=0;
	 Timer1Overflow=0;
	 while(DIO_GetPinValue(PORTB,PIN0)==1);
	 count=TCNT1+(65535*Timer1Overflow);
	 Distance=count/466.4723032;
	 if(Distance<=6)
		  	 {
		          Sensor_Readings_Tx[6]=1; // Full Basket
		  	 }
	 else
		     {
		          Sensor_Readings_Tx[6]=0; // Empty Basket :D
		  	 }
	 _delay_ms(30);
	 DIO_SetPinValue(PORTC,PIN1,HIGH); // C1: HIGH ( Connected with Trigger pin on Ultrasonic2 )
	 _delay_us(10);                    // at least 10us pulse on trigger
	 DIO_SetPinValue(PORTC,PIN1,LOW); // C1 : LOW
	 while(DIO_GetPinValue(PORTB,PIN1)!=1);
	 TCNT1=0;
	 Timer1Overflow=0;
	 while(DIO_GetPinValue(PORTB,PIN1)==1);
	 count=TCNT1+(65535*Timer1Overflow);
	 Distance=count/466.4723032;
	 if(Distance<=6)
		  	 {
		          Sensor_Readings_Tx[7]=1; // Full Basket
		  	 }
	 else
		     {
		          Sensor_Readings_Tx[7]=0; // Empty Basket :D
		  	 }
	 _delay_ms(30);
	 DIO_SetPinValue(PORTC,PIN2,HIGH); // C2: HIGH ( Connected with Trigger pin on Ultrasonic3 )
	 _delay_us(10);                    // at least 10us pulse on trigger
	 DIO_SetPinValue(PORTC,PIN2,LOW); // C2 : LOW
	 while(DIO_GetPinValue(PORTB,PIN2)!=1);
	 TCNT1=0;
	 Timer1Overflow=0;
	 while(DIO_GetPinValue(PORTB,PIN2)==1);
	 count=TCNT1+(65535*Timer1Overflow);
	 Distance=count/466.4723032;
	 if(Distance<=6)
		  	 {
		          Sensor_Readings_Tx[8]=1; // Full Basket
		  	 }
	 else
		     {
		          Sensor_Readings_Tx[8]=0; // Empty Basket :D
		  	 }
	 _delay_ms(30);
	 DIO_SetPinValue(PORTC,PIN3,HIGH); // C3: HIGH ( Connected with Trigger pin on Ultrasonic4 )
	 _delay_us(10);                    // at least 10us pulse on trigger
	 DIO_SetPinValue(PORTC,PIN3,LOW); // C3 : LOW
	 while(DIO_GetPinValue(PORTC,PIN5)!=1);
	 TCNT1=0;
	 Timer1Overflow=0;
	 while(DIO_GetPinValue(PORTC,PIN5)==1);
	 count=TCNT1+(65535*Timer1Overflow);
	 Distance=count/466.4723032;
	 if(Distance<=6)
		  	 {
		          Sensor_Readings_Tx[9]=1; // Full Basket
		  	 }
	 else
		     {
		          Sensor_Readings_Tx[9]=0; // Empty Basket :D
		  	 }
	 _delay_ms(30);
	 DIO_SetPinValue(PORTC,PIN4,HIGH); // C4: HIGH ( Connected with Trigger pin on Ultrasonic5 )
	 _delay_us(10);                    // at least 10us pulse on trigger
	 DIO_SetPinValue(PORTC,PIN4,LOW); // C4 : LOW
	 while(DIO_GetPinValue(PORTB,PIN4)!=1);
	 TCNT1=0;//	 Timer1Overflow=0;
	 while(DIO_GetPinValue(PORTB,PIN4)==1);
	 count=TCNT1+(65535*Timer1Overflow);
	 Distance=count/466.4723032;
	 if(Distance<=6)
		  	 {
		          Sensor_Readings_Tx[10]=1; // Full Basket
		  	 }
	 else
		     {
		          Sensor_Readings_Tx[10]=0; // Empty Basket :D
		  	 }
	 _delay_ms(30);
}


ISR(TIMER1_OVF_vect)
  {
	  Timer1Overflow++;
  }
