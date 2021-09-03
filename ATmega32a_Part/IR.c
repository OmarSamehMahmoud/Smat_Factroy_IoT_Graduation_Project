#include"IR.h"
volatile u8 Sensor_Readings_Tx[14];


void Check_All_IR(void)
{
	if(DIO_GetPinValue(PORTA,PIN2)==0)
	{
		Sensor_Readings_Tx[0]+=1;
	}
	if(DIO_GetPinValue(PORTA,PIN3)==0)
	{
		Sensor_Readings_Tx[1]+=1;
	}
	if(DIO_GetPinValue(PORTA,PIN4)==0)
	{
		Sensor_Readings_Tx[2]+=1;
	}
	if(DIO_GetPinValue(PORTA,PIN5)==0)
	{
		Sensor_Readings_Tx[3]+=1;
	}
	if(DIO_GetPinValue(PORTA,PIN6)==0)
	{
		Sensor_Readings_Tx[4]+=1;
	}
	if(DIO_GetPinValue(PORTA,PIN7)==0)
	{
		Sensor_Readings_Tx[5]+=1;
	}
}
