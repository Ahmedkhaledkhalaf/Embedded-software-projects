/**
 * @file Main_Block.c
 * @author Ahmed khaled khalaf (khalafawy22899@gmail.com)
 * @brief the source file of the Main Block driver contains the implementation and APIs
 * @version 0.1
 * @date 2024-06-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "Main_Block.h"

//define a variable to recive the current pressure value
static uint32_t CP_Value;
static uint8_t P_Threshold = 20;






/**
 * @brief  initialize the Main block
 * @note   none
 * @retval none
 */
 
STATE_define(MB_Init)
{
    //state define
    //initialize the Main Block
    MB_Status_t = MB_Init;

    //state action
    MB_State = STATE(MB_Reciving_Values);

}

/**
 * @brief  Reciving values form the Pressure sensor
 * @note   none
 * @retval none
 */
 
STATE_define(MB_Reciving_Values)
{
    //state define
    MB_Status_t = MB_Reciving_Values;

    //recive the current pressure value
    CP_Value = Pressure_Sensor_Value_Send();

    //check if the pressure value high or low
    if (CP_Value >= P_Threshold )
    {
        MB_State = STATE(MB_HP_detected);
        
    }
    MB_State = STATE(MB_Reciving_Values);
    
}

/**
 * @brief  the main block detected a high pressure signal so it will send a signal to the alarm manager 
 *         to tigger the alarm actuator for 60 sec
 * @note   none
 * @retval none
 */
 
STATE_define(MB_HP_detected)
{
    //define state
    MB_Status_t = MB_HP_detected;

    //Actiorn
   
    HP_detected_signal();
    
    MB_State = STATE(MB_Reciving_Values);

}

/**
 * @brief  sending a signal to the alarm manger
 * @note   none
 * @retval True
 */
 
uint8_t HP_detected_signal(void)
{
    
    
    return (CP_Value > P_Threshold);
    
    
}