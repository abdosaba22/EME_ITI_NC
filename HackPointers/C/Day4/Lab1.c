#include <stdio.h>

int main() {
	int x=10;
	int *ptr=&x;
	
	printf("X before change : %d\n", x);fflush(stdout);
	*ptr=20;
	printf("X After change : %d\n", x);fflush(stdout);
    //printf("ptr = %p\n", ptr);fflush(stdout);
	//ptr++;
	//printf("ptr = %p\n", ptr);fflush(stdout);
	return 0;
}