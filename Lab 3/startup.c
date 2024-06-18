/**
 * @file startup.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-06-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "STD_DataTypes.h"

void Reset_Handler();
extern int main(void);

void Defult_Handler(void)
{
    Reset_Handler();
}

void NMI_Handler () __attribute__((weak, alias("Defult_Handler")));;
void H_fault_Handler () __attribute__((weak, alias("Defult_Handler")));;

//reserve stack size

static uint_t32 Stack_top[256]; //size = 256*4=1024bytes
//======================================================

void (* G_P_Fn_Vector[])() __attribute__((section (".vectors"))) = 
{
    (void (*)())   ((uint_t32)Stack_top + sizeof(Stack_top)),
    &Reset_Handler,
    &NMI_Handler,
    &H_fault_Handler
};

//===========================

extern uint_t32 _E_text ;
extern uint_t32 _S_DATA ;
extern uint_t32 _E_DATA ;
extern uint_t32 _S_bss  ;
extern uint_t32 _E_bss  ;


void Reset_Handler()
{
    /*copying the data from flash to RAM*/
    uint_t32 DATA_Size = (uint_t8 *) &_E_DATA - (uint_t8 *) &_S_DATA;
    uint_t8* P_SRC = (uint_t8*) &_E_text;
    uint_t8* P_dst = (uint_t8*) &_S_DATA;

    for (uint_t32 i = 0; i < DATA_Size; i++)
    {
        *((uint_t8*)P_dst++) = *((uint_t8*)P_SRC++);

    }

    // init .bss section in SRAM = 0

    uint_t32 bss_Size = (uint_t8 *)&_E_bss - (uint_t8 *)&_S_bss;
    P_dst = (uint_t8 *) &_S_bss;

        for (int i = 0; i < bss_Size; i++)
        {
            *((uint_t8 *)P_dst++) = (uint_t8) 0;
        }
        main();
    

}