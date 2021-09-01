/*
 * INA219.h
 *
 *  Created on: 1 Eyl 2021
 *      Author: Uranus
 */

#ifndef INC_INA219_H_
#define INC_INA219_H_

#include <stdint.h>
#include "main.h"

typedef enum
{
	MODE_PG_40 = 0x0000,          //40 mV
	MODE_PG_80 = 0x0800,          //80 mV
	MODE_PG_160 = 0x1000,         //160 mV
	MODE_PG_320 = 0x1800        //320 mV


}INA219_PG_t;

typedef enum{
	MODE_POWER_DOWN = 0x0000,
	MODE_SHUNT_VOLTAGE_TRIG = 0x0100,
	MODE_BUS_VOLTAGE_TRIG = 0x0200,
	MODE_SHUNT_BUS_VOLTAGE_TRIG = 0x0300,
	MODE_ADC_DE = 0x0400,
	MODE_SHUNT_VOLTAGE_CON = 0x0500,
	MODE_BUS_VOLTAGE_CON = 0x0600,
	MODE_SHUNT_BUS_VOLTAGE_CON = 0x0700



}INA219_Mode_t;


#endif /* INC_INA219_H_ */
