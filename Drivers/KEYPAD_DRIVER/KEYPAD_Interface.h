/*
 * KEYPAD_Interface.h
 *
 *      Author: youssef
 */

#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

void KPD_Void_Get_KPD_Status(u8 *Copy_PU8_KPD);
void KPD_Void_Init();
void KPD_Void_Init_ActiveCol();
void KPD_Void_Init_ActiveRow();
#define KPD_U8_Size (KPD_U8_Col_Number*KPD_U8_Row_Number)



#endif /* KEYPAD_INTERFACE_H_ */
