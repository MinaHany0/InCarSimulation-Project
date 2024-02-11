/*========================================================================================
===========================   - Created: 3/8/2022	     =============================
===========================   - Author: Wave 6 G 3     =============================
========================================================================================*/ 


/*============= INCLUDE LIB ==============*/
	 #include "Std_Types.h"
	 
/*========================================*/	 

/*============= INCLUDE MCAL ==============*/

	#include "Delay_interface.h"
	
/*========================================*/	

/*============= INCLUDE HAL ==============*/ 
			

/*========================================*/





/*======================================================== Start_FUNCTION  ========================================================*/
/*
*		Function To Delay By Milliseconds ( 16MHz CPU CLK )
*/

extern void Delay_vMsIn16MHz(uint16 copy_u16CountNum)
{
	volatile uint32 u16Local_Count1 ;
	volatile uint32 u16Local_Count2 ;
	for(u16Local_Count1 = 0 ; u16Local_Count1 < copy_u16CountNum  ; u16Local_Count1++ ){
          for(u16Local_Count2  = 0 ; u16Local_Count2  < 3180  ; u16Local_Count2 ++ ){} // Do nothing for 1 ms
        }
	
}



/*======================================================== END_ FUNCTION   ========================================================*/



/*======================================================== Start_FUNCTION  ========================================================*/
/*
*		Function To Delay By Microseconds ( 16MHz CPU CLK )
*/

extern void Delay_vUsIn16MHzint (uint16 copy_u16CountNum)
{
	volatile uint16 u16Local_Count1 ;
	volatile uint16 u16Local_Count2 ;
	for(u16Local_Count1 = 0 ; u16Local_Count1 < copy_u16CountNum  ; u16Local_Count1++ )
	for(u16Local_Count2  = 0 ; u16Local_Count2  < 3  ; u16Local_Count2 ++ )
	{} // Do nothing for 1 ms
}



/*======================================================== END_ FUNCTION   ========================================================*/
