#ifndef GPIO_H_
#define GPIO_H_

#include "stm32f401xc.h"

/**
 * @brief Enumeration for GPIO pin configuration modes.
 * This enum defines the possible modes for GPIO pins.
 */
typedef enum
{
    Input = 0, /*!< Input mode (reset state) */
    Output, /*!< General purpose output mode */
    Alternative, /*!< Alternate function mode */
    Analog /*!< Analog mode */
} Pin_Config_t;

/**
 * @brief Enumeration for GPIO output types.
 * This enum defines the possible output types for GPIO pins.
 */
typedef enum
{
    Push_Pull = 0, /*!< Output push-pull (reset state) */
    Open_Drain /*!< Output open-drain */
} Pin_Output_mode_t;

/**
 * @brief Enumeration for GPIO output speeds.
 * This enum defines the possible output speeds for GPIO pins.
 */
typedef enum
{
    Low_Speed = 0, /*!< Low speed */
    Medium_Speed, /*!< Medium speed */
    High_Speed, /*!< High speed */
    Very_High_Speed /*!< Very high speed */
} Pin_Logic_Speed_t;

/**
 * @brief Enumeration for GPIO pull-up/pull-down configurations.
 * This enum defines the possible pull-up or pull-down configurations for GPIO pins.
 */
typedef enum
{
    No_Pulling = 0, /*!< No pull-up or pull-down */
    Pull_Up, /*!< Pull-up */
    Pull_Down /*!< Pull-down */
} Pin_Pulling_t;

/**
 * @brief Enumeration for GPIO pin logic status.
 * This enum defines the possible logic status (high or low) for GPIO pins.
 */
typedef enum
{
    Low = 0, /*!< Logic low */
    High /*!< Logic high */
} Pin_Logic_Status_t;

/**
 * @brief Enumeration for GPIO pin numbers.
 * This enum defines the possible pin numbers for a GPIO port (0 to 15).
 */
typedef enum
{
    PIN_0 = 0, /*!< GPIO Pin 0 */
    PIN_1, /*!< GPIO Pin 1 */
    PIN_2, /*!< GPIO Pin 2 */
    PIN_3, /*!< GPIO Pin 3 */
    PIN_4, /*!< GPIO Pin 4 */
    PIN_5, /*!< GPIO Pin 5 */
    PIN_6, /*!< GPIO Pin 6 */
    PIN_7, /*!< GPIO Pin 7 */
    PIN_8, /*!< GPIO Pin 8 */
    PIN_9, /*!< GPIO Pin 9 */
    PIN_10, /*!< GPIO Pin 10 */
    PIN_11, /*!< GPIO Pin 11 */
    PIN_12, /*!< GPIO Pin 12 */
    PIN_13, /*!< GPIO Pin 13 */
    PIN_14, /*!< GPIO Pin 14 */
    PIN_15 /*!< GPIO Pin 15 */
} Pin_index_t;

/**
 * @brief Structure for configuring a GPIO pin.
 * This structure combines the configuration options for a GPIO pin.
 */
typedef struct
{
    Pin_index_t Pin_Number; /*!< Pin number (0 to 15) */
    Pin_Config_t Functionality; /*!< Pin configuration mode (Input, Output, Alternative, Analog) */
    Pin_Output_mode_t Output_mode; /*!< Output type (Push_Pull, Open_Drain) */
    Pin_Logic_Speed_t Speed; /*!< Output speed (Low_Speed, Medium_Speed, High_Speed, Very_High_Speed) */
    Pin_Pulling_t Pulling_State; /*!< Pull-up/pull-down configuration (No_Pulling, Pull_Up, Pull_Down) */
} Pin_t;

/**
 * @brief Initialize GPIO pin.
 * @param GPIOx: Pointer to the GPIO port.
 * @param Pin: Pointer to the Pin_t structure defining the pin configuration.
 */
void Mcal_Gpio_Init(GPIO_TypeDef *GPIOx, Pin_t *Pin);

/**
 * @brief Deinitialize GPIO port.
 * @param GPIOx: Pointer to the GPIO port.
 */
void Mcal_Gpio_Deinit(GPIO_TypeDef *GPIOx);

/**
 * @brief Write a logic level to a GPIO pin.
 * @param GPIOx: Pointer to the GPIO port.
 * @param Pin_Number: Pin number to write.
 * @param Logic: Logic level to write (Low or High).
 */
void Mcal_Gpio_Write(GPIO_TypeDef *GPIOx, Pin_index_t Pin_Number, Pin_Logic_Status_t Logic);

/**
 * @brief Read the logic level of a GPIO pin.
 * @param GPIOx: Pointer to the GPIO port.
 * @param Pin_Number: Pin number to read.
 * @return: Logic level of the pin (Low or High).
 */
uint8_t Mcal_Gpio_Read(GPIO_TypeDef *GPIOx, Pin_index_t Pin_Number);

/**
 * @brief Toggle the logic level of a GPIO pin.
 * @param GPIOx: Pointer to the GPIO port.
 * @param Pin_Number: Pin number to toggle.
 */
void Mcal_Gpio_Toggle(GPIO_TypeDef *GPIOx, Pin_index_t Pin_Number);

#endif /* GPIO_H_ */
