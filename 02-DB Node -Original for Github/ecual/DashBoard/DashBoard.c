

#include "DashBoard.h"
#include "../../ecual/lcd/LCD_Interface.h"


//init tha DashBoards
void DashBoard_Initialization(void){

  LCD_voidINIT(LCD0_ID, &LCD_Configuration);
  LCD_voidINIT(LCD1_ID, &LCD_Configuration);

}

//Display on First DashBoard
void DashBoard_TEMP_SPD_AC_Display(uint16 tempVal, uint16 speedVal, uint16 AC_Status){

  //LCD 0 Display Temp, AC Status, Speed
  LCD_voidGoTo(LCD1_ID, LCD_ROW1, 0);
  LCD_voidStringDisplay(LCD1_ID, "TEMP ");
  LCD_voidInttoChar(LCD1_ID,tempVal);
  
  LCD_voidGoTo(LCD1_ID, LCD_ROW1, 8);
  LCD_voidStringDisplay(LCD1_ID, "FAN ");
  if(tempVal <= 30)
  {
    LCD_voidStringDisplay(LCD1_ID, "OFF  ");
  }
  else if(tempVal > 30 &&  tempVal < 32)
  {
    LCD_voidStringDisplay(LCD1_ID, "ON Lo");
  }
  else
  {
    LCD_voidStringDisplay(LCD1_ID, "ON Hi");
  }

  LCD_voidGoTo(LCD1_ID, LCD_ROW2, 0);
  LCD_voidStringDisplay(LCD1_ID, "SPEED ");
  LCD_voidInttoChar(LCD1_ID,speedVal);
  
  LCD_voidGoTo(LCD1_ID, LCD_ROW2, 10);
  LCD_voidStringDisplay(LCD1_ID, "RPM");
}


//Display on Second DashBoard
void DashBoard_DISTANCE_Display(uint16 frontVal, uint16 parkVal){

  	//LCD 1 Display Park distance, Front distance
  	LCD_voidGoTo(LCD0_ID, LCD_ROW1, 0);
  	
  	LCD_voidStringDisplay(LCD0_ID, "FRONT DIST ");
  	if(frontVal >= 100)
  	{
		LCD_voidStringDisplay(LCD0_ID, "CLEAR");
  	}
  	
  	else
  	{
		  LCD_voidInttoChar(LCD0_ID,frontVal);
		  LCD_voidStringDisplay(LCD0_ID, "    ");
  	}
  	  
  	LCD_voidGoTo(LCD0_ID, LCD_ROW2, 0);
  	
  	LCD_voidStringDisplay(LCD0_ID, "PARK  DIST ");
  	if(parkVal >= 100)
  	{
		LCD_voidStringDisplay(LCD0_ID, "CLEAR");
  	}
  	else
  	{
  		LCD_voidInttoChar(LCD0_ID,parkVal);
		LCD_voidStringDisplay(LCD0_ID, "    ");
  	}
    

}