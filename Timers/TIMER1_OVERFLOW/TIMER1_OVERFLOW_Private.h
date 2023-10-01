/*
 * TIMER1_OVERFLOW_Private.h
 *
 *      Author: youssef
 */

#ifndef TIMER1_OVERFLOW_PRIVATE_H_
#define TIMER1_OVERFLOW_PRIVATE_H_

#define TCCR1B *((volatile u16*)0x4E)

#define TCNT1H *((volatile u16*)0x4D)
#define TCNT1L *((volatile u16*)0x4C)
#define OCR1H *((volatile u16*)0x4B)
#define OCR1L *((volatile u16*)0x4A)

#define TIMSK *((volatile u8*)0x59)
#define SREG *((volatile u8*)0x5F)


#endif /* TIMER1_OVERFLOW_PRIVATE_H_ */
