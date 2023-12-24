#ifndef _BIT_MATH_H_
		
#define _BIT_MATH_H_


#define GIT_BIT(REG,BIT)  		 ( (REG>>BIT) & 1 )
#define SIT_BIT(REG,BIT)  		 ( REG|= ( 1<<BIT ) )
#define CLEAR_BIT(REG,BIT) 		 ( REG&=~( 1<<BIT ) )
#define TOGGLE_BIT(REG,BIT) 	 ( REG^= ( 1<<BIT ) )


#endif