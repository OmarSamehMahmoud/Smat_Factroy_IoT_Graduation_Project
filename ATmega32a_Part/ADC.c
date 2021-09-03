#include"ADC.h"

volatile u8 Sensor_Readings_Tx[14];

void ADC_init(void)
{
	ADMUX|=(1<<REFS0)|(1<<ADLAR);//adjust reference and left adjust
	//we now select prescalar and enable adc
	ADCSRA|=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);

}
char ADC_GetResult(char ch)
{
	char value;
	ADMUX|=(ch&(0b00000111));//ADC Channels
	ADCSRA|=(1<<ADSC);//adc conversion
	while((ADCSRA&(1<<ADSC))!=0)
		{

		}
	value=ADCH;
	ADCSRA|=0x10;
	return value;
}

void LED_Init(void)
{
	TCCR0=0b01101001;
}

void Fan(void)
{
	u16 val;
	u16 Volt;
	u8 Temprature;

	val=ADC_GetResult(0); // obtain Digital value from LM35 connected with Channel 0 (A0)

	Volt=val*4.88; // (ADC*5000)/1024 calculate voltage in mv  (5000/1024=4.88) -- 2 power 10 = 1024 ( 10 bits = ADCL + ADCH = ADC )

	Temprature=Volt/10;

	if(Temprature>=30)
	{
		SET_BIT(PORTC_Register,PIN6); // Active Fan
		Sensor_Readings_Tx[13]=1; // Cooling system On
	}
	else
	{
		CLR_BIT(PORTC_Register,PIN6); // Disactive Fan
		Sensor_Readings_Tx[13]=0; // Cooling system Off
	}
}

void LDR(void)
{
	u16 val;
	u8 Volt;

	val=ADC_GetResult(1);//obtain Digital value from LDR

	Volt=(val*500)/1024;  // Donot Understand Yet

	if(Volt>=4)
	{
		OCR0=0; // B3: LED 100%
		Sensor_Readings_Tx[12]=2;
	}
	else if((Volt>=2)&&(Volt<4))
	{
		OCR0=64;  // 50%
		Sensor_Readings_Tx[12]=1;
	}
	else
	{
		OCR0=128;
		Sensor_Readings_Tx[12]=0; // Initialy OFF
	}

}
