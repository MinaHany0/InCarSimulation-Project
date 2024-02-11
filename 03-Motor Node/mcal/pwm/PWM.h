#ifndef  PWM_H_
#define  PWM_H_

#include "../../library/Std_Types.h"
#include "../../library/Platform_Types.h"
#include "PWM_Types.h"

#define PWM_CLOCK_ENABLE     0x0010.0000
#define GPIO_CLOCK_ENABLE    

#define MAX_PWM_CHANNELS               8

#define PWM_CHANNEL_NUM_0              0
#define PWM_CHANNEL_NUM_1              1
#define PWM_CHANNEL_NUM_2              2
#define PWM_CHANNEL_NUM_3              3
#define PWM_CHANNEL_NUM_4              4
#define PWM_CHANNEL_NUM_5              5
#define PWM_CHANNEL_NUM_6              6
#define PWM_CHANNEL_NUM_7              7

void Pwm_Init(const Pwm_ConfigType* ConfigPtr);
void Pwm_DeInit(void);
void Pwm_SetDutyCycle(Pwm_ChannelType ChannelNumber, uint16 DutyCycle);
void Pwm_SetPeriodAndDuty(Pwm_ChannelType ChannelNumber, Pwm_PeriodType Period, uint16 DutyCycle); 
void Pwm_SetOutputToIdle(Pwm_ChannelType ChannelNumber);
Pwm_OutputStateType Pwm_GetOutputState(Pwm_ChannelType ChannelNumber);
void Pwm_DisableNotification(Pwm_ChannelType ChannelNumber);
void Pwm_EnableNotification(Pwm_ChannelType ChannelNumber, Pwm_EdgeNotificationType Notification);
//Std_ReturnType Pwm_SetPowerState(Pwm_PowerStateRequestResultType* Result);
//Std_ReturnType Pwm_GetCurrentPowerState(Pwm_PowerStateType* CurrentPowerState, Pwm_PowerStateRequestResultType* Result);
//Std_ReturnType Pwm_GetTargetPowerState(Pwm_PowerStateType* TargetPowerState, Pwm_PowerStateRequestResultType* Result);
//Std_ReturnType Pwm_PreparePowerState(Pwm_PowerStateType PowerState, Pwm_PowerStateRequestResultType* Result);
void Pwm_GetVersionInfo(Std_VersionInfoType* versioninfo);
void Pwm_Main_PowerTransitionManager(void);

#endif
