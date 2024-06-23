/**
 * @file Pressure_sensor.c
 * @author Ahmed khaled khalaf (khalafawy22899@gmail.com)
 * @brief the source file of the pressure sensor driver contains the implementation and APIs
 * @version 0.1
 * @date 2024-06-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#include "Pressure_sensor.h"
static uint32_t Pressure_Value;

/**
 * @brief  The startup function which will initialize the pressure sensor
 * @note   none
 * @retval void
 */

 
STATE_define(PressureSensor_Init)
{
    //initialize the pressure sensor
    //state define
    Pressure_Sensor_Status_t = PressureSensor_Init;

    //action
    //check event and update status pointer by updating the pointer to the next state
    Pressure_Sensor_State = STATE(PressureSensor_Reading);
}

/**
 * @brief  At this function the Pressure sensor enter the state reading and shall store the reading at a variable
 * @param  Pressure_Value is a static float type which will contain the reading of the sensor
 * @note   the physical world has floating quantities more than integers 
 * @retval none
 */
 
STATE_define(PressureSensor_Reading)
{
    //state define
    Pressure_Sensor_Status_t = PressureSensor_Reading;


    //action
    Pressure_Value = getPressureVal();

    //action
    //enter the next state
    Pressure_Sensor_State = STATE(PressureSensor_Idle);

}

/**
 * @brief At this function the Pressure sensor shall wait and reurn to the reading state
 * @note   it's a delay function instead of the timer
 * @retval none
 */
 
STATE_define(PressureSensor_Idle)
{
    //state define
    Pressure_Sensor_Status_t = PressureSensor_Idle;

    //fire a delay
    Delay(1000);


    //check event and update status by updating the pointer to the next state
    Pressure_Sensor_State = STATE(PressureSensor_Reading); 
}

/**
 * @brief this function usage is to interface to the upper layer and send the read value of the sensor 
 * @note   none
 * @retval pressure sensor value
 */
 
uint32_t Pressure_Sensor_Value_Send(void)
{
    return Pressure_Value;
}
