

#include "../HAL/Inc/Lcd.h"

void delay_ms(uint32_t ms) {
    volatile uint32_t count = ms * (16000 / 5); // Adjusted for 16 MHz clock
    while (count--) {
        __asm("nop");
    }
}
int main(void) {
    RCC_GPIOA_Enable();
    LCD_PinConfig lcd_config = {
        .port = GPIOA,
        .rs = PIN_0,
        .rw = PIN_1,
        .en = PIN_2,
        .d4 = PIN_3,
        .d5 = PIN_4,
        .d6 = PIN_5,
        .d7 = PIN_6
    };

    LCD_Init(&lcd_config);

    LCD_PrintString("Hello, World!");
    LCD_SetCursor(1, 0);
    LCD_PrintString("LCD 4-bit mode");

    while(1) {
        // Main program loop
    }
}
