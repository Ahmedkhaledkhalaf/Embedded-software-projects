#include <stdint.h>
#include <stdio.h>

#include "driver.h"
#include "Main_Block.h"

void Setup(void)
{
	GPIO_INITIALIZATION();
	MB_State = STATE(MB_Init);
	AM_State = STATE(AM_Init);
	Pressure_Sensor_State = STATE(PressureSensor_Init);
	Alarm_Act_State = STATE(Alarm_Act_Init);

}
void main ()
{
	Setup();
	while (1)
	{
		Pressure_Sensor_State();
		MB_State();
		AM_State();
		Alarm_Act_State();
	}

}
