#include "PWM.h"
#include "PWM_cfg.h"
#include "PWM_priv.h"
#include "PWM_Types.h"
#include "../../library/tm4c123gh6pm_registers.h"
#include "../../mcal/dio/Dio.h"
#include "../../mcal/port/Port.h"
#include "../../library/Common_Macros.h"

void Pwm_Init(const Pwm_ConfigType* ConfigPtr)
{
  Port_ConfigType pwmConfigPort;
  SET_BIT(SYSCTL_RCGCPWM_R,0 );
#if PWM_MODULE_NUM == PWM_MODULE_0
  switch(ConfigPtr -> u8ChannelType)
  {
  case PWM_CHANNEL_NUM_0:
    if(ConfigPtr -> tenumOutputStateType == PWM_LOW)
    {
      pwmConfigPort.Pin[14] = (Port_ConfigPin){PORT_B, PIN_6, PORT_PIN_OUT, OFF, PORT_PIN_LEVEL_LOW,  PORT_PIN_MODE_4, STD_OFF, STD_OFF};
    }
    else
    {
      pwmConfigPort.Pin[14] = (Port_ConfigPin){PORT_B, PIN_6, PORT_PIN_OUT, OFF, PORT_PIN_LEVEL_HIGH,  PORT_PIN_MODE_4, STD_OFF, STD_OFF};
    }
    break;
  case PWM_CHANNEL_NUM_1:
    if(ConfigPtr -> tenumOutputStateType == PWM_LOW)
    {
      pwmConfigPort.Pin[15] = (Port_ConfigPin){PORT_B, PIN_7, PORT_PIN_OUT, OFF, PORT_PIN_LEVEL_LOW,  PORT_PIN_MODE_4, STD_OFF, STD_OFF};
    }
    else
    {
      pwmConfigPort.Pin[15] = (Port_ConfigPin){PORT_B, PIN_7, PORT_PIN_OUT, OFF, PORT_PIN_LEVEL_HIGH,  PORT_PIN_MODE_4, STD_OFF, STD_OFF};
    }
    break;
  case PWM_CHANNEL_NUM_2:
    if(ConfigPtr -> tenumOutputStateType == PWM_LOW)
    {
      pwmConfigPort[12] = (Port_ConfigPin){PORT_B, PIN_4, PORT_PIN_OUT, OFF, PORT_PIN_LEVEL_LOW,  PORT_PIN_MODE_4, STD_OFF, STD_OFF};
    }
    else
    {
      pwmConfigPort[12] =  (Port_ConfigPin){PORT_B, PIN_4, PORT_PIN_OUT, OFF, PORT_PIN_LEVEL_HIGH,  PORT_PIN_MODE_4, STD_OFF, STD_OFF};
    }
    break;
  case PWM_CHANNEL_NUM_3:
    if(ConfigPtr -> tenumOutputStateType == PWM_LOW)
    {
      pwmConfigPort[13] = (Port_ConfigPin){PORT_B, PIN_5, PORT_PIN_OUT, OFF, PORT_PIN_LEVEL_LOW,  PORT_PIN_MODE_4, STD_OFF, STD_OFF};
    }
    else
    {
      pwmConfigPort[13] = (Port_ConfigPin){PORT_B, PIN_5, PORT_PIN_OUT, OFF, PORT_PIN_LEVEL_HIGH,  PORT_PIN_MODE_4, STD_OFF, STD_OFF};
    }
    break;
  case PWM_CHANNEL_NUM_4:
    if(ConfigPtr -> tenumOutputStateType == PWM_LOW)
    {
      pwmConfigPort[36] = (Port_ConfigPin){PORT_E, PIN_4, PORT_PIN_OUT, OFF, PORT_PIN_LEVEL_LOW,  PORT_PIN_MODE_4, STD_OFF, STD_OFF};
    }
    else
    {
      pwmConfigPort[36] = (Port_ConfigPin){PORT_E, PIN_4, PORT_PIN_OUT, OFF, PORT_PIN_LEVEL_HIGH,  PORT_PIN_MODE_4, STD_OFF, STD_OFF};
    }
    break;
  case PWM_CHANNEL_NUM_5:
    if(ConfigPtr -> tenumOutputStateType == PWM_LOW)
    {
      pwmConfigPort[37] = (Port_ConfigPin){PORT_E, PIN_5, PORT_PIN_OUT, OFF, PORT_PIN_LEVEL_LOW,  PORT_PIN_MODE_4, STD_OFF, STD_OFF};
    }
    else
    {
      pwmConfigPort[37] = (Port_ConfigPin){PORT_E, PIN_5, PORT_PIN_OUT, OFF, PORT_PIN_LEVEL_HIGH,  PORT_PIN_MODE_4, STD_OFF, STD_OFF};
    }
    break;
  case PWM_CHANNEL_NUM_6:
    if(ConfigPtr -> tenumOutputStateType == PWM_LOW)
    {
      pwmConfigPort[24] = (Port_ConfigPin){PORT_D, PIN_0, PORT_PIN_OUT, OFF, PORT_PIN_LEVEL_LOW,  PORT_PIN_MODE_4, STD_OFF, STD_OFF};
    }
    else
    {
      pwmConfigPort[24] = (Port_ConfigPin){PORT_D, PIN_0, PORT_PIN_OUT, OFF, PORT_PIN_LEVEL_HIGH,  PORT_PIN_MODE_4, STD_OFF, STD_OFF};
    }
    break;
  case PWM_CHANNEL_NUM_7:
    if(ConfigPtr -> tenumOutputStateType == PWM_LOW)
    {
      pwmConfigPort[25] = (Port_ConfigPin){PORT_D, PIN_1, PORT_PIN_OUT, OFF, PORT_PIN_LEVEL_LOW,  PORT_PIN_MODE_4, STD_OFF, STD_OFF};
    }
    else
    {
      pwmConfigPort[25] = (Port_ConfigPin){PORT_D, PIN_1, PORT_PIN_OUT, OFF, PORT_PIN_LEVEL_HIGH,  PORT_PIN_MODE_4, STD_OFF, STD_OFF};
    }
    break;
  default:
    if(ConfigPtr -> tenumOutputStateType == PWM_LOW)
    {
    }
    else
    {
    }
    break;
  }
#else 
  SET_BIT(SYSCTL_RCGCPWM_R,1 );
  switch(ConfigPtr -> u8ChannelType)
  {
  case PWM_CHANNEL_NUM_0:
    if(ConfigPtr -> tenumOutputStateType == PWM_LOW)
    {
      pwmConfigPort.Pin[38] = (Port_ConfigPin){PORT_F, PIN_0, PORT_PIN_OUT, OFF, PORT_PIN_LEVEL_LOW,  PORT_PIN_MODE_5, STD_OFF, STD_OFF};
    }
    else
    {
      pwmConfigPort.Pin[38] = (Port_ConfigPin){PORT_F, PIN_0, PORT_PIN_OUT, OFF, PORT_PIN_LEVEL_HIGH,  PORT_PIN_MODE_5, STD_OFF, STD_OFF};
    }
    break;
  case PWM_CHANNEL_NUM_1:
    if(ConfigPtr -> tenumOutputStateType == PWM_LOW)
    {
      pwmConfigPort.Pin[25] = (Port_ConfigPin){PORT_D, PIN_1, PORT_PIN_OUT, OFF, PORT_PIN_LEVEL_LOW,  PORT_PIN_MODE_5, STD_OFF, STD_OFF};
    }
    else
    {
      pwmConfigPort.Pin[25] = (Port_ConfigPin){PORT_D, PIN_1, PORT_PIN_OUT, OFF, PORT_PIN_LEVEL_HIGH,  PORT_PIN_MODE_5, STD_OFF, STD_OFF};
    }
    break;
  case PWM_CHANNEL_NUM_2:
    if(ConfigPtr -> tenumOutputStateType == PWM_LOW)
    {
      pwmConfigPort.Pin[6] = (Port_ConfigPin){PORT_A, PIN_6, PORT_PIN_OUT, OFF, PORT_PIN_LEVEL_LOW,  PORT_PIN_MODE_5, STD_OFF, STD_OFF};
    }
    else
    {
      pwmConfigPort.Pin[6] =  (Port_ConfigPin){PORT_A, PIN_6, PORT_PIN_OUT, OFF, PORT_PIN_LEVEL_HIGH,  PORT_PIN_MODE_5, STD_OFF, STD_OFF};
    }
    break;
  case PWM_CHANNEL_NUM_3:
    if(ConfigPtr -> tenumOutputStateType == PWM_LOW)
    {
      pwmConfigPort.Pin[7] = (Port_ConfigPin){PORT_A, PIN_7, PORT_PIN_OUT, OFF, PORT_PIN_LEVEL_LOW,  PORT_PIN_MODE_5, STD_OFF, STD_OFF};
    }
    else
    {
      pwmConfigPort.Pin[7] = (Port_ConfigPin){PORT_A, PIN_7, PORT_PIN_OUT, OFF, PORT_PIN_LEVEL_HIGH,  PORT_PIN_MODE_5, STD_OFF, STD_OFF};
    }
    break;
  case PWM_CHANNEL_NUM_4:
    if(ConfigPtr -> tenumOutputStateType == PWM_LOW)
    {
      pwmConfigPort.Pin[38] = (Port_ConfigPin){PORT_F, PIN_0, PORT_PIN_OUT, OFF, PORT_PIN_LEVEL_LOW,  PORT_PIN_MODE_5, STD_OFF, STD_OFF};
    }
    else
    {
      pwmConfigPort.Pin[38] = (Port_ConfigPin){PORT_F, PIN_0, PORT_PIN_OUT, OFF, PORT_PIN_LEVEL_HIGH,  PORT_PIN_MODE_5, STD_OFF, STD_OFF};
    }
    break;
  case PWM_CHANNEL_NUM_5:
    if(ConfigPtr -> tenumOutputStateType == PWM_LOW)
    {
      pwmConfigPort.Pin[39] = (Port_ConfigPin){PORT_F, PIN_1, PORT_PIN_OUT, OFF, PORT_PIN_LEVEL_LOW,  PORT_PIN_MODE_5, STD_OFF, STD_OFF};
    }
    else
    {
      pwmConfigPort.Pin[39] = (Port_ConfigPin){PORT_F, PIN_1, PORT_PIN_OUT, OFF, PORT_PIN_LEVEL_HIGH,  PORT_PIN_MODE_5, STD_OFF, STD_OFF};
    }
    break;
  case PWM_CHANNEL_NUM_6:
    if(ConfigPtr -> tenumOutputStateType == PWM_LOW)
    {
      pwmConfigPort.Pin[40] = (Port_ConfigPin){PORT_F, PIN_2, PORT_PIN_OUT, OFF, PORT_PIN_LEVEL_LOW,  PORT_PIN_MODE_5, STD_OFF, STD_OFF};
	        	SET_BIT(GPIO_PORTF_PCTL_REG,8);   //Make PF2 output pin
	SET_BIT(GPIO_PORTF_PCTL_REG,10);  //Make PF2 output pin
	SET_BIT(GPIO_PORTF_DEN_REG,2);    //PF2 digital pin
    }
    else
    {
      pwmConfigPort.Pin[40] = (Port_ConfigPin){PORT_F, PIN_2, PORT_PIN_OUT, OFF, PORT_PIN_LEVEL_HIGH,  PORT_PIN_MODE_5, STD_OFF, STD_OFF};
    }
    break;
  case PWM_CHANNEL_NUM_7:
    if(ConfigPtr -> tenumOutputStateType == PWM_LOW)
    {
      pwmConfigPort.Pin[41] = (Port_ConfigPin){PORT_F, PIN_3, PORT_PIN_OUT, OFF, PORT_PIN_LEVEL_LOW,  PORT_PIN_MODE_5, STD_OFF, STD_OFF};
    }
    else
    {
      pwmConfigPort.Pin[41] = (Port_ConfigPin){PORT_F, PIN_3, PORT_PIN_OUT, OFF, PORT_PIN_LEVEL_HIGH,  PORT_PIN_MODE_5, STD_OFF, STD_OFF};
    }
    break;
  default:
    if(ConfigPtr -> tenumOutputStateType == PWM_LOW)
    {
    }
    else
    {
    }
    break;
  }
#endif

    Port_Init(&pwmConfigPort);
    
	//SET_BIT(SYSCTL_RCGCPWM_R,1);          //Enable PWM1 clock  
	//SET_BIT(SYSCTL_RCGCGPIO_R,5);         //Enable CLK for PORTF
	CLEAR_BIT(SYSCTL_RCC_R,20);             //directly feed clk to pwm1 without pre division
	
	/**PORTF Config**/
	//SET_BIT(GPIO_PORTF_AFSEL_REG,2);  //alternate function select for PF2
        //SET_BIT(GPIO_PORTF_AFSEL_REG,7);  //alternate function select for PF0
	//SET_BIT(GPIO_PORTF_PCTL_REG,8);   //Make PF2 output pin
	//SET_BIT(GPIO_PORTF_PCTL_REG,10);  //Make PF2 output pin
	//SET_BIT(GPIO_PORTF_DEN_REG,2);    //PF2 digital pin
        //SET_BIT(GPIO_PORTF_DEN_REG,7);    //PF0 digital pin
	

}
void Pwm_DeInit(void)
{
	CLEAR_BIT(PWM0_0_CTL_R,0);
	CLEAR_BIT(PWM0_1_CTL_R,0);
	CLEAR_BIT(PWM0_2_CTL_R,0);
	CLEAR_BIT(PWM0_3_CTL_R,0);
}
void Pwm_SetDutyCycle(Pwm_ChannelType ChannelNumber, uint16 DutyCycle)
{

}

void Pwm_SetPeriodAndDuty(Pwm_ChannelType ChannelNumber, Pwm_PeriodType Period, uint16 DutyCycle)
{
  switch(ChannelNumber)
  {
    case PWM_CHANNEL_NUM_6:
      CLEAR_BIT(PWM1_3_CTL_R,0);        /* Disable Generator 3 counter */
      CLEAR_BIT(PWM1_3_CTL_R,1);        /* select down count mode of counter 3*/
      PWM1_3_GENA_R = 0x0000008C;       /* Set PWM output to high when counter reloaded and clear when matches PWMCMPA */
      PWM1_3_LOAD_R = Period;           /* set load value for 1kHz (16MHz/16000) */
      PWM1_3_CMPA_R = DutyCycle;        /* set duty cyle to 50% by loading of 16000 to PWM1CMPA */
      SET_BIT(PWM1_3_CTL_R,0);          /* Enable Generator 3 counter */
      PWM1_ENABLE_R = 0x40;             /* Enable PWM1 channel 6 output */
    break;

    case PWM_CHANNEL_NUM_7:
      CLEAR_BIT(PWM1_3_CTL_R,0);        /* Disable Generator 3 counter */
      CLEAR_BIT(PWM1_3_CTL_R,1);        /* select down count mode of counter 3*/
      PWM1_3_GENB_R = 0x0000008C;       /* Set PWM output when counter reloaded and clear when matches PWMCMPB */
      PWM1_3_LOAD_R = Period;           /* set load value for 1kHz (16MHz/16000) */
      PWM1_3_CMPB_R = DutyCycle;        /* set duty cyle to 50% by loading of 16000 to PWM1CMPA */
      SET_BIT(PWM1_3_CTL_R,0);          /* Enable Generator 3 counter */
      PWM1_ENABLE_R = 0x80;             /* Enable PWM1 channel 7 output */
    break;
  }
}

void Pwm_SetOutputToIdle(Pwm_ChannelType ChannelNumber)
{
	Pwm_OutputStateType pwmStates[MAX_PWM_CHANNELS] = {PWM_LOW};
	if (ChannelNumber < MAX_PWM_CHANNELS) 
	{
        pwmStates[ChannelNumber] = PWM_LOW;
    }
	else 
	{		
	}
}
Pwm_OutputStateType Pwm_GetOutputState(Pwm_ChannelType ChannelNumber)
{
	
}
void Pwm_DisableNotification(Pwm_ChannelType ChannelNumber)
{
	
}
void Pwm_EnableNotification(Pwm_ChannelType ChannelNumber, Pwm_EdgeNotificationType Notification)
{
	
}
void Pwm_GetVersionInfo(Std_VersionInfoType* versioninfo)
{
	
}


