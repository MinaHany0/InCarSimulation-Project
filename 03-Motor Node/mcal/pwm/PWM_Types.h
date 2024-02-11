#ifndef  PWM_TYPES_H_
#define  PWM_TYPES_H_

#include "../../library/Std_Types.h"
#include "../../library/Platform_Types.h"

typedef void (*Pwm_NotificationHandlerType)();

typedef uint8 Pwm_ChannelType;
typedef uint16 Pwm_PeriodType ;

typedef enum{
	PWM_LOW,
	PWM_HIGH
}Pwm_OutputStateType;

typedef enum{
	PWM_RISING_EDGE,
	PWM_FALLING_EDGE,
	PWM_BOTH_EDGES
}Pwm_EdgeNotificationType; 

typedef enum{
	PWM_VARIABLE_PERIOD,
	PWM_FIXED_PERIOD,
	PWM_FIXED_PERIOD_SHIFTED
}Pwm_ChannelClassType;

typedef struct{
	Pwm_ChannelType           u8ChannelType;
	Pwm_PeriodType            u16PeriodType ;
	Pwm_OutputStateType       tenumOutputStateType;
	Pwm_EdgeNotificationType  tenumEdgeNotificationType;
	Pwm_ChannelClassType      tenumChannelClassType;
}Pwm_ConfigType;  

typedef enum{
	PWM_SERVICE_ACCEPTED,
	PWM_NOT_INIT,
	PWM_SEQUENCE_ERROR,
	PWM_HW_FAILURE,
	PWM_POWER_STATE_NOT_SUPP,
	PWM_TRANS_NOT_POSSIBLE
}Pwm_PowerStateRequestResultType;

typedef enum{
	PWM_FULL_POWER
}Pwm_PowerStateType;

typedef enum
{
  PWM_E_PARAM_CONFIG              = 0x10,
  PWM_E_UNINIT,
  PWM_E_PARAM_CHANNEL,
  PWM_E_PERIOD_UNCHANGEABLE,
  PWM_E_ALREADY_INITIALIZED
}Pwm_DetErrorType;


#endif