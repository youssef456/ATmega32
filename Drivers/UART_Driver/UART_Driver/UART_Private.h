/*
 * UART_Private.h
 *
 *      Author: youssef
 */

#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

#define UDR *((volatile u8*)0x2C)
#define UCSRA *((volatile u8*)0x2B)
#define UCSRB *((volatile u8*)0x2A)
#define UCSRC *((volatile u8*)0x40)
#define UBRRL *((volatile u8*)0x29)
#define UBRRH *((volatile u8*)0x40)

#define RXC 7




#endif /* UART_PRIVATE_H_ */
