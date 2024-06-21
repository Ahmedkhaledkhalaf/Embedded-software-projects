/**
 * @file main.c
 * @author ahmed khaled khalaf (khalafawy22899@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-06-21
 *
 * @copyright Copyright (c) 2024
 *
 */


#include "US_sensor.h"
#include "DC_MOTOR.h"
#include "Colision_Avoidance.h"

void setup ()
{

    US_init();
	DC_init();

	CA_state = STATE(CA_waiting);
	US_state = STATE(US_busy);
	DC_state = STATE(DC_idle);
}



void main()
{
    setup();

    while (1)
    {
        US_state();
		CA_state();
		DC_state();
		for(int i=0;i<190000000;i++);
    }

}
