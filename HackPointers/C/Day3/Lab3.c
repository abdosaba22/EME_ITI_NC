#include <stdio.h>

int num1 =10,num2 = 20;

void Swap_2Numbers(void);

int main() {
    
	printf("1st num before swap :  %d \n",num1);fflush(stdout);
	printf("2nd num before swap :  %d \n \n",num2);fflush(stdout);
	
	Swap_2Numbers();
	
	printf("the 1st num is %d\nthe 2nd num is %d\n",num1 ,num2);fflush(stdout);
	

    return 0;
}


void Swap_2Numbers(void){
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
 	num1=num1*num2;
	num2=num1/num2;
	num1=num1/num2;

}