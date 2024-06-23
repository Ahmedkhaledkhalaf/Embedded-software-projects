/**
 * @file state.h
 * @author Ahmed khaled khalaf (khalafawy22899@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-06-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef _STATE_H_
#define _STATE_H_

//Standered data types file include
#include "STD_DataTypes.h"
#include "driver.h"

//Automatic State Functions declaration
#define STATE_define(_state_Func_) void ST_##_state_Func_()
#define STATE(_state_Func_) ST_##_state_Func_

#endif
