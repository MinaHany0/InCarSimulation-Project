#include "DC_Motor.h"
#include "DC_Motor_cfg.h"
#include "DC_Motor_priv.h"
#include "../../MCAL/dio/Dio.h"
#include "../../MCAL/port/Port.h"
#include "../../MCAL/pwm/PWM.h"


void DCM_PWMSelect(uint32 PWM_Freq, uint32 PWM_DutyCycle)
{
    uint32 period_RegVal = (16000000 / PWM_Freq) -1;
    uint64 DutyCycle_RegVal = (period_RegVal * (100 - PWM_DutyCycle) / 100);


    Pwm_ConfigType pwmChannel6 = {PWM_CHANNEL_NUM_6, 0, PWM_LOW, PWM_FALLING_EDGE, PWM_FIXED_PERIOD};
    Pwm_Init(&pwmChannel6);
    Pwm_SetPeriodAndDuty(PWM_CHANNEL_NUM_6, period_RegVal, DutyCycle_RegVal);
    Dio_WriteChannel(DioConf_DCM_IN1_CHANNEL_ID_INDEX, DCM_u8HIGH);

}

void DCM_Stop(void)
{
    Dio_WriteChannel(DioConf_DCM_IN1_CHANNEL_ID_INDEX, DCM_u8LOW);
}

void FAN_PWMSelect(uint32 PWM_Freq, uint32 PWM_DutyCycle)
{
    uint32 period_RegVal = (16000000 / PWM_Freq) -1;
    uint64 DutyCycle_RegVal = (period_RegVal * (100 - PWM_DutyCycle) / 100);

    Pwm_ConfigType pwmChannel7 = {PWM_CHANNEL_NUM_7, 0, PWM_LOW, PWM_FALLING_EDGE, PWM_FIXED_PERIOD};
    Pwm_Init(&pwmChannel7);

    Pwm_SetPeriodAndDuty(PWM_CHANNEL_NUM_7, period_RegVal, DutyCycle_RegVal);
    Dio_WriteChannel(DioConf_FAN_IN1_CHANNEL_ID_INDEX, DCM_u8HIGH);

}

void FAN_Stop(void)
{
    Dio_WriteChannel(DioConf_FAN_IN1_CHANNEL_ID_INDEX, DCM_u8LOW);
}