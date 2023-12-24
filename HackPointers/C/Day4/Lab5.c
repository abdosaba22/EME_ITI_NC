#include <stdio.h>

void display(int * arr,int size);

int main() {
	int i,arr_intnums[10];
	

	for(i=0;i<10;i++){
		printf("Enter number %d: ",i);
		fflush(stdout);
		scanf("%d",&arr_intnums[i]);fflush(stdin);	
	}
	
	display(arr_intnums,10);	
    return 0;
}

void display(int * arr,int size){
	int i;
	for(i=0;i<size;i++){
		printf("%d\n",arr[i]);
	}
	
}