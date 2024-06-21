/**
 * @file DC_MOTOR.h
 * @author ahmed khaled khalaf (khalafawy22899@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-06-21
 *
 * @copyright Copyright (c) 2024
 *
 */



#ifndef  DC_MOTOR_H_
#define  DC_MOTOR_H_
#include "state.h"

enum
{
    DC_idle,
    DC_busy
}DC_state_id;


void DC_init();

STATE_define(DC_idle);
STATE_define(DC_busy);

void DC_motor(int s);


void (*DC_state) ();
#endif
