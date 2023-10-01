/*
 * EXTI_Private.h
 *
 *      Author: youssef
 */

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_


#define EXTI_U8_MCUCR *((volatile u8*)0x55)
#define EXTI_U8_MCUCSR *((volatile u8*)0x54)
#define EXTI_U8_GICR *((volatile u8*)0x5B)
#define EXTI_U8_GIFR *((volatile u8*)0x5A)
#define EXTI_U8_SREG *((volatile u8*)0x5F)

void __vector_1(void)__attribute__((signal));
void __vector_2(void)__attribute__((signal));
void __vector_3(void)__attribute__((signal));



#endif /* EXTI_PRIVATE_H_ */
