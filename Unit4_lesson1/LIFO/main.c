/**
 * @file main.c
 * @author ahmed khaled khalaf(khalafawy22899@gmail.com)
 * @brief this is a lifo project 
 * @version 0.1
 * @date 2024-06-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#include <stdio.h>
#include "stdint.h"
#include "stdlib.h"

#define MY_Lifo_buff_length 100

typedef enum 
{
    LIFO_No_Error,
    LIFO_Full,
    LIFO_not_Full, //not full and not empty both expressions have the same meaning that the lifo buffer contains data and it's not full 
    LIFO_Empty,
    LIFO_NULL
}buffer_status;


typedef struct 
{
    uint32_t length;
    uint8_t* base;
    uint8_t* head;
    uint32_t count; 
}LIFO_BUFFER_t;


buffer_status LIFO_ADD_Item(LIFO_BUFFER_t* Ptr_BUFF, uint8_t item);
buffer_status LIFO_POP_Item(LIFO_BUFFER_t* Ptr_BUFF, uint8_t* item);
buffer_status Is_LIFO_Full(LIFO_BUFFER_t* Ptr_BUFF);


int main()
{
    //using dynamic alocation
    LIFO_BUFFER_t My_Buffer;
    My_Buffer.base = (uint8_t *) malloc(MY_Lifo_buff_length);
    if(My_Buffer.base == NULL)
    {
        printf("\nError alocating memory\n");
    }
    else 
    {
        printf("\nalocating memory succedded\n");
            My_Buffer.head = My_Buffer.base;
            My_Buffer.count = 0;
            My_Buffer.length = MY_Lifo_buff_length;

            //push items automatically
            for (uint32_t i = 0; i < MY_Lifo_buff_length; i++)
            {
                printf("\t%d", i);
                LIFO_ADD_Item(&My_Buffer, i);
            }
            printf("\n\n\n\n\n\n\n");

            //pop items automatically
            for (uint32_t i = 0; i < MY_Lifo_buff_length; i++)
            {
                uint8_t temp;
                
                LIFO_POP_Item(&My_Buffer, &temp);
                printf("\t%d", temp);
            }
            
    }
    


return 0;
}


buffer_status LIFO_ADD_Item(LIFO_BUFFER_t* Ptr_BUFF, uint8_t item)
{
    //checking whether the pointer are setted to a valid memory section
     if (!Ptr_BUFF || !Ptr_BUFF->base || !Ptr_BUFF->head)
    {
        return LIFO_NULL;
    }
    else
    {
        if (Ptr_BUFF->head >= (Ptr_BUFF->base + Ptr_BUFF->length))
        {
            return LIFO_Full;
        }
        else
        {
            *(Ptr_BUFF->head) = item;
            Ptr_BUFF->head++;
            Ptr_BUFF->count++;
            return LIFO_No_Error;
        }
        
    }
}
buffer_status LIFO_POP_Item(LIFO_BUFFER_t* Ptr_BUFF, uint8_t* item)
{
        //checking whether the pointer are setted to a valid memory section

     if (!Ptr_BUFF || !Ptr_BUFF->base || !Ptr_BUFF->head)
    {
        return LIFO_NULL;
    }
    else
    {
        if (Ptr_BUFF->head == Ptr_BUFF->base)
        {
            return LIFO_Empty;
        }
        else
        {
            Ptr_BUFF->head --;
            *item = *(Ptr_BUFF->head);
            Ptr_BUFF->count--;
            return LIFO_No_Error;
        }
        
    }
}
buffer_status Is_LIFO_Full(LIFO_BUFFER_t* Ptr_BUFF)
{
    //checking whether the pointer are setted to a valid memory section

    if (!Ptr_BUFF || !Ptr_BUFF->base || !Ptr_BUFF->head)
    {
        return LIFO_NULL;
    }
    else
    {
        if (Ptr_BUFF->head >= (Ptr_BUFF->base + Ptr_BUFF->length))
        {
            return LIFO_Full;
        }
        else
        {
            return LIFO_not_Full;
        }
        
    }
    
}