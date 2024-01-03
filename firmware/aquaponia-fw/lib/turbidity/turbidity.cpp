/**
 * turbidity.c
 *
 *  @date Created at:	29/12/2023, 16:00:20
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
 * https://www.usinainfo.com.br/blog/sensor-de-turbidez-projeto-de-leitura-da-qualidade-da-agua/
 * https://www.electroniclinic.com/turbidity-sensor-with-arduino-for-water-quality-monitoring-turbidity-meter/
 *
 */



/* Includes ----------------------------------------------------------------------------------------------------------------------------------------------*/
#include "turbidity.h"
#include <appConfig.h>

/* Setings -----------------------------------------------------------------------------------------------------------------------------------------------*/
/* Setup -------------------------------------------------------------------------------------------------------------------------------------------------*/
static float fVoltage = 0.00;

/* Function prototype ------------------------------------------------------------------------------------------------------------------------------------*/
/* -------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*########################################################################################################################################################*/
/*########################################################################################################################################################*/
/*########################################################################################################################################################*/
/*--------------------------------------------------------------------- Local Functions ------------------------------------------------------------------*/
/*########################################################################################################################################################*/



void turbidity_vStartMeasure( void ){
	
	
	for (uint8_t sample = 0; sample < SAMPLE_SIZE; sample++) {		
		fVoltage = analogRead( INPUT_PIN_turbidity ) + fVoltage;
		delay( SAMPLE_RATE );
	}
	
	fVoltage = fVoltage / SAMPLE_SIZE;
	


	fVoltage = ADC_BITS_TO_VOLTAGE( fVoltage );
}


float turbidity_fGetVoltage( void ){
	return fVoltage;
}


float turbidity_fGetNTU( void ){
	
	if( fVoltage < 2.5 ){
		return 3000;
	}

	if( fVoltage > 4.2 ){
		return 0;
	}

	return ( -1120.4 * square( fVoltage ) + 5742.3 * fVoltage - 4353.8 );

}

