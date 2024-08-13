// LCD.h

#ifndef LCD_H_
#define LCD_H_

#include "../../Inc/GPIO.h"

// LCD commands
#define LCD_CLEAR_DISPLAY 0x01
#define LCD_RETURN_HOME 0x02
#define LCD_ENTRY_MODE_SET 0x04
#define LCD_DISPLAY_CONTROL 0x08
#define LCD_CURSOR_SHIFT 0x10
#define LCD_FUNCTION_SET 0x20
#define LCD_SET_CGRAM_ADDR 0x40
#define LCD_SET_DDRAM_ADDR 0x80

// LCD dimensions
#define LCD_ROWS 2
#define LCD_COLS 16

// LCD pin configuration
typedef struct {
    GPIO_TypeDef* port;
    Pin_index_t rs;
    Pin_index_t rw;
    Pin_index_t en;
    Pin_index_t d4;
    Pin_index_t d5;
    Pin_index_t d6;
    Pin_index_t d7;
} LCD_PinConfig;

// Function prototypes
void LCD_Init(LCD_PinConfig* config);
void LCD_SendCommand(uint8_t cmd);
void LCD_SendData(uint8_t data);
void LCD_Clear(void);
void LCD_SetCursor(uint8_t row, uint8_t col);
void LCD_PrintString(const char* str);
void LCD_PrintChar(char c);

#endif /* LCD_H_ */
