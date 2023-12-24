/* ******************************************************** */
/* Author      	:	 Abd-alrahman Amin						*/
/* SWC         	:	 SPI									*/
/* Layer       	:	 MCAL              						*/
/* MCu     		:	 stm32f401         						*/
/* Version     	:	 1.0               						*/
/* Date        	:	 September 26, 2023						*/
/* Last Edit   	:	 N/A 									*/
/* ******************************************************** */

#ifndef _MSPI_CONFIG_H_
#define _MSPI_CONFIG_H_

/*  in main " case Master "  */

		// MGPIO_CONFIG_t L_SPIMOSI={
				// .Port=PORTA,
				// .Pin=PIN7,
				// .Mode=ALTERNATE_FUNCTION,
				// .Speed=LOW,
				// .AltFunc=AF5,
				// .OutputType=PUSH_PULL,
		// };
		// MGPIO_CONFIG_t L_SPISCK={
				// .Port=PORTA,
				// .Pin=PIN5,
				// .Mode=ALTERNATE_FUNCTION,
				// .Speed=LOW,
				// .AltFunc=AF5,
				// .OutputType=PUSH_PULL,
				// .PullType=NOPULL,
		// };
		// MGPIO_CONFIG_t L_NSS_Select={
				// .Port=PORTA,
				// .Pin=PIN0,
				// .Mode=OUTPUT,
				// .Speed=LOW,
				// .OutputType=PUSH_PULL,
		// };

		// MGPIO_stderrPinConfig(&L_NSS_Select);
////		MGPIO_stderrPinConfig(&L_SPIMISO);
		// MGPIO_stderrPinConfig(&L_SPIMOSI);
		// MGPIO_stderrPinConfig(&L_SPISCK);

		// MGPIO_stderrSetPinValue(PORTA, PIN0, PIN_HIGH); // NSS

		// /* configure SPI struct  Master */

		// MSPI_Config_t L_SPI1Config =
		// {
			// .SPI_Num = MSPI_NUM1,
			// .Mode = MSPI_MASTER,
			// .ClockPolPha = MSPI_POLPHA_INVERTING_TAILLING,
			// .DataSize = MSPI_DFF_1BYTE,
			// .NSS_mode = MSPI_NSS_SW_MANAGE, /* SW so need to write */
			// .Prescaler = MSPI_PERIPH_CLK_BY16 ,
			// .DataOrder = MSPI_MSB_FIRST,
			// .CommunicationMode = MSPI_COMMUNI_MODE_FULL_DUPLEX,
////			.SSOE_Type = MSPI_SSOUT_EN,
			// .InterruptEnable={
					// .ERR  = MSPI_INT_DISABLED,
					// .RXNE = MSPI_INT_DISABLED,
					// .TXE  = MSPI_INT_DISABLED,
			// },
			// .Status = MSPI_ENABLE
		// };


/* Nothing */

#endif