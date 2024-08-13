/*
 * Lcd.c
 *
 *  Created on: Aug 13, 2024
 *      Author: xcite
 */
#include "Inc/Lcd.h"
#include <stddef.h>

static LCD_PinConfig* lcd_config;

static void LCD_Write4Bits(uint8_t data) {
    Mcal_Gpio_Write(lcd_config->port, lcd_config->d4, (data >> 0) & 0x01);
    Mcal_Gpio_Write(lcd_config->port, lcd_config->d5, (data >> 1) & 0x01);
    Mcal_Gpio_Write(lcd_config->port, lcd_config->d6, (data >> 2) & 0x01);
    Mcal_Gpio_Write(lcd_config->port, lcd_config->d7, (data >> 3) & 0x01);

    // Generate EN pulse
    Mcal_Gpio_Write(lcd_config->port, lcd_config->en, High);
    for(volatile int i = 0; i < 1000; i++); // Short delay
    Mcal_Gpio_Write(lcd_config->port, lcd_config->en, Low);
    for(volatile int i = 0; i < 1000; i++); // Short delay
}

static void LCD_Write8Bits(uint8_t data) {
    LCD_Write4Bits(data >> 4);  // Send upper 4 bits
    LCD_Write4Bits(data);       // Send lower 4 bits
}

void LCD_SendCommand(uint8_t cmd) {
    Mcal_Gpio_Write(lcd_config->port, lcd_config->rs, Low);
    Mcal_Gpio_Write(lcd_config->port, lcd_config->rw, Low);
    LCD_Write8Bits(cmd);
}

void LCD_SendData(uint8_t data) {
    Mcal_Gpio_Write(lcd_config->port, lcd_config->rs, High);
    Mcal_Gpio_Write(lcd_config->port, lcd_config->rw, Low);
    LCD_Write8Bits(data);
}

void LCD_Init(LCD_PinConfig* config) {
    lcd_config = config;

    // Initialize GPIO pins
    Pin_t pin_config = {0};
    pin_config.Functionality = Output;
    pin_config.Output_mode = Push_Pull;
    pin_config.Speed = Medium_Speed;
    pin_config.Pulling_State = No_Pulling;

    pin_config.Pin_Number = config->rs;
    Mcal_Gpio_Init(config->port, &pin_config);

    pin_config.Pin_Number = config->rw;
    Mcal_Gpio_Init(config->port, &pin_config);

    pin_config.Pin_Number = config->en;
    Mcal_Gpio_Init(config->port, &pin_config);

    pin_config.Pin_Number = config->d4;
    Mcal_Gpio_Init(config->port, &pin_config);

    pin_config.Pin_Number = config->d5;
    Mcal_Gpio_Init(config->port, &pin_config);

    pin_config.Pin_Number = config->d6;
    Mcal_Gpio_Init(config->port, &pin_config);

    pin_config.Pin_Number = config->d7;
    Mcal_Gpio_Init(config->port, &pin_config);

    // LCD initialization sequence
    for(volatile int i = 0; i < 50000; i++); // Wait for >40ms after power on

    LCD_Write4Bits(0x03);
    for(volatile int i = 0; i < 5000; i++); // Wait for >4.1ms

    LCD_Write4Bits(0x03);
    for(volatile int i = 0; i < 150; i++); // Wait for >100us

    LCD_Write4Bits(0x03);
    LCD_Write4Bits(0x02); // Set 4-bit mode

    LCD_SendCommand(0x28); // Function set: 4-bit mode, 2 lines, 5x8 font
    LCD_SendCommand(0x0C); // Display control: Display on, cursor off, blink off
    LCD_SendCommand(0x06); // Entry mode set: Increment cursor, no display shift
    LCD_Clear();
}

void LCD_Clear(void) {
    LCD_SendCommand(LCD_CLEAR_DISPLAY);
    for(volatile int i = 0; i < 2000; i++); // Wait for >1.52ms
}

void LCD_SetCursor(uint8_t row, uint8_t col) {
    uint8_t row_offsets[] = {0x00, 0x40};
    LCD_SendCommand(LCD_SET_DDRAM_ADDR | (col + row_offsets[row]));
}

void LCD_PrintChar(char c) {
    LCD_SendData(c);
}

void LCD_PrintString(const char* str) {
    while(*str) {
        LCD_PrintChar(*str++);
    }
}



