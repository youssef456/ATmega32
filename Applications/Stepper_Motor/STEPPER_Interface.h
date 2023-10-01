/*
 * STEPPER_Interface.h
 *
 *      Author: youssef
 */

#ifndef STEPPER_INTERFACE_H_
#define STEPPER_INTERFACE_H_

#define Group_A 0
#define Group_B 1
#define Group_C 2
#define Group_D 3

// Pin define//
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

// Pin define//
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#define COILS_PORT

#define CW 0
#define CCW 1


#define COILS_PINK
#define COILS_BLUE
#define COILS_YELLOW
#define COILS_ORANGE

//pin direction define//
#define INPUT 0
#define OUTPUT 1


//pin value define//
#define HIGH 1
#define LOW 0

void stepper_motor_init(void);
void stepper_Rotate_CW_Full_Step(void);
void stepper_Rotate_CCW_Full_Step(void);
void stepper_Rotate_Angle(u32 angle,u8 direction);

#endif /* STEPPER_INTERFACE_H_ */
