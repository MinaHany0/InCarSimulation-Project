/*
 * 
 *
 * Created: 11/20/2023 11:24:52 PM
 * Author : 
 */ 

//*****************************************************************************
//
// INCLUDES SECTION
//
//*****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include "library/Common_Macros.h"
#include "library/Platform_Types.h"
#include "library/tm4c123gh6pm_registers.h"
#include "mcal/port/Port.h"
#include "mcal/dio/Dio.h"
#include "mcal/gpt/Gpt.h"
#include "ecual/DC_Motor/DC_Motor.h"
#include "ecual/CanDriver/CanDriver.h"
#include "driverlib/pwm.h"
#include "driverlib/sysctl.h"
#include "ecual/pwmDriver/PWM_Interface.h"

uint32_t clockFreq = 0;
uint32_t pwmPeriod = 10;
uint32_t pwm10percent;
uint32_t pwmDutyCycle;
uint8 pwmCounter;

void canGetDataOrCheck(void);
void blockingDelay(void);
void TempProcessAndTakeAction(void);
void FrontDistProcessAndTakeAction(void);
void RaiseOneSecondFlag(void);
int main(void)
{
	pwm10percent = pwmPeriod / 10;
	
	clockFreq = SysCtlClockGet();
    InitCAN0();
	Port_Init(&Port_PinConfig);
    Dio_Init(&Dio_Configuration);
	PWM0_Init();
	PWM1_Init();
	
	
	while(1)
	{
		canGetDataOrCheck();
		TempProcessAndTakeAction();
		FrontDistProcessAndTakeAction();	

	}	  
}

void canGetDataOrCheck(void)
{
	if(Flag_AcButt_Motor)
	{
		Flag_AcButt_Motor = 0;
		CANMessageGet(CAN0_BASE, ObjID_AcButt_Motor, &g_sCAN0T_MsgID_AcButt_Motor, MSG_OBJ_TYPE_RX);
	}
	else
	{
		if(g_ui32ErrFlag != 0)
		{
			CANErrorHandler();
		}
	}
}


void TempProcessAndTakeAction(void)
{
	if(TEMP_SENSOR <= 27 )
	{
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_3,PWM_FAN_0_PERCENT);
	}
	else if(TEMP_SENSOR > 27 &&  TEMP_SENSOR < 30)
	{
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_3,PWM_FAN_25_PERCENT);
	}
	else
	{
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_3,PWM_FAN_100_PERCENT);
	}
}

void FrontDistProcessAndTakeAction(void)
{
	if(CRASH_SENSOR <= 10 )
	{
		PWMOutputState(PWM1_BASE, PWM_OUT_2_BIT , false);
	}
	else if(CRASH_SENSOR <= 20 )
	{
		PWMOutputState(PWM1_BASE, PWM_OUT_2_BIT , true);
		PWMPulseWidthSet(PWM1_BASE, PWM_OUT_2,PWM_MOTOR_30_PERCENT);
	}
	else if(CRASH_SENSOR <= 40 )
	{
		PWMOutputState(PWM1_BASE, PWM_OUT_2_BIT , true);
		PWMPulseWidthSet(PWM1_BASE, PWM_OUT_2,PWM_MOTOR_50_PERCENT);
	}
	else if(CRASH_SENSOR <= 60 )
	{
		PWMOutputState(PWM1_BASE, PWM_OUT_2_BIT , true);
		PWMPulseWidthSet(PWM1_BASE, PWM_OUT_2,PWM_MOTOR_70_PERCENT);
	}
	else
	{
		PWMOutputState(PWM1_BASE, PWM_OUT_2_BIT , true);
		PWMPulseWidthSet(PWM1_BASE, PWM_OUT_2,PWM_MOTOR_100_PERCENT);
	}
	
}

void blockingDelay(void)
{
	for(int i = 0; i < 8000000; i++)
	{
		
	}
}