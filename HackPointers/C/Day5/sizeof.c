#include <stdio.h>

#include "../std_types.h"

const u8 h=10;

void change(const u8 * ptr){
	u8**p=&ptr;
	**p=10;
	/**ptr=30; //error */
}

int main (void){

	printf("size of u8 is %lu  bytes\n",sizeof(u8));
	printf("size of s8 is %lu  bytes\n",sizeof(s8));
	printf("size of u16 is %lu  bytes\n",sizeof(u16));
	printf("size of s16 is %lu  bytes\n",sizeof(s16));
	printf("size of u32 is %lu  bytes\n",sizeof(u32));
	printf("size of s32 is %lu  bytes\n",sizeof(s32));
	printf("size of f32 is %lu  bytes\n",sizeof(f32));
	printf("size of f64 is %lu  bytes\n",sizeof(f64));
	
	u8 x=5;
	u8 * p=&h;
	/* *p=20; */
	printf("%d ,",h); fflush(stdout);
	change(&x);
	printf("%d",x);

	
	return 0;
	
}

