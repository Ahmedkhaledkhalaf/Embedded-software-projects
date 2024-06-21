/**
 * @file state.h
 * @author ahmed khaled khalaf (khalafawy22899@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-06-21
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef _STATE_H_
#define _STATE_H_

#define STATE_define(_state_Func_) void ST_##_state_Func_()
#define STATE(_state_Func_)  ST_##_state_Func_

#include <stdio.h>
#include <stdlib.h>

void US_distance_set(int dis);
void DC_motor(int speed);

#endif
