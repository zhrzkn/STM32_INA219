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

#define Conf_RESET     0x399F

#define BusVoltageRange_16   0x0000
#define BusVoltageRange_32   0x2000

#define INA219_CONFIG_SADC_9BIT_84              0x00
#define INA219_CONFIG_SADC_10BIT_148            0x08
#define INA219_CONFIG_SADC_11BIT_276            0x10
#define INA219_CONFIG_SADC_12BIT_532            0x18
#define INA219_CONFIG_SADC_12BIT_532            0x40 
#define INA219_CONFIG_SADC_12BIT_1060           0x48
#define INA219_CONFIG_SADC_12BIT_4S_2130        0x50 
#define INA219_CONFIG_SADC_12BIT_8S_4260        0x58 
#define INA219_CONFIG_SADC_12BIT_16S_8510       0x60
#define INA219_CONFIG_SADC_12BIT_32S_1702       0x68
#define INA219_CONFIG_SADC_12BIT_64S_3405       0x70
#define INA219_CONFIG_SADC_12BIT_128S_6810      0x78


#endif /* INC_INA219_REGISTER_H_ */
