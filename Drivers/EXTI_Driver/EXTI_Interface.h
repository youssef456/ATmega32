/*
 * EXTI_Interface.h
 *
 *      Author: youssef
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#define EXTI_U8_Global_Enable 1
#define EXTI_U8_Global_Disable 0

#define EXTI_U8_Global_Int_PIN 7

#define EXTI_U8_INT0 6
#define EXTI_U8_INT1 7
#define EXTI_U8_INT2 5

#define EXTI_U8_INT0_Set_LVL_Bit_0 0
#define EXTI_U8_INT0_Set_LVL_Bit_1 1
#define EXTI_U8_INT1_Set_LVL_Bit_2 2
#define EXTI_U8_INT1_Set_LVL_Bit_3 3
#define EXTI_U8_INT2_Set_LVL_Bit_6 6

#define BIT0 0
#define BIT1 1

#define EXTI_U8_LOW_Level 0b00000000
#define EXTI_U8_IOC 0b00000001
#define EXTI_U8_Falling_Edge 0b00000010
#define EXTI_U8_Rising_Edge 0b00000011


#define EXTI_U8_INT0_PORT GROUP_D
#define EXTI_U8_INT0_PIN 2

#define EXTI_U8_INT1_PORT GROUP_D
#define EXTI_U8_INT1_PIN 3

#define EXTI_U8_INT2_PORT GROUP_B
#define EXTI_U8_INT2_PIN 2


#define mapping 5
#define NULL ((void*)0)

void EXTI_Void_Global_Enable_Disable(u8 Copy_u8_Ein_Dis);
void EXTI_Void_Ein_Dis(u8 Copy_U8_INT_Index, u8 Copy_U8_Ein_Dis);
void EXTI_U8_Set_Level (u8 Copy_U8_Int_Index, u8 Copy_U8_Int_Level);
void EXTI_Void_Set_Call_Back(u8 Copy_U8_Int_index, void (*PVOID_CallBack)(void));



#endif /* EXTI_INTERFACE_H_ */
