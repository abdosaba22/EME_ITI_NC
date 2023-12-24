/* Library Includes */
#include "LSTD_types.h"
#include "LBIT_math.h"

#include "HLED_Private.h"
#include "HLED_Interface.h"
#include "MGPIO_interface.h"

/* config LEDs */
LED_t LED1=
{
.LedPin.Port=PORTA,
.LedPin.Pin=PIN0,
.LedPin.Mode=LED_MODE,
.LedPin.Speed=LED_SPEED,
.LedPin.OutputType= LED_OUTPTYPE,
.LedPin.PullType= LED_PULLTYPE,
.conn_type=LED_SourceConnnec,
};

LED_t LED2=
{
.LedPin.Port=PORTA,
.LedPin.Pin=PIN1,
.LedPin.Mode=LED_MODE,
.LedPin.Speed=LED_SPEED,
.LedPin.OutputType= LED_OUTPTYPE,
.LedPin.PullType= LED_PULLTYPE,
.conn_type=LED_SourceConnnec,
};

LED_t LED3=
{
.LedPin.Port=PORTA,
.LedPin.Pin=PIN2,
.LedPin.Mode=LED_MODE,
.LedPin.Speed=LED_SPEED,
.LedPin.OutputType= LED_OUTPTYPE,
.LedPin.PullType= LED_PULLTYPE,
.conn_type=LED_SourceConnnec,
};

LED_t LED4=
{
.LedPin.Port=PORTA,
.LedPin.Pin=PIN3,
.LedPin.Mode=LED_MODE,
.LedPin.Speed=LED_SPEED,
.LedPin.OutputType= LED_OUTPTYPE,
.LedPin.PullType= LED_PULLTYPE,
.conn_type=LED_SourceConnnec,
};

LED_t LED5=
{
.LedPin.Port=PORTA,
.LedPin.Pin=PIN4,
.LedPin.Mode=LED_MODE,
.LedPin.Speed=LED_SPEED,
.LedPin.OutputType= LED_OUTPTYPE,
.LedPin.PullType= LED_PULLTYPE,
.conn_type=LED_SourceConnnec,
};

LED_t LED6=
{
.LedPin.Port=PORTA,
.LedPin.Pin=PIN5,
.LedPin.Mode=LED_MODE,
.LedPin.Speed=LED_SPEED,
.LedPin.OutputType= LED_OUTPTYPE,
.LedPin.PullType= LED_PULLTYPE,
.conn_type=LED_SourceConnnec,
};

LED_t LED7=
{
.LedPin.Port=PORTA,
.LedPin.Pin=PIN6,
.LedPin.Mode=LED_MODE,
.LedPin.Speed=LED_SPEED,
.LedPin.OutputType= LED_OUTPTYPE,
.LedPin.PullType= LED_PULLTYPE,
.conn_type=LED_SourceConnnec,
};

LED_t LED8=
{
.LedPin.Port=PORTA,
.LedPin.Pin=PIN7,
.LedPin.Mode=LED_MODE,
.LedPin.Speed=LED_SPEED,
.LedPin.OutputType= LED_OUTPTYPE,
.LedPin.PullType= LED_PULLTYPE,
.conn_type=LED_SourceConnnec,
};
