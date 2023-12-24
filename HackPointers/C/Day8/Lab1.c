#include <stdio.h>
#include <stdlib.h>

#include "../std_types.h"
#include "../bit_math.h"



void Bubble_sort(u8* arr,u8 size);
void display(u8 *copy_arr,u8 size);

int main (void)
{
	u8 i,Local_u8NumberElem=0;
	
	printf("enter the Number of elemnt:\t");fflush(stdout);
	scanf("%d",&Local_u8NumberElem);fflush(stdin);
	
	u8 * u8_ptr=(void *)0;
	
	u8_ptr = (u8 * ) malloc(sizeof(u8) * Local_u8NumberElem);
	
	for(i=0;i<Local_u8NumberElem;i++){
		printf("enter the elemnt %d:",i);fflush(stdout);
		scanf("%d",&u8_ptr[i]);fflush(stdin);
	}
	//u8_ptr[10]=5;
	/* sort using bubble sort alg */
	Bubble_sort(u8_ptr,Local_u8NumberElem);
	/* display  */
	printf("\nThe sorted elem :\n");fflush(stdout);	
	display(u8_ptr,Local_u8NumberElem);
	free(u8_ptr);
//	*u8_ptr = 5;
	
	//printf("\n%d\n",*u8_ptr);fflush(stdout);
	return 0;
}


void Bubble_sort(u8* arr,u8 size){
	u8 i,j,flag=0;
	for(i=0;i<size-1;i++){
		flag=0;
		for(j=0;j<size-i-1;j++){
			/* swap */
			if(arr[j]>arr[j+1]){
				arr[j]  = arr[j] +  arr[j+1];
				arr[j+1]= arr[j] -  arr[j+1];
				arr[j]  = arr[j] -  arr[j+1];
				flag=1;
			}
		}
		if(0==flag) {break;}
		else{}
	}
	
}

void display(u8 * copy_arr,u8 size){
	int i;
	for(i=0;i<size;i++){
		printf("%d\n",copy_arr[i]);fflush(stdout);
	}
	
}
