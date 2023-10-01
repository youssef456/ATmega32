/*
 * LCD_Interface.h
 *
 *      Author: youssef
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#define maximum_port_direction 0b11111111


void LCD_Void_Init_8Bits (void);
void LCD_Void_Write(u8 Copy_U8_Value);
void LCD_Void_Write_Cmd(u8 Copy_u8_Cmd);
void LCD_Void_Write_Data(u8 Copy_u8_Data);
void LCD_Void_Write_String(u8* Copy_PU8_DATA, u8 Copy_U8_X_Postion, u8 Copy_U8_Y_Postion);
void LCD_Void_Write_Number(u32 Copy_U32_Number, u8 Copy_U8_X_Postion, u8 Copy_U8_Y_Postion);
void LCD_ClearDisplay();
u8 Calculate_String_Length(u8* Copy_PU8_DATA);
void reverse(u8 arr[], u8 lenght);
#endif /* LCD_INTERFACE_H_ */
