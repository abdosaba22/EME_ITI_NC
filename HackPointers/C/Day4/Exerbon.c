#include <stdio.h>

void func1(void){
	static int k=1;
	printf("inside func1 k is %d\n",k);
	k++;
}

int main() {
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
	
	
	
    return 0;
	
}