/**
 * main.cpp
 *
 *  @date Created at:	15/11/2023
 *	@author:	Pedro Igor B. S.
 *	@email:		pibscontato@gmail.com
 * 	GitHub:		https://github.com/pedro-ibs
 * 	tabSize:	8
 *
 * ######################################################################################
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
 * ######################################################################################
 *
 */
/* Includes ----------------------------------------------------------------------------------------------------------------------------------------------*/
#include <Arduino.h>
#include <ArduinoJson.h>

#include <appConfig.h>
#include <temp.h>
#include <turbidity.h>
#include <ph.h>
#include <tds.h>

/* Setings -----------------------------------------------------------------------------------------------------------------------------------------------*/
/* Setup -------------------------------------------------------------------------------------------------------------------------------------------------*/
DynamicJsonDocument		jsonPackage( BUFFER_SIZE );
uint32_t uSample		= 0;
/* Function prototype ------------------------------------------------------------------------------------------------------------------------------------*/
void app_vShowTelemetry( void );
void app_vUpdatePin( void );
/* -------------------------------------------------------------------------------------------------------------------------------------------------------*/

void setup( void ) {

	Serial.begin( 115200 );



	temp_vStartup();


}

void loop( void ) {

	temp_vStartMeasure();
	turbidity_vStartMeasure();
	ph_vStartMeasure();
	tds_vStartMeasure();

	delay( SAMPLE_RATE );
	temp_vUpdate();

	jsonPackage[ "info"		][ "timstamp"			]	= millis();
	jsonPackage[ "info"		][ "sample"			]	= uSample++;

	jsonPackage[ "temperature" 	][ "unit"			]	= "celsius";
	jsonPackage[ "temperature" 	][ "type"			]	= "digital";
	jsonPackage[ "temperature" 	][ "value"			][ 0 ] 	= temp_fGet( 0 );
	jsonPackage[ "temperature" 	][ "value"			][ 1 ] 	= temp_fGet( 1 );
	jsonPackage[ "temperature" 	][ "average"			]	= temp_fGetAverageBetweenS0AndS1();

	jsonPackage[ "flow" 		][ "unit"			]	= "ml/s";
	jsonPackage[ "flow" 		][ "type"			]	= "digital";
	jsonPackage[ "flow" 		][ "value"			][ 0 ] 	= "0.00";

	jsonPackage[ "turbidity"	][ "unit"			]	= "ntu";
	jsonPackage[ "turbidity" 	][ "type"			]	= "analog";
	jsonPackage[ "turbidity"	][ "voltage"			][ 0 ] 	= turbidity_fGetVoltage();
	jsonPackage[ "turbidity"	][ "value"			][ 0 ] 	= turbidity_fGetNTU();

	jsonPackage[ "ph"		][ "unit"			]	= "ph";
	jsonPackage[ "ph" 		][ "type"			]	= "analog";
	jsonPackage[ "ph"		][ "voltage"			][ 0 ] 	= ph_fGetVoltage();
	jsonPackage[ "ph"		][ "value"			][ 0 ] 	= ph_fGetPH();

	jsonPackage[ "tds"		][ "unit"			]	= "ppm";
	jsonPackage[ "tds" 		][ "type"			]	= "analog";
	jsonPackage[ "tds"		][ "voltage"			][ 0 ] 	= tds_fGetVoltage();
	jsonPackage[ "tds"		][ "value"			][ 0 ] 	= tds_fGetPPM();

	serializeJson(jsonPackage, Serial);

}