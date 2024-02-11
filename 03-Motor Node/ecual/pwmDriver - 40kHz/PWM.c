
#include <stdint.h>
#include <stdbool.h>
//#include "TM4C123.h"
#include "driverlib/sysctl.h"
#include "inc/tm4c123gh6pm.h"
#include "driverlib/pwm.h"
#include "driverlib/gpio.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/pin_map.h"
#include "PWM_Interface.h"
//#include "Utlise.h"
/*************************/



//extern uint32_t pwmPeriod;
uint32_t PWMClock = 0;
void PWM0_Init(void)
{
	
	//get PWM CLock
	PWMClock = SysCtlPWMClockGet();

	//Configure PWM prescaler to 8
   	SysCtlPWMClockSet(SYSCTL_PWMDIV_8);

   	// Enable the peripherals used by this program.
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
	
	//The Tiva Launchpad has two modules (0 and 1). Module 1 covers the LED pins
    SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0); 
  
	
    //Configure PB5 Pins as PWM
    GPIOPinConfigure(GPIO_PB5_M0PWM3);
    GPIOPinTypePWM(GPIO_PORTB_BASE, GPIO_PIN_5);

	/*configuration of GEN0 : PWM_0 and PWM_1 are associated with Gen0
	  configuration of GEN1 :PWM_2 and PWM_3 are associated with Gen1*/
	PWMGenConfigure(PWM0_BASE, PWM_GEN_1, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC); 

    //Set the Period (expressed in clock ticks)
	//freq of GEN 1 is 33 Hz
	PWMGenPeriodSet(PWM0_BASE, PWM_GEN_1, 60000);
		
    //Set PWM duty-0% for PWM 3
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_3,1);
    // Enable the PWM generator
    PWMGenEnable(PWM0_BASE, PWM_GEN_1);

    // Turn on the Output pins
	PWMOutputState(PWM0_BASE, PWM_OUT_0_BIT | PWM_OUT_1_BIT | PWM_OUT_3_BIT, true);
}

void PWM1_Init(void)
{
	
	//get PWM CLock
	PWMClock = SysCtlPWMClockGet();

	//Configure PWM prescaler to 8
   	SysCtlPWMClockSet(SYSCTL_PWMDIV_8);

   	// Enable the peripherals used by this program.
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
	
	//The Tiva Launchpad has two modules (0 and 1). Module 1 covers the LED pins
    SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM1); 
  
	
    //Configure PB5 Pins as PWM
    GPIOPinConfigure(GPIO_PA6_M1PWM2);
    GPIOPinTypePWM(GPIO_PORTA_BASE, GPIO_PIN_6);

	/*configuration of GEN0 : PWM_0 and PWM_1 are associated with Gen0
	  configuration of GEN1 :PWM_2 and PWM_3 are associated with Gen1*/
	PWMGenConfigure(PWM1_BASE, PWM_GEN_1, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC); 

    //Set the Period (expressed in clock ticks)
	//freq of GEN 1 is 40 kHz
	PWMGenPeriodSet(PWM1_BASE, PWM_GEN_1, 50);
		
    //Set PWM duty-0%
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_2,1);
    // Enable the PWM generator
    PWMGenEnable(PWM1_BASE, PWM_GEN_1);

    // Turn on the Output pins
	PWMOutputState(PWM1_BASE, PWM_OUT_0_BIT | PWM_OUT_1_BIT | PWM_OUT_2_BIT | PWM_OUT_3_BIT, true);
}