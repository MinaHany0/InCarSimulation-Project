#ifndef TM4C123GH6PM_REGISTERS
#define TM4C123GH6PM_REGISTERS

#include "Std_Types.h"

/*****************************************************************************
GPIO registers (PORTA)
*****************************************************************************/
#define GPIO_PORTA_DATA_REG       (*((volatile uint32 *)0x400043FC))
#define GPIO_PORTA_DIR_REG        (*((volatile uint32 *)0x40004400))
#define GPIO_PORTA_AFSEL_REG      (*((volatile uint32 *)0x40004420))
#define GPIO_PORTA_PUR_REG        (*((volatile uint32 *)0x40004510))
#define GPIO_PORTA_PDR_REG        (*((volatile uint32 *)0x40004514))
#define GPIO_PORTA_DEN_REG        (*((volatile uint32 *)0x4000451C))
#define GPIO_PORTA_LOCK_REG       (*((volatile uint32 *)0x40004520))
#define GPIO_PORTA_CR_REG         (*((volatile uint32 *)0x40004524))
#define GPIO_PORTA_AMSEL_REG      (*((volatile uint32 *)0x40004528))
#define GPIO_PORTA_PCTL_REG       (*((volatile uint32 *)0x4000452C))

/* PORTA External Interrupts Registers */
#define GPIO_PORTA_IS_REG         (*((volatile uint32 *)0x40004404))
#define GPIO_PORTA_IBE_REG        (*((volatile uint32 *)0x40004408))
#define GPIO_PORTA_IEV_REG        (*((volatile uint32 *)0x4000440C))
#define GPIO_PORTA_IM_REG         (*((volatile uint32 *)0x40004410))
#define GPIO_PORTA_RIS_REG        (*((volatile uint32 *)0x40004414))
#define GPIO_PORTA_ICR_REG        (*((volatile uint32 *)0x4000441C))

/*****************************************************************************
GPIO registers (PORTB)
*****************************************************************************/
#define GPIO_PORTB_DATA_REG       (*((volatile uint32 *)0x400053FC))
#define GPIO_PORTB_DIR_REG        (*((volatile uint32 *)0x40005400))
#define GPIO_PORTB_AFSEL_REG      (*((volatile uint32 *)0x40005420))
#define GPIO_PORTB_PUR_REG        (*((volatile uint32 *)0x40005510))
#define GPIO_PORTB_PDR_REG        (*((volatile uint32 *)0x40005514))
#define GPIO_PORTB_DEN_REG        (*((volatile uint32 *)0x4000551C))
#define GPIO_PORTB_LOCK_REG       (*((volatile uint32 *)0x40005520))
#define GPIO_PORTB_CR_REG         (*((volatile uint32 *)0x40005524))
#define GPIO_PORTB_AMSEL_REG      (*((volatile uint32 *)0x40005528))
#define GPIO_PORTB_PCTL_REG       (*((volatile uint32 *)0x4000552C))

/* PORTB External Interrupts Registers */
#define GPIO_PORTB_IS_REG         (*((volatile uint32 *)0x40005404))
#define GPIO_PORTB_IBE_REG        (*((volatile uint32 *)0x40005408))
#define GPIO_PORTB_IEV_REG        (*((volatile uint32 *)0x4000540C))
#define GPIO_PORTB_IM_REG         (*((volatile uint32 *)0x40005410))
#define GPIO_PORTB_RIS_REG        (*((volatile uint32 *)0x40005414))
#define GPIO_PORTB_ICR_REG        (*((volatile uint32 *)0x4000541C))

/*****************************************************************************
GPIO registers (PORTC)
*****************************************************************************/
#define GPIO_PORTC_DATA_REG       (*((volatile uint32 *)0x400063FC))
#define GPIO_PORTC_DIR_REG        (*((volatile uint32 *)0x40006400))
#define GPIO_PORTC_AFSEL_REG      (*((volatile uint32 *)0x40006420))
#define GPIO_PORTC_PUR_REG        (*((volatile uint32 *)0x40006510))
#define GPIO_PORTC_PDR_REG        (*((volatile uint32 *)0x40006514))
#define GPIO_PORTC_DEN_REG        (*((volatile uint32 *)0x4000651C))
#define GPIO_PORTC_LOCK_REG       (*((volatile uint32 *)0x40006520))
#define GPIO_PORTC_CR_REG         (*((volatile uint32 *)0x40006524))
#define GPIO_PORTC_AMSEL_REG      (*((volatile uint32 *)0x40006528))
#define GPIO_PORTC_PCTL_REG       (*((volatile uint32 *)0x4000652C))

/* PORTC External Interrupts Registers */
#define GPIO_PORTC_IS_REG         (*((volatile uint32 *)0x40006404))
#define GPIO_PORTC_IBE_REG        (*((volatile uint32 *)0x40006408))
#define GPIO_PORTC_IEV_REG        (*((volatile uint32 *)0x4000640C))
#define GPIO_PORTC_IM_REG         (*((volatile uint32 *)0x40006410))
#define GPIO_PORTC_RIS_REG        (*((volatile uint32 *)0x40006414))
#define GPIO_PORTC_ICR_REG        (*((volatile uint32 *)0x4000641C))

/*****************************************************************************
GPIO registers (PORTD)
*****************************************************************************/
#define GPIO_PORTD_DATA_REG       (*((volatile uint32 *)0x400073FC))
#define GPIO_PORTD_DIR_REG        (*((volatile uint32 *)0x40007400))
#define GPIO_PORTD_AFSEL_REG      (*((volatile uint32 *)0x40007420))
#define GPIO_PORTD_PUR_REG        (*((volatile uint32 *)0x40007510))
#define GPIO_PORTD_PDR_REG        (*((volatile uint32 *)0x40007514))
#define GPIO_PORTD_DEN_REG        (*((volatile uint32 *)0x4000751C))
#define GPIO_PORTD_LOCK_REG       (*((volatile uint32 *)0x40007520))
#define GPIO_PORTD_CR_REG         (*((volatile uint32 *)0x40007524))
#define GPIO_PORTD_AMSEL_REG      (*((volatile uint32 *)0x40007528))
#define GPIO_PORTD_PCTL_REG       (*((volatile uint32 *)0x4000752C))

/* PORTD External Interrupts Registers */
#define GPIO_PORTD_IS_REG         (*((volatile uint32 *)0x40007404))
#define GPIO_PORTD_IBE_REG        (*((volatile uint32 *)0x40007408))
#define GPIO_PORTD_IEV_REG        (*((volatile uint32 *)0x4000740C))
#define GPIO_PORTD_IM_REG         (*((volatile uint32 *)0x40007410))
#define GPIO_PORTD_RIS_REG        (*((volatile uint32 *)0x40007414))
#define GPIO_PORTD_ICR_REG        (*((volatile uint32 *)0x4000741C))

/*****************************************************************************
GPIO registers (PORTE)
*****************************************************************************/
#define GPIO_PORTE_DATA_REG       (*((volatile uint32 *)0x400243FC))
#define GPIO_PORTE_DIR_REG        (*((volatile uint32 *)0x40024400))
#define GPIO_PORTE_AFSEL_REG      (*((volatile uint32 *)0x40024420))
#define GPIO_PORTE_PUR_REG        (*((volatile uint32 *)0x40024510))
#define GPIO_PORTE_PDR_REG        (*((volatile uint32 *)0x40024514))
#define GPIO_PORTE_DEN_REG        (*((volatile uint32 *)0x4002451C))
#define GPIO_PORTE_LOCK_REG       (*((volatile uint32 *)0x40024520))
#define GPIO_PORTE_CR_REG         (*((volatile uint32 *)0x40024524))
#define GPIO_PORTE_AMSEL_REG      (*((volatile uint32 *)0x40024528))
#define GPIO_PORTE_PCTL_REG       (*((volatile uint32 *)0x4002452C))

/* PORTE External Interrupts Registers */
#define GPIO_PORTE_IS_REG         (*((volatile uint32 *)0x40024404))
#define GPIO_PORTE_IBE_REG        (*((volatile uint32 *)0x40024408))
#define GPIO_PORTE_IEV_REG        (*((volatile uint32 *)0x4002440C))
#define GPIO_PORTE_IM_REG         (*((volatile uint32 *)0x40024410))
#define GPIO_PORTE_RIS_REG        (*((volatile uint32 *)0x40024414))
#define GPIO_PORTE_ICR_REG        (*((volatile uint32 *)0x4002441C))

/*****************************************************************************
GPIO registers (PORTF)
*****************************************************************************/
#define GPIO_PORTF_DATA_REG       (*((volatile uint32 *)0x400253FC))
#define GPIO_PORTF_DIR_REG        (*((volatile uint32 *)0x40025400))
#define GPIO_PORTF_AFSEL_REG      (*((volatile uint32 *)0x40025420))
#define GPIO_PORTF_PUR_REG        (*((volatile uint32 *)0x40025510))
#define GPIO_PORTF_PDR_REG        (*((volatile uint32 *)0x40025514))
#define GPIO_PORTF_DEN_REG        (*((volatile uint32 *)0x4002551C))
#define GPIO_PORTF_LOCK_REG       (*((volatile uint32 *)0x40025520))
#define GPIO_PORTF_CR_REG         (*((volatile uint32 *)0x40025524))
#define GPIO_PORTF_AMSEL_REG      (*((volatile uint32 *)0x40025528))
#define GPIO_PORTF_PCTL_REG       (*((volatile uint32 *)0x4002552C))

/* PORTF External Interrupts Registers */
#define GPIO_PORTF_IS_REG         (*((volatile uint32 *)0x40025404))
#define GPIO_PORTF_IBE_REG        (*((volatile uint32 *)0x40025408))
#define GPIO_PORTF_IEV_REG        (*((volatile uint32 *)0x4002540C))
#define GPIO_PORTF_IM_REG         (*((volatile uint32 *)0x40025410))
#define GPIO_PORTF_RIS_REG        (*((volatile uint32 *)0x40025414))
#define GPIO_PORTF_ICR_REG        (*((volatile uint32 *)0x4002541C))
#define SYSCTL_REGCGC2_REG        (*((volatile uint32 *)0x400FE108))
//*****************************************************************************
//
// PWM registers (PWM0)
//
//*****************************************************************************
#define PWM0_CTL_R              (*((volatile uint32 *)0x40028000))
#define PWM0_SYNC_R             (*((volatile uint32 *)0x40028004))
#define PWM0_ENABLE_R           (*((volatile uint32 *)0x40028008))
#define PWM0_INVERT_R           (*((volatile uint32 *)0x4002800C))
#define PWM0_FAULT_R            (*((volatile uint32 *)0x40028010))
#define PWM0_INTEN_R            (*((volatile uint32 *)0x40028014))
#define PWM0_RIS_R              (*((volatile uint32 *)0x40028018))
#define PWM0_ISC_R              (*((volatile uint32 *)0x4002801C))
#define PWM0_STATUS_R           (*((volatile uint32 *)0x40028020))
#define PWM0_FAULTVAL_R         (*((volatile uint32 *)0x40028024))
#define PWM0_ENUPD_R            (*((volatile uint32 *)0x40028028))
#define PWM0_0_CTL_R            (*((volatile uint32 *)0x40028040))
#define PWM0_0_INTEN_R          (*((volatile uint32 *)0x40028044))
#define PWM0_0_RIS_R            (*((volatile uint32 *)0x40028048))
#define PWM0_0_ISC_R            (*((volatile uint32 *)0x4002804C))
#define PWM0_0_LOAD_R           (*((volatile uint32 *)0x40028050))
#define PWM0_0_COUNT_R          (*((volatile uint32 *)0x40028054))
#define PWM0_0_CMPA_R           (*((volatile uint32 *)0x40028058))
#define PWM0_0_CMPB_R           (*((volatile uint32 *)0x4002805C))
#define PWM0_0_GENA_R           (*((volatile uint32 *)0x40028060))
#define PWM0_0_GENB_R           (*((volatile uint32 *)0x40028064))
#define PWM0_0_DBCTL_R          (*((volatile uint32 *)0x40028068))
#define PWM0_0_DBRISE_R         (*((volatile uint32 *)0x4002806C))
#define PWM0_0_DBFALL_R         (*((volatile uint32 *)0x40028070))
#define PWM0_0_FLTSRC0_R        (*((volatile uint32 *)0x40028074))
#define PWM0_0_FLTSRC1_R        (*((volatile uint32 *)0x40028078))
#define PWM0_0_MINFLTPER_R      (*((volatile uint32 *)0x4002807C))
#define PWM0_1_CTL_R            (*((volatile uint32 *)0x40028080))
#define PWM0_1_INTEN_R          (*((volatile uint32 *)0x40028084))
#define PWM0_1_RIS_R            (*((volatile uint32 *)0x40028088))
#define PWM0_1_ISC_R            (*((volatile uint32 *)0x4002808C))
#define PWM0_1_LOAD_R           (*((volatile uint32 *)0x40028090))
#define PWM0_1_COUNT_R          (*((volatile uint32 *)0x40028094))
#define PWM0_1_CMPA_R           (*((volatile uint32 *)0x40028098))
#define PWM0_1_CMPB_R           (*((volatile uint32 *)0x4002809C))
#define PWM0_1_GENA_R           (*((volatile uint32 *)0x400280A0))
#define PWM0_1_GENB_R           (*((volatile uint32 *)0x400280A4))
#define PWM0_1_DBCTL_R          (*((volatile uint32 *)0x400280A8))
#define PWM0_1_DBRISE_R         (*((volatile uint32 *)0x400280AC))
#define PWM0_1_DBFALL_R         (*((volatile uint32 *)0x400280B0))
#define PWM0_1_FLTSRC0_R        (*((volatile uint32 *)0x400280B4))
#define PWM0_1_FLTSRC1_R        (*((volatile uint32 *)0x400280B8))
#define PWM0_1_MINFLTPER_R      (*((volatile uint32 *)0x400280BC))
#define PWM0_2_CTL_R            (*((volatile uint32 *)0x400280C0))
#define PWM0_2_INTEN_R          (*((volatile uint32 *)0x400280C4))
#define PWM0_2_RIS_R            (*((volatile uint32 *)0x400280C8))
#define PWM0_2_ISC_R            (*((volatile uint32 *)0x400280CC))
#define PWM0_2_LOAD_R           (*((volatile uint32 *)0x400280D0))
#define PWM0_2_COUNT_R          (*((volatile uint32 *)0x400280D4))
#define PWM0_2_CMPA_R           (*((volatile uint32 *)0x400280D8))
#define PWM0_2_CMPB_R           (*((volatile uint32 *)0x400280DC))
#define PWM0_2_GENA_R           (*((volatile uint32 *)0x400280E0))
#define PWM0_2_GENB_R           (*((volatile uint32 *)0x400280E4))
#define PWM0_2_DBCTL_R          (*((volatile uint32 *)0x400280E8))
#define PWM0_2_DBRISE_R         (*((volatile uint32 *)0x400280EC))
#define PWM0_2_DBFALL_R         (*((volatile uint32 *)0x400280F0))
#define PWM0_2_FLTSRC0_R        (*((volatile uint32 *)0x400280F4))
#define PWM0_2_FLTSRC1_R        (*((volatile uint32 *)0x400280F8))
#define PWM0_2_MINFLTPER_R      (*((volatile uint32 *)0x400280FC))
#define PWM0_3_CTL_R            (*((volatile uint32 *)0x40028100))
#define PWM0_3_INTEN_R          (*((volatile uint32 *)0x40028104))
#define PWM0_3_RIS_R            (*((volatile uint32 *)0x40028108))
#define PWM0_3_ISC_R            (*((volatile uint32 *)0x4002810C))
#define PWM0_3_LOAD_R           (*((volatile uint32 *)0x40028110))
#define PWM0_3_COUNT_R          (*((volatile uint32 *)0x40028114))
#define PWM0_3_CMPA_R           (*((volatile uint32 *)0x40028118))
#define PWM0_3_CMPB_R           (*((volatile uint32 *)0x4002811C))
#define PWM0_3_GENA_R           (*((volatile uint32 *)0x40028120))
#define PWM0_3_GENB_R           (*((volatile uint32 *)0x40028124))
#define PWM0_3_DBCTL_R          (*((volatile uint32 *)0x40028128))
#define PWM0_3_DBRISE_R         (*((volatile uint32 *)0x4002812C))
#define PWM0_3_DBFALL_R         (*((volatile uint32 *)0x40028130))
#define PWM0_3_FLTSRC0_R        (*((volatile uint32 *)0x40028134))
#define PWM0_3_FLTSRC1_R        (*((volatile uint32 *)0x40028138))
#define PWM0_3_MINFLTPER_R      (*((volatile uint32 *)0x4002813C))
#define PWM0_0_FLTSEN_R         (*((volatile uint32 *)0x40028800))
#define PWM0_0_FLTSTAT0_R       (*((volatile uint32 *)0x40028804))
#define PWM0_0_FLTSTAT1_R       (*((volatile uint32 *)0x40028808))
#define PWM0_1_FLTSEN_R         (*((volatile uint32 *)0x40028880))
#define PWM0_1_FLTSTAT0_R       (*((volatile uint32 *)0x40028884))
#define PWM0_1_FLTSTAT1_R       (*((volatile uint32 *)0x40028888))
#define PWM0_2_FLTSTAT0_R       (*((volatile uint32 *)0x40028904))
#define PWM0_2_FLTSTAT1_R       (*((volatile uint32 *)0x40028908))
#define PWM0_3_FLTSTAT0_R       (*((volatile uint32 *)0x40028984))
#define PWM0_3_FLTSTAT1_R       (*((volatile uint32 *)0x40028988))
#define PWM0_PP_R               (*((volatile uint32 *)0x40028FC0))

//*****************************************************************************
//
// PWM registers (PWM1)
//
//*****************************************************************************
#define PWM1_CTL_R              (*((volatile uint32 *)0x40029000))
#define PWM1_SYNC_R             (*((volatile uint32 *)0x40029004))
#define PWM1_ENABLE_R           (*((volatile uint32 *)0x40029008))
#define PWM1_INVERT_R           (*((volatile uint32 *)0x4002900C))
#define PWM1_FAULT_R            (*((volatile uint32 *)0x40029010))
#define PWM1_INTEN_R            (*((volatile uint32 *)0x40029014))
#define PWM1_RIS_R              (*((volatile uint32 *)0x40029018))
#define PWM1_ISC_R              (*((volatile uint32 *)0x4002901C))
#define PWM1_STATUS_R           (*((volatile uint32 *)0x40029020))
#define PWM1_FAULTVAL_R         (*((volatile uint32 *)0x40029024))
#define PWM1_ENUPD_R            (*((volatile uint32 *)0x40029028))
#define PWM1_0_CTL_R            (*((volatile uint32 *)0x40029040))
#define PWM1_0_INTEN_R          (*((volatile uint32 *)0x40029044))
#define PWM1_0_RIS_R            (*((volatile uint32 *)0x40029048))
#define PWM1_0_ISC_R            (*((volatile uint32 *)0x4002904C))
#define PWM1_0_LOAD_R           (*((volatile uint32 *)0x40029050))
#define PWM1_0_COUNT_R          (*((volatile uint32 *)0x40029054))
#define PWM1_0_CMPA_R           (*((volatile uint32 *)0x40029058))
#define PWM1_0_CMPB_R           (*((volatile uint32 *)0x4002905C))
#define PWM1_0_GENA_R           (*((volatile uint32 *)0x40029060))
#define PWM1_0_GENB_R           (*((volatile uint32 *)0x40029064))
#define PWM1_0_DBCTL_R          (*((volatile uint32 *)0x40029068))
#define PWM1_0_DBRISE_R         (*((volatile uint32 *)0x4002906C))
#define PWM1_0_DBFALL_R         (*((volatile uint32 *)0x40029070))
#define PWM1_0_FLTSRC0_R        (*((volatile uint32 *)0x40029074))
#define PWM1_0_FLTSRC1_R        (*((volatile uint32 *)0x40029078))
#define PWM1_0_MINFLTPER_R      (*((volatile uint32 *)0x4002907C))
#define PWM1_1_CTL_R            (*((volatile uint32 *)0x40029080))
#define PWM1_1_INTEN_R          (*((volatile uint32 *)0x40029084))
#define PWM1_1_RIS_R            (*((volatile uint32 *)0x40029088))
#define PWM1_1_ISC_R            (*((volatile uint32 *)0x4002908C))
#define PWM1_1_LOAD_R           (*((volatile uint32 *)0x40029090))
#define PWM1_1_COUNT_R          (*((volatile uint32 *)0x40029094))
#define PWM1_1_CMPA_R           (*((volatile uint32 *)0x40029098))
#define PWM1_1_CMPB_R           (*((volatile uint32 *)0x4002909C))
#define PWM1_1_GENA_R           (*((volatile uint32 *)0x400290A0))
#define PWM1_1_GENB_R           (*((volatile uint32 *)0x400290A4))
#define PWM1_1_DBCTL_R          (*((volatile uint32 *)0x400290A8))
#define PWM1_1_DBRISE_R         (*((volatile uint32 *)0x400290AC))
#define PWM1_1_DBFALL_R         (*((volatile uint32 *)0x400290B0))
#define PWM1_1_FLTSRC0_R        (*((volatile uint32 *)0x400290B4))
#define PWM1_1_FLTSRC1_R        (*((volatile uint32 *)0x400290B8))
#define PWM1_1_MINFLTPER_R      (*((volatile uint32 *)0x400290BC))
#define PWM1_2_CTL_R            (*((volatile uint32 *)0x400290C0))
#define PWM1_2_INTEN_R          (*((volatile uint32 *)0x400290C4))
#define PWM1_2_RIS_R            (*((volatile uint32 *)0x400290C8))
#define PWM1_2_ISC_R            (*((volatile uint32 *)0x400290CC))
#define PWM1_2_LOAD_R           (*((volatile uint32 *)0x400290D0))
#define PWM1_2_COUNT_R          (*((volatile uint32 *)0x400290D4))
#define PWM1_2_CMPA_R           (*((volatile uint32 *)0x400290D8))
#define PWM1_2_CMPB_R           (*((volatile uint32 *)0x400290DC))
#define PWM1_2_GENA_R           (*((volatile uint32 *)0x400290E0))
#define PWM1_2_GENB_R           (*((volatile uint32 *)0x400290E4))
#define PWM1_2_DBCTL_R          (*((volatile uint32 *)0x400290E8))
#define PWM1_2_DBRISE_R         (*((volatile uint32 *)0x400290EC))
#define PWM1_2_DBFALL_R         (*((volatile uint32 *)0x400290F0))
#define PWM1_2_FLTSRC0_R        (*((volatile uint32 *)0x400290F4))
#define PWM1_2_FLTSRC1_R        (*((volatile uint32 *)0x400290F8))
#define PWM1_2_MINFLTPER_R      (*((volatile uint32 *)0x400290FC))
#define PWM1_3_CTL_R            (*((volatile uint32 *)0x40029100))
#define PWM1_3_INTEN_R          (*((volatile uint32 *)0x40029104))
#define PWM1_3_RIS_R            (*((volatile uint32 *)0x40029108))
#define PWM1_3_ISC_R            (*((volatile uint32 *)0x4002910C))
#define PWM1_3_LOAD_R           (*((volatile uint32 *)0x40029110))
#define PWM1_3_COUNT_R          (*((volatile uint32 *)0x40029114))
#define PWM1_3_CMPA_R           (*((volatile uint32 *)0x40029118))
#define PWM1_3_CMPB_R           (*((volatile uint32 *)0x4002911C))
#define PWM1_3_GENA_R           (*((volatile uint32 *)0x40029120))
#define PWM1_3_GENB_R           (*((volatile uint32 *)0x40029124))
#define PWM1_3_DBCTL_R          (*((volatile uint32 *)0x40029128))
#define PWM1_3_DBRISE_R         (*((volatile uint32 *)0x4002912C))
#define PWM1_3_DBFALL_R         (*((volatile uint32 *)0x40029130))
#define PWM1_3_FLTSRC0_R        (*((volatile uint32 *)0x40029134))
#define PWM1_3_FLTSRC1_R        (*((volatile uint32 *)0x40029138))
#define PWM1_3_MINFLTPER_R      (*((volatile uint32 *)0x4002913C))
#define PWM1_0_FLTSEN_R         (*((volatile uint32 *)0x40029800))
#define PWM1_0_FLTSTAT0_R       (*((volatile uint32 *)0x40029804))
#define PWM1_0_FLTSTAT1_R       (*((volatile uint32 *)0x40029808))
#define PWM1_1_FLTSEN_R         (*((volatile uint32 *)0x40029880))
#define PWM1_1_FLTSTAT0_R       (*((volatile uint32 *)0x40029884))
#define PWM1_1_FLTSTAT1_R       (*((volatile uint32 *)0x40029888))
#define PWM1_2_FLTSTAT0_R       (*((volatile uint32 *)0x40029904))
#define PWM1_2_FLTSTAT1_R       (*((volatile uint32 *)0x40029908))
#define PWM1_3_FLTSTAT0_R       (*((volatile uint32 *)0x40029984))
#define PWM1_3_FLTSTAT1_R       (*((volatile uint32 *)0x40029988))
#define PWM1_PP_R               (*((volatile uint32 *)0x40029FC0))

//*****************************************************************************
//
// System Control registers (SYSCTL)
//
//*****************************************************************************
#define SYSCTL_DID0_R           (*((volatile uint32 *)0x400FE000))
#define SYSCTL_DID1_R           (*((volatile uint32 *)0x400FE004))
#define SYSCTL_DC0_R            (*((volatile uint32 *)0x400FE008))
#define SYSCTL_DC1_R            (*((volatile uint32 *)0x400FE010))
#define SYSCTL_DC2_R            (*((volatile uint32 *)0x400FE014))
#define SYSCTL_DC3_R            (*((volatile uint32 *)0x400FE018))
#define SYSCTL_DC4_R            (*((volatile uint32 *)0x400FE01C))
#define SYSCTL_DC5_R            (*((volatile uint32 *)0x400FE020))
#define SYSCTL_DC6_R            (*((volatile uint32 *)0x400FE024))
#define SYSCTL_DC7_R            (*((volatile uint32 *)0x400FE028))
#define SYSCTL_DC8_R            (*((volatile uint32 *)0x400FE02C))
#define SYSCTL_PBORCTL_R        (*((volatile uint32 *)0x400FE030))
#define SYSCTL_SRCR0_R          (*((volatile uint32 *)0x400FE040))
#define SYSCTL_SRCR1_R          (*((volatile uint32 *)0x400FE044))
#define SYSCTL_SRCR2_R          (*((volatile uint32 *)0x400FE048))
#define SYSCTL_RIS_R            (*((volatile uint32 *)0x400FE050))
#define SYSCTL_IMC_R            (*((volatile uint32 *)0x400FE054))
#define SYSCTL_MISC_R           (*((volatile uint32 *)0x400FE058))
#define SYSCTL_RESC_R           (*((volatile uint32 *)0x400FE05C))
#define SYSCTL_RCC_R            (*((volatile uint32 *)0x400FE060))
#define SYSCTL_GPIOHBCTL_R      (*((volatile uint32 *)0x400FE06C))
#define SYSCTL_RCC2_R           (*((volatile uint32 *)0x400FE070))
#define SYSCTL_MOSCCTL_R        (*((volatile uint32 *)0x400FE07C))
#define SYSCTL_RCGC0_R          (*((volatile uint32 *)0x400FE100))
#define SYSCTL_RCGC1_R          (*((volatile uint32 *)0x400FE104))
#define SYSCTL_RCGC2_R          (*((volatile uint32 *)0x400FE108))
#define SYSCTL_SCGC0_R          (*((volatile uint32 *)0x400FE110))
#define SYSCTL_SCGC1_R          (*((volatile uint32 *)0x400FE114))
#define SYSCTL_SCGC2_R          (*((volatile uint32 *)0x400FE118))
#define SYSCTL_DCGC0_R          (*((volatile uint32 *)0x400FE120))
#define SYSCTL_DCGC1_R          (*((volatile uint32 *)0x400FE124))
#define SYSCTL_DCGC2_R          (*((volatile uint32 *)0x400FE128))
#define SYSCTL_DSLPCLKCFG_R     (*((volatile uint32 *)0x400FE144))
#define SYSCTL_SYSPROP_R        (*((volatile uint32 *)0x400FE14C))
#define SYSCTL_PIOSCCAL_R       (*((volatile uint32 *)0x400FE150))
#define SYSCTL_PIOSCSTAT_R      (*((volatile uint32 *)0x400FE154))
#define SYSCTL_PLLFREQ0_R       (*((volatile uint32 *)0x400FE160))
#define SYSCTL_PLLFREQ1_R       (*((volatile uint32 *)0x400FE164))
#define SYSCTL_PLLSTAT_R        (*((volatile uint32 *)0x400FE168))
#define SYSCTL_SLPPWRCFG_R      (*((volatile uint32 *)0x400FE188))
#define SYSCTL_DSLPPWRCFG_R     (*((volatile uint32 *)0x400FE18C))
#define SYSCTL_DC9_R            (*((volatile uint32 *)0x400FE190))
#define SYSCTL_NVMSTAT_R        (*((volatile uint32 *)0x400FE1A0))
#define SYSCTL_LDOSPCTL_R       (*((volatile uint32 *)0x400FE1B4))
#define SYSCTL_LDODPCTL_R       (*((volatile uint32 *)0x400FE1BC))
#define SYSCTL_PPWD_R           (*((volatile uint32 *)0x400FE300))
#define SYSCTL_PPTIMER_R        (*((volatile uint32 *)0x400FE304))
#define SYSCTL_PPGPIO_R         (*((volatile uint32 *)0x400FE308))
#define SYSCTL_PPDMA_R          (*((volatile uint32 *)0x400FE30C))
#define SYSCTL_PPHIB_R          (*((volatile uint32 *)0x400FE314))
#define SYSCTL_PPUART_R         (*((volatile uint32 *)0x400FE318))
#define SYSCTL_PPSSI_R          (*((volatile uint32 *)0x400FE31C))
#define SYSCTL_PPI2C_R          (*((volatile uint32 *)0x400FE320))
#define SYSCTL_PPUSB_R          (*((volatile uint32 *)0x400FE328))
#define SYSCTL_PPCAN_R          (*((volatile uint32 *)0x400FE334))
#define SYSCTL_PPADC_R          (*((volatile uint32 *)0x400FE338))
#define SYSCTL_PPACMP_R         (*((volatile uint32 *)0x400FE33C))
#define SYSCTL_PPPWM_R          (*((volatile uint32 *)0x400FE340))
#define SYSCTL_PPQEI_R          (*((volatile uint32 *)0x400FE344))
#define SYSCTL_PPEEPROM_R       (*((volatile uint32 *)0x400FE358))
#define SYSCTL_PPWTIMER_R       (*((volatile uint32 *)0x400FE35C))
#define SYSCTL_SRWD_R           (*((volatile uint32 *)0x400FE500))
#define SYSCTL_SRTIMER_R        (*((volatile uint32 *)0x400FE504))
#define SYSCTL_SRGPIO_R         (*((volatile uint32 *)0x400FE508))
#define SYSCTL_SRDMA_R          (*((volatile uint32 *)0x400FE50C))
#define SYSCTL_SRHIB_R          (*((volatile uint32 *)0x400FE514))
#define SYSCTL_SRUART_R         (*((volatile uint32 *)0x400FE518))
#define SYSCTL_SRSSI_R          (*((volatile uint32 *)0x400FE51C))
#define SYSCTL_SRI2C_R          (*((volatile uint32 *)0x400FE520))
#define SYSCTL_SRUSB_R          (*((volatile uint32 *)0x400FE528))
#define SYSCTL_SRCAN_R          (*((volatile uint32 *)0x400FE534))
#define SYSCTL_SRADC_R          (*((volatile uint32 *)0x400FE538))
#define SYSCTL_SRACMP_R         (*((volatile uint32 *)0x400FE53C))
#define SYSCTL_SRPWM_R          (*((volatile uint32 *)0x400FE540))
#define SYSCTL_SRQEI_R          (*((volatile uint32 *)0x400FE544))
#define SYSCTL_SREEPROM_R       (*((volatile uint32 *)0x400FE558))
#define SYSCTL_SRWTIMER_R       (*((volatile uint32 *)0x400FE55C))
#define SYSCTL_RCGCWD_R         (*((volatile uint32 *)0x400FE600))
#define SYSCTL_RCGCTIMER_R      (*((volatile uint32 *)0x400FE604))
#define SYSCTL_RCGCGPIO_R       (*((volatile uint32 *)0x400FE608))
#define SYSCTL_RCGCDMA_R        (*((volatile uint32 *)0x400FE60C))
#define SYSCTL_RCGCHIB_R        (*((volatile uint32 *)0x400FE614))
#define SYSCTL_RCGCUART_R       (*((volatile uint32 *)0x400FE618))
#define SYSCTL_RCGCSSI_R        (*((volatile uint32 *)0x400FE61C))
#define SYSCTL_RCGCI2C_R        (*((volatile uint32 *)0x400FE620))
#define SYSCTL_RCGCUSB_R        (*((volatile uint32 *)0x400FE628))
#define SYSCTL_RCGCCAN_R        (*((volatile uint32 *)0x400FE634))
#define SYSCTL_RCGCADC_R        (*((volatile uint32 *)0x400FE638))
#define SYSCTL_RCGCACMP_R       (*((volatile uint32 *)0x400FE63C))
#define SYSCTL_RCGCPWM_R        (*((volatile uint32 *)0x400FE640))
#define SYSCTL_RCGCQEI_R        (*((volatile uint32 *)0x400FE644))
#define SYSCTL_RCGCEEPROM_R     (*((volatile uint32 *)0x400FE658))
#define SYSCTL_RCGCWTIMER_R     (*((volatile uint32 *)0x400FE65C))
#define SYSCTL_SCGCWD_R         (*((volatile uint32 *)0x400FE700))
#define SYSCTL_SCGCTIMER_R      (*((volatile uint32 *)0x400FE704))
#define SYSCTL_SCGCGPIO_R       (*((volatile uint32 *)0x400FE708))
#define SYSCTL_SCGCDMA_R        (*((volatile uint32 *)0x400FE70C))
#define SYSCTL_SCGCHIB_R        (*((volatile uint32 *)0x400FE714))
#define SYSCTL_SCGCUART_R       (*((volatile uint32 *)0x400FE718))
#define SYSCTL_SCGCSSI_R        (*((volatile uint32 *)0x400FE71C))
#define SYSCTL_SCGCI2C_R        (*((volatile uint32 *)0x400FE720))
#define SYSCTL_SCGCUSB_R        (*((volatile uint32 *)0x400FE728))
#define SYSCTL_SCGCCAN_R        (*((volatile uint32 *)0x400FE734))
#define SYSCTL_SCGCADC_R        (*((volatile uint32 *)0x400FE738))
#define SYSCTL_SCGCACMP_R       (*((volatile uint32 *)0x400FE73C))
#define SYSCTL_SCGCPWM_R        (*((volatile uint32 *)0x400FE740))
#define SYSCTL_SCGCQEI_R        (*((volatile uint32 *)0x400FE744))
#define SYSCTL_SCGCEEPROM_R     (*((volatile uint32 *)0x400FE758))
#define SYSCTL_SCGCWTIMER_R     (*((volatile uint32 *)0x400FE75C))
#define SYSCTL_DCGCWD_R         (*((volatile uint32 *)0x400FE800))
#define SYSCTL_DCGCTIMER_R      (*((volatile uint32 *)0x400FE804))
#define SYSCTL_DCGCGPIO_R       (*((volatile uint32 *)0x400FE808))
#define SYSCTL_DCGCDMA_R        (*((volatile uint32 *)0x400FE80C))
#define SYSCTL_DCGCHIB_R        (*((volatile uint32 *)0x400FE814))
#define SYSCTL_DCGCUART_R       (*((volatile uint32 *)0x400FE818))
#define SYSCTL_DCGCSSI_R        (*((volatile uint32 *)0x400FE81C))
#define SYSCTL_DCGCI2C_R        (*((volatile uint32 *)0x400FE820))
#define SYSCTL_DCGCUSB_R        (*((volatile uint32 *)0x400FE828))
#define SYSCTL_DCGCCAN_R        (*((volatile uint32 *)0x400FE834))
#define SYSCTL_DCGCADC_R        (*((volatile uint32 *)0x400FE838))
#define SYSCTL_DCGCACMP_R       (*((volatile uint32 *)0x400FE83C))
#define SYSCTL_DCGCPWM_R        (*((volatile uint32 *)0x400FE840))
#define SYSCTL_DCGCQEI_R        (*((volatile uint32 *)0x400FE844))
#define SYSCTL_DCGCEEPROM_R     (*((volatile uint32 *)0x400FE858))
#define SYSCTL_DCGCWTIMER_R     (*((volatile uint32 *)0x400FE85C))
#define SYSCTL_PRWD_R           (*((volatile uint32 *)0x400FEA00))
#define SYSCTL_PRTIMER_R        (*((volatile uint32 *)0x400FEA04))
#define SYSCTL_PRGPIO_R         (*((volatile uint32 *)0x400FEA08))
#define SYSCTL_PRDMA_R          (*((volatile uint32 *)0x400FEA0C))
#define SYSCTL_PRHIB_R          (*((volatile uint32 *)0x400FEA14))
#define SYSCTL_PRUART_R         (*((volatile uint32 *)0x400FEA18))
#define SYSCTL_PRSSI_R          (*((volatile uint32 *)0x400FEA1C))
#define SYSCTL_PRI2C_R          (*((volatile uint32 *)0x400FEA20))
#define SYSCTL_PRUSB_R          (*((volatile uint32 *)0x400FEA28))
#define SYSCTL_PRCAN_R          (*((volatile uint32 *)0x400FEA34))
#define SYSCTL_PRADC_R          (*((volatile uint32 *)0x400FEA38))
#define SYSCTL_PRACMP_R         (*((volatile uint32 *)0x400FEA3C))
#define SYSCTL_PRPWM_R          (*((volatile uint32 *)0x400FEA40))
#define SYSCTL_PRQEI_R          (*((volatile uint32 *)0x400FEA44))
#define SYSCTL_PREEPROM_R       (*((volatile uint32 *)0x400FEA58))
#define SYSCTL_PRWTIMER_R       (*((volatile uint32 *)0x400FEA5C))

/*****************************************************************************
NVIC Registers
*****************************************************************************/
#define NVIC_PRI0_REG             (*((volatile uint32 *)0xE000E400))
#define NVIC_PRI1_REG             (*((volatile uint32 *)0xE000E404))
#define NVIC_PRI2_REG             (*((volatile uint32 *)0xE000E408))
#define NVIC_PRI3_REG             (*((volatile uint32 *)0xE000E40C))
#define NVIC_PRI4_REG             (*((volatile uint32 *)0xE000E410))
#define NVIC_PRI5_REG             (*((volatile uint32 *)0xE000E414))
#define NVIC_PRI6_REG             (*((volatile uint32 *)0xE000E418))
#define NVIC_PRI7_REG             (*((volatile uint32 *)0xE000E41C))
#define NVIC_PRI8_REG             (*((volatile uint32 *)0xE000E420))
#define NVIC_PRI9_REG             (*((volatile uint32 *)0xE000E424))
#define NVIC_PRI10_REG            (*((volatile uint32 *)0xE000E428))
#define NVIC_PRI11_REG            (*((volatile uint32 *)0xE000E42C))
#define NVIC_PRI12_REG            (*((volatile uint32 *)0xE000E430))
#define NVIC_PRI13_REG            (*((volatile uint32 *)0xE000E434))
#define NVIC_PRI14_REG            (*((volatile uint32 *)0xE000E438))
#define NVIC_PRI15_REG            (*((volatile uint32 *)0xE000E43C))
#define NVIC_PRI16_REG            (*((volatile uint32 *)0xE000E440))
#define NVIC_PRI17_REG            (*((volatile uint32 *)0xE000E444))
#define NVIC_PRI18_REG            (*((volatile uint32 *)0xE000E448))
#define NVIC_PRI19_REG            (*((volatile uint32 *)0xE000E44C))
#define NVIC_PRI20_REG            (*((volatile uint32 *)0xE000E450))
#define NVIC_PRI21_REG            (*((volatile uint32 *)0xE000E454))
#define NVIC_PRI22_REG            (*((volatile uint32 *)0xE000E458))
#define NVIC_PRI23_REG            (*((volatile uint32 *)0xE000E45C))
#define NVIC_PRI24_REG            (*((volatile uint32 *)0xE000E460))
#define NVIC_PRI25_REG            (*((volatile uint32 *)0xE000E464))
#define NVIC_PRI26_REG            (*((volatile uint32 *)0xE000E468))
#define NVIC_PRI27_REG            (*((volatile uint32 *)0xE000E46C))
#define NVIC_PRI28_REG            (*((volatile uint32 *)0xE000E470))
#define NVIC_PRI29_REG            (*((volatile uint32 *)0xE000E474))
#define NVIC_PRI30_REG            (*((volatile uint32 *)0xE000E478))
#define NVIC_PRI31_REG            (*((volatile uint32 *)0xE000E47C))
#define NVIC_PRI32_REG            (*((volatile uint32 *)0xE000E480))
#define NVIC_PRI33_REG            (*((volatile uint32 *)0xE000E484))
#define NVIC_PRI34_REG            (*((volatile uint32 *)0xE000E488))

#define NVIC_EN0_REG              (*((volatile uint32 *)0xE000E100))
#define NVIC_EN1_REG              (*((volatile uint32 *)0xE000E104))
#define NVIC_EN2_REG              (*((volatile uint32 *)0xE000E108))
#define NVIC_EN3_REG              (*((volatile uint32 *)0xE000E10C))
#define NVIC_EN4_REG              (*((volatile uint32 *)0xE000E110))
#define NVIC_DIS0_REG             (*((volatile uint32 *)0xE000E180))
#define NVIC_DIS1_REG             (*((volatile uint32 *)0xE000E184))
#define NVIC_DIS2_REG             (*((volatile uint32 *)0xE000E188))
#define NVIC_DIS3_REG             (*((volatile uint32 *)0xE000E18C))
#define NVIC_DIS4_REG             (*((volatile uint32 *)0xE000E190))

#define NVIC_SYSTEM_PRI1_REG      (*((volatile uint32 *)0xE000ED18))
#define NVIC_SYSTEM_PRI2_REG      (*((volatile uint32 *)0xE000ED1C))
#define NVIC_SYSTEM_PRI3_REG      (*((volatile uint32 *)0xE000ED20))
#define NVIC_SYSTEM_SYSHNDCTRL    (*((volatile uint32 *)0xE000ED24))

#endif