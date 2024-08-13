/*
 * GPIO.h
 *
 *  Created on: Aug 13, 2024
 *      Author: xcite
 */

#ifndef GPIO_H_
#define GPIO_H_
#include "stm32f401xc.h"

/*
 Bits 2y:2y+1 MODERy[1:0]: Port x configuration bits (y = 0..15)
 These bits are written by software to configure the I/O direction mode.
 00: Input (reset state)
 01: General purpose output mode
 10: Alternate function mode
 11: Analog mode
 */
typedef enum
    {
    Input,
    Output,
    Alternative,
    Analog
    } Pin_Config_t;

/*
 * Bits 15:0 OTy: Port x configuration bits (y = 0..15)
 These bits are written by software to configure the output type of the I/O port.
 0: Output push-pull (reset state)
 1: Output open-drain
 */
typedef enum
    {
    Push_Pull,
    Open_Drain
    } Pin_Output_mode_t;

/*
 * Bits 2y:2y+1 OSPEEDRy[1:0]: Port x configuration bits (y = 0..15)
 These bits are written by software to configure the I/O output speed.
 00: Low speed
 01: Medium speed
 10: High speed
 11: Very high speed
 Note: Refer to the product datasheets for the values of OSPEEDRy bits versus VDD
 range and external load.
 */
typedef enum
    {
    Low_Speed,
    Medium_Speed,
    High_Speed,
    Very_High_Speed
    } Pin_Logic_Speed_t;
/*
 * Bits 2y:2y+1 PUPDRy[1:0]: Port x configuration bits (y = 0..15)
 These bits are written by software to configure the I/O pull-up or pull-down
 00: No pull-up, pull-down
 01: Pull-up
 10: Pull-down
 11: Reserved
 */

typedef enum
    {
    No_Pulling,
    Pull_Up,
    Pull_Down
    } Pin_Pulling_t;

/*
 * Bits 15:0 ODRy: Port output data (y = 0..15)
 These bits can be read and written by software.
 Note: For atomic bit set/reset, the ODR bits can be individually set and reset by writing to the
 GPIOx_BSRR register (x = A..E and H).
 */

typedef enum
    {
    Low,
    High
    } Pin_Logic_Status_t;
/*
 * AFRy: Alternate function selection for port x bit y (y = 0..7)
 These bits are written by software to configure alternate function I/Os
 AFRLy selection:
 0000: AF0
 0001: AF1
 0010: AF2
 0011: AF3
 0100: AF4
 0101: AF5
 0110: AF6
 0111: AF7
 1000: AF8
 1001: AF9
 1010: AF10
 1011: AF11
 1100: AF12
 1101: AF13
 1110: AF14
 1111: AF15
 */
typedef enum
    {
    AF0 = 0, /*!< Alternate Function 0 */
    AF1, /*!< Alternate Function 1 */
    AF2, /*!< Alternate Function 2 */
    AF3, /*!< Alternate Function 3 */
    AF4, /*!< Alternate Function 4 */
    AF5, /*!< Alternate Function 5 */
    AF6, /*!< Alternate Function 6 */
    AF7, /*!< Alternate Function 7 */
    AF8, /*!< Alternate Function 8 */
    AF9, /*!< Alternate Function 9 */
    AF10, /*!< Alternate Function 10 */
    AF11, /*!< Alternate Function 11 */
    AF12, /*!< Alternate Function 12 */
    AF13, /*!< Alternate Function 13 */
    AF14, /*!< Alternate Function 14 */
    AF15 /*!< Alternate Function 15 */
    } Pin_Alternatives_t;
#endif /* GPIO_H_ */
