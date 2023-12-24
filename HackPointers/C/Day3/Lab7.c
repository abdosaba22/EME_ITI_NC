#include <stdio.h>


void Bubble_sort(int* copy_arr,int);
void Swap_2Numbers(int*copy_elem1,int *copy_elem2);
void display(int *arr,int size);

int main() {
	int i,arr_intnums[11];
	
	for(i=0;i<10;i++){
		printf("Enter number %d: ",i);
		fflush(stdout);
		scanf("%d",&arr_intnums[i]);fflush(stdin);
		//Sum+=arr_intnums[i];
	}
	Bubble_sort(&arr_intnums[0],10);
	printf("The sorted array : \n");
	display(&arr_intnums[0],10);
    return 0;
}

void Bubble_sort(int* copy_arr,int n){
	int i,j,flag=0;
	for(i=0;i<n-1;i++){
		flag=0;
		for(j=0;j<n-1-i;j++){
			if(copy_arr[j]>copy_arr[j+1]) {
				Swap_2Numbers(&copy_arr[j],&copy_arr[j+1]);
				flag=1;
			}
		}
		if(flag==0){break;}
		else{}
	
	}
	
}

void Swap_2Numbers(int*copy_elem1,int *copy_elem2){
	/* 1st method  */
	 /* num1= num1+num2;
	num2=num1-num2;
	num1=num1-num2;
	 */

	/* 2nd method */
/* 	 num1=num1^num2;
	num2=num2^num1;
	num1=num1^num2;
 */
 
	/* 3rd method */
 	*copy_elem1= *copy_elem1 +  *copy_elem2;
	*copy_elem2= *copy_elem1 -  *copy_elem2;
	*copy_elem1= *copy_elem1 -  *copy_elem2;

}
void display(int* copy_arr,int size){
	int i;
	for(i=0;i<size;i++){
		printf("%d\n",copy_arr[i]);
	}
	
}