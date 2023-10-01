/*
 * TIMER1_FAST_PWM_SERVO_MOTOR_Private.h
 *
 *      Author: youssef
 */

#ifndef TIMER1_FAST_PWM_SERVO_MOTOR_PRIVATE_H_
#define TIMER1_FAST_PWM_SERVO_MOTOR_PRIVATE_H_

#define TCCRIA *((volatile u8*)0x4f)
#define TCCRIB *((volatile u16*)0x4E)

#define OCRIAH *((volatile u8*)0x4B)
#define OCRIAL *((volatile u16*)0x4A)

#define OCRIBH *((volatile u8*)0x49)
#define OCRIBL *((volatile u16*)0x48)

#define ICRIH *((volatile u8*)0x47)
#define ICRIL *((volatile u16*)0x46)

#endif /* TIMER1_FAST_PWM_SERVO_MOTOR_PRIVATE_H_ */
