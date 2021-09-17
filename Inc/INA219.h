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


#define INA219_ADDRESS = 0x40

#define Configuration  0x00
#define Shunt_Voltage  0x01
#define Bus_Voltage    0x02
#define Power          0x03
#define Current        0x04
#define Calibration    0x05

typedef enum
{
	MODE_PG_40 = 0x0000,          //40 mV
	MODE_PG_80 = 0x0800,          //80 mV
	MODE_PG_160 = 0x1000,         //160 mV
	MODE_PG_320 = 0x1800        //320 mV
}INA219_PG_t;

typedef enum{
	MODE_POWER_DOWN = 0x0000,
	MODE_SHUNT_VOLTAGE_TRIG = 0x0001,
	MODE_BUS_VOLTAGE_TRIG = 0x0002,
	MODE_SHUNT_BUS_VOLTAGE_TRIG = 0x0003,
	MODE_ADC_DE = 0x0004,
	MODE_SHUNT_VOLTAGE_CON = 0x0005,
	MODE_BUS_VOLTAGE_CON = 0x0006,
	MODE_SHUNT_BUS_VOLTAGE_CON = 0x0007
}INA219_Mode_t;

typedef enum{
	BADC_9bit = 0x0000,
	BADC_10bit = 0x0080,
	BADC_11bit = 0x0100,
	BADC_12bit = 0x0180,
	BADC_2S = 0x00480,
	BADC_4S = 0x00500,
	BADC_8S = 0x00580,
	BADC_16S = 0x00600,
	BADC_32S = 0x00680,
	BADC_64S = 0x00700,
	BADC_128S = 0x00780
}INA219_BusADC_t;

typedef enum{
	SADC_9BIT_84           =   0x00,
	SADC_10BIT_148         =   0x08,
	SADC_11BIT_276         =   0x10,
	SADC_12BIT_532         =   0x18,
	SADC_12BIT_532         =   0x40,  // olmalı mı olmamalı
	SADC_12BIT_2S_1060     =   0x48,
	SADC_12BIT_4S_2130     =   0x50,
	SADC_12BIT_8S_4260     =   0x58,
	SADC_12BIT_16S_8510    =   0x60,
	SADC_12BIT_32S_1702    =   0x68,
	SADC_12BIT_64S_3405    =   0x70,
	SADC_12BIT_128S_6810   =   0x78,
}INA219_ShuntADC_t;

typedef enum{
	BusFSR16V =	0x0000,
	BusFSR32V = 0x2000
}INA219_BusVoltageRange_t;


typedef struct
{
	I2C_HandleTypeDef *i2c;
	uint8_t Adress;
	uint16_t ShuntVoltage;
	uint16_t BusVoltage;
	uint16_t current;
	uint16_t power;
	float CurrentCoEff;
	float PowerCoEff;
} INA219_t;

#if ADVANCED_MODE
INA219_Status_t INA219_Init(INA219_t *sensor, I2C_HandleTypeDef *hi2c, uint8_t deviceAddr,
							INA219_BusVoltageRange_t, busRange, INA219_PG_t gain,
							INA219_BusADC_t busADC, INA219_ShuntADC_t shuntADC, INA219_Mode_t mode,
							uint16_t calibration);
#else
INA219_Status_t INA219_Init(INA219_t *sensor, I2C_HandleTypeDef *hi2c, uint8_t deviceAddr);
#endif


void	 INA219_GetBusVoltage( INA219_t *sensor);
void     INA219_GetShuntVoltage( INA219_t *sensor);
void	 INA219_GetCurrent( INA219_t *sensor);
void	 INA219_GetPower( INA219_t *sensor);

void INA219_Reset(INA219_t *sensor);

void INA219_SetCalibration(INA219_t *sensor, uint16_t calibration);
void INA219_SetConfiguration(INA219_t *sensor, uint16_t config);

#endif /* INC_INA219_H_ */
