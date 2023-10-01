/*
 * SPI_Interface.h
 *
 *      Author: youssef
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_


void SPI_Master_INIT(void);
void SPI_Slave_INIT(void);
u8 SPI_u8_Transfer(u8 data);

#endif /* SPI_INTERFACE_H_ */
