#include <stdio.h>
#include <stdarg.h>

int Sum(int n,...);

int main() {
	int x,y,z;
	x=Sum(3,1,2,3);
	y=Sum(4,1,2,3,4);
	z=Sum(2,2,3);
	printf("sum of x is %d  \nsum of y is %d  \n sum of z is %d  \n ",x,y,z);
	fflush(stdout);
}
int Sum(int n,...){
	int i,sum=0;
	va_list ar;
	va_start(ar,n);
	for(i=0;i<n;i++){
		sum+=va_arg(ar,int);
	}
	va_end(ar);
	return sum;
}

