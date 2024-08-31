/*
 * I2C_priv.h
 *
 *  Created on: Aug 27, 2024
 *      Author: user
 */

#ifndef I2C_PRIV_H_
#define I2C_PRIV_H_


#define IIC_NUMBER                 3
#define MASKING_BIT                1

#define ADD_MASKING                0x7F

#define DATA_MASK                  0xFF

#define CLOCK_FREQ                 800000UL

#define FREQ_MASKING               0x3F

#define CCR_MASKING                0xfff

#define TRISE_MASKING               0x3F

// CR1 bits
#define ACK                        10
#define STOP                       9
#define START                      8
#define PE                         0

//OAR1 bits
#define ADDMODE                    15

//SR1 bits
#define TXE                         7
#define RXNE                        6
#define STOPF                       4
#define BTF                         2
#define ADDR                        1
#define SB                          0

//CCR bits
#define F_S                         15

#endif /* I2C_PRIV_H_ */
