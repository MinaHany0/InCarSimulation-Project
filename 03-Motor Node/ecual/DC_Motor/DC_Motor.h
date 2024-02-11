#ifndef  DC_MOTOR_H_
#define  DC_MOTOR_H_

#include "../../library/Platform_Types.h"

#define DCM_u8HIGH  ((uint8) 0x01)
#define DCM_u8LOW   ((uint8) 0x00)


void DCM_PWMSelect(uint32 PWM_Freq, uint32 PWM_DutyCycle);
void DCM_Stop(void);
void FAN_PWMSelect(uint32 PWM_Freq, uint32 PWM_DutyCycle);
void FAN_Stop(void);


#endif





