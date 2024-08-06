/*
 * GPIO.c
 *
 *  Created on: Aug 6, 2024
 *      Author: xcite
 */

#include "../Inc/GPIO.h"

/**
 * @brief Initialize GPIO pin according to the specified configuration.
 *
 * This function sets up the GPIO pin by configuring its functionality, speed, and pull-up/pull-down resistors.
 *
 * @param Pin Pointer to a Pin_Config_t structure containing the configuration settings for the GPIO pin.
 *
 * @ref Pin_Config_t
 */
void Mcal_Gpio_Init(Pin_Config_t *Pin)
{
    if (!Pin)
    {
        return; // Return if the Pin pointer is null
    }

    // Initialize pin functionality, speed, and pull-up/pull-down status
    MCAL_GPIO_Functionality_init(Pin);
    Mcal_GPIO_Speed_Set(Pin);
    Mcal_GPIO_Pull_Status(Pin);
}

/**
 * @brief Initialize GPIO pin functionality.
 *
 * Configures the GPIO pin mode (input, output, alternate function, or analog) and output type (push-pull or open-drain).
 *
 * @param Pin Pointer to a Pin_Config_t structure containing the configuration settings for the GPIO pin.
 *
 * @ref Pin_Config_t
 */
void MCAL_GPIO_Functionality_init(Pin_Config_t *Pin)
{
    // Reset pin mode bits
    ((Pin->Port_index)->MODER) &= ~((0b11) << (Pin->Pin_Number * 2));

    // Set pin mode
    ((Pin->Port_index)->MODER) |= ((Pin->Functionality) << (Pin->Pin_Number * 2));

    // Configure output type (if applicable)
    if (Pin->Functionality == GPO) // Only configure output type if functionality is General Purpose Output
    {
        if (Pin->Output_Cfg)
        {
            (Pin->Port_index)->OTYPER |= (Pin->Output_Cfg << Pin->Pin_Number); // Set output type
        }
        else
        {
            (Pin->Port_index)->OTYPER &= ~(Pin->Output_Cfg << Pin->Pin_Number); // Reset output type
        }
    }
}

/**
 * @brief Set GPIO pin speed.
 *
 * Configures the speed of the GPIO pin (low, medium, high, or very high).
 *
 * @param Pin Pointer to a Pin_Config_t structure containing the speed setting for the GPIO pin.
 *
 * @ref Pin_Config_t
 */
void Mcal_GPIO_Speed_Set(Pin_Config_t *Pin)
{
    // Reset speed bits
    (Pin->Port_index)->OSPEEDR &= ~(0b11 << (Pin->Pin_Number * 2));

    // Set pin speed
    (Pin->Port_index)->OSPEEDR |= (Pin->Logic_Speed << (Pin->Pin_Number * 2));
}

/**
 * @brief Configure GPIO pin pull-up/pull-down status.
 *
 * Sets the pull-up or pull-down resistors for the GPIO pin.
 *
 * @param Pin Pointer to a Pin_Config_t structure containing the pull-up/pull-down settings for the GPIO pin.
 *
 * @ref Pin_Config_t
 */
void Mcal_GPIO_Pull_Status(Pin_Config_t *Pin)
{
    // Reset pull-up/pull-down bits
    (Pin->Port_index)->PUPDR &= ~(0b11 << (Pin->Pin_Number * 2));

    // Set pull-up/pull-down configuration
    (Pin->Port_index)->PUPDR |= (Pin->Pull_Mode << (Pin->Pin_Number * 2));
}

/**
 * @brief Write logic level to a GPIO pin.
 *
 * Sets or clears the specified GPIO pin based on the logic level.
 *
 * @param GPIOx Pointer to the GPIO port register structure.
 * @param Pin_Num The pin number (0 to 15).
 * @param Logic The logic level to set (High or Low).
 */
void Mcal_GPIO_Logic_Write(GPIOX_TypeDef *GPIOx, uint8_t Pin_Num, uint32_t Logic)
{
    if (Logic)
    {
        GPIOx->ODR |= (1 << Pin_Num); // Set the pin high
    }
    else
    {
        GPIOx->ODR &= ~(1 << Pin_Num); // Set the pin low
    }
}

/**
 * @brief Read logic level from a GPIO pin.
 *
 * Reads the current logic level of the specified GPIO pin.
 *
 * @param GPIOx Pointer to the GPIO port register structure.
 * @param Pin_Num The pin number (0 to 15).
 *
 * @return The current logic level of the pin (High or Low).
 */
uint8_t Mcal_GPIO_Logic_Read(GPIOX_TypeDef *GPIOx, uint8_t Pin_Num)
{
    return (GPIOx->IDR & (1 << Pin_Num)) ? HIGH : LOW; // Return High if the pin is set, otherwise Low
}
