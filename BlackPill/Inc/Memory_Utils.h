/*
 * Memory_Utils.h
 *
 *  Created on: Aug 6, 2024
 *      Author: xcite
 */

#ifndef MEMORY_UTILS_H_
#define MEMORY_UTILS_H_

#include <stdint.h>

/**
 * @brief Defines a volatile 32-bit integer type.
 */
typedef volatile uint32_t vint;

/******************************* GPIOX_Section ********************************/

/**
 * @brief GPIO Port Register Structure
 *
 * This structure defines the layout of the GPIO peripheral registers.
 */
typedef struct
{
    vint MODER;   /**< GPIO port mode register. */
    vint OTYPER;  /**< GPIO port output type register. */
    vint OSPEEDR; /**< GPIO port output speed register. */
    vint PUPDR;   /**< GPIO port pull-up/pull-down register. */
    vint IDR;     /**< GPIO port input data register. */
    vint ODR;     /**< GPIO port output data register. */
    vint BSRR;    /**< GPIO port bit set/reset register. */
    vint LCKR;    /**< GPIO port configuration lock register. */
    vint AFRL;    /**< GPIO alternate function low register. */
    vint AFRH;    /**< GPIO alternate function high register. */
} GPIOX_TypeDef;

// Base addresses for GPIO ports
#define GPIOA_BASE (0x40020000) /**< Base address for GPIOA. */
#define GPIOB_BASE (0x40020400) /**< Base address for GPIOB. */
#define GPIOC_BASE (0x40020800) /**< Base address for GPIOC. */

// Macros to access GPIO ports
#define GPIOA ((GPIOX_TypeDef *) GPIOA_BASE) /**< Pointer to GPIOA registers. */
#define GPIOB ((GPIOX_TypeDef *) GPIOB_BASE) /**< Pointer to GPIOB registers. */
#define GPIOC ((GPIOX_TypeDef *) GPIOC_BASE) /**< Pointer to GPIOC registers. */

/******************************* RCC_Section ********************************/

/**
 * @brief RCC (Reset and Clock Control) Register Structure
 *
 * This structure defines the layout of the RCC peripheral registers.
 */
typedef struct
{
    vint CR;                /**< RCC clock control register. */
    vint PLLCFGR;           /**< RCC PLL configuration register. */
    vint CFGR;              /**< RCC clock configuration register. */
    vint CIR;               /**< RCC clock interrupt register. */
    vint AHB1RSTR;          /**< RCC AHB1 peripheral reset register. */
    vint AHB2RSTR;          /**< RCC AHB2 peripheral reset register. */
    vint Reserved0[2];      /**< Reserved. */
    vint APB1RSTR;          /**< RCC APB1 peripheral reset register. */
    vint APB2RSTR;          /**< RCC APB2 peripheral reset register. */
    vint Reserved1[2];      /**< Reserved. */
    vint AHB1ENR;           /**< RCC AHB1 peripheral clock enable register. */
    vint AHB2ENR;           /**< RCC AHB2 peripheral clock enable register. */
    vint Reserved2[2];      /**< Reserved. */
    vint APB1ENR;           /**< RCC APB1 peripheral clock enable register. */
    vint APB2ENR;           /**< RCC APB2 peripheral clock enable register. */
    vint Reserved3[2];      /**< Reserved. */
    vint AHB1LPENR;         /**< RCC AHB1 peripheral clock enable in low power mode register. */
    vint AHB2LPENR;         /**< RCC AHB2 peripheral clock enable in low power mode register. */
    vint Reserved4[2];      /**< Reserved. */
    vint RCC_APB1LPENR;     /**< RCC APB1 peripheral clock enable in low power mode register. */
    vint RCC_APB2LPENR;     /**< RCC APB2 peripheral clock enable in low power mode register. */
    vint Reserved5[2];      /**< Reserved. */
    vint BDCR;              /**< RCC Backup Domain Control Register. */
    vint CSR;               /**< RCC Clock Source Recovery Register. */
    vint Reserved6[2];      /**< Reserved. */
    vint SSCGR;             /**< RCC Spread Spectrum Clock Generator Register. */
    vint PLLI2SCFGR;        /**< RCC PLLI2S Configuration Register. */
    vint Reserved;          /**< Reserved. */
    vint DCKCFGR;           /**< RCC Dedicated Clock Configuration Register. */
} RCC_TypeDef;

#define RCC_BASE (0x40023800) /**< Base address for RCC. */
#define RCC ((RCC_TypeDef *)(RCC_BASE)) /**< Pointer to RCC registers. */

/**
 * @brief Macros to enable GPIO clocks.
 */
#define RCC_GPIOA_Enable()  (RCC->AHB1ENR |= (1 << 0)) /**< Enable clock for GPIOA. */
#define RCC_GPIOB_Enable()  (RCC->AHB1ENR |= (1 << 1)) /**< Enable clock for GPIOB. */
#define RCC_GPIOC_Enable()  (RCC->AHB1ENR |= (1 << 2)) /**< Enable clock for GPIOC. */

/**
 * @brief Macros to reset GPIO peripherals.
 */
#define RCC_GPIOA_Reset()   (RCC->AHB1RSTR |= (1 << 0); RCC->AHB1RSTR &= ~(1 << 0)) /**< Reset GPIOA. */
#define RCC_GPIOB_Reset()   (RCC->AHB1RSTR |= (1 << 1); RCC->AHB1RSTR &= ~(1 << 1)) /**< Reset GPIOB. */
#define RCC_GPIOC_Reset()   (RCC->AHB1RSTR |= (1 << 2); RCC->AHB1RSTR &= ~(1 << 2)) /**< Reset GPIOC. */

/**
 * @brief Macros to disable GPIO clocks.
 */
#define RCC_GPIOA_Disable() (RCC->AHB1ENR &= ~(1 << 0)) /**< Disable clock for GPIOA. */
#define RCC_GPIOB_Disable() (RCC->AHB1ENR &= ~(1 << 1)) /**< Disable clock for GPIOB. */
#define RCC_GPIOC_Disable() (RCC->AHB1ENR &= ~(1 << 2)) /**< Disable clock for GPIOC. */

#endif /* MEMORY_UTILS_H_ */
