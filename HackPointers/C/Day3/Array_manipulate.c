#include <stdio.h>
#include <stdlib.h>

#include "../std_types.h"
#include "../bit_math.h"

/* this file contain all fun for arrays */

void Bubble_sort(u32* copy_arr,u32);//
void Swap_2Numbers(u32*copy_elem1,u32 *copy_elem2);
void display(u32 *arr,u32 size);
u32 Binary_Search(u32 arr[], u32 size, u32 key);
void Revers_Str(u8 * Str1);
u32 Lengthof_Str(u8 arr[]);
u32 *func(u32 a, u32 b);
u32 Binary_Search_recursion(u32 arr[], u32 low, u32 high, u32 key);
void Bubble_sort_recursion(u32* copy_arr,u32 n);//
u32 partition(u32 *arr, u32 low, u32 high);//
void quickSort(u32 *arr, u32 low, u32 high);
void Insertion_sort(u32 * arr,u32 size);
void merge(u32 * arr,u32 beg,u32 mid,u32 end);
void merge_sort(u32 * arr,u32 beg,u32 end);



int main() {
	u32 i,arr_intnums[10],search,index;
	
	for(i=0;i<10;i++){
		printf("Enter number %d: ",i);
		fflush(stdout);
		scanf("%d",&arr_intnums[i]);fflush(stdin);
		//Sum+=arr_intnums[i];
	}
	Bubble_sort(&arr_intnums[0],10);
	printf("The sorted array : \n");
	display(arr_intnums,10);
	
	
	printf("Enter number to search :");
	fflush(stdout);
	scanf("%d",&search);fflush(stdin);
	index=Binary_Search(arr_intnums,10,search);

	if(-1==index){
		printf("Enterd num not found\n");
		fflush(stdout);
	}
	else {
		printf("Enterd num at index :%d\n",index);
		fflush(stdout);
	}

    return 0;
}

void Bubble_sort(u32* copy_arr,u32 n){
	u32 i,j,flag=0;
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

void Swap_2Numbers(u32*copy_elem1,u32 *copy_elem2){
	
	*copy_elem1= *copy_elem1 +  *copy_elem2;
	*copy_elem2= *copy_elem1 -  *copy_elem2;
	*copy_elem1= *copy_elem1 -  *copy_elem2;

}

void display(u32 copy_arr[],u32 size){
	u32 i;
	for(i=0;i<size;i++){
		printf("%d\n",copy_arr[i]);
	}
	
}

u32 Binary_Search(u32 arr[], u32 size, u32 key) {
    u32 mid,low = 0, high = size - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == key) {
            break;  // Return index of key if found
        } else if (arr[mid] < key) {
            low = mid + 1;  // Key is in upper half
        } else {
            high = mid - 1;  // Key is in lower half
        }
		
    }
    if(low>high) mid =-1;
	return mid;  // Return -1 if key not found
}

u32 partition(u32 *arr, u32 low, u32 high)
{
	u32 pivot = arr[high];
	u32 j,i = (low - 1);
	
	for (j = low; j <= high - 1; j++) 
	{
		if (arr[j] <= pivot) 
		{
			i++;
			Swap_2Numbers(&arr[i], &arr[j]);
		}
	}
	Swap_2Numbers(&arr[i + 1], &arr[high]);
	return (i + 1);
}


void quickSort(u32 *arr, u32 low, u32 high)
{
	if (low < high) {
		u32 pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

/* 1st Assignment func to return length of str*/
u32 Lengthof_Str(u8 arr[]){
	u32 length = 0;
	while('\0'!=arr[length]){
		length ++;
	}
	return length;
}

/* 2nd Assignment */
void Bubble_sort_recursion(u32* copy_arr,u32 n){
	u32 j,flag=0;
	for(j=0;j<n-1;j++){
		
		if(copy_arr[j]>copy_arr[j+1]) {
			copy_arr[j]= copy_arr[j] +  copy_arr[j+1];
			copy_arr[j+1]= copy_arr[j] -  copy_arr[j+1];
		    copy_arr[j]= copy_arr[j] -  copy_arr[j+1];
			flag=1;
		}
	}
	
	if(flag==1){
		flag=0;
		Bubble_sort_recursion(copy_arr,j);
	}
	else{
	}
	
}


/* 4th Assignment */
								//1st  high ==size 			
u32 Binary_Search_recursion(u32 arr[], u32 low, u32 high, u32 key) {
    static u32 mid,j=0;
	
	mid = (low + high) / 2;
	printf("iteration num %d\n",++j);
    if(low>high) {
		mid =-1;
	}
    else if (arr[mid] == key) {
         // Return index of key if found
    } else if (arr[mid] < key) {
        low = mid + 1;  // Key is in upper half
		mid=Binary_Search_recursion(arr,low,high,key);
	} else {
		high = mid - 1;  // Key is in lower half
        mid=Binary_Search_recursion(arr,low,high,key);  // Key is in lower half
    }
		
	return mid;  // Return -1 if key not found
}

u32 *func(u32 a, u32 b) {
    u32 *arr = (u32 []) {a + b, a - b}; // temporary array this called compound Literal
    return arr;
}

void Revers_Str(u8 * Str1){
	u32 i, size = Lengthof_Str(Str1) - 1, mid =size/2;
	u8 Temp;
	
	for(i=0;i<mid;i++,size--){
		Temp =*(Str1+i);
		*(Str1+i)=*(Str1+size); 
		*(Str1+size)=Temp;	
	
	}
}

void Insertion_sort(u32 * arr,u32 size){
	
	u32 i,num;
	s32 j;
    for(i=1 ; i<size ; i++)
    {
        j=i-1;
        num = arr[i];

        while( (j>-1) && (arr[j] > num) )
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1]=num;
    }
}

void merge_sort(u32 * arr,u32 beg,u32 end){
	if(beg < end){
		int mid = (beg + end)/2;
		/* divide into 2 arr L and R and sort */
		merge_sort(arr,beg,mid);   /* L arr */
		merge_sort(arr,mid+1,end); /* R arr */
		/*  */
		merge(arr,beg,mid,end);
	}
	
}

void merge(u32 * arr,u32 beg,u32 mid,u32 end){
	u32 i , j , k ;
	u32 arrL_size = mid - beg + 1 ;
	u32 arrR_size = end - mid ;
	
	u32 arrL[arrL_size] , arrR[arrR_size] ;
	/* copy elem in temp arr L & R */
	for(i=0;i<arrL_size;i++) 
		arrL[i]=arr[l+i];
	for(j=0;j<arrR_size;j++) 
		arrL[j]=arr[mid+j+1];	
	
	i=0;
	j=0;
	k=0;
	
	while(i<arrL_size && j < arrR_size){
		if(arrL[i] <= arrR[j])
		{
			arr[k]= arrL[i];
			i++;
		}
		else{
			arr[k]= arrR[j];
		    j++;
		}
		k++;
	}
	while(i<arrL_size){
		arr[k]= arrL[i];
	    i++;
		k++;
	}
	while(j<arrR_size){
		arr[k]= arrR[j];
	    j++;
		k++;
	}
	
}