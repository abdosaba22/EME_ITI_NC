#include <stdio.h>

void Func1(int,int,int*,int*);

int main() {
	int x,y,Sum,Mul;
	
	printf("Please Enter value 1 : \n");fflush(stdout);
	scanf("%d",&x);fflush(stdin);
	printf("Please Enter value 2 : \n");fflush(stdout);
	scanf("%d",&y);fflush(stdin);
	
	Func1(x,y,&Sum,&Mul);	
	printf("the sum is %d the mul is %d \n",Sum,Mul);fflush(stdout);
    return 0;
}

void Func1(int copy_x,int copy_y,int*ptrSum,int*ptrMul)
{
	*ptrSum=copy_x +copy_y;
	*ptrMul=copy_x *copy_y;
}