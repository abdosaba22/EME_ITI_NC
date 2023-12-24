#ifndef _HLED_INTERFACE_H_
#define _HLED_INTERFACE_H_

#include "MGPIO_interface.h"


#define LED_SourceConnnec		 0 // to turn on need high pin
#define LED_SinkConnec  		 1 // to turn on need LOW pin



typedef struct
{
	MGPIO_CONFIG_t LedPin;
	u8 conn_type; /* connection type */
}LED_t;

void HLED_voidInit(const LED_t * LED_Config);
void HLED_voidTurnOn(const LED_t * LED_Config);
void HLED_voidTurnOff(const LED_t * LED_Config);
void HLED_voidToggle(const LED_t * LED_Config);
/* extern var to be included in main */
extern LED_t LED1 ;
extern LED_t LED2 ;
extern LED_t LED3 ;
extern LED_t LED4 ;
extern LED_t LED5 ;
extern LED_t LED6 ;
extern LED_t LED7 ;
extern LED_t LED8 ;



#endif
