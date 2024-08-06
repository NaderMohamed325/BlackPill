#include "../Inc/GPIO.h"

#define SCB_CPACR      (*(volatile unsigned int*)0xE000ED88U)

// Function to initialize the FPU
void FPU_Init(void)
    {
    // Set bits 20-23 (CP10 and CP11) to 0b11 to enable full access to the FPU
    SCB_CPACR |= (0xF << 20);
    }

// Simple delay function
void delay(volatile unsigned int count)
    {
    while (count--)
	;
    }

int main(void)
    {
    // Initialize the FPU
    FPU_Init();

    // Enable GPIOA clock
    RCC_GPIOA_Enable();

    // Define and initialize the pin configuration structure
    Pin_Config_t Pin;
    Pin.Functionality = GPO;          // General Purpose Output mode
    Pin.Logic_Speed = MEDIUM_SPEED;    // Medium speed
    Pin.Pin_Number = 5;               // Pin number 1
    Pin.Port_index = GPIOA;           // GPIOA port
    Pin.Pull_Mode = NO_PU_PD;         // No pull-up or pull-down
    Pin.Output_Cfg = OUTPUT_PP;       // Push-Pull output configuration

    // Initialize GPIO pin with the specified configuration
    Mcal_Gpio_Init(&Pin);

    // Main loop
    while (1)
	{
	Mcal_GPIO_Logic_Write(GPIOA, 5, HIGH);
	delay(1000000);
	Mcal_GPIO_Logic_Write(GPIOA, 5, LOW);
	delay(1000000);
	}
    }
