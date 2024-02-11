/******************************************************************************
*
* Module: Adc
*
* File Name: Adc_PBCfg.C
*
* Description: Post build configure source file for TM4C123GH6PM Microcontroller - Adc Driver.
*
* Author: 
******************************************************************************/

#include "Adc.h"
#include "Adc_Cfg.h"

/*
*Module version 1.0.0
*/
#define ADC_PBCFG_SW_MAJOR_VERSION (1U)
#define ADC_PBCFG_SW_MINOR_VERSION (0U)
#define ADC_PBCFG_SW_PACTH_VERSION (0U)

/*
*AUTOSAR version 4.0.4
*/
#define ADC_PBCFG_AR_RELEASE_MAJOR_VERSION (4U)
#define ADC_PBCFG_AR_RELEASE_MINOR_VERSION (0U)
#define ADC_PBCFG_AR_RELEASE_PATCH_VERSION (3U)

/* AUTOSAR Version checking between Adc_PBcfg.c and Adc.h files */
#if ((ADC_PBCFG_AR_RELEASE_MAJOR_VERSION != ADC_AR_RELEASE_MAJOR_VERSION)\
||  (ADC_PBCFG_AR_RELEASE_MINOR_VERSION != ADC_AR_RELEASE_MINOR_VERSION)\
||  (ADC_PBCFG_AR_RELEASE_PATCH_VERSION != ADC_AR_RELEASE_PATCH_VERSION))
#error "The AR version of PBcfg.c does not match the expected version"
#endif

/* Software Version checking between Adc_PBcfg.c and Adc.h files */
#if ((ADC_PBCFG_SW_MAJOR_VERSION != ADC_SW_MAJOR_VERSION)\
||  (ADC_PBCFG_SW_MINOR_VERSION != ADC_SW_MINOR_VERSION)\
||  (ADC_PBCFG_SW_PACTH_VERSION != ADC_SW_PATCH_VERSION))
#error "The SW version of PBcfg.c does not match the expected version"
#endif

Adc_ChannelType Adc_Group0_Channels[ADC_GROUP0_CHANNELS] = {ADC_CHANNEL_0 , ADC_CHANNEL_1, ADC_CHANNEL_2};
	
Adc_ValueGroupType Adc_Group0_Buffers[ADC_GROUP0_CHANNELS];

Adc_StatusType Adc_GroupStatus[ADC_CONFIGURED_GROUP]=
{
	/* ADC_IDLE */ 
	/* The conversion of the specified group has not been started. - 
	No result is available.*/
	ADC_IDLE,
};

const Adc_ConfigType Adc_Configuration = {
.Groups[0].Adc_Module_ID			=ADC_MODULE_0,
.Groups[0].Adc_Module_Sequencer		=ADC_SEQUENCER_0,
.Groups[0].Adc_Module_Group_ID		=ADC_GROUP_0,
.Groups[0].Adc_Group_Channel_No		=ADC_GROUP0_CHANNELS,
.Groups[0].Adc_Channels				=Adc_Group0_Channels,
.Groups[0].Adc_Group_Buffer			=Adc_Group0_Buffers,
.Groups[0].Adc_Group_Trigg_Src		=ADC_TRIGG_SRC_SW,
.Groups[0].Adc_Resolution			=12,
.Groups[0].Adc_HWOverSampling		=ADC_NoHardwareOverSampling,
.Groups[0].Adc_Sampling_Time      	=KS_125,
.Groups[0].Adc_GroupConv			=ADC_CONV_MODE_ONESHOT,
.Groups[0].Adc_GroupPriority		=ADC_GroupPriority_0,
.Groups[0].Adc_StreamBufferMode		=ADC_STREAM_BUFFER_LINEAR,
.Groups[0].Adc_GroupAccessMode		=ADC_ACCESS_MODE_SINGLE,
.Groups[0].Adc_HwTrigger			=ADC_HW_TRIG_RISING_EDGE,
.Groups[0].Adc_PrioImplementation	=ADC_PRIORITY_HW,
.Groups[0].Adc_GroupReplacement		=ADC_GROUP_REPL_ABORT_RESTART,
.Groups[0].Adc_ChannelRangeSelect	=ADC_RANGE_ALWAYS,
.Groups[0].Adc_ResultAlignment 		=ADC_ALIGN_RIGHT,
.Groups[0].Adc_PowerState			=ADC_FULL_POWER,
};