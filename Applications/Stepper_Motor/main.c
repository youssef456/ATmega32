/*
 * main.c
 *
 *      Author: youssef
 */
#include "STD_Types.h"
#include "bit_calc.h"
#include "util/delay.h"
#include "DIO_Interface.h"

#include "STEPPER_Interface.h"

int main(void){
    stepper_motor_init();
	stepper_Rotate_Angle(50,CW);

    while(1){
    	//stepper_Rotate_CW_Full_Step();
    }

}

