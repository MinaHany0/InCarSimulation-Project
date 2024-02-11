/******************************************************************************
 *
 * Module: CanDriver
 *
 * File Name: CanDriver.h
 *
 * Description: Header file for Can Driver
 *
 * Author:
 ******************************************************************************/
#ifndef CANDRIVER_H
#define CANDRIVER_H

#define TARGET_IS_TM4C123_RA1
#define TARGET_IS_BLIZZARD_RA1
#define PART_TM4C123GH6PM 
#define ccs
#define ewarm

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_can.h"
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "driverlib/can.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"

#include "ecual/led/Led.h"
#include "driverlib/interrupt.h"
#include "driverlib/rom.h"
#include "inc/tm4c123gh6pm.h"
#include "driverlib/sysctl.h"


// Message Identifiers and Objects
// RXID is set to 0 so all messages are received
#define RXOBJECT                		0x01
#define TXOBJECT                		0x02
#define MsgID_AcButt_Motor				0x24
#define ObjID_AcButt_Motor				0x05
#define CRASH_SENSOR					g_ui8RX_AcButt_Motor[0]
#define FUEL_VALVE						g_ui8RX_AcButt_Motor[5]
#define TEMP_SENSOR						g_ui8RX_AcButt_Motor[3]

extern volatile uint32_t g_ui32RXMsgCount;
extern volatile uint32_t g_ui32TXMsgCount;
extern volatile bool Flag_AcButt_Motor;
extern volatile uint32_t g_ui32ErrFlag;
extern tCANMsgObject g_sCAN0T_MsgID_AcButt_Motor;
extern uint8_t g_ui8RX_AcButt_Motor[8];

void CANErrorHandler(void);
void CAN0IntHandler(void);
void InitCAN0(void);
#endif /* CANDRIVER_H */
