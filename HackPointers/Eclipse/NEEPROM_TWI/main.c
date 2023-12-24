

#define F_CPU 8000000UL

#include "LSTD_types.h"
#include "LBIT_math.h"
#include<util/delay.h>
#include "MDIO_interface.h"
#include "MTWI_interface.h"

#include"HLCD_interface.h"
#include"HNVM_interface.h"

int main(void)
{
	u8 L_u8Data=0;
	MDIO_stderrSetPinDirection(MDIO_PORTC,0,MDIO_INPUT_PULLUP); // SCL and SDA must be input
    MDIO_stderrSetPinDirection(MDIO_PORTC,1,MDIO_INPUT_PULLUP);
    MTWI_voidEnable();
    HNVM_stderrInit();
    HLCD_voidInit();
    HLCD_voidSendString("Welcome");
    _delay_ms(1000);
    HLCD_voidClear();
    _delay_ms(1000);

	while(1)
	{
		HNVM_voidWrite(0x00,'A');
		HLCD_voidSendString("DATA WRITTEN : A");
		_delay_ms(1000);
		HLCD_voidClear();
		_delay_ms(2);
		L_u8Data = HNVM_u8Read(0x00);
		HLCD_voidSendString("DATA READ :  ");
		HLCD_voidSendChar(L_u8Data);
		_delay_ms(1000);
		HLCD_voidClear();
		_delay_ms(2);
		_delay_ms(250);
	}


	return 0;
}

