/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-06-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "STD_DataTypes.h"

#define SYSCTL_RCGC2_R                  *((vuint_t32*)(0x400FE108))
#define GPIO_PORTF_DIR_R                *((vuint_t32*)(0x40025400))
#define GPIO_PORTF_DEN_R                *((vuint_t32*)(0x4002551C))
#define GPIO_PORTF_DATA_R               *((vuint_t32*)(0x400253FC))

int main(void)
{
    vuint_t32 delay_count;
    //enable system control clock for GPIO 
    SYSCTL_RCGC2_R |= 0x00000020;
    for ( delay_count = 0; delay_count < 200; delay_count++)
    //Make the direction of pin 3 as output pin
    GPIO_PORTF_DIR_R |= (1<<3);
    //enable PORT F Data
    GPIO_PORTF_DEN_R |= (1<<3);
    

    while (1)
    {
        GPIO_PORTF_DATA_R |= (1<<3);
        for (delay_count = 0; delay_count < 20000; delay_count++);
        GPIO_PORTF_DATA_R &= ~(1<<3);
        for ( delay_count = 0; delay_count < 20000; delay_count++);


    }
    
    return 0;
    
}