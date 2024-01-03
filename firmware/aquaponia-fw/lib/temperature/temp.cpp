/**
 * temp.cpp
 *
 *  @date Created at:	29/12/2023, 12:29:53
 *	@author:	Pedro Igor B. S.
 *	@email:		pibscontato@gmail.com
 * 	GitHub:		https://github.com/pedro-ibs
 * 	tabSize:	8
 *
 * #######################################################################
 *
 *   Copyright (C) Pedro Igor B. S 2021
 * -------------------------------------------------------------------
 *
 *   Licença: GNU GPL 2
 * -------------------------------------------------------------------
 *   This program is free software; you can redistribute it and/or
 *   modify it under the terms of the GNU General Public License as
 *   published by the Free Software Foundation; version 2 of the
 *   License.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 * -------------------------------------------------------------------
 * #######################################################################
 *
 * TODO: documentation or resume or Abstract
 *
 */




/* Includes ----------------------------------------------------------------------------------------------------------------------------------------------*/
#include "temp.h"
#include <appConfig.h>

#include <OneWire.h>
#include <DallasTemperature.h>
/* Setings -----------------------------------------------------------------------------------------------------------------------------------------------*/
/* Setup -------------------------------------------------------------------------------------------------------------------------------------------------*/
OneWire				oneWire0		( INPUT_PIN_temperature0	);
OneWire				oneWire1		( INPUT_PIN_temperature1	);
DallasTemperature 		temperatureSensors0	( &oneWire0			);
DallasTemperature 		temperatureSensors1	( &oneWire1			);
static uint16_t			sample			= 1;
static float			temp[2]			= { 0 };
/* Function prototype ------------------------------------------------------------------------------------------------------------------------------------*/
/* -------------------------------------------------------------------------------------------------------------------------------------------------------*/


void temp_vStartup( void ){
	temperatureSensors0.begin();
	temperatureSensors1.begin();
}


void temp_vStartMeasure( void ){
	temperatureSensors0.requestTemperatures();
	temperatureSensors1.requestTemperatures();

	sample++;
}

void temp_vUpdate( void ){
	temp[ 0 ] = temperatureSensors0.getTempCByIndex( 0 );
	temp[ 1 ] = temperatureSensors1.getTempCByIndex( 0 );
	delay( 40 );
	temperatureSensors0.setUserDataByIndex( 0, sample );
	temperatureSensors1.setUserDataByIndex( 0, sample );

}


float temp_fGet( uint8_t index ){
	return temp[ index ];
}

float temp_fGetAverageBetweenS0AndS1( void ){
	return ( temp[ 0 ] + temp[ 1 ] ) / 2;
}


/*########################################################################################################################################################*/
/*########################################################################################################################################################*/
/*########################################################################################################################################################*/
/*--------------------------------------------------------------------- Local Functions ------------------------------------------------------------------*/
/*########################################################################################################################################################*/
