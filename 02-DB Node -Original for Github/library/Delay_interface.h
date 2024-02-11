/*========================================================================================
===========================   - Created: 3/8/2022	     =============================
===========================   - Author: Wave 6 G 3     =============================
========================================================================================*/ 



#ifndef DELAY_INTERFACE_H
#define DELAY_INTERFACE_H
	 
#include "Std_Types.h"


/*========================================================================================
 *                      Functions Prototypes                                   *
========================================================================================*/


  /* =============  Function To Delay By Milliseconds ( 16MHz CPU CLK )   ============= */
  extern void Delay_vMsIn16MHz(uint16 copy_u16CountNum);

 /* =============  Function To Delay By Microseconds ( 16MHz CPU CLK )   ============= */
  extern void Delay_vUsIn16MHzint (uint16 copy_u16CountNum);






#endif //DELAY_INTERFACE_H
