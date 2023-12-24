/* ************************************************ */
/* Author      : Abd-alrahman Amin                  */
/* SWC         : ADC                               */
/* Layer       : MCAL                               */
/* Version     : 1.0                                */
/* Date        : August 14, 2023                    */
/* Last Edit   : N/A 			                    */
/* ************************************************ */

/* Library Includes */
#include "LSTD_types.h"
#include "LBIT_math.h"

/* SWC Includes */
#include "MADC_private.h"
#include "MADC_interface.h"

STD_error_t MADC_stderrInit(u8 ARG_u8VoltageReference, u8 ARG_u8Prescaler, u8 ARG_u8ADCAdjust)
{
	STD_error_t L_stderrError =E_OK;
	if(  (ARG_u8VoltageReference<=1 || 3==ARG_u8VoltageReference)   &&  ARG_u8Prescaler<=7 &&ARG_u8ADCAdjust<=MADC_ADJUST_LEFT )
	{
		/* mask Then OR with the needed val */
		ADMUX = ( ADMUX & 0x1F ) | (ARG_u8VoltageReference<<REFS0) | (ARG_u8ADCAdjust<<ADLAR) ; /* set voltage Ref, ADLAR=1 */
		ADCSRA = (ADLAR & 0xF8) | (ARG_u8Prescaler<<ADPS0) ; /* note ADPS0 is 0 not important, set prescaler */
	}
	else {
		L_stderrError =E_NOK;
	}
	return L_stderrError;
}

STD_error_t MADC_stderrReadADC(u16* ARG_u16pADCReading, u8 ARG_u8Channel)
{
	STD_error_t L_stderrError = E_OK;
	if(NULL_POINTER != ARG_u16pADCReading)
	{	
		MADC_voidEnableADC(); /* enable ADC to convert */
		L_stderrError = MADC_stderrStartConversion(ARG_u8Channel);
		
		if(E_OK==L_stderrError)
		{
			MADC_voidPollFlag(); /* polling wait flag ADIF be 1 */
			*ARG_u16pADCReading	= ADCH ; /* in this case we read the 8-MSB that mean we use 8 bit Resolution */
			MADC_voidClearFlag(); /* CLear flag by SW */	
		}
		else{
			/*do nothing*/
		}
	}
	else{
		L_stderrError = E_NULL_POINTER;
	}
	
	return L_stderrError;
}		
	
STD_error_t MADC_stderrStartConversion(u8 ARG_u8Channel)
{	
	STD_error_t L_stderrError = E_OK;
    
    if (ARG_u8Channel <= 7) {
        /* Select the channel using the ADMUX register */
        ADMUX = (ADMUX & 0xE0) | (ARG_u8Channel<<MUX0); /* note MUX0 is 0 not important*/
		/* Start the conversion by setting the ADSC bit */
		SET_BIT(ADCSRA,ADSC);	//ADCSRA |= (1 << ADSC);
    } else {
        L_stderrError = E_NOK;
    }
    return L_stderrError;
}

void MADC_voidEnableADC(void)
{
	SET_BIT(ADCSRA,ADEN);
}

void MADC_voidDisableADC(void)
{
	CLEAR_BIT(ADCSRA,ADEN);
}

void MADC_voidPollFlag(void)
{
	while(!GET_BIT(ADCSRA,ADIF)); /* POLL , stuck while flag is low */
}

void MADC_voidClearFlag(void)
{
	SET_BIT(ADCSRA,ADIF); /* Clear flag by set it */
}