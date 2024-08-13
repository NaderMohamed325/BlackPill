/*
 * GPIO.c
 *
 *  Created on: Aug 13, 2024
 *      Author: xcite
 */

#include "../Inc/GPIO.h"

/**
 * @brief  Initializes a specific GPIO pin with the provided configuration.
 * @param  GPIOx: Pointer to the GPIO peripheral (GPIOA, GPIOB, etc.).
 * @param  Pin: Pointer to a Pin_t structure containing the pin configuration.
 * @return None
 */
void Mcal_Gpio_Init(GPIO_TypeDef *GPIOx, Pin_t *Pin)
    {
    // Clear the pin mode bits and set the new mode
    Clear(GPIOx->MODER, Pin->Pin_Number * 2, 0b11);
    Set(GPIOx->MODER, Pin->Pin_Number * 2, Pin->Functionality);

    //---------------------------------------------------------//

    // Configure output type: push-pull or open-drain
    if (Pin->Output_mode == Push_Pull)
	{
	Clear(GPIOx->OTYPER, Pin->Pin_Number, 1);
	}
    else if (Pin->Output_mode == Open_Drain)
	{
	Set(GPIOx->OTYPER, Pin->Pin_Number, 1);
	}

    //---------------------------------------------------------//

    // Set the pin speed
    Clear(GPIOx->OSPEEDR, Pin->Pin_Number * 2, 0b11);
    Set(GPIOx->OSPEEDR, Pin->Pin_Number * 2, Pin->Speed);

    //--------------------------------------------------------//

    // Configure the pull-up/pull-down resistors
    Clear(GPIOx->PUPDR, Pin->Pin_Number * 2, 0b11);
    Set(GPIOx->PUPDR, Pin->Pin_Number * 2, Pin->Pulling_State);

    //--------------------------------------------------------//

    // Configure alternate function if the pin is set as an alternate function
    if (Pin->Functionality == Alternative)
	{
	if (Pin->Pin_Number < PIN_8)
	    {
	    // Configure alternate function for pin numbers 0-7
	    Clear(GPIOx->AFR[0], Pin->Pin_Number * 4, 0b1111);
	    Set(GPIOx->AFR[0], Pin->Pin_Number * 4, Pin->Pin_Number);
	    }
	else if (Pin->Pin_Number <= PIN_15)
	    {
	    // Configure alternate function for pin numbers 8-15
	    Clear(GPIOx->AFR[1], Pin->Pin_Number * 4, 0b1111);
	    Set(GPIOx->AFR[1], Pin->Pin_Number * 4, Pin->Pin_Number);
	    }
	}
    }

/**
 * @brief  Deinitializes a GPIO port, resetting its configuration.
 * @param  GPIOx: Pointer to the GPIO peripheral to reset (GPIOA, GPIOB, etc.).
 * @return None
 */
void Mcal_Gpio_Deinit(GPIO_TypeDef *GPIOx)
    {
    // Reset the specified GPIO peripheral
    if (GPIOx == GPIOA)
	{
	RCC_GPIOA_Reset();
	}
    else if (GPIOx == GPIOB)
	{
	RCC_GPIOB_Reset();
	}
    else if (GPIOx == GPIOC)
	{
	RCC_GPIOC_Reset();
	}
    }

/**
 * @brief  Writes a logic level to a specific GPIO pin.
 * @param  GPIOx: Pointer to the GPIO peripheral.
 * @param  Pin_Number: Index of the pin to write to.
 * @param  Logic: Logic level to write (High or Low).
 * @return None
 */
void Mcal_Gpio_Write(GPIO_TypeDef *GPIOx, Pin_index_t Pin_Number,
	Pin_Logic_Status_t Logic)
    {
    // Set or clear the pin output level
    if (Logic == High)
	{
	Set(GPIOx->ODR, Pin_Number, 1);
	}
    else if (Logic == Low)
	{
	Clear(GPIOx->ODR, Pin_Number, 1);
	}
    }

/**
 * @brief  Reads the logic level from a specific GPIO pin.
 * @param  GPIOx: Pointer to the GPIO peripheral.
 * @param  Pin_Number: Index of the pin to read.
 * @return Logic level of the pin (0 or 1).
 */
uint8_t Mcal_Gpio_Read(GPIO_TypeDef *GPIOx, uint8_t Pin_Number)
    {
    // Return the current input data level of the pin
    return Read(GPIOx->IDR, Pin_Number);
    }

/**
 * @brief  Toggles the logic level of a specific GPIO pin.
 * @param  GPIOx: Pointer to the GPIO peripheral.
 * @param  Pin_Number: Index of the pin to toggle.
 * @return None
 */
void Mcal_Gpio_Toggel(GPIO_TypeDef *GPIOx, Pin_index_t Pin_Number)
    {
    // Toggle the output level of the pin
    Toggle(GPIOx->ODR, Pin_Number, 1);
    }
