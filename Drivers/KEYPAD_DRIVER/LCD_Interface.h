/*
 * LCD_Interface.h
 *
 *      Author: youssef
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_


// FUNCTION INIT FOR LCD DISPLAY
void LCD_Void_Init_8Bit();
void LCD_Void_Write_Data(u8 Copy_U8_Data);
void LCD_Void_Write_Cmd(u8 Copy_U8_Cmd);
void LCD_Void_Write_String(u8 *Copy_PU8_String , u8 Copy_U8_Xpos ,u8 Copy_U8_Ypos);
void LCD_Void_Write_Number(u32 Copy_U32_Num, u8 Copy_U8_Xpos,u8 Copy_U8_Ypos);
void LCD_Void_Clear_Display();
void LCD_Void_Move_Name(u8 *Copy_PU8_String);
#endif /* LCD_INTERFACE_H_ */
