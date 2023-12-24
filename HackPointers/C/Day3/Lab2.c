#include <stdio.h>

int Max_Number(int,int);

int main() {
    int num1,num2,Max;
   
	
	printf("please Enter the 1st num:\t");fflush(stdout);
	scanf("%d",&num1);fflush(stdin);
	printf("please Enter the 2nd num:\t");fflush(stdout);
	scanf("%d",&num2);fflush(stdin);
	Max=Max_Number(num1,num2);
	printf("Max is %d \n", Max);fflush(stdout);
	

    return 0;
}

int Max_Number(int Copy_num1,int Copy_num2){
	int Local_Max=Copy_num1;
	if(Copy_num2>Copy_num1){
		Local_Max=Copy_num2;
	}
	else{
		
	}
	return Local_Max;
}