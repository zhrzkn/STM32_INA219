/*
 * INA219_Register.h
 *
 *  Created on: 1 Eyl 2021
 *      Author: Uranus
 */

#ifndef INC_INA219_REGISTER_H_
#define INC_INA219_REGISTER_H_


#define Configuration  0x00
#define Shunt_Voltage  0x01
#define Bus_Voltage    0x02
#define Power          0x03
#define Current        0x04
#define Calibration    0x05

#define RESET          0x00

#define Conf_RESET     0x399F

#define BusVoltageRange_16   0x0000
#define BusVoltageRange_32   0x2000


#endif /* INC_INA219_REGISTER_H_ */
