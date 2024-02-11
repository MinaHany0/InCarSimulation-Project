#include "../DC_Motor/DC_Motor.h"
#include "FAN.h"
#include "../../MCAL/dio/Dio.h"
#include "../../MCAL/port/Port.h"
#include "../../library/Platform_Types.h"


void FAN_voidMove(void)
{
    //Dio_WriteChannel(DioConf_FAN_ENB_CHANNEL_ID_INDEX, FAN_u8HIGH);
   // Dio_WriteChannel(DioConf_FAN_IN2_B_CHANNEL_ID_INDEX, FAN_u8LOW);
}
void FAN_voidStop(void)
{
    //Dio_WriteChannel(DioConf_FAN_ENB_CHANNEL_ID_INDEX, DCM_u8LOW);
    //Dio_WriteChannel(DioConf_FAN_IN1_B_CHANNEL_ID_INDEX, DCM_u8LOW);
   // Dio_WriteChannel(DioConf_DCM_IN2_CHANNEL_ID_INDEX, DCM_u8LOW);
}

