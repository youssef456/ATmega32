/*
 * EXTI_Program.c

 *
 *      Author: youssef
 */

#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include "EXTI_Private.h"
#include "EXTI_Interface.h"


void(*AVoidCallBack[3])(void);

void __vector_1(void){
	if(AVoidCallBack[1]!= NULL){
		AVoidCallBack[1]();
	}
}

void __vector_2(void){
	if(AVoidCallBack[2]!= NULL){
		AVoidCallBack[2]();
	}
}

void __vector_3(void){
	if(AVoidCallBack[0]!= NULL){
		AVoidCallBack[0]();
	}
}

void EXTI_Void_Global_Enable_Disable(u8 Copy_u8_Ein_Dis){


		switch(Copy_u8_Ein_Dis){
		case EXTI_U8_Global_Enable:
			Set_Bit(EXTI_U8_SREG,EXTI_U8_Global_Int_PIN);
			break;
		case EXTI_U8_Global_Disable:
			Clear_Bit(EXTI_U8_SREG,EXTI_U8_Global_Int_PIN);
			break;
		}

}

void EXTI_Void_Ein_Dis(u8 Copy_U8_INT_Index, u8 Copy_U8_Ein_Dis){
	Assign_Bit(EXTI_U8_GICR,Copy_U8_INT_Index,Copy_U8_Ein_Dis);
}

void EXTI_U8_Set_Level (u8 Copy_U8_Int_Index, u8 Copy_U8_Int_Level){
	switch(Copy_U8_Int_Index){
	case EXTI_U8_INT0:
		Assign_Bit(EXTI_U8_MCUCR, EXTI_U8_INT0_Set_LVL_Bit_0, Get_Bit(Copy_U8_Int_Level,BIT0));
		Assign_Bit(EXTI_U8_MCUCR, EXTI_U8_INT0_Set_LVL_Bit_1, Get_Bit(Copy_U8_Int_Level,BIT1));
		break;
	case EXTI_U8_INT1:
		Assign_Bit(EXTI_U8_MCUCR, EXTI_U8_INT1_Set_LVL_Bit_2, Get_Bit(Copy_U8_Int_Level,BIT0));
		Assign_Bit(EXTI_U8_MCUCR, EXTI_U8_INT1_Set_LVL_Bit_3, Get_Bit(Copy_U8_Int_Level,BIT1));
		break;
	case EXTI_U8_INT2:
		Assign_Bit(EXTI_U8_MCUCSR, EXTI_U8_INT2_Set_LVL_Bit_6, Get_Bit(Copy_U8_Int_Level,BIT0));
		break;

	}
}


void EXTI_Void_Set_Call_Back(u8 Copy_U8_Int_index, void (*PVOID_CallBack)(void)){
	AVoidCallBack[Copy_U8_Int_index-mapping]= PVOID_CallBack;
}


