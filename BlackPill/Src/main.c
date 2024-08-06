/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Nader
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>

#define SCB_CPACR      (*(volatile unsigned int*)0xE000ED88U)

void FPU_Init(void) {
    // Set bits 20-23 (CP10 and CP11) to 0b11 to enable full access to the FPU
    SCB_CPACR |= (0xF << 20);
}



int main(void) {
    // Initialize the FPU
    FPU_Init();

    // The rest of your initialization code

    while (1) {
        // Main loop code
    }
}
