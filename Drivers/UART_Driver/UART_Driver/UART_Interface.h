/*
 * UART_Interface.h
 *
 *      Author: youssef
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void UART_void_INIT(void);
void UART_void_Transmit_Char(u8 data);
u8 UART_U8_Receive_Char(void);

#endif /* UART_INTERFACE_H_ */
