/**
 * @file Colision_Avoidance.c
 * @author ahmed khaled khalaf (khalafawy22899@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-06-21
 *
 * @copyright Copyright (c) 2024
 *
 */


 #include "Colision_Avoidance.h"

unsigned int CA_Distance = 0;
unsigned int CA_Speed = 0;
unsigned int CA_threshold = 50;

void US_distance_set(int des){

	CA_Distance=des;
	(CA_Distance<=CA_threshold)? (CA_state=STATE(CA_waiting)):(CA_state=STATE(CA_driving));
	printf("US-----distance=%d------>CA\n",des);
}

STATE_define(CA_waiting)
{
    CA_state_id = CA_waiting;
    CA_Speed = 0;
    if (CA_Distance <= CA_threshold)
    {
        CA_state = STATE(CA_waiting);
    }
    else
    {
        CA_state = STATE(CA_driving);
    }
    DC_motor(CA_Speed);

}



STATE_define(CA_driving)
{
    CA_state_id = CA_driving;
    CA_Speed = 30;
    if (CA_Distance > CA_threshold)
    {
        CA_state = STATE(CA_driving);
    }
    else
    {
        CA_state = STATE(CA_waiting);
    }

DC_motor(CA_Speed);
}

