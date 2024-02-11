/*
 * 
 *
 * Created: 11/20/2023 11:24:52 PM
 * Author : Mina
 */ 

//*****************************************************************************
//
// INCLUDES SECTION
//
//*****************************************************************************

#define TARGET_IS_TM4C123_RA1
#define TARGET_IS_BLIZZARD_RA1
#define PART_TM4C123GH6PM 
#define ccs

//
// registers for CAN loop back mode 
//
#define CAN0_CTL_R              (*((volatile uint32_t *)0x40040000))
#define CAN0_TST_R              (*((volatile uint32_t *)0x40040014))

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_can.h"
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "driverlib/can.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/interrupt.h"
#include "driverlib/rom.h"
#include "inc/tm4c123gh6pm.h"

#include "mcal/dio/Dio.h"
#include "ecual/DashBoard/DashBoard.h"
#include "mcal/port/Port.h"



//*****************************************************************************
//
// A counter that keeps track of the number of times the TX & RX interrupt has
// occurred, which should match the number of messages that were transmitted /
// received.
//
//*****************************************************************************
volatile uint32_t g_ui32RXMsgCount = 0;
volatile uint32_t g_ui32TXMsgCount = 0;

//*****************************************************************************
//
// A flag for the interrupt handler to indicate that a message was received.
//
//*****************************************************************************
volatile bool Flag_ParkUs_DB   		= 0x00;
volatile bool Flag_Lm35_DB			= 0x00;
volatile bool Flag_AcButt_Motor		= 0x00;
volatile bool Flag_SpdEnc_DB		= 0x00;
volatile bool Flag_FrontUs_DB   	= 0x00;


//*****************************************************************************
//
// A global to keep track of the error flags that have been thrown so they may
// be processed. This is necessary because reading the error register clears
// the flags, so it is necessary to save them somewhere for processing.
//
//*****************************************************************************
volatile uint32_t g_ui32ErrFlag = 0;

//*****************************************************************************
//
// CAN message Objects for data being sent / received
//
//*****************************************************************************
tCANMsgObject g_sCAN0R_MsgID_ParkUs_DB;
tCANMsgObject g_sCAN0R_MsgID_Lm35_DB;
tCANMsgObject g_sCAN0T_MsgID_AcButt_Motor;
tCANMsgObject g_sCAN0R_MsgID_SpdEnc_DB;
tCANMsgObject g_sCAN0R_MsgID_FrontUs_DB;   

//*****************************************************************************
//
// Message Identifiers and Objects
// RXID is set to 0 so all messages are received
//
//*****************************************************************************
#define RXOBJECT                		0x01
#define TXOBJECT                		0x02

#define MsgID_ParkUs_DB                	0x12
#define MsgID_Lm35_DB					0x18
#define MsgID_AcButt_Motor				0x24
#define MsgID_SpdEnc_DB					0x30
#define MsgID_FrontUs_DB   	            0x36

#define ObjID_ParkUs_DB                	0x03
#define ObjID_Lm35_DB					0x04
#define ObjID_AcButt_Motor				0x05
#define ObjID_SpdEnc_DB					0x06
#define ObjID_FrontUs_DB   	            0x07

//*****************************************************************************
//
// Variables to hold character being sent / reveived
//
//*****************************************************************************
uint8_t g_ui8RX_AcButt_Motor[8];
uint8_t g_ui8TX_ParkUs_DB[8] 	= {0xAA};
uint8_t g_ui8TX_Lm35_DB[8] 	= {0xBB};
uint8_t g_ui8TX_SpdEnc_DB[8] 	= {0xCC};
uint8_t g_ui8TX_FrontUs_DB[8] 	= {0xDD};

//*****************************************************************************
//
// The error routine that is called if the driver library encounters an error.
//
//*****************************************************************************
#ifdef DEBUG
void
__error__(char *pcFilename, uint32_t ui32Line)
{
}
#endif

void
CANErrorHandler(void);

void 
LED_init(void)
{
    volatile uint32_t ui32Loop;

    //
    // Enable the GPIO port that is used for the on-board LED.
    //
    SYSCTL_RCGC2_R = SYSCTL_RCGC2_GPIOF;

    //
    // Do a dummy read to insert a few cycles after enabling the peripheral.
    //
    ui32Loop = SYSCTL_RCGC2_R;

    //
    // Enable the GPIO pin for the LED (PF3).  Set the direction as output, and
    // enable the GPIO pin for digital function.
    //
    GPIO_PORTF_DIR_R = 0x08 | 0x04 | 0x02;
    GPIO_PORTF_DEN_R = 0x08 | 0x04 | 0x02;
}

void 
LED_G_turnOn(void)
{
        //
        // Turn on the LED.
        //
        GPIO_PORTF_DATA_R |= 0x08;
}

void 
LED_B_turnOn(void)
{
        //
        // Turn on the LED.
        //if
        GPIO_PORTF_DATA_R |= 0x04;
}

void 
LED_R_turnOn(void)
{
        //
        // Turn on the LED.
        //
        GPIO_PORTF_DATA_R |= 0x02;
}

void 
LED_turnOff(void)
{
        //
        // Turn off the LED.
        //
        GPIO_PORTF_DATA_R &= ~(0x08);
        GPIO_PORTF_DATA_R &= ~(0x04);
		GPIO_PORTF_DATA_R &= ~(0x02);
}

void 
Delay(void)
{
	
    volatile uint32_t ui32Loop;
    for(ui32Loop = 0; ui32Loop<1600000; ui32Loop++)
    {
    }
}

//*****************************************************************************
//
// CAN 0 Interrupt Handler. It checks for the cause of the interrupt, and
// maintains a count of all messages that have been transmitted / received
//
//*****************************************************************************
void
CAN0IntHandler(void)
{
    uint32_t ui32Status;

    //
    // Read the CAN interrupt status to find the cause of the interrupt
    //
    // CAN_INT_STS_CAUSE register values
    // 0x0000        = No Interrupt Pending
    // 0x0001-0x0020 = Number of message object that caused the interrupt
    // 0x8000        = Status interrupt
    // all other numbers are reserved and have no meaning in this system
    //
    ui32Status = CANIntStatus(CAN0_BASE, CAN_INT_STS_CAUSE);

    //
    // If this was a status interrupt acknowledge it by reading the CAN
    // controller status register.
    //
    if(ui32Status == CAN_INT_INTID_STATUS)
    {
        //
        // Read the controller status.  This will return a field of status
        // error bits that can indicate various errors. Refer to the
        // API documentation for details about the error status bits.
        // The act of reading this status will clear the interrupt.
        //
        ui32Status = CANStatusGet(CAN0_BASE, CAN_STS_CONTROL);

        //
        // Add ERROR flags to list of current errors. To be handled
        // later, because it would take too much time here in the
        // interrupt.
        //
        g_ui32ErrFlag |= ui32Status;
    }

    //
    // Check if the cause is message object RXOBJECT, which we are using
    // for receiving messages.
    //
    else if(ui32Status == ObjID_AcButt_Motor)
    {
        //
        CANIntClear(CAN0_BASE, ObjID_AcButt_Motor);
        g_ui32RXMsgCount++;
        Flag_AcButt_Motor = true;
        g_ui32ErrFlag = 0;
    }

    //
    // Check if the cause is message object TXOBJECT, which we are using
    // for transmitting messages.
    //
    else if(ui32Status == ObjID_ParkUs_DB)
    {
        //
        // Getting to this point means that the TX interrupt occurred on
        // message object TXOBJECT, and the message reception is complete.
        // Clear the message object interrupt.
        //
        CANIntClear(CAN0_BASE, ObjID_ParkUs_DB);

        //
        // Increment a counter to keep track of how many messages have been
        // transmitted. In a real application this could be used to set
        // flags to indicate when a message is transmitted.
        //
        g_ui32TXMsgCount++;

        //
        // Since a message was transmitted, clear any error flags.
        // This is done because before the message is transmitted it triggers
        // a Status Interrupt for TX complete. by clearing the flag here we
        // prevent unnecessary error handling from happeneing
        //
        g_ui32ErrFlag = 0;
    }
	else if(ui32Status == ObjID_Lm35_DB)
    {
        CANIntClear(CAN0_BASE, ObjID_Lm35_DB);
        g_ui32TXMsgCount++;
        g_ui32ErrFlag = 0;
    }
	else if(ui32Status == ObjID_SpdEnc_DB)
    {
        CANIntClear(CAN0_BASE, ObjID_SpdEnc_DB);
        g_ui32TXMsgCount++;
        g_ui32ErrFlag = 0;
    }
	else if(ui32Status == ObjID_FrontUs_DB)
    {
        CANIntClear(CAN0_BASE, ObjID_FrontUs_DB);
        g_ui32TXMsgCount++;
        g_ui32ErrFlag = 0;
    }

    //
    // Otherwise, something unexpected caused the interrupt.  This should
    // never happen.
    //
    else
    {
        //
        // Spurious interrupt handling can go here.
        //
		CANErrorHandler();
    }
}

//*****************************************************************************
//
// Setup CAN0 to both send and receive at 500KHz.
// Interrupts on
// Use PE4 / PE5
//
//*****************************************************************************
void
InitCAN0(void)
{
    //
    // For this example CAN0 is used with RX and TX pins on port E4 and E5.
    // GPIO port E needs to be enabled so these pins can be used.
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);

    //
    // Configure the GPIO pin muxing to select CAN0 functions for these pins.
    // This step selects which alternate function is available for these pins.
    //
    GPIOPinConfigure(GPIO_PE4_CAN0RX);										
    GPIOPinConfigure(GPIO_PE5_CAN0TX);										

    //
    // Enable the alternate function on the GPIO pins.  The above step selects
    // which alternate function is available.  This step actually enables the
    // alternate function instead of GPIO for these pins.
    //
    GPIOPinTypeCAN(GPIO_PORTE_BASE, GPIO_PIN_4 | GPIO_PIN_5);

    //
    // The GPIO port and pins have been set up for CAN.  The CAN peripheral
    // must be enabled.
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_CAN0);

    //
    // Initialize the CAN controller
    //
    CANInit(CAN0_BASE);

    //
    // Set up the bit rate for the CAN bus.  This function sets up the CAN
    // bus timing for a nominal configuration.  You can achieve more control
    // over the CAN bus timing by using the function CANBitTimingSet() instead
    // of this one, if needed.
    // In this example, the CAN bus is set to 500 kHz.
    //
    CANBitRateSet(CAN0_BASE, SysCtlClockGet(), 650000);
	  
    //
    // Enable interrupts on the CAN peripheral.  This example uses static
    // allocation of interrupt handlers which means the name of the handler
    // is in the vector table of startup code.
    //
    CANIntEnable(CAN0_BASE, CAN_INT_MASTER | CAN_INT_ERROR | CAN_INT_STATUS);

    //
    // Enable the CAN interrupt on the processor (NVIC).
    //
    IntEnable(INT_CAN0);

    //
    // Enable the CAN for operation.
    //
    CANEnable(CAN0_BASE);

    //
    // Initialize a message object to for receiving AC Button state
    //
    g_sCAN0T_MsgID_AcButt_Motor.ui32MsgID = MsgID_AcButt_Motor;
    g_sCAN0T_MsgID_AcButt_Motor.ui32MsgIDMask = 0x1ff;
    g_sCAN0T_MsgID_AcButt_Motor.ui32Flags = MSG_OBJ_RX_INT_ENABLE | MSG_OBJ_USE_ID_FILTER;
    g_sCAN0T_MsgID_AcButt_Motor.ui32MsgLen = sizeof(g_ui8RX_AcButt_Motor);
g_sCAN0T_MsgID_AcButt_Motor.pui8MsgData  = g_ui8RX_AcButt_Motor;
	

    //
    // Now load the message object into the CAN peripheral.  Once loaded the
    // CAN will receive any message on the bus, and an interrupt will occur.
    // Use message object RXOBJECT for receiving messages (this is not the
    //same as the CAN ID which can be any value in this example).
    //	
	CANMessageSet(CAN0_BASE, ObjID_AcButt_Motor, &g_sCAN0T_MsgID_AcButt_Motor, MSG_OBJ_TYPE_RX);
	
	//
    // Initialize a message object to for receiving parking US DB state
    //
    g_sCAN0R_MsgID_ParkUs_DB.ui32MsgID = MsgID_ParkUs_DB;
    g_sCAN0R_MsgID_ParkUs_DB.ui32MsgIDMask = 0x1ff;
    g_sCAN0R_MsgID_ParkUs_DB.ui32Flags = MSG_OBJ_TX_INT_ENABLE;
    g_sCAN0R_MsgID_ParkUs_DB.ui32MsgLen = sizeof(g_ui8TX_ParkUs_DB);
	g_sCAN0R_MsgID_ParkUs_DB.pui8MsgData  = g_ui8TX_ParkUs_DB;
	
	//
    // Initialize a message object to for receiving parking LM35 DB state
    //
    g_sCAN0R_MsgID_Lm35_DB.ui32MsgID = MsgID_Lm35_DB;
    g_sCAN0R_MsgID_Lm35_DB.ui32MsgIDMask = 0x1ff;
    g_sCAN0R_MsgID_Lm35_DB.ui32Flags = MSG_OBJ_TX_INT_ENABLE;
    g_sCAN0R_MsgID_Lm35_DB.ui32MsgLen = sizeof(g_ui8TX_Lm35_DB);
	g_sCAN0R_MsgID_Lm35_DB.pui8MsgData  = g_ui8TX_Lm35_DB;
	
	//
    // Initialize a message object to for receiving parking Speed Encoder DB state
    //
    g_sCAN0R_MsgID_SpdEnc_DB.ui32MsgID = MsgID_SpdEnc_DB;
    g_sCAN0R_MsgID_SpdEnc_DB.ui32MsgIDMask = 0x1ff;
    g_sCAN0R_MsgID_SpdEnc_DB.ui32Flags = MSG_OBJ_TX_INT_ENABLE;
    g_sCAN0R_MsgID_SpdEnc_DB.ui32MsgLen = sizeof(g_ui8TX_SpdEnc_DB);
	g_sCAN0R_MsgID_SpdEnc_DB.pui8MsgData  = g_ui8TX_SpdEnc_DB;
	
	//
    // Initialize a message object to for receiving Front UltraSonic DB State
    //
    g_sCAN0R_MsgID_FrontUs_DB.ui32MsgID = MsgID_FrontUs_DB;
    g_sCAN0R_MsgID_FrontUs_DB.ui32MsgIDMask = 0x1ff;
    g_sCAN0R_MsgID_FrontUs_DB.ui32Flags = MSG_OBJ_TX_INT_ENABLE;
    g_sCAN0R_MsgID_FrontUs_DB.ui32MsgLen = sizeof(g_ui8TX_FrontUs_DB);
	g_sCAN0R_MsgID_FrontUs_DB.pui8MsgData  = g_ui8TX_FrontUs_DB;
	
	
	
}

//*****************************************************************************
//
// Can ERROR handling. When a message is received if there is an erro it is
// saved to g_ui32ErrFlag, the Error Flag Set. Below the flags are checked
// and cleared. It is left up to the user to add handling fuctionality if so
// desiered.
//
// For more information on the error flags please see the CAN section of the
// microcontroller datasheet.
//
// NOTE: you may experience errors during setup when only one board is powered
// on. This is caused by one board sending signals and there not being another
// board there to acknoledge it. Dont worry about these errors, they can be
// disregarded.
//
//*****************************************************************************
void
CANErrorHandler(void)
{
    //
    // CAN controller has entered a Bus Off state.
    //
    if(g_ui32ErrFlag & CAN_STATUS_BUS_OFF)
    {
        //
        // Handle Error Condition here
        //
        //LED_R_turnOn();
        //
        // Clear CAN_STATUS_BUS_OFF Flag
        //
        g_ui32ErrFlag &= ~(CAN_STATUS_BUS_OFF);

    }

    //
    // CAN controller error level has reached warning level.
    //
    if(g_ui32ErrFlag & CAN_STATUS_EWARN)
    {
        //
        // Handle Error Condition here
        //
        //LED_R_turnOn();

        //
        // Clear CAN_STATUS_EWARN Flag
        //
        g_ui32ErrFlag &= ~(CAN_STATUS_EWARN);
    }

    //
    // CAN controller error level has reached error passive level.
    //
    if(g_ui32ErrFlag & CAN_STATUS_EPASS)
    {
        //
        // Handle Error Condition here
        //
		//LED_R_turnOn();
        //
        // Clear CAN_STATUS_EPASS Flag
        //
        g_ui32ErrFlag &= ~(CAN_STATUS_EPASS);
    }

    //
    // A message was received successfully since the last read of this status.
    //
    if(g_ui32ErrFlag & CAN_STATUS_RXOK)
    {
        //
        // Handle Error Condition here
        //
	//	LED_B_turnOn();
        //
        // Clear CAN_STATUS_RXOK Flag
        //
        g_ui32ErrFlag &= ~(CAN_STATUS_RXOK);
    }

    //
    // A message was transmitted successfully since the last read of this
    // status.
    //
    if(g_ui32ErrFlag & CAN_STATUS_TXOK)
    {
        //
        // Handle Error Condition here
        //
		
        //LED_B_turnOn();
        //
        // Clear CAN_STATUS_TXOK Flag
        //
        g_ui32ErrFlag &= ~(CAN_STATUS_TXOK);
    }

    //
    // This is the mask for the last error code field.
    //
    if(g_ui32ErrFlag & CAN_STATUS_LEC_MSK)
    {
        //
        // Handle Error Condition here
        //

        //
        // Clear CAN_STATUS_LEC_MSK Flag
        //
        g_ui32ErrFlag &= ~(CAN_STATUS_LEC_MSK);
    }

    //
    // A bit stuffing error has occurred.
    //
    if(g_ui32ErrFlag & CAN_STATUS_LEC_STUFF)
    {
        //
        // Handle Error Condition here
        //
        //LED_G_turnOn();
        //
        // Clear CAN_STATUS_LEC_STUFF Flag
        //
        g_ui32ErrFlag &= ~(CAN_STATUS_LEC_STUFF);
    }

    //
    // A formatting error has occurred.
    //
    if(g_ui32ErrFlag & CAN_STATUS_LEC_FORM)
    {
        //
        // Handle Error Condition here
        //
        //LED_G_turnOn();
        //
        // Clear CAN_STATUS_LEC_FORM Flag
        //
        g_ui32ErrFlag &= ~(CAN_STATUS_LEC_FORM);
    }

    //
    // An acknowledge error has occurred.
    //
    if(g_ui32ErrFlag & CAN_STATUS_LEC_ACK)
    {
        //
        // Handle Error Condition here
        //
        //LED_G_turnOn();
        //
        // Clear CAN_STATUS_LEC_ACK Flag
        //
        g_ui32ErrFlag &= ~(CAN_STATUS_LEC_ACK);
    }

    //
    // The bus remained a bit level of 1 for longer than is allowed.
    //
    if(g_ui32ErrFlag & CAN_STATUS_LEC_BIT1)
    {
        //
        // Handle Error Condition here
        //
        //LED_G_turnOn();
        //
        // Clear CAN_STATUS_LEC_BIT1 Flag
        //
        g_ui32ErrFlag &= ~(CAN_STATUS_LEC_BIT1);
    }

    //
    // The bus remained a bit level of 0 for longer than is allowed.
    //
    if(g_ui32ErrFlag & CAN_STATUS_LEC_BIT0)
    {
        //
        // Handle Error Condition here
        //
        //LED_G_turnOn();
        //
        // Clear CAN_STATUS_LEC_BIT0 Flag
        //
        g_ui32ErrFlag &= ~(CAN_STATUS_LEC_BIT0);
    }

    //
    // A CRC error has occurred.
    //
    if(g_ui32ErrFlag & CAN_STATUS_LEC_CRC)
    {
        //
        // Handle Error Condition here
        //
        //LED_G_turnOn();
        //
        // Clear CAN_STATUS_LEC_CRC Flag
        //
        g_ui32ErrFlag &= ~(CAN_STATUS_LEC_CRC);
    }

    //
    // This is the mask for the CAN Last Error Code (LEC).
    //
    if(g_ui32ErrFlag & CAN_STATUS_LEC_MASK)
    {
        //
        // Handle Error Condition here
        //
	
        //
        // Clear CAN_STATUS_LEC_MASK Flag
        //
        g_ui32ErrFlag &= ~(CAN_STATUS_LEC_MASK);
    }

    //
    // If there are any bits still set in g_ui32ErrFlag then something unhandled
    // has happened. Print the value of g_ui32ErrFlag.
    //
    if(g_ui32ErrFlag !=0)
    {
		//LED_G_turnOn();
    }
}
int main(void)
{	
	//
    // Set the clocking to run directly from the crystal.
    //
    ROM_SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ |
                       SYSCTL_OSC_MAIN);
	
	//
    // Initialize CAN0
    //
    InitCAN0();
	Port_Init(&Port_PinConfig);
	Dio_Init(&Dio_Configuration);
	DashBoard_Initialization();
	
	
	
	while(1)
	{
		
		
		//
        // If the flag is set, that means that the RX interrupt occurred and
        // there is a message ready to be read from the CAN
        //
		if(Flag_AcButt_Motor)
		{
			//
			// Clear the pending message flag so that the interrupt handler can
			// set it again when the next message arrives.
			//
			Flag_AcButt_Motor = 0;			
			
			//
			// Retrieve the received message
			//
    		CANMessageGet(CAN0_BASE, ObjID_AcButt_Motor, &g_sCAN0T_MsgID_AcButt_Motor, MSG_OBJ_TYPE_RX);
			//if(g_ui8RX_AcButt_Motor[0] == 0xAA)
			//{
			//	LED_R_turnOn();
			//}
			//else if(g_ui8RX_AcButt_Motor[0] == 0xBB)
			//{
			//	LED_turnOff();
			//}

		}
		else
        {
            //
            // Error Handling
            //
            if(g_ui32ErrFlag != 0)
            {
                CANErrorHandler();
            }
		}
		
		
		
		DashBoard_DISTANCE_Display(g_ui8RX_AcButt_Motor[0],g_ui8RX_AcButt_Motor[1]);
		DashBoard_TEMP_SPD_AC_Display(g_ui8RX_AcButt_Motor[3],g_ui8RX_AcButt_Motor[2],1);
	}	  
}