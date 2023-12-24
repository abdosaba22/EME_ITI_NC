/* ******************************************************** */
/* Author      	:	 Abd-alrahman Amin						*/
/* SWC         	:	 TFT									*/
/* Layer       	:	 HAL              						*/
/* MCu     		:	 stm32f401         						*/
/* Version     	:	 1.0               						*/
/* Date        	:	 September 28, 2023						*/
/* Last Edit   	:	 N/A 									*/
/* ******************************************************** */

#include "LSTD_types.h"
#include "LBIT_math.h"

#include "MGPIO_interface.h"
#include "MSPI_interface.h"
#include "MSYSTICK_interface.h"

#include "HTFT_interface.h"
#include "HTFT_private.h"
#include "HTFT_config.h"

#include "font.h"


//static void HTFT_voidBounders(0,127,0,159);

		/* static functions used just here */
static void HTFT_voidDrawPixel(u8 x1, u8 y1, u16  Copy_u16Color)
{

	/* adusting pixel size */
	u8 x2 = x1 + PixelLenght - 1;
	u8 y2 = y1 + PixelLenght - 1;
	HTFT_voidBounders(x1,x2,y1,y2);

	u8 PixelSize = PixelLenght * PixelLenght;
	/* RAM write */
	voidWriteCommand(0x2C);

	for(u8 Counter = 0 ; Counter <= PixelSize ; Counter++)
	{
		DrawTheColor(Copy_u16Color);
	}
}

static void DrawTheColor(u16 Color)
{
	/* write the high byte */
	voidWriteData(Color >> 8);
	/* write the low byte */
	voidWriteData(Color & 0x00FF);
}

static void HTFT_voidBounders(u8 x1, u8 x2, u8 y1, u8 y2)
{
	/* Set 'x' address */
	voidWriteCommand(0x2A);
		/* area of working */
	/* start of 'x' */
	voidWriteData(0);
	voidWriteData(x1);
	/* end of 'x' */
	voidWriteData(0);
	voidWriteData(x2);

	/* Set 'y' address */
	voidWriteCommand(0x2B);
		/* area of working */
	/* start of 'y' */
	voidWriteData(0);
	voidWriteData(y1);
	/* end of 'y' */
	voidWriteData(0);
	voidWriteData(y2);

}

static void voidWriteCommand(u8 Copy_u8Command)
{
	u8 Local_u8Temp;

	/* Set A0 pin to LOW */
	MGPIO_stderrSetPinValue(TFT_A0_PIN,GPIO_LOW);

	/* Send Command over SPI */
	MSPI_stderrTransceiveData(MSPI_NUM1,&Local_u8Temp,Copy_u8Data);
}

static void voidWriteData(u8 Copy_u8Data)
{
	u8 Local_u8Temp;

	/* Set A0 pin to HIGH */
	MGPIO_stderrSetPinValue(TFT_A0_PIN,GPIO_HIGH);

	/* Send Data over SPI */
	MSPI_stderrTransceiveData(MSPI_NUM1,&Local_u8Temp,Copy_u8Data);
}

		/* interfacing functions */
void HTFT_voidInitialize(void)
{
	/* Reset Pulse */
	MGPIO_stderrSetPinValue(TFT_RST_PIN,GPIO_HIGH);
	MSTK_voidBusyDelay(100);
	MGPIO_stderrSetPinValue(TFT_RST_PIN,GPIO_HIGH);
	MSTK_voidBusyDelay(1);
	MGPIO_stderrSetPinValue(TFT_RST_PIN,GPIO_HIGH);
	MSTK_voidBusyDelay(100);
	MGPIO_stderrSetPinValue(TFT_RST_PIN,GPIO_HIGH);
	MSTK_voidBusyDelay(100);
	MGPIO_stderrSetPinValue(TFT_RST_PIN,GPIO_HIGH);
	MSTK_voidBusyDelay(120000);

	/* sleep out command */
	voidWriteCommand(0x11);

	MSTK_voidBusyDelay(150000);

	/* color mode command */
	voidWriteCommand(0x3A);
	voidWriteData(0x05);

	/* Display on command */
	voidWriteCommand(0x29);

	
}

void HTFT_voidDisplayImage(const u16 * Copy_Image)
{
	u16  Counter;
	/* Set 'x' address */
	voidWriteCommand(0x2A);
		/* area of working */
	HTFT_voidBounders(0,127,0,159);

	/* RAM write */
	voidWriteCommand(0x2C);

	for(Counter = 0 ; Counter < 20480 ; Counter++)
	{
		/* write the high byte */
		voidWriteData(Copy_Image[Counter] >> 8);
		/* write the low byte */
		voidWriteData(Copy_Image[Counter] & 0x00FF);


	}

	
}

void HTFT_voidFillColor(u16  Copy_u16Color)
{
	u16  Counter;

	HTFT_voidBounders(0,127,0,159);

	/* RAM write */
	voidWriteCommand(0x2C);

	for(Counter = 0 ; Counter < 20480 ; Counter++)
	{
		/* write the high byte */
		voidWriteData(Copy_u16Color >> 8);
		/* write the low byte */
		voidWriteData(Copy_u16Color & 0x00FF);


	}
	/* to invert color */
	//voidWriteCommand(0x21);


}

void HTFT_voidDrawRect(u8 x1, u8 x2, u8 y1, u8 y2, u16  Copy_u16Color)
{
	u16  Counter;

	u16 Size = (x2 - x1 +1) * (y2 - y1 +1);

	HTFT_voidBounders(x1,x2,y1,y2);

	/* RAM write */
	voidWriteCommand(0x2C);

	for(Counter = 0 ; Counter <= Size ; Counter++)
	{
		DrawTheColor(Copy_u16Color);
	}
	/* to invert color */
	//voidWriteCommand(0x21);


}

void HTFT_voidDrawChar(u8 x1,u8 y1,u16 CharColor, u16 BackColor, u8 charcter)
{
	u8 value;

	u8 charX1 = x1;
	u8 charY1 = y1;

    for (u8 i = 0; i < 5; i++)
    {
        for (u8 j = 0; j < 7; j++)
        {
            value = 0;

            value = ((font[(charcter) - 32][i]));

            if(value & (1 << j))
            {
            	HTFT_voidDrawPixel(charX1, charY1, CharColor);
            }
            else
            {
            	HTFT_voidDrawPixel(charX1, charY1, BackColor);
            }
            charY1 += PixelLenght;
            /* drawing "t"
              ####0###
              ###000##
              ####0###
              ####0###
              ####000#		<< shifting by charY1 += 3; to draw 8 pixels
             */

         }
        /* to set the charY1 to the start box of the letter */
        charY1 = y1;

        charX1 += PixelLenght;
        /* drawing "t"
          ####0###
          ###000##
          ####0###		/\
          ####0###		/\
          ####000#		/\ shifting by charX1 += 3; to draw 5 raws
         */
     }


}

void HTFT_voidDrawString(u8 x1,u8 y1,u16 CharColor, u16 BackColor, u8 * string)
{
	u8 x = x1;
	u8 y = y1;
	u8 c = 0;
	u8 i = 0;
	while(string[i] != '\0' )
	{

		c = string[i];
		HTFT_voidDrawChar(x,y,CharColor,BackColor,c);
		i++;
		x += ((PixelLenght * 5) + 2);
		//y += (PixelLenght * 5);
	}

}

