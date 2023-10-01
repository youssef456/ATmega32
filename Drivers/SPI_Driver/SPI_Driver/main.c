/*
 * main.c
 *
 *      Author: youssef
 */


#include "BIT_CALC.h"
#include "STD_TYPES.h"
#include "SPI_Private.h"
#include "SPI_Interface.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"


int main(){
	/*
	slave
	//CLK inout   B7 (SCK)
	//MOSI input   B5
	//MISO output    B6
	//SS INput    B4
	SPI_Slave_INIT();
	while(1){
	u8 char;
	char = SPI_u8_Transfer('M');
	}
	*/

	/*
	Master
	//CLK Output
	//MOSI output
	//MISO input
	//SS INput
	SPI_Master_INIT();

	while(1){
		u8 char;
		char = SPI_u8_Transfer('G');
	}
	return 0;
	*/

}
