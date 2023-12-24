#include <stdio.h>
#include "../std_types.h"

//#pragma pack(1) // for remove padding 

typedef struct {
	u8 Math;
	u16 Language;
	u8 Physics;
	u16 Chemistry;
}__attribute__((packed)) S_Students8_t;

typedef struct{
	u8 Math;
	u8 Language;
	u8 Physics;
	u8 Chemistry;
}S_Students6_t;

typedef struct{
	u8 x:2;
	u8 y:3;
	u8 z:3;
}S_Studentsbit_t;

typedef struct{
	u8 B0:1;
	u8 B1:1;
	u8 B2:1;
	u8 B3:1;
	u8 B4:1;
	u8 B5:1;
	u8 B6:1;
	u8 B7:1;
}S_BITS_t;

typedef union { 
	u8 Byte;
	S_BITS_t BIT;
	
}U_REG_X_t;

int main() {
	S_Students8_t x;
	S_Students6_t y={10,20,30,40},*p=&y;
	U_REG_X_t regx;
	regx.Byte=10;
	S_Studentsbit_t m={1,2,3};	
    
	printf("%d\t \n", sizeof(x));
    printf("%d\t \n", sizeof(y));
    printf("%d\t \n", sizeof(m));
	printf("%d\t \n", sizeof(regx));
	printf("%d\t \n", sizeof(S_BITS_t));
	printf("%d\t \n", regx);
	regx.BIT.B0=1;
	printf("%d\t \n", regx);
	printf("%p \n", p);
	//((u8*)p+1);
	printf("%p \n", ((u8*)p + 1));
	
    return 0;
}