#ifndef ADC_CFG_H
#define ADC_CFG_H

/*
 * Module Version 1.0.0
 */
#define ADC_CFG_SW_MAJOR_VERSION              (1U)
#define ADC_CFG_SW_MINOR_VERSION              (0U)
#define ADC_CFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.4
 */
#define ADC_CFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define ADC_CFG_AR_RELEASE_MINOR_VERSION     (0U)
#define ADC_CFG_AR_RELEASE_PATCH_VERSION     (3U)


/* Pre-compile option for Development Error Detect */
#define ADC_DEV_ERROR_DETECT                (STD_ON)

/* Pre-compile option for Version Info API */
#define ADC_VERSION_INFO_API                (STD_ON)

#define ADC_ENABLE_START_STOP_GROUP_API     (STD_ON)

/* Number of Groups */
#define ADC_CONFIGURED_GROUP                (1U)

#define ADC_GROUP0_CHANNELS                 (3U)

#define ADC_GROUP1_CHANNELS

#define ADC_GROUP2_CHANNELS

#define ADC_GROUP3_CHANNELS

/* Adc_Channels Id for TM4C123GH6PM */
#define ADC_CHANNEL_0                           (0u)
#define ADC_CHANNEL_1							(1u)
#define ADC_CHANNEL_2							(2u)
#define ADC_CHANNEL_3 							(3u)
#define ADC_CHANNEL_4							(4u)
#define ADC_CHANNEL_5							(5u)
#define ADC_CHANNEL_6 							(6u)
#define ADC_CHANNEL_7							(7u)
#define ADC_CHANNEL_8							(8u)
#define ADC_CHANNEL_9							(9u)
#define ADC_CHANNEL_10							(10u)
#define ADC_CHANNEL_11	                        (11u)

/* Adc Modules for TM4C123GH6PM */
#define ADC_MODULE_0							(0u)
#define ADC_MODULE_1                            (1u)

/* Adc Sequencers for TM4C123GH6PM */
#define ADC_SEQUENCER_0							(0u)
#define ADC_SEQUENCER_1							(1u)
#define ADC_SEQUENCER_2							(2u)
#define ADC_SEQUENCER_3                         (3u)

/* Adc Groups for TM4C123GH6PM */
#define ADC_GROUP_0							    (0u)
#define ADC_GROUP_1							    (1u)
#define ADC_GROUP_2							    (2u)
#define ADC_GROUP_3							    (3u)

/* Adc Sample Averaging for TM4C123GH6PM */
#define ADC_NoHardwareOverSampling				(0u)
#define ADC_2xHardwareOversampling				(1u)
#define ADC_4xHardwareOversampling				(2u)
#define ADC_8xHardwareOversampling              (3u)
#define ADC_16xHardwareOversampling				(4u)
#define ADC_32xHardwareOversampling				(5u)
#define ADC_64xHardwareOversampling             (6u)

/*GROUP Priority for TM4C123GH6PM*/
#define ADC_GroupPriority_0				        (0u)
#define ADC_GroupPriority_1				        (1u)
#define ADC_GroupPriority_2				        (2u)
#define ADC_GroupPriority_3				        (3u)














#endif /* ADC_CFG_H */