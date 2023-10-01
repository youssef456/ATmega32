/*
 * TIMER_0_Private.h
 *
 *      Author: youssef
 */

#ifndef TIMER_0_PRIVATE_H_
#define TIMER_0_PRIVATE_H_


#define TIMER0_U8_TCCR0 *((volatile u8*)0x53)
#define TIMER0_U8_TCNT0 *((volatile u8*)0x52)
#define TIMER0_U8_TIMSK *((volatile u8*)0x59)
#define TIMER0_U8_SREG 	*((volatile u8*)0x5F)


#endif /* TIMER_0_PRIVATE_H_ */
