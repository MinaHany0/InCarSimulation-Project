/*
 * LCD_Interface.h
 *
 * Created: 10/21/2023 12:07:54 PM
 *  Author: adham
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#include "../../library/Std_Types.h"
   
#define LCD_CONFIGURED_NUM     (2U)

#define LCD0_ID                (0U)
#define LCD1_ID                (1U)

#define LCD_ROW1 0x00+0x80
#define LCD_ROW3 0x14+0x80
#define LCD_ROW2 0x40+0x80
#define LCD_ROW4 0x54+0x80


typedef struct{
    uint8 LCD_RS;
    uint8 LCD_E;

    uint8 LCD_D4;
    uint8 LCD_D5;
    uint8 LCD_D6;
    uint8 LCD_D7;

}LCD_PINS;



enum RS_Pin{
	Command=0,
	Data=1
};

typedef struct{
  LCD_PINS Channels[LCD_CONFIGURED_NUM];
}LCD_ConfigChannel;

void LCD_voidINIT(uint8 LCD_ID, LCD_ConfigChannel *ConfigPtr);

void LCD_voidCommandWrite(uint8 LCD_ID, uint8 data);

void LCD_voidCharDisplay(uint8 LCD_ID, uint8 data);

void LCD_voidPulse(uint8 LCD_ID);

void LCD_voidGoTo(uint8 LCD_ID, uint8 row,uint8 col);

void LCD_voidStringDisplay(uint8 LCD_ID, uint8* Str);

void LCD_voidInttoChar(uint8 LCD_ID, uint16 num);



uint8 uint8inttochar(uint16 num);
   


extern LCD_ConfigChannel LCD_Configuration;

#endif /* LCD_INTERFACE_H_ */