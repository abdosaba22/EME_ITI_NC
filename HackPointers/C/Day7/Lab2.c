#include <stdio.h>
//#include "../std_types.h"
#define X 5

#define print() do{ \
	int g =5; \
	printf("hello \n");  \
	printf("g is %d inside macro",g);\
}while(0)


int main() {
	#if X==5 
		int y=X;
	#elif X==6
		int y=6;
	#else
		int y=10;
	#endif
	 printf("Abdalrahman Amin Sabaa ^ _ ^ \n");	
	print();
	//printf("%d",g);
    return 0;
}