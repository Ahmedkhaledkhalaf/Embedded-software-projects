/**
 * @file Colision_Avoidance.h
 * @author ahmed khaled khalaf (khalafawy22899@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-06-21
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef _COLISION_AVOIDANCE_H_
#define _COLISION_AVOIDANCE_H_

#include "state.h"

enum
{
    CA_waiting,
    CA_driving
}CA_state_id;

STATE_define(CA_waiting);
STATE_define(CA_driving);

void (*CA_state)();




#endif
