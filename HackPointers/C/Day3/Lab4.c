#include <stdio.h>

int Factorial(char);

int main() {
	char x;
	printf("Enter number to display its factorial: ");
	fflush(stdout);
	scanf("%d",&x);
	fflush(stdin);
	printf("factorial is %d: ",Factorial(x));
	fflush(stdout);
}
int Factorial(char copy_x){
	static int Local_res=1;
	/*Local_res*=copy_x;
	 */
	if(1!=copy_x){
		Local_res=copy_x*Factorial(copy_x-1);
	}
	else{
		
	}
	return Local_res;
}

