/*
 * ICU_TIMER1_EXTI_0_Private.h
 *
 *      Author: youssef
 */

#ifndef ICU_TIMER1_EXTI_0_PRIVATE_H_
#define ICU_TIMER1_EXTI_0_PRIVATE_H_

#define TCCR0 *((volatile u8*)0x53)
#define OCR0 *((volatile u8*)0x5c)

#define TCCR1A *((volatile u8*)0x4f)
#define TCCR1B *((volatile u16*)0x4E)
#define TCNT1L *((volatile u8*)0x4C)
#define TCNT1H *((volatile u8*)0x4D)

#define MCUCR *((volatile u8*)0x55)
#define GICR *((volatile u8*)0x5B)
#define SREG *((volatile u8*)0x5F)

#endif /* ICU_TIMER1_EXTI_0_PRIVATE_H_ */
