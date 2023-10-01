/*
 * KEYPAD_Interface.h
 *
 *      Author: youssef
 */

#include "STD_Types.h"
#include "bit_calc.h"
#include "avr/delay.h"
#include "DIO_Interface.h"
#include "KEYPAD_Config.h"
#include "KEYPAD_Interface.h"


u8 KPD_PU8_Col_Pins[KPD_U8_Col_Number] = {KPD_U8_Col_0,KPD_U8_Col_1,KPD_U8_Col_2,KPD_U8_Col_3};

u8 KPD_PU8_Row_Pins[KPD_U8_Row_Number] = {KPD_U8_Row_0,KPD_U8_Row_1,KPD_U8_Row_2,KPD_U8_Row_3};

void KPD_Void_Init() {
    #if KPD_U8_Activation_Type == KPD_U8_Active_Col
        KPD_Void_Init_ActiveCol();
    #elif KPD_U8_Activation_Type == KPD_U8_Active_Row
        KPD_Void_Init_ActiveRow();
    #endif
}

void KPD_Void_Init_ActiveCol() {
    // Active column configuration
    // Set column pins as inputs and enable internal pull-up resistors if using pull-up configuration
    for (u8 col = 0; col < KPD_U8_Col_Number; col++) {
        DIO_U8_SetPinDirection(KPD_U8_Col_Port, KPD_PU8_Col_Pins[col], OUTPUT);


        #if KPD_U8_ConnectionType == KPD_U8_PullUp
            DIO_U8_SetPinValue(KPD_U8_Col_Port, KPD_PU8_Col_Pins[col], HIGH);
		#elif KPD_U8_ConnectionType == KPD_U8_PullDown
           DIO_U8_SetPinValue(KPD_U8_Col_Port, KPD_PU8_Col_Pins[col], LOW);
        #endif

    }

    // Set row pins as outputs and initialize them based on pull-up/pull-down configuration
    for (u8 row = 0; row < KPD_U8_Row_Number; row++) {
        DIO_U8_SetPinDirection(KPD_U8_Row_Port, KPD_PU8_Row_Pins[row], INPUT);

        #if KPD_U8_ConnectionType == KPD_U8_PullUp
            DIO_U8_SetPinValue(KPD_U8_Row_Port, KPD_PU8_Row_Pins[row], HIGH);
        #elif KPD_U8_ConnectionType == KPD_U8_PullDown
            DIO_U8_SetPinValue(KPD_U8_Row_Port, KPD_PU8_Row_Pins[row], LOW);
        #endif
    }
}

void KPD_Void_Init_ActiveRow() {
    // Active row configuration
    // Set row pins as outputs and initialize them based on pull-up/pull-down configuration
    for (u8 row = 0; row < KPD_U8_Row_Number; row++) {
        DIO_U8_SetPinDirection(KPD_U8_Row_Port, KPD_PU8_Row_Pins[row], OUTPUT);

        #if KPD_U8_ConnectionType == KPD_U8_PullUp
            DIO_U8_SetPinValue(KPD_U8_Row_Port, KPD_PU8_Row_Pins[row], HIGH);
        #elif KPD_U8_ConnectionType == KPD_U8_PullDown
            DIO_U8_SetPinValue(KPD_U8_Row_Port, KPD_PU8_Row_Pins[row], LOW);
        #endif
    }

    // Set column pins as inputs and enable internal pull-up resistors if using pull-up configuration
    for (u8 col = 0; col < KPD_U8_Col_Number; col++) {
        DIO_U8_SetPinDirection(KPD_U8_Col_Port, KPD_PU8_Col_Pins[col], INPUT);

        #if KPD_U8_ConnectionType == KPD_U8_PullUp
            DIO_U8_SetPinValue(KPD_U8_Col_Port, KPD_PU8_Col_Pins[col], HIGH);
		#elif KPD_U8_ConnectionType == KPD_U8_PullDown
            DIO_U8_SetPinValue(KPD_U8_Col_Port, KPD_PU8_Col_Pins[col], LOW);
        #endif
    }
}

void KPD_Void_Get_KPD_Status(u8 *Copy_PU8_KPD) {
    u8 key_index=0;

    #if KPD_U8_Activation_Type == KPD_U8_Active_Col
        // Handle active column configuration
        for (u8 col = 0; col < KPD_U8_Col_Number; col++) {
            DIO_U8_SetPinValue(KPD_U8_Col_Port, KPD_PU8_Col_Pins[col], LOW);

            for (u8 row = 0; row < KPD_U8_Row_Number; row++) {
                key_index = (row * KPD_U8_Col_Number) + col;
                Copy_PU8_KPD[key_index] = DIO_U8_GetPinValue(KPD_U8_Row_Port, KPD_PU8_Row_Pins[row]);
            }

            DIO_U8_SetPinValue(KPD_U8_Col_Port, KPD_PU8_Col_Pins[col], HIGH);
        }

	#elif KPD_U8_Activation_Type == KPD_U8_Active_Row
       // Handle active row configuration
       for (u8 row = 0; row < KPD_U8_Row_Number; row++) {
           DIO_U8_SetPinValue(KPD_U8_Row_Port, KPD_PU8_Row_Pins[row], LOW);

           for (u8 col = 0; col < KPD_U8_Col_Number; col++) {
               key_index = (row * 4) + col;
               Copy_PU8_KPD[key_index] = DIO_U8_GetPinValue(KPD_U8_Col_Port, KPD_PU8_Col_Pins[col]);

               //Copy_PU8_KPD[key_index] = DIO_U8_GetPinValue(KPD_U8_Col_Port, KPD_PU8_Col_Pins[col]);
           }

           DIO_U8_SetPinValue(KPD_U8_Row_Port, KPD_PU8_Row_Pins[row], HIGH);
       }
   #endif
}
