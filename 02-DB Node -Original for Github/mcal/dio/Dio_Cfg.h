 /******************************************************************************
 *
 * Module: Dio
 *
 * File Name: Dio_Cfg.h
 *
 * Description: Pre-Compile Configuration Header file for TM4C123GH6PM Microcontroller - Dio Driver
 *
 * Author: Mohamed Tarek
 ******************************************************************************/

#ifndef DIO_CFG_H
#define DIO_CFG_H

/*
 * Module Version 1.0.0
 */
#define DIO_CFG_SW_MAJOR_VERSION              (1U)
#define DIO_CFG_SW_MINOR_VERSION              (0U)
#define DIO_CFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define DIO_CFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define DIO_CFG_AR_RELEASE_MINOR_VERSION     (0U)
#define DIO_CFG_AR_RELEASE_PATCH_VERSION     (3U)

/* Pre-compile option for Development Error Detect */
#define DIO_DEV_ERROR_DETECT                (STD_ON)

/* Pre-compile option for Version Info API */
#define DIO_VERSION_INFO_API                (STD_OFF)

/* Pre-compile option for presence of Dio_FlipChannel API */
#define DIO_FLIP_CHANNEL_API                (STD_ON)

/* Number of the configured Dio Channels */
#define DIO_CONFIGURED_CHANNLES              (14U)

/* Number of the configured Dio Ports */
#define DIO_CONFIGURED_PORTS                 (6U)

/* Channel Index in the array of structures in Dio_PBcfg.c */
#define DioConf_LED1_CHANNEL_ID_INDEX        (uint8)0x00
#define DioConf_SW1_CHANNEL_ID_INDEX         (uint8)0x01

#define DioConf_LCD_RS_CHANNEL_ID_INDEX      (uint8)0x02
//#define DioConf_LCD_RW_CHANNEL_ID_INDEX      (uint8)0x03
#define DioConf_LCD_E_CHANNEL_ID_INDEX       (uint8)0x03
#define DioConf_LCD_D4_CHANNEL_ID_INDEX      (uint8)0x04
#define DioConf_LCD_D5_CHANNEL_ID_INDEX      (uint8)0x05
#define DioConf_LCD_D6_CHANNEL_ID_INDEX      (uint8)0x06
#define DioConf_LCD_D7_CHANNEL_ID_INDEX      (uint8)0x07

#define DioConf_LCD1_RS_CHANNEL_ID_INDEX      (uint8)0x08
//#define DioConf_LCD_RW_CHANNEL_ID_INDEX      (uint8)0x03
#define DioConf_LCD1_E_CHANNEL_ID_INDEX       (uint8)0x09
#define DioConf_LCD1_D4_CHANNEL_ID_INDEX      (uint8)0x0A
#define DioConf_LCD1_D5_CHANNEL_ID_INDEX      (uint8)0x0B
#define DioConf_LCD1_D6_CHANNEL_ID_INDEX      (uint8)0x0C
#define DioConf_LCD1_D7_CHANNEL_ID_INDEX      (uint8)0x0D

/* DIO Configured Port ID's  */
#define DioConf_LED1_PORT_NUM                (Dio_PortType)5 /* PORTF */
#define DioConf_SW1_PORT_NUM                 (Dio_PortType)5 /* PORTF */

#define DioConf_LCD_RS_PORT_NUM              (Dio_PortType)1 /* PORTB */
//#define DioConf_LCD_RW_PORT_NUM              (Dio_PortType)0 /* PORTA */
#define DioConf_LCD_E_PORT_NUM               (Dio_PortType)1 /* PORTB */
#define DioConf_LCD_DATA_PORT_NUM            (Dio_PortType)1 /* PORTB */

#define DioConf_LCD1_E_PORT_NUM               (Dio_PortType)0 /* PORTA */
#define DioConf_LCD1_RS_PORT_NUM            (Dio_PortType)0 /* PORTA */
#define DioConf_LCD1_DATA_PORT_NUM         (Dio_PortType)0 /* PORTA */

/* DIO Configured Channel ID's */
#define DioConf_LED1_CHANNEL_NUM             (Dio_ChannelType)1 /* Pin 1 in PORTF */
#define DioConf_SW1_CHANNEL_NUM              (Dio_ChannelType)4 /* Pin 4 in PORTF */

#define DioConf_LCD_RS_CHANNEL_NUM              (Dio_ChannelType)0 /* Pin 0 in PORTB */
//#define DioConf_LCD_RW_CHANNEL_NUM              (Dio_ChannelType)3 /* Pin 3 in PORTA */
#define DioConf_LCD_E_CHANNEL_NUM               (Dio_ChannelType)1 /* Pin 1 in PORTB */

#define DioConf_LCD_D4_CHANNEL_NUM               (Dio_ChannelType)2 /* Pin 2 in PORTB */
#define DioConf_LCD_D5_CHANNEL_NUM               (Dio_ChannelType)3 /* Pin 3 in PORTB */
#define DioConf_LCD_D6_CHANNEL_NUM               (Dio_ChannelType)4 /* Pin 4 in PORTB */
#define DioConf_LCD_D7_CHANNEL_NUM               (Dio_ChannelType)5 /* Pin 5 in PORTB */

#define DioConf_LCD1_RS_CHANNEL_NUM              (Dio_ChannelType)2 /* Pin 2 in PORTA */
//#define DioConf_LCD_RW_CHANNEL_NUM              (Dio_ChannelType)3 /* Pin 3 in PORTE */
#define DioConf_LCD1_E_CHANNEL_NUM               (Dio_ChannelType)3 /* Pin 3 in PORTA */

#define DioConf_LCD1_D4_CHANNEL_NUM               (Dio_ChannelType)4 /* Pin 4 in PORTA */
#define DioConf_LCD1_D5_CHANNEL_NUM               (Dio_ChannelType)5 /* Pin 5 in PORTA */
#define DioConf_LCD1_D6_CHANNEL_NUM               (Dio_ChannelType)6 /* Pin 6 in PORTA */
#define DioConf_LCD1_D7_CHANNEL_NUM               (Dio_ChannelType)7 /* Pin 7 in PORTA */

#endif /* DIO_CFG_H */
