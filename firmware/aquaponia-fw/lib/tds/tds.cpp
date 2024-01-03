/**
 * tds.cpp
 *
 *  @date Created at:	29/12/2023, 13:20:19
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
 * 
 * https://wiki.keyestudio.com/KS0429_keyestudio_TDS_Meter_V1.0#TDS_Probe:
 * https://randomnerdtutorials.com/arduino-tds-water-quality-sensor/
 *
 */




/* Includes ----------------------------------------------------------------------------------------------------------------------------------------------*/
#include "tds.h"

#include <appConfig.h>
#include <Arduino.h>
#include <temp.h>


/* Setings -----------------------------------------------------------------------------------------------------------------------------------------------*/
/* Setup -------------------------------------------------------------------------------------------------------------------------------------------------*/
static float fVoltage = 0.0;
/* Function prototype ------------------------------------------------------------------------------------------------------------------------------------*/
/* -------------------------------------------------------------------------------------------------------------------------------------------------------*/



void tds_vStartMeasure( void ){
	
	
	for (uint8_t sample = 0; sample < SAMPLE_SIZE; sample++) {		
		fVoltage = analogRead( INPUT_PIN_conductivity ) + fVoltage;
		delay( SAMPLE_RATE );
	}
	
	fVoltage = fVoltage / SAMPLE_SIZE;
	


	fVoltage = ADC_BITS_TO_VOLTAGE( fVoltage );

}


float tds_fGetVoltage( void ){
	return fVoltage;
}


float tds_fGetPPM( void ){
	float compensationCoefficient = 1.0 + ( 0.02 * ( temp_fGet( 0 ) - 25.0 ) );
	float compensationVoltage = fVoltage / compensationCoefficient;

	return ( ( 133.42 * compensationVoltage * compensationVoltage * compensationVoltage ) - ( 255.86 * compensationVoltage * compensationVoltage ) + ( 857.39 * compensationVoltage * 0.5) );

}






/*########################################################################################################################################################*/
/*########################################################################################################################################################*/
/*########################################################################################################################################################*/
/*--------------------------------------------------------------------- Local Functions ------------------------------------------------------------------*/
/*########################################################################################################################################################*/


