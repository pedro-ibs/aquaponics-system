/**
 * ph.cpp
 *
 *  @date Created at:	29/12/2023, 16:46:24
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
 * https://www.usinainfo.com.br/blog/sensor-de-ph-arduino-como-calibrar-e-configurar/
 * https://capsistema.com.br/index.php/2021/03/10/medidor-de-ph-diy-usando-sensor-de-ph-e-arduino-com-display-oled/
 * https://bestengineeringprojects.com/arduino-ph-meter-using-ph-sensor/
 *
 */




/* Includes ----------------------------------------------------------------------------------------------------------------------------------------------*/
#include "ph.h"

#include <Arduino.h>
#include <appConfig.h>
/* Setings -----------------------------------------------------------------------------------------------------------------------------------------------*/
#define CALIBRATION_FACTOR	( 21.34	)
#define VOLTAGE_OFFSET		( -0.13	)


/* Setup -------------------------------------------------------------------------------------------------------------------------------------------------*/
static float fVoltage = 0.0;
/* Function prototype ------------------------------------------------------------------------------------------------------------------------------------*/
/* -------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*########################################################################################################################################################*/
/*########################################################################################################################################################*/
/*########################################################################################################################################################*/
/*--------------------------------------------------------------------- Local Functions ------------------------------------------------------------------*/
/*########################################################################################################################################################*/

void ph_vStartMeasure( void ){
	
	for (uint8_t sample = 0; sample < SAMPLE_SIZE; sample++) {		
		fVoltage = analogRead( INPUT_PIN_ph ) + fVoltage;
		delay( SAMPLE_RATE );
	}
	
	fVoltage = fVoltage / SAMPLE_SIZE;

	fVoltage = ADC_BITS_TO_VOLTAGE( fVoltage ) + VOLTAGE_OFFSET;

}


float ph_fGetVoltage( void ){

	return fVoltage  ;

}


float ph_fGetPH( void ){
	
	return  ( ( ( -5.70 ) * fVoltage ) + CALIBRATION_FACTOR );

}
