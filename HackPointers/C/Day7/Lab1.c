#include <stdio.h>
#include "../std_types.h"


typedef struct{
	s32 x:1;
	s32 y:4;
	s32 z:4;
}S_Studentsbit_t;



/* 
 *		bit field  x 0b1 only 1 bit th sign bit is 1 so negative num x is -2^(n-1) = -1 
 *		bit field  y 0b0010 the sign bit is 0 so positive num y is  2
 *		bit field  z 0b1101 the sign bit is 1 so negative num z is 0011 2's complement =3 
 *
 */

int main() {
	
	S_Studentsbit_t m={1,2,13};	
    
    printf("%d byte\t \n", sizeof(m));
	
	printf("x = 0b%d\t\t x=%d\n", (m.x>>0&1) , m.x);
	printf("y = 0b%d%d%d%d \t y=%d \n", (m.y>>3&1),(m.y>>2&1),(m.y>>1&1), (m.y>>0&1),m.y);
	printf("z = 0b%d%d%d%d \t z=%d \n", (m.z>>3&1),(m.z>>2&1),(m.z>>1&1), (m.z>>0&1),m.z);
	
    return 0;
}