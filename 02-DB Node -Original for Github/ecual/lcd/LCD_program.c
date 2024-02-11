
#include "../../library/Delay_interface.h"

#include "../../library/Common_Macros.h"
#include "../../library/Std_Types.h"
#include "../../mcal/dio/dio.h"

#include "LCD_Interface.h"


STATIC LCD_PINS *LCD_ptr;

void LCD_voidINIT(uint8 LCD_ID, LCD_ConfigChannel * ConfigPtr){

    LCD_ptr = ConfigPtr->Channels;

    Dio_WriteChannel(LCD_ptr[LCD_ID].LCD_E ,STD_LOW);
	
     Delay_vMsIn16MHz(10);
     LCD_voidCommandWrite(LCD_ID , 0x02);
     Delay_vMsIn16MHz(1);
      LCD_voidCommandWrite(LCD_ID, 0x28);
      Delay_vMsIn16MHz(1);
	LCD_voidCommandWrite(LCD_ID, 0x0C);
	Delay_vMsIn16MHz(1);
	LCD_voidCommandWrite(LCD_ID, 0x01);
	Delay_vMsIn16MHz(1);
	LCD_voidCommandWrite(LCD_ID, 0x06);
	Delay_vMsIn16MHz(5);
    

}

void LCD_voidCommandWrite(uint8 LCD_ID, uint8 data){

    Dio_WriteChannel(LCD_ptr[LCD_ID].LCD_RS,Command);

	Dio_WriteChannel(LCD_ptr[LCD_ID].LCD_D4,1&(data>>4));
	Dio_WriteChannel(LCD_ptr[LCD_ID].LCD_D5,1&(data>>5));
	Dio_WriteChannel(LCD_ptr[LCD_ID].LCD_D6,1&(data>>6));
	Dio_WriteChannel(LCD_ptr[LCD_ID].LCD_D7,1&(data>>7));
	Delay_vMsIn16MHz(1);

	LCD_voidPulse(LCD_ID);


	Dio_WriteChannel(LCD_ptr[LCD_ID].LCD_D4,1&(data));
	Dio_WriteChannel(LCD_ptr[LCD_ID].LCD_D5,1&(data>>1));
	Dio_WriteChannel(LCD_ptr[LCD_ID].LCD_D6,1&(data>>2));
	Dio_WriteChannel(LCD_ptr[LCD_ID].LCD_D7,1&(data>>3));
	
	LCD_voidPulse(LCD_ID);
	
	
	Delay_vMsIn16MHz(2);
    
}


void LCD_voidCharDisplay(uint8 LCD_ID, uint8 data){
    

    Dio_WriteChannel(LCD_ptr[LCD_ID].LCD_RS,Data);

	Dio_WriteChannel(LCD_ptr[LCD_ID].LCD_D4,1&(data>>4));
	Dio_WriteChannel(LCD_ptr[LCD_ID].LCD_D5,1&(data>>5));
	Dio_WriteChannel(LCD_ptr[LCD_ID].LCD_D6,1&(data>>6));
	Dio_WriteChannel(LCD_ptr[LCD_ID].LCD_D7,1&(data>>7));
	Delay_vMsIn16MHz(1);

	LCD_voidPulse(LCD_ID);


	Dio_WriteChannel(LCD_ptr[LCD_ID].LCD_D4,1&(data));
	Dio_WriteChannel(LCD_ptr[LCD_ID].LCD_D5,1&(data>>1));
	Dio_WriteChannel(LCD_ptr[LCD_ID].LCD_D6,1&(data>>2));
	Dio_WriteChannel(LCD_ptr[LCD_ID].LCD_D7,1&(data>>3));
	
	LCD_voidPulse(LCD_ID);
	
	
	Delay_vMsIn16MHz(2);
}

void LCD_voidPulse(uint8 LCD_ID){
    
    Dio_WriteChannel(LCD_ptr[LCD_ID].LCD_E,STD_HIGH);
    Delay_vMsIn16MHz(3);
    Dio_WriteChannel(LCD_ptr[LCD_ID].LCD_E,STD_LOW);
    Delay_vMsIn16MHz(3);
    
}

void LCD_voidGoTo(uint8 LCD_ID, uint8 row,uint8 col){
	LCD_voidCommandWrite(LCD_ID, row+col);
}

void LCD_voidStringDisplay(uint8 LCD_ID, uint8* Str){
	
	for(uint8 i=0;Str[i]!='\0';i++){
		LCD_voidCharDisplay(LCD_ID, Str[i]);
	}
}


void LCD_voidInttoChar(uint8 LCD_ID, uint16 num){
	uint8 str[4] = {' ', ' ', ' ', '\0'};
	sprintf((sint8*)str,"%u",num);
	LCD_voidStringDisplay(LCD_ID,str);
	LCD_voidStringDisplay(LCD_ID, "  ");
}

uint8 uint8inttochar(uint16 num){
	
	switch (num){
		case 0:
			return '0';
		case 1:
			return '1';
		case 2:
			return '2';
		case 3:
			return '3';
		case 4:
			return '4';
		case 5:
			return '5';
		case 6:
			return '6';
		case 7:
			return '7';
		case 8:
			return '8';
		case 9:
			return '9';
	}
	return 0;
}