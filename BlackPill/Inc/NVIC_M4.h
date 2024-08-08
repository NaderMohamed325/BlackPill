/*
 * NVIC_M4.h
 *
 *  Created on: Aug 9, 2024
 *      Author: xcite
 */

#ifndef NVIC_M4_H_
#define NVIC_M4_H_

#include <stdint.h>
typedef volatile uint32_t vint;


typedef enum
    {
    Disable,
    Enable
    } Status_t;

typedef struct
    {
    vint ISER0;
    vint ISER1;
    vint ISER2;
    vint ISER3;
    } NVIC_Set_TypeDef;

#define NVIC_SET         ((NVIC_Set_TypeDef*)(0xE000E100))

typedef struct
    {
    vint ICER0;
    vint ICER1;
    vint ICER2;
    vint ICER3;
    } NVIC_Clear_TypeDef;

#define NVIC_CLEAR    	((NVIC_Clear_TypeDef*)(0XE000E180))

void NVIC_Interrupt_Status_Write(uint32_t irq,Status_t status);

#endif /* NVIC_M4_H_ */
