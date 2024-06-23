/**
 * @file Main_Block.h
 * @author Ahmed khaled khalaf (khalafawy22899@gmail.com)
 * @brief  This file contains all the prototypes and macros needed to Main Block driver implementation
 * @version 0.1
 * @date 2024-06-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#ifndef _MAIN_BLOCK_H_
#define _MAIN_BLOCK_H_
#include "state.h"
#include "alarm_manager.h"
#include "Pressure_sensor.h"

//define states of the man block
enum
{
    MB_Init,
    MB_Reciving_Values,
    MB_HP_detected
}MB_Status_t;

// Declare State Function
STATE_define(MB_Init);
STATE_define(MB_Reciving_Values);
STATE_define(MB_HP_detected);
uint8_t HP_detected_signal(void);
// State Pointer to Function
void (* MB_State)() ;

#endif