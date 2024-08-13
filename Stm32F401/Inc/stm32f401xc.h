/*
 * stm32f401xc.h
 *
 *  Created on: Aug 13, 2024
 *      Author: xcite
 */

#ifndef STM32F401XC_H_
#define STM32F401XC_H_

#include <stdint.h>

/**
 * @brief Macro to set specific bits in a register.
 * @param Reg: Register to modify.
 * @param bit: Bit position to start setting.
 * @param mask: Value to set in the specified bit position.
 */
#define Set(Reg, bit, mask)       ((Reg) |= ((mask) << (bit)))

/**
 * @brief Macro to clear specific bits in a register.
 * @param Reg: Register to modify.
 * @param bit: Bit position to start clearing.
 * @param mask: Value to clear in the specified bit position.
 */
#define Clear(Reg, bit, mask)     ((Reg) &= ~((mask) << (bit)))

/**
 * @brief Macro to toggle specific bits in a register.
 * @param Reg: Register to modify.
 * @param bit: Bit position to start toggling.
 * @param mask: Value to toggle in the specified bit position.
 */
#define Toggle(Reg, bit, mask)    ((Reg) ^= ((mask) << (bit)))

/**
 * @brief Macro to read a specific bit in a register.
 * @param Reg: Register to read.
 * @param bit: Bit position to read.
 * @return: Non-zero if the bit is set, zero otherwise.
 */
#define Read(Reg, bit)            (((Reg) & (1 << (bit))) != 0)

/**
 * @brief Structure for GPIO peripheral registers.
 */
typedef struct
{
    uint32_t volatile MODER;   /*!< GPIO port mode register */
    uint32_t volatile OTYPER;  /*!< GPIO port output type register */
    uint32_t volatile OSPEEDR; /*!< GPIO port output speed register */
    uint32_t volatile PUPDR;   /*!< GPIO port pull-up/pull-down register */
    uint32_t volatile IDR;     /*!< GPIO port input data register */
    uint32_t volatile ODR;     /*!< GPIO port output data register */
    uint32_t volatile BSRR;    /*!< GPIO port bit set/reset register */
    uint32_t volatile LCKR;    /*!< GPIO port configuration lock register */
    uint32_t volatile AFR[2];  /*!< GPIO alternate function registers */
} GPIO_TypeDef;

/**
 * @brief Base address for GPIOA peripheral.
 */
#define GPIOA ((GPIO_TypeDef *) (0x40020000))

/**
 * @brief Base address for GPIOB peripheral.
 */
#define GPIOB ((GPIO_TypeDef *) (0x40020400))

/**
 * @brief Base address for GPIOC peripheral.
 */
#define GPIOC ((GPIO_TypeDef *) (0x40020800))

/**
 * @brief Structure for RCC peripheral registers.
 */
typedef struct
{
    volatile uint32_t CR;           /*!< RCC clock control register */
    volatile uint32_t PLLCFGR;      /*!< RCC PLL configuration register */
    volatile uint32_t CFGR;         /*!< RCC clock configuration register */
    volatile uint32_t CIR;          /*!< RCC clock interrupt register */
    volatile uint32_t AHB1RSTR;     /*!< RCC AHB1 peripheral reset register */
    volatile uint32_t AHB2RSTR;     /*!< RCC AHB2 peripheral reset register */
    uint32_t RESERVED0[2];          /*!< Reserved */
    volatile uint32_t APB1RSTR;     /*!< RCC APB1 peripheral reset register */
    volatile uint32_t APB2RSTR;     /*!< RCC APB2 peripheral reset register */
    uint32_t RESERVED1[2];          /*!< Reserved */
    volatile uint32_t AHB1ENR;      /*!< RCC AHB1 peripheral clock enable register */
    volatile uint32_t AHB2ENR;      /*!< RCC AHB2 peripheral clock enable register */
    uint32_t RESERVED2[2];          /*!< Reserved */
    volatile uint32_t APB1ENR;      /*!< RCC APB1 peripheral clock enable register */
    volatile uint32_t APB2ENR;      /*!< RCC APB2 peripheral clock enable register */
    uint32_t RESERVED3[2];          /*!< Reserved */
    volatile uint32_t AHB1LPENR;    /*!< RCC AHB1 peripheral clock enable in low power mode register */
    volatile uint32_t AHB2LPENR;    /*!< RCC AHB2 peripheral clock enable in low power mode register */
    uint32_t RESERVED4[2];          /*!< Reserved */
    volatile uint32_t APB1LPENR;    /*!< RCC APB1 peripheral clock enable in low power mode register */
    volatile uint32_t APB2LPENR;    /*!< RCC APB2 peripheral clock enable in low power mode register */
    uint32_t RESERVED5[2];          /*!< Reserved */
    volatile uint32_t BDCR;         /*!< RCC Backup domain control register */
    volatile uint32_t CSR;          /*!< RCC clock control & status register */
    uint32_t RESERVED6[2];          /*!< Reserved */
    volatile uint32_t SSCGR;        /*!< RCC spread spectrum clock generation register */
    volatile uint32_t PLLI2SCFGR;   /*!< RCC PLLI2S configuration register */
    uint32_t RESERVED7;             /*!< Reserved */
    volatile uint32_t DCKCFGR;      /*!< RCC Dedicated Clocks Configuration Register */
} RCC_TypeDef;

/**
 * @brief Base address for RCC peripheral.
 */
#define RCC ((RCC_TypeDef *) (0x40023800))

/**
 * @brief Enable GPIOA clock.
 */
#define RCC_GPIOA_Enable()   (Set(RCC->AHB1ENR, 0, 1))

/**
 * @brief Enable GPIOB clock.
 */
#define RCC_GPIOB_Enable()   (Set(RCC->AHB1ENR, 1, 1))

/**
 * @brief Enable GPIOC clock.
 */
#define RCC_GPIOC_Enable()   (Set(RCC->AHB1ENR, 2, 1))

/**
 * @brief Disable GPIOA clock.
 */
#define RCC_GPIOA_Disable()  (Clear(RCC->AHB1ENR, 0, 1))

/**
 * @brief Disable GPIOB clock.
 */
#define RCC_GPIOB_Disable()  (Clear(RCC->AHB1ENR, 1, 1))

/**
 * @brief Disable GPIOC clock.
 */
#define RCC_GPIOC_Disable()  (Clear(RCC->AHB1ENR, 2, 1))

/**
 * @brief Reset GPIOA peripheral.
 */
#define RCC_GPIOA_Reset()    (Set(RCC->AHB1RSTR, 0, 1))

/**
 * @brief Reset GPIOB peripheral.
 */
#define RCC_GPIOB_Reset()    (Set(RCC->AHB1RSTR, 1, 1))

/**
 * @brief Reset GPIOC peripheral.
 */
#define RCC_GPIOC_Reset()    (Set(RCC->AHB1RSTR, 2, 1))

#endif /* STM32F401XC_H_ */
