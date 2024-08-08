/*
 * NVIC_M4.c
 *
 *  Created on: Aug 9, 2024
 *      Author: xcite
 */

#include "../Inc/NVIC_M4.h"

void NVIC_Interrupt_Status_Write(uint32_t irq, Status_t status)
    {
    if (irq < 32) // For IRQ numbers 0 to 31
	{
	if (status == Enable)
	    {
	    NVIC_SET->ISER0 |= (1 << irq); // Set the corresponding bit in ISER0
	    }
	else
	    {
	    NVIC_CLEAR->ICER0 |= (1 << irq); // Clear the corresponding bit in ICER0
	    }
	}
    else if (irq < 64) // For IRQ numbers 32 to 63
	{
	if (status == Enable)
	    {
	    NVIC_SET->ISER1 |= (1 << (irq - 32)); // Set the corresponding bit in ISER1
	    }
	else
	    {
	    NVIC_CLEAR->ICER1 |= (1 << (irq - 32)); // Clear the corresponding bit in ICER1
	    }
	}
    else if (irq < 96) // For IRQ numbers 64 to 95
	{
	if (status == Enable)
	    {
	    NVIC_SET->ISER2 |= (1 << (irq - 64)); // Set the corresponding bit in ISER2
	    }
	else
	    {
	    NVIC_CLEAR->ICER2 |= (1 << (irq - 64)); // Clear the corresponding bit in ICER2
	    }
	}
    // If there are more than 96 IRQs
    }
