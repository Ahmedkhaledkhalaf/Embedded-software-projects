/**
 * @file alarm_actuator.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-06-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "alarm_actuator.h"

/**
 * @brief  initialize the alarm actuator
 * @note   none
 * @retval none
 */
 
STATE_define(Alarm_Act_Init)
{
    // Initialize The Alarm Actuator	
	// State define
    Alarm_Act_Status_t = Alarm_Act_Init;

    //State Action
    // Call The Alarm Actuator Driver Function to update the next state
    Alarm_Act_State = STATE(Alarm_Act_OFF);


}


STATE_define(Alarm_Act_Waiting)
{
    Alarm_Act_Status_t = Alarm_Act_Waiting;
}

/**
 * @brief  at this state the alarm actuator will be triggered for 60 sec
 * @note   none
 * @retval none
 */
 
STATE_define(Alarm_Act_ON)
{
     // State define
    Alarm_Act_Status_t = Alarm_Act_ON;

    //state action
    //write GPIO turn off the alarm
    Set_Alarm_actuator(FALSE);
    
    Alarm_Act_State = STATE(Alarm_Act_Waiting);
    

}


/**
 * @brief  the idle state of the alarm actuator is to be off
 * @note   none
 * @retval none
 */
 
STATE_define(Alarm_Act_OFF)
{
    // State define
    Alarm_Act_Status_t = Alarm_Act_OFF;

    //state action
    //write GPIO turn off the alarm
    Set_Alarm_actuator(TRUE);
    Alarm_Act_State = STATE(Alarm_Act_Waiting);

}

extern void AA_Start_Alarm(void)
{
	// Update State	
	Alarm_Act_State = STATE(Alarm_Act_ON) ;
}
 
extern void AA_Stop_Alarm(void)
{
	// Update State	
	Alarm_Act_State = STATE(Alarm_Act_OFF) ;
}