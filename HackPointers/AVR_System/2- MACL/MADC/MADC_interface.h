/* ************************************************ */
/* Author      : Abd-alrahman Amin                  */
/* SWC         : ADC                               */
/* Layer       : MCAL                               */
/* Version     : 1.0                                */
/* Date        : August 14, 2023                    */
/* Last Edit   : N/A 			                    */
/* ************************************************ */

#ifndef _MADC_INTERFACE_H_
#define _MADC_INTERFACE_H_

// Reference Selection Bits
#define MADC_VREF_AREF  	         			0U	
#define MADC_VREF_AVCC  	         			1U	
#define MADC_VREF_2V56  	          			3U	

// Adjust Result options
#define MADC_ADJUST_LEFT						1U
#define MADC_ADJUST_RIGHT   				    0U


// Input Channels
#define MADC_SCHANNEL_ADC0          			0b00000
#define MADC_SCHANNEL_ADC1          			0b00001
#define MADC_SCHANNEL_ADC2          			0b00010
#define MADC_SCHANNEL_ADC3          			0b00011
#define MADC_SCHANNEL_ADC4          			0b00100
#define MADC_SCHANNEL_ADC5          			0b00101
#define MADC_SCHANNEL_ADC6          			0b00110
#define MADC_SCHANNEL_ADC7          			0b00111

// Differential Channels Inputs
/* NOTE in this case the ADC Result is 2's complement */
#define MADC_DIFF_ADC0_ADC0_GAIN_10   			0b01000
#define MADC_DIFF_ADC1_ADC0_GAIN_10  			0b01001
#define MADC_DIFF_ADC0_ADC0_GAIN_200   			0b01010
#define MADC_DIFF_ADC1_ADC0_GAIN_200   			0b01011
#define MADC_DIFF_ADC2_ADC2_GAIN_10   			0b01100
#define MADC_DIFF_ADC3_ADC2_GAIN_10   			0b01101
#define MADC_DIFF_ADC2_ADC2_GAIN_200   			0b01110
#define MADC_DIFF_ADC3_ADC2_GAIN_200   			0b01111
#define MADC_DIFF_ADC0_ADC1_GAIN_1   			0b10000
#define MADC_DIFF_ADC1_ADC1_GAIN_1   			0b10001
#define MADC_DIFF_ADC3_ADC1_GAIN_1   			0b10011
#define MADC_DIFF_ADC4_ADC1_GAIN_1   			0b10100
#define MADC_DIFF_ADC5_ADC1_GAIN_1   			0b10101
#define MADC_DIFF_ADC6_ADC1_GAIN_1   			0b10110
#define MADC_DIFF_ADC7_ADC1_GAIN_1   			0b10111
#define MADC_DIFF_ADC0_ADC2_GAIN_1   			0b11000
#define MADC_DIFF_ADC1_ADC2_GAIN_1   			0b11001
#define MADC_DIFF_ADC2_ADC2_GAIN_1   			0b11010
#define MADC_DIFF_ADC3_ADC2_GAIN_1   			0b11011
#define MADC_DIFF_ADC4_ADC2_GAIN_1   			0b11100
#define MADC_DIFF_ADC5_ADC2_GAIN_1   			0b11101

// Prescaler options
#define MADC_PRESCALER_2         				0b001
#define MADC_PRESCALER_4         				0b010
#define MADC_PRESCALER_8         				0b011
#define MADC_PRESCALER_16        				0b100
#define MADC_PRESCALER_32        				0b101
#define MADC_PRESCALER_64        				0b110
#define MADC_PRESCALER_128       				0b111

STD_error_t MADC_stderrInit(u8 ARG_u8VoltageReference, u8 ARG_u8Prescaler, u8 ARG_u8ADCAdjust);
STD_error_t MADC_stderrReadADC(u16* ARG_u16pADCReading, u8 ARG_u8Channel);
STD_error_t MADC_stderrStartConversion(u8 ARG_u8Channel);

void MADC_voidEnableADC   (void);
void MADC_voidDisableADC  (void);
void MADC_voidPollFlag    (void);
void MADC_voidClearFlag   (void);



#endif
