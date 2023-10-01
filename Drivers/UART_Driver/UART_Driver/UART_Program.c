/*
 * UART_Program.c
 *
 *      Author: youssef
 */

#include "BIT_CALC.h"
#include "STD_TYPES.h"
#include "UART_Private.h"
#include "UART_Interface.h"

void UART_void_INIT(void){
	// UBRR Calculation
	// UBRRL = ((system clock (8MHZ) / (16 * Baudrate(9600) ) - 1 = 51
	UBRRH=0;
	UBRRL=51;

	// Receiver and Transmitter Enable PINS
	Set_Bit(UCSRB,4); //Receiver
	Set_Bit(UCSRB,3); //Transmitter

	// Bit 7 in UCSRC Must be Set when writing to UCSRC
	Set_Bit(UCSRC,7);

	// Asynchronous
	Clear_Bit(UCSRC,6);

	// No Parity
	Clear_Bit(UCSRC,5);
	Clear_Bit(UCSRC,4);

	// Character Size : 8bit
	Clear_Bit(UCSRB,2);
	Set_Bit(UCSRC,2);
	Set_Bit(UCSRC,1);

}


void UART_void_Transmit_Char(u8 data){
	// In transmission: UDRE FLAG IN UCSRA is set as transmit buffer can only be written then
	//waiting until Transmission register is empty  check the UDRE flag
	while(!(UCSRA & 0b00100000));

	UDR = data;
}

u8 UART_U8_Receive_Char(void) {
    u8 result;

    // Wait until there is unread data in the receiver buffer
    while (!(UCSRA & 0b10000000));

    // Read the received character from the UDR register
    result = UDR;

    // Clear the RXC flag by writing logic 1 to it
    Set_Bit(UCSRA,7);
    return result;
}

void UART_Send_String(u8 *str){
	while(*str != '\0'){
		UART_void_Transmit_Char(*str);
		str++;
	}
	UART_void_Transmit_Char('\0');

}
void UART_Recive_String(u8 *str){
	u8 i = 0;
	str[i] = UART_U8_Receive_Char();
	while(str[i] != '\0'){
		i++;
		str[i] = UART_U8_Receive_Char();
	}
}





















