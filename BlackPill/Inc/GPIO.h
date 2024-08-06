/*
 * GPIO.h
 *
 *  Created on: Aug 6, 2024
 *      Author: xcite
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "Memory_Utils.h"

/**
 * @brief GPIO Configuration Structure
 *
 * This structure holds the configuration settings for a GPIO pin.
 *
 * @param Port_index Pointer to the GPIO port register structure.
 * @param Pin_Number The pin number within the GPIO port (0 to 15).
 * @param Logic_Speed The speed of the GPIO pin (Low, Medium, High, Very High).
 * @param Functionality The mode of the GPIO pin (Input, Output, Alternate Function, Analog).
 * @param Output_Cfg The output type (Push-Pull or Open-Drain).
 * @param Pull_Mode The pull-up/pull-down configuration (No Pull, Pull-Up, Pull-Down).
 */
typedef struct
{
    GPIOX_TypeDef *Port_index; /**< Pointer to the GPIO port register structure. */
    uint8_t Pin_Number; /**< The pin number (0 to 15). */
    uint8_t Logic_Speed; /**< Speed of the GPIO pin (Low, Medium, High, Very High). */
    uint8_t Functionality; /**< Mode of the GPIO pin (Input, Output, Alternate Function, Analog). */
    uint8_t Output_Cfg; /**< Output type (Push-Pull or Open-Drain). */
    uint8_t Pull_Mode; /**< Pull-up/Pull-down configuration (No Pull, Pull-Up, Pull-Down). */
} Pin_Config_t;

/**
 * @brief GPIO Pin Modes
 *
 * These are the possible modes for GPIO pins.
 */
#define INPUT       (uint32_t)0   /**< Input floating mode. */
#define GPO         (uint32_t)1   /**< General Purpose Output mode. */
#define AF          (uint32_t)2   /**< Alternate Function mode. */
#define ANALOG      (uint32_t)3   /**< Analog mode. */

/**
 * @brief GPIO Output Types
 *
 * These define the output configuration for GPIO pins.
 */
#define OUTPUT_PP   (uint32_t)0   /**< Output Push-Pull configuration. */
#define OUTPUT_OD   (uint32_t)1   /**< Output Open-Drain configuration. */

/**
 * @brief GPIO Pin Speeds
 *
 * These define the speed settings for GPIO pins.
 */
#define LOW_SPEED       (uint32_t)0  /**< Low speed. */
#define MEDIUM_SPEED    (uint32_t)1  /**< Medium speed. */
#define HIGH_SPEED      (uint32_t)2  /**< High speed. */
#define VERY_HIGH_SPEED (uint32_t)3  /**< Very high speed. */

/**
 * @brief GPIO Pull-up/Pull-down Modes
 *
 * These define the pull-up/pull-down configurations for GPIO pins.
 */
#define NO_PU_PD       (uint32_t)0  /**< No pull-up/pull-down. */
#define PU             (uint32_t)1  /**< Pull-up configuration. */
#define PD             (uint32_t)2  /**< Pull-down configuration. */

/**
 * @brief GPIO Output Levels
 *
 * These define the output levels for GPIO pins.
 */
#define HIGH (uint32_t)1  /**< High level. */
#define LOW  (uint32_t)0  /**< Low level. */

/**
 * @brief Initialize GPIO Pin
 *
 * Configures the GPIO pin according to the settings provided in the Pin_Config_t structure.
 *
 * @param Pin Pointer to the Pin_Config_t structure containing pin configuration settings.
 *
 * @ref Pin_Config_t
 */
void Mcal_Gpio_Init(Pin_Config_t *Pin);

/**
 * @brief Initialize GPIO Functionality
 *
 * Sets up the GPIO pin functionality according to the configuration specified in the Pin_Config_t structure.
 *
 * @param Pin Pointer to the Pin_Config_t structure containing pin functionality settings.
 *
 * @ref Pin_Config_t
 */
void MCAL_GPIO_Functionality_init(Pin_Config_t *Pin);

/**
 * @brief Set GPIO Pin Speed
 *
 * Configures the speed setting for the GPIO pin based on the Logic_Speed value in the Pin_Config_t structure.
 *
 * @param Pin Pointer to the Pin_Config_t structure containing pin speed settings.
 *
 * @ref Pin_Config_t
 */
void Mcal_GPIO_Speed_Set(Pin_Config_t *Pin);

/**
 * @brief Configure GPIO Pull-up/Pull-down Status
 *
 * Configures the pull-up or pull-down resistors for the GPIO pin based on the Pull_Mode value in the Pin_Config_t structure.
 *
 * @param Pin Pointer to the Pin_Config_t structure containing pull-up/pull-down settings.
 *
 * @ref Pin_Config_t
 */
void Mcal_GPIO_Pull_Status(Pin_Config_t *Pin);

/**
 * @brief Write Logic Level to GPIO Pin
 *
 * Sets or clears the specified GPIO pin based on the logic level.
 *
 * @param GPIOx Pointer to the GPIO port register structure.
 * @param Pin_Num The pin number (0 to 15).
 * @param Logic The logic level to set (High or Low).
 */
void Mcal_GPIO_Logic_Write(GPIOX_TypeDef *GPIOx, uint8_t Pin_Num, uint32_t Logic);

/**
 * @brief Read Logic Level from GPIO Pin
 *
 * Reads the current logic level of the specified GPIO pin.
 *
 * @param GPIOx Pointer to the GPIO port register structure.
 * @param Pin_Num The pin number (0 to 15).
 *
 * @return The current logic level of the pin (High or Low).
 */
uint8_t Mcal_GPIO_Logic_Read(GPIOX_TypeDef *GPIOx, uint8_t Pin_Num);

#endif /* GPIO_H_ */
