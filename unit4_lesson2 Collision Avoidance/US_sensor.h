/**
 * @file US_sensor.h
 * @author ahmed khaled khalaf (khalafawy22899@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-06-21
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef _US_SENSOR_H_
#define _US_SENSOR_H_

#include "state.h"

enum
{
    US_busy
}US_state_id;

//prototypes

void US_init();
STATE_define(US_busy);

//global pointer ro function
void (*US_state)();




#endif
