/**
 * @file Pressure_sensor.h
 * @author Ahmed khaled khalaf (khalafawy22899@gmail.com)
 * @brief This file contains all the prototypes and macros needed to Pressure sensor driver implementation
 * @version 0.1
 * @date 2024-06-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#ifndef  _PRESSURE_SENSOR_H_
#define  _PRESSURE_SENSOR_H_


#include "state.h"


//the Pressure sensor state
enum{
	 
	 PressureSensor_Init,
	 PressureSensor_Reading,
	 PressureSensor_Idle
}Pressure_Sensor_Status_t;

//prototypes of the pressure sensor states function
STATE_define(PressureSensor_Init);
STATE_define(PressureSensor_Reading);
STATE_define(PressureSensor_Idle);
uint32_t Pressure_Sensor_Value_Send(void);

//Pressure Sensor Module Pointer to state functions
void (*Pressure_Sensor_State) ();



#endif