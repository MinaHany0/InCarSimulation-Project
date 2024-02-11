/*****************************************************************************************
 *
 * Module: Adc
 * File Name: Adc.c
 * Description: Source file for TM4C123GH6PM Microcontroller - ADC Driver
 * Author:
 *****************************************************************************************/

/*****************************************************************************************
 *
 *  Project                     : Project    
 *  Platform                    : ARM
 *  Peripheral                  : TM4C123GH6PM
 *  Autosar Version             : 4.4.0
 *  Autosar Revision            : ASR_REL_4_0_REV_0000
 *  SW Version                  : 1.0.0
 *****************************************************************************************/

#include "Adc.h"
#include "Adc_Regs.h"

#define REG(BASE,OFFSET) 	(*((volatile uint32 *)(BASE + OFFSET)))

#if (ADC_DEV_ERROR_DETECT == STD_ON)

#include "../../service/det/Det.h"
/* AUTOSAR Version checking between Det and ADC Modules */
#if ((DET_AR_MAJOR_VERSION != ADC_AR_RELEASE_MAJOR_VERSION)\
|| (DET_AR_MINOR_VERSION != ADC_AR_RELEASE_MINOR_VERSION)\
|| (DET_AR_PATCH_VERSION != ADC_AR_RELEASE_PATCH_VERSION))
#error "The AR version of Det.h does not match the expected version"
#endif

#endif

STATIC const Adc_ConfigGroup * Adc_Groups = NULL_PTR;
STATIC uint8 Adc0_Status = ADC_NOT_INITIALIZED;
STATIC uint8 Adc1_Status = ADC_NOT_INITIALIZED;


void Adc_Init(const Adc_ConfigType* ConfigPtr){
	
#if  (ADC_DEV_ERROR_DETECT == STD_ON)

	/* check if the input configuration pointer is not a NULL_PTR */
	if (NULL_PTR == ConfigPtr)
	{
		Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_INIT_SID,ADC_E_PARAM_POINTER);
		return;
	}
	else{
		
	}



	/* Adc_Init has been called while ADC is already initialized */
	for(uint8 Group_num = 0 ; Group_num < ADC_CONFIGURED_GROUP ; Group_num++){
		if((ADC_MODULE_0 == ConfigPtr->Groups[Group_num].Adc_Module_ID)&&(ADC_INITIALIZED == Adc0_Status)){
			Det_ReportError(ADC_MODULE_ID, ADC_MODULE_0, ADC_INIT_SID,ADC_E_ALREADY_INITIALIZED);
			return;
		}
		else if((ADC_MODULE_1 == ConfigPtr->Groups[Group_num].Adc_Module_ID) && (ADC_INITIALIZED == Adc1_Status)){
			Det_ReportError(ADC_MODULE_ID, ADC_MODULE_1, ADC_INIT_SID,ADC_E_ALREADY_INITIALIZED);
			return;
		}
		else	
#endif
	{
		/*
		 * Set the module state to initialized and point to the PB configuration structure using a global pointer.
		 * This global pointer is global to be used by other functions to read the PB configuration structures
		 */
		Adc_Groups = ConfigPtr->Groups; /* address of the first Groups structure --> Groups[0] */
		
		//Loop through Groups for initializing the ADC Groups
		for(uint8 Group_num = 0 ; Group_num < ADC_CONFIGURED_GROUP ; Group_num++){
			
			volatile uint32 * ADC_Module_Ptr = NULL_PTR; /* point to the required ADC base address */
			
			//1. Initialize the Module
			if(ADC_MODULE_0 == Adc_Groups[Group_num].Adc_Module_ID){
				
				ADC_Module_Ptr = (volatile uint32 *)ADC0_BASE_ADDRESS;
				
				if(ADC_NOT_INITIALIZED == Adc0_Status){
					//Enable and provide a clock to ADC module 0 in Run mode
					*((volatile uint32 *)RCGCADC) = 0x0001;
					
					Adc0_Status = ADC_INITIALIZED;
				}
				else{
					
				}		
			}
			else if(ADC_MODULE_1 == Adc_Groups[Group_num].Adc_Module_ID){
				
				ADC_Module_Ptr = (volatile uint32 *)ADC1_BASE_ADDRESS;
				
				if(ADC_NOT_INITIALIZED == Adc1_Status){
			
					//Enable and provide a clock to ADC module 1 in Run mode
					*((volatile uint32 *)RCGCADC) = 0x0002;
					
					Adc1_Status = ADC_INITIALIZED;
				}
				else{
					
				}
				
			}
			else{
				
			}
			
			//2. Select the time Sampling
			*((volatile uint32 *)(ADC_Module_Ptr + ADCPC)) = Adc_Groups[Group_num].Adc_Sampling_Time;
			
			
			switch(Adc_Groups[Group_num].Adc_Module_Sequencer){
				
				case ADC_SEQUENCER_0:
					//3. Disable the sample sequencer 
					REG(ADC_Module_Ptr,ADCACTSS) &= ~(1<< ADC_SEQUENCER_0);
					
					//4. Set the Sequencer priority if exist
					if(ADC_PRIORITY_NONE != Adc_Groups[Group_num].Adc_PrioImplementation){
						REG(ADC_Module_Ptr,ADCSSPRI) &= 0xFFF0;
						REG(ADC_Module_Ptr,ADCSSPRI) = (Adc_Groups[Group_num].Adc_GroupPriority << 4 * ADC_SEQUENCER_0);
					}
					else
					{
						
					}
					
					//5. Choose the Trigger Type
					if(ADC_TRIGG_SRC_SW == Adc_Groups[Group_num].Adc_Group_Trigg_Src){
						REG(ADC_Module_Ptr,ADCEMUX) &= 0xFFF0;
					}
					else{
						
					}
					
					//6. Choose the Channels in the Sequencer *Note: Seq0 can HOLD 8 CHANNELS
					REG(ADC_Module_Ptr,ADCSSMUX0) = 0;
					for(uint8 Ch_num = 0; Ch_num < Adc_Groups[Group_num].Adc_Group_Channel_No ; Ch_num++){
						
						REG(ADC_Module_Ptr,ADCSSMUX0) |= (Adc_Groups[Group_num].Adc_Channels[Ch_num] << Ch_num * 4);
						
					}
					
					//7.
					
					//8. Disable Seq notification / interrupt -> [SWS_Adc_00077] Adc_Init shall disable the notifications
					REG(ADC_Module_Ptr,ADCIM) &= 0xFFFE; // E -> 1110
					
					
					break;
				case ADC_SEQUENCER_1:
					//3. Disable the sample sequencer
					REG(ADC_Module_Ptr,ADCACTSS) = REG(ADC_Module_Ptr,ADCACTSS) & ~(1<< ADC_SEQUENCER_1);
					
					//4. Set the Sequencer priority if exist
					if(ADC_PRIORITY_NONE != Adc_Groups[Group_num].Adc_PrioImplementation){
						REG(ADC_Module_Ptr,ADCSSPRI) = REG(ADC_Module_Ptr,ADCSSPRI) & 0xFF0F;
						REG(ADC_Module_Ptr,ADCSSPRI) = (Adc_Groups[Group_num].Adc_GroupPriority << 4 * ADC_SEQUENCER_1);
					}
					
					//5. Choose the Trigger Type
					if(ADC_TRIGG_SRC_SW == Adc_Groups[Group_num].Adc_Group_Trigg_Src){
						REG(ADC_Module_Ptr,ADCEMUX) = REG(ADC_Module_Ptr,ADCEMUX) & 0xFF0F;
					}
					else{
						
					}
					
					//6. Choose the Channels in the Sequencer *Note: Seq1 can HOLD 4 CHANNELS
					REG(ADC_Module_Ptr,ADCSSMUX1) = 0;
					for(uint8 Ch_num = 0; Ch_num < Adc_Groups[Group_num].Adc_Group_Channel_No ; Ch_num++){
						
						REG(ADC_Module_Ptr,ADCSSMUX1) |= (Adc_Groups[Group_num].Adc_Channels[Ch_num] << Ch_num * 4);
						
					}
					
					//7.
					
					//8. Disable Seq notification / interrupt -> [SWS_Adc_00077] Adc_Init shall disable the notifications
					REG(ADC_Module_Ptr,ADCIM) = REG(ADC_Module_Ptr,ADCIM) & 0xFFFD; // D -> 1101
					
					
					break;
				case ADC_SEQUENCER_2:
					//3. Disable the sample sequencer
					REG(ADC_Module_Ptr,ADCACTSS) = REG(ADC_Module_Ptr,ADCACTSS) & ~(1<< ADC_SEQUENCER_2);
					
					//4. Set the Sequencer priority if exist
					if(ADC_PRIORITY_NONE != Adc_Groups[Group_num].Adc_PrioImplementation){
						REG(ADC_Module_Ptr,ADCSSPRI) = REG(ADC_Module_Ptr,ADCSSPRI) & 0xF0FF;
						REG(ADC_Module_Ptr,ADCSSPRI) = (Adc_Groups[Group_num].Adc_GroupPriority << 4 * ADC_SEQUENCER_2);
					}
					
					//5. Choose the Trigger Type
					if(ADC_TRIGG_SRC_SW == Adc_Groups[Group_num].Adc_Group_Trigg_Src){
						REG(ADC_Module_Ptr,ADCEMUX) = REG(ADC_Module_Ptr,ADCEMUX) & 0xF0FF;
					}
					else{
						
					}
					
					//6. Choose the Channels in the Sequencer *Note: Seq2 can HOLD 4 CHANNELS
					REG(ADC_Module_Ptr,ADCSSMUX2) = 0;
					for(uint8 Ch_num = 0; Ch_num < Adc_Groups[Group_num].Adc_Group_Channel_No ; Ch_num++){
						
						REG(ADC_Module_Ptr,ADCSSMUX2) |= (Adc_Groups[Group_num].Adc_Channels[Ch_num] << Ch_num * 4);
						
					}
					
					//7.
					
					//8. Disable Seq notification / interrupt -> [SWS_Adc_00077] Adc_Init shall disable the notifications
					REG(ADC_Module_Ptr,ADCIM) = REG(ADC_Module_Ptr,ADCIM) & 0xFFFB; //B -> 1011
					
					break;
				case ADC_SEQUENCER_3:
					//3. Disable the sample sequencer
					REG(ADC_Module_Ptr,ADCACTSS) = REG(ADC_Module_Ptr,ADCACTSS) & ~(1<< ADC_SEQUENCER_3);
					
					//4. Set the Sequencer priority if exist
					if(ADC_PRIORITY_NONE != Adc_Groups[Group_num].Adc_PrioImplementation){
						REG(ADC_Module_Ptr,ADCSSPRI) = REG(ADC_Module_Ptr,ADCSSPRI) & 0x0FFF;
						REG(ADC_Module_Ptr,ADCSSPRI) = (Adc_Groups[Group_num].Adc_GroupPriority << 4 * ADC_SEQUENCER_3);
					}
					
					//5. Choose the Trigger Type
					if(ADC_TRIGG_SRC_SW == Adc_Groups[Group_num].Adc_Group_Trigg_Src){
						REG(ADC_Module_Ptr,ADCEMUX) = REG(ADC_Module_Ptr,ADCEMUX) & 0x0FFF;
					}
					else{
						
					}
					
					//6. Choose the Channels in the Sequencer *Note: Seq0 can HOLD 1 CHANNEL
					REG(ADC_Module_Ptr,ADCSSMUX3) = Adc_Groups[Group_num].Adc_Channels[0];
					
					//7.
					
					//8. Disable Seq notification / interrupt -> [SWS_Adc_00077] Adc_Init shall disable the notifications
					REG(ADC_Module_Ptr,ADCIM) = REG(ADC_Module_Ptr,ADCIM) & 0xFFF7; // 7 -> 0111
					
					break;
					
				default: break;
                                
			}
			
			//Choose HW averaging Mode
			REG(ADC_Module_Ptr,ADCSAC) = Adc_Groups[Group_num].Adc_HWOverSampling;
			
			//[SWS_Adc_00307] Adc_Init shall set all groups to ADC_IDLE state
			Adc_GroupStatus[Group_num] = ADC_IDLE;
			
			
		}
		
		
		
		
                }
	
        }
}