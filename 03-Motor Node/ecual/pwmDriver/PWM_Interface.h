#ifndef _PWM_INTERFACE_
#define   _PWM_INTERFACE_
	#include <stdint.h>

#define GPIO_PF1_M1PWM5         0x00050405
#define GPIO_PF2_M1PWM6         0x00050805
#define GPIO_PF3_M1PWM7         0x00050C05
#define GPIO_PB5_M0PWM3         0x00011404
#define GPIO_PB6_M0PWM0         0x00011804
#define GPIO_PB7_M0PWM1         0x00011C04
#define GPIO_PA6_M1PWM2         0x00001805

#define PWM_FAN_0_PERCENT		01
#define PWM_FAN_25_PERCENT		15000
#define PWM_FAN_100_PERCENT		59999

#define PWM_MOTOR_0_PERCENT		1
#define PWM_MOTOR_10_PERCENT	2
#define PWM_MOTOR_20_PERCENT	3
#define PWM_MOTOR_30_PERCENT	4
#define PWM_MOTOR_40_PERCENT	5
#define PWM_MOTOR_50_PERCENT	6
#define PWM_MOTOR_60_PERCENT	7
#define PWM_MOTOR_70_PERCENT	8
#define PWM_MOTOR_80_PERCENT	9
#define PWM_MOTOR_100_PERCENT	0

typedef enum {
	PWM_0 = 0,
	PWM_1 = 1,
	PWM_2 = 2,
	PWM_3 = 3,
	PWM_4 = 4,
	PWM_5 = 5,
	PWM_6 = 6,
	PWM_7 = 7,
} PWMChannel;


typedef enum {
	PWMModule0 = 0,
	PWMModule1 = 1
} PWMModule;

	void PWM0_Init (void);
	void PWM0_Set(uint16_t duty);
	void PWM_Test(void);
		void PWM3_Init( uint16_t period, uint16_t duty);
void PWM5_SetDuty(uint16_t duty);


void PWM1_Init(void);
	
	
	#endif