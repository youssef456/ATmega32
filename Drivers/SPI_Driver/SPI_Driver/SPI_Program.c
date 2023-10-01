/*
 * SPI_Program.c
 *
 *      Author: youssef
 */


#include "BIT_CALC.h"
#include "STD_TYPES.h"
#include "SPI_Private.h"
#include "SPI_Interface.h"

void SPI_Master_INIT(void){
	SPCR = 0b01010001;
	// SPI-Interrupt disable -- SPI enable
	//MSB FIRST
	// MASTER MODE
	// CPOL=0, CPHA =0
	//PRSCALAR CLK/16
}


void SPI_Slave_INIT(void){
	SPCR = 0b01000000;
	// SPI-Interrupt disable
	// SPI enable
	//MSB FIRST
	// SLAVE MODE
	// CPOL=0, CPHA =0
	//PRSCALAR dont care
}
u8 SPI_u8_Transfer(u8 data){
	SPDR = data;
	while(!(Get_Bit(SPDR,7)));
	return SPDR;

}
