#include <stdio.h>

int SumTwoVar(int*,int*);

int main() {
	int x,y;
	
	printf("Please Enter value 1 : \n");fflush(stdout);
	scanf("%d",&x);fflush(stdin);
	printf("Please Enter value 2 : \n");fflush(stdout);
	scanf("%d",&y);fflush(stdin);
	
		
	printf("the sum is %d \n",SumTwoVar(&x,&y));fflush(stdout);
    return 0;
}

int SumTwoVar(int*ptr_x,int*ptr_y){
	int Local_sum =  *ptr_x + *ptr_y ;
	return Local_sum;
}

