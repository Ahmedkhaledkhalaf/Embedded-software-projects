/**
 * @file US_sensor.c
 * @author ahmed khaled khalaf (khalafawy22899@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-06-21
 *
 * @copyright Copyright (c) 2024
 *
 */


#include "US_sensor.h"

extern void (*US_state)();

//Module Variable
unsigned int distance;

int generate_random(int l, int r, int count)
{
    int i;
    for ( i = 0; i < count; i++)
    {
        int rand_num = (rand() % (r-l+1)) +l;
        return rand_num;
    }

}

void US_init()
{
    //init US Sensor
    //call the US Driver or function

    printf("\nUS_init\n");
}

STATE_define(US_busy)

{
    US_state_id = US_busy;

    //generate random readings to memic the physical
    distance = generate_random(45,55,1);

    printf("US_busy state : distance = %d \n" , distance);

    US_distance_set(distance);
    US_state = STATE(US_busy);
}
