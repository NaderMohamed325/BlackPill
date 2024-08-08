/*
 * EXTI.h
 *
 *  Created on: Aug 9, 2024
 *      Author: xcite
 */

#ifndef EXTI_H_
#define EXTI_H_
#include "Memory_Utils.h"
#include "GPIO.h"
//to be modified
void (*EXTI_CallBack)[23]={NULL};
typedef enum
    {
    EXTI16 = 1,
    EXTI21,
    EXTI22,
    EXTI21,
    EXTI0 = 6,
    EXTI1,
    EXTI2,
    EXTI3,
    EXTI4,
    EXTI9_5 = 23,
    EXTI15_10 = 40,
    EXTI17,
    EXTI18
    } IRQ_t;
//	from 1 to 15 is OK
//    The five other EXTI lines are connected as follows:
//    • EXTI line 16 is connected to the PVD output
//    • EXTI line 17 is connected to the RTC Alarm event
//    • EXTI line 18 is connected to the USB OTG FS Wakeup event
//    • EXTI line 21 is connected to the RTC Tamper and TimeStamp events
//    • EXTI line 22 is connected to the RTC Wakeup event
typedef struct
    {
    GPIOX_TypeDef *Port;
    uint8_t Pin;
    uint8_t Trigger;
    void (*EXTI_Call_Back)(void);
    };







#endif /* EXTI_H_ */
