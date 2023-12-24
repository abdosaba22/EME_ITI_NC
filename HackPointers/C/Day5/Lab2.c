#include <stdio.h>

typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;
typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;
typedef float  f32;
typedef double f64;

typedef unsigned long int u8;
typedef unsigned long int u8;

int main (void){
	/* unsigned char x=128;
	signed char y= 127;
	//unsigned char *ptr=&y;
	printf(" befor incr x is %u , y is %d \n",x,y);
	x+=2;
	y++;						  
	printf(" after incr x is %u , y is %d \n",x,y);
	//printf(" y is %d",*ptr); */
	char a;
	int x ;
	float y;
	double z;
	short int b;
	long int c;
	long double m;
	
	printf("size of char is %d \nsize of int is %d\n\
size of float is %d \nsize of double is %d\nsize of short int is %d\nsize of long int is %d\nsize of long double is %d\n ",sizeof(a),sizeof(x),sizeof(y),sizeof(z),sizeof(b),sizeof(c),sizeof(long double));
	
	return 0;
	
}

