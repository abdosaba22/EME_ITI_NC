/* ************************************************ */
/* Author      : Abd-alrahman Amin                  */
/* SWC         : LCD                                */
/* Layer       : HAL                                */
/* Version     : 1.1                                */
/* Date        : August 7, 2023                     */
/* Last Edit   : August 8, 2023	                    */
/* ************************************************ */

#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

/* LCD commands */
#define HLCD_START_LINE_1							0x80U
#define HLCD_START_LINE_2							0xC0U
#define HLCD_CLEAR_DISPLAY 							0x01U
#define HLCD_CURSOR_ON 								0x0EU
#define HLCD_CURSOR_OFF			 					0x0CU
#define HLCD_SHIFT_RIGHT 							0x18U
#define HLCD_SHIFT_LEFT 							0x1CU
#define HLCD_MOVE_LEFT 								0x10U
#define HLCD_MOVE_RIGHT 							0x14U
#define HLCD_FUNCTION_SET							0x3CU
#define HLCD_ENTRY_MODE_SET 						0x06U
#define HLCD_DISPLAY_OFF 							0x08U
#define HLCD_DISPLAY_ON 							0x0FU
#define HLCD_ENABLE_4BIT_MODE 						0x32U
#define HLCD_INIT 									0x33U



void HLCD_voidInit(void);
void HLCD_voidSendCmd(u8);
void HLCD_voidSendChar(char);
void HLCD_voidSendNum(u16);
void HLCD_voidSendString(const char *);
void HLCD_voidSetCur(u8 , u8 );
void HLCD_voidClear (void);


#endif
