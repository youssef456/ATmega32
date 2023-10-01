/*
 *  Timer1_ICU_Private.h
 *
 *      Author: youssef
 */

#ifndef TIMER1_ICU_PRIVATE_H_
#define TIMER1_ICU_PRIVATE_H_

#define TCCR0 *((volatile u8*)0x53)
#define OCR0 *((volatile u8*)0x5c)

#define TCCR1A *((volatile u8*)0x4f)
#define TCCR1B *((volatile u16*)0x4E)
#define TCNT1L *((volatile u8*)0x4C)
#define TCNT1H *((volatile u8*)0x4D)
#define ICR1L *((volatile u8*)0x46)
#define ICR1H *((volatile u8*)0x47)
#define TIMSK *((volatile u8*)0x59)
#define SREG *((volatile u8*)0x5F)

#endif /* TIMER1_ICU_PRIVATE_H_ */
