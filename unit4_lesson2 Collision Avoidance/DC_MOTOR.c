/**
 * @file DC_MOTOR.c
 * @author ahmed khaled khalaf (khalafawy22899@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-06-21
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "DC_MOTOR.h"

unsigned int speed;

void DC_init()
{
    printf("\nDC_init\n");
}

void DC_motor(int s)
{
    speed = s;
    DC_state = STATE(DC_busy);

    printf("\nCA-> -> -> DC_motor()\n");

}

STATE_define(DC_idle)
{
    DC_state_id = DC_idle;
    DC_state = STATE(DC_idle);
    printf("\nDC_idle state : Speed = %d \n\n\n", speed);
}
STATE_define(DC_busy)
{
    DC_state_id = DC_busy;
    DC_state = STATE(DC_idle);
    printf("\nDC_busy state : Speed = %d \n\n\n", speed);
}
