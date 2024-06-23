/**
 * @file alarm_manager.c
 * @author Ahmed khaled khalaf (khalafawy22899@gmail.com)
 * @brief the source file of the alarm manager driver contains the implementation and APIs
 * @version 0.1
 * @date 2024-06-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#include "alarm_manager.h"
#include "alarm_actuator.h"
#include "Main_Block.h"


/**
 * @brief  initialize the alarm actuator
 * @note   none
 * @retval none
 */
STATE_define(AM_Init)
{
    //initialize the Alarm manager
    //state define
    AM_Status_t = AM_Init;

    //action
    AM_State = STATE(AM_Alarm_OFF);
}
/**
 * @brief  At this function the alarm manger shall wait and the alarm actuatutor remain off
 * @note   it is the idle state of the alarm manager 
 * @retval none
 */
 
STATE_define(AM_Alarm_OFF) 
{
    //define the state
    AM_Status_t = AM_Alarm_OFF;
    Delay(50000);
    //send alarm actuator stop signal
    AA_Stop_Alarm();
    
    //checking whether the high pressure detected or not
    if (HP_detected_signal() == TRUE)
    {
        //the high pressure signal is detected and update status by updating the pointer to the next state alarm on
       AM_State = STATE(AM_Alarm_ON); 
    }
    else
    {
        //the high pressure signal is not detected and update status by updating the pointer to the next state alarm off
        //remain at the state
        AM_State = STATE(AM_Alarm_OFF);
    }
    
    //sending alarm actuator off signal

}



/**
 * @brief  at this function the hogh pressure signal is detected and it will send a signal to trigger the alarm actuator
 * @note   none
 * @retval none
 */
 
STATE_define(AM_Alarm_ON) 
{
    //state define
    AM_Status_t = AM_Alarm_ON;

    //action
    //send alarm actuator start signal
    AA_Start_Alarm();

    AM_State = STATE(AM_Alarm_OFF);
    

}