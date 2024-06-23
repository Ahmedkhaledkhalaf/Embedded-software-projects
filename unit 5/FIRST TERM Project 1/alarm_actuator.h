/**
 * @file alarm_actuator.h
 * @author Ahmed khaled khalaf (khalafawy22899@gmail.com)
 * @brief  This file contains all the prototypes and macros needed to Alarm actuator driver implementation
 * @version 0.1
 * @date 2024-06-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#ifndef _ALARM_ACTUATOR_H
#define _ALARM_ACTUATOR_H

#include "state.h"

// Define Status
enum {
		Alarm_Act_Init,
		Alarm_Act_Waiting,
		Alarm_Act_ON,
		Alarm_Act_OFF
  }Alarm_Act_Status_t ;


// Declare State Fuctions 
STATE_define(Alarm_Act_Init);
STATE_define(Alarm_Act_ON);
STATE_define(Alarm_Act_OFF);
STATE_define(Alarm_Act_Waiting);
//functions to recive the signal of the alarm actuator
extern void AA_Start_Alarm(void);
extern void AA_Stop_Alarm(void);
// State Pointer to Function
void (*Alarm_Act_State)() ;

#endif