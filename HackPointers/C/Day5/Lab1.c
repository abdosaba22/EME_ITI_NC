#include <stdio.h>

int main (void){
	int x=5;
	int *ptrx=&x;
	int** ptrtoptr= &ptrx;
	
	printf("x is using p2 is %d \n",**ptrtoptr);
	** ptrtoptr=10;
	
	printf("x is using p2 is %d \n",**ptrtoptr);
	
	return 0;
}