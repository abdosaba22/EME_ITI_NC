#include <stdio.h>

long long int Func1(int*,int);

int main() {
	int i,arr_intnums[10];
	

	for(i=0;i<10;i++){
		printf("Enter number %d: ",i);
		fflush(stdout);
		scanf("%d",&arr_intnums[i]);fflush(stdin);	
	}
	
		
	printf("the sum of arr is %lld \n",Func1(arr_intnums,10));fflush(stdout);
    return 0;
}

long long int Func1(int*arr,int size)
{
	int j;
	long long int Local_sum=0;
	for(j=0;j<size;j++){
		Local_sum+=(*arr++);
	}
	return Local_sum;
}