/**
 * config.h
 *
 *  @date Created at:	29/12/2023, 12:25:12
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

/* Includes ---------------------------------------------------------------------------------------------------------------------------------------------*/
#include <Arduino.h>


#ifndef app_config_H_
#define app_config_H_

/* macro -------------------------------------------------------------------------------------------------------------------------------------------------*/
#define ADC_BITS_TO_VOLTAGE( VALUE ) ( ( ( float ) VALUE / 1023.00 ) * 5.00 )

/*--------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*  Hardware input interface																  */
/*--------------------------------------------------------------------------------------------------------------------------------------------------------*/
#define INPUT_PIN_temperature0		( A0	)
#define INPUT_PIN_temperature1		( A1	)
#define INPUT_PIN_conductivity		( A2	)
#define INPUT_PIN_ph			( A3	)
#define INPUT_PIN_pressure		( A4	)
#define INPUT_PIN_turbidity		( A5	)
#define INPUT_PIN_flow			( A6	)


/*--------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*  application																  */
/*--------------------------------------------------------------------------------------------------------------------------------------------------------*/
#define BUFFER_SIZE			( 255*2	)
#define SAMPLE_SIZE			( 30	)
#define SAMPLE_RATE			( 40	)



/* Definition --------------------------------------------------------------------------------------------------------------------------------------------*/


#endif /* config_H_ */
