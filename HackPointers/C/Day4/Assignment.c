#include <stdio.h>

int Lengthof_Str(char arr[]);
void display(int copy_arr[],int size);
void Bubble_sort(int* copy_arr,int n);
int Binary_Search(int arr[], int low, int high, int key);
int *func(int a, int b);
void Revers_Str(char * Str1);
/* void func1(void){
	static int k=1;
	printf("inside func1 k is %d\n",k);
	k++;
}
 */
const int gvar=10;
int main() {
	char str[]="ALI"; /*11 */
	//printf("Length of arr = %d\n",Lengthof_Str(str));
	//int arr[10]={3,5,7,6,10,50,60,100,20,46};
	//Bubble_sort(arr,10);
	//display(arr,10);
	int *k=&gvar;
	*k=15;
	printf("%s \n",str);
	Revers_Str(str);
	printf("%s \n",str);
	int arr[10]={1,2,5,6,8,13,20,25,30,36},index=0;
	int *ptrc=func(5,10);
	printf("%d , %d \n",ptrc[0],ptrc[1]);
	
	/* Assignment3 */
	int x = 10, y = 20, z = 30;
    int *p = &x, *q = &y, *r = &z;
    //x=5;
    printf("x: %d, y: %d, z: %d\n", x, y, z);
    printf("p: %p, q: %p, r: %p\n", p, q, r);
    printf("*p: %d, *q: %d, *r: %d\n", *p, *q, *r);
    
    printf("Swapping pointers\n");
    
    int *temp = r;
    r = p;
    p = q;
    q = temp;
    
    printf("x: %d, y: %d, z: %d\n", x, y, z);
    printf("p: %p, q: %p, r: %p\n", p, q, r);
    printf("*p: %d, *q: %d, *r: %d\n", *p, *q, *r);
	index=Binary_Search(arr,0,10,5);
	if(-1 != index ){
		printf("index at %d\n",index);
	}else{printf("Not found");}
	//printf("%d "Binary_Search(arr,size,key));
	/* 
	int x=30000;
	int * ptr=&x;
	char xs[10]="myName";
	char *ptrs="myName";
	
	printf("%s\n",ptrs);
	printf("%s\n",xs);
	
	xs[0]='M';
	ptr[0]='M';
	printf("%s\n",xs);
	printf("%s\n",ptrs);
	
	void (*func_ptr)(void)=func1;
	func_ptr();
	func_ptr();
	unsigned char byte2 = *((unsigned char*)ptr + 1);
	ptr=&x;
	unsigned short int byte1_2 = *((unsigned short int*)ptr);
	
	printf("%d\n",byte2);
	ptr=&x;
	printf("%d",byte1_2);
	
	 */
	
    return 0;
	
}

/* 1st Assignment func to return length of str*/
int Lengthof_Str(char arr[]){
	int length = 0;
	while('\0'!=arr[length]){
		length ++;
	}
	return length;
}

/* 2nd Assignment */
void Bubble_sort(int* copy_arr,int n){
	int j,flag=0;
	for(j=0;j<n-1;j++){
		
		if(copy_arr[j]>copy_arr[j+1]) {
			copy_arr[j]= copy_arr[j] +  copy_arr[j+1];
			copy_arr[j+1]= copy_arr[j] -  copy_arr[j+1];
		    copy_arr[j]= copy_arr[j] -  copy_arr[j+1];
			flag=1;
		}
	}
	//display(copy_arr,10);
	//printf("flag is %d ,,, \n",flag);
	if(flag==1){flag=0;Bubble_sort(copy_arr,j);}
	else{
	}
}

/* 3rd Assignment */
void display(int copy_arr[],int size){
	int i;
	for(i=0;i<size;i++){
		printf("%d\n",copy_arr[i]);
	}
}

/* 4th Assignment */
								//1st  high ==size 			
int Binary_Search(int arr[], int low, int high, int key) {
    static int mid,j=0;
	
	mid = (low + high) / 2;
	printf("iteration num %d\n",++j);
    if(low>high) {
		mid =-1;
	}
    else if (arr[mid] == key) {
         // Return index of key if found
    } else if (arr[mid] < key) {
        low = mid + 1;  // Key is in upper half
		mid=Binary_Search(arr,low,high,key);
	} else {
		high = mid - 1;  // Key is in lower half
        mid=Binary_Search(arr,low,high,key);  // Key is in lower half
    }
		
	return mid;  // Return -1 if key not found
}

int *func(int a, int b) {
    int *arr = (int []) {a + b, a - b}; // temporary array this called compound Literal
    return arr;
}

void Revers_Str(char * Str1){
	int i, size = Lengthof_Str(Str1) - 1, mid =size/2;
	char Temp;
	
	for(i=0;i<mid;i++,size--){
		Temp =*(Str1+i);
		*(Str1+i)=*(Str1+size); 
		*(Str1+size)=Temp;	
		//printf("%d\n",copy_arr[i]);
	}
}
