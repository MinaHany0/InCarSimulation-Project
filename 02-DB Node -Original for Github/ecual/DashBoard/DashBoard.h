
#ifndef DASHBOARD_H_
#define DASHBOARD_H_

#include "../../library/Std_Types.h"


void DashBoard_Initialization(void);

void DashBoard_DISTANCE_Display(uint16 frontVal, uint16 parkVal);

void DashBoard_TEMP_SPD_AC_Display(uint16 tempVal, uint16 speedVal, uint16 AC_Status);


#endif