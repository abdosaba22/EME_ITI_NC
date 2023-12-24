#include "LSTD_types.h"
#include "LBIT_math.h"

#include "MDIO_interface.h"
#include "MGIE_interface.h"
#include "MTIM_interface.h"

void TOG(void);


int main(void)
{




	MDIO_stderrSetPinDirection(MDIO_PORTB,0,MDIO_OUTPUT);
	MTIM_stderrInit(MTIM_TIMER0,MTIM_CS_PRESCALER_1024,MTIM_MODE_T0T2_NORMAL,MTIM_HWPIN_T0T2_DISCONNECTED);
	MTIM_stderrEnableInterrupt(MTIM_INTERRUPT_T0_OVF);
	MGIE_voidEnableGI();
	MTIM_stderrSetCallBack(TOG,MTIM_INTERRUPT_T0_OVF);
	MTIM_stderrTimerDelay(MTIM_TIMER0,1000);
	MTIM_stderrStartTimer(MTIM_TIMER0);
	while(1)
	{

	}
	return 0;
}

void TOG(void)
{
	MDIO_stderrTogglePinValue(MDIO_PORTB,0);
}
