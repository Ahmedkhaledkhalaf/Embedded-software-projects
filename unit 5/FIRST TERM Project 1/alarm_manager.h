/**
 * @file alarm_manager.h
 * @author Ahmed khaled khalaf (khalafawy22899@gmail.com)
 * @brief  This file contains all the prototypes and macros needed to Alarm Manager driver implementation
 * @version 0.1
 * @date 2024-06-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#ifndef ALARM_MANAGER_H_
#define ALARM_MANAGER_H_

#include "state.h"
#include "alarm_actuator.h"


// Define Status
enum {
    AM_Init,
	AM_Alarm_OFF,
	AM_Alarm_ON
}AM_Status_t;



// Declare State Function
STATE_define(AM_Init);
STATE_define(AM_Alarm_OFF) ;
STATE_define(AM_Alarm_ON) ;


// State Pointer to Function
void (*AM_State)() ;



#endif 