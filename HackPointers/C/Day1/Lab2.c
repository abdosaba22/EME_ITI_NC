#include <stdio.h>

int main (void){
	/*  2nd Lab  read a var from user and print it */
	signed int x ;
	printf("\nPlease Enter the value:\t");
	scanf("%i",&x);
	x=x>>1;
	printf("\nThe value you entered is %i\n\n ",x);
	
	return 0;
}
