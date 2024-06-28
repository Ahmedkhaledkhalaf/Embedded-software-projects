/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Ahmed khaled khalaf
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

//Ahmed Khaled khalaf

#include "stdint.h"


#define RCC_BASE 		0x40021000
#define RCC_APB2ENR 	*(volatile uint32_t*)(RCC_BASE+0x18) //GPIOA enable bit 2

#define GPIOA_BASE 		0x40010800
#define GPIOA_CRH 		*(volatile uint32_t*)(GPIOA_BASE+0x04)
#define GPIOA_CRL  		*(volatile uint32_t*)(GPIOA_BASE+0x00)
#define GPIOA_ODR  		*(volatile uint32_t*)(GPIOA_BASE+0x0C)


int main(void)
{
	//initialize GPIOA
	RCC_APB2ENR |= (1<<2);
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x00200000;

	while(1)
	{
		GPIOA_ODR ^= (1<<13);
		for(int i =0; i<= 500; i++);
		GPIOA_ODR ^= (1<<13);
		for(int i =0; i<= 500; i++);
	}



}

