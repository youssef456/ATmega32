/*
 * DIO_Interface.h
 *
 *      Author: youssef
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#define Max_Port_Value 0b11111111
void LCD_VOID_Init_8Bit (void);
void LCD_Void_Write_Cmd(u8 Copy_u8_Cmd);
void LCD_Void_Write_Data(u8 Copy_u8_Data);
void LCD_Void_Write(u8 Copy_U8_Value);
void LCD_Void_Write_String(u8 *Copy_PU8_Data,u8 xPos,u8 yPOS);
void LCD_Void_Write_Number(u32 Copy_U32_Num);
void reverse(u8 *ptr,u8 lenght);
void LCD_Void_Clear_Display();
void swap(u8 *a,u8 *b);
#endif /* LCD_INTERFACE_H_ */
