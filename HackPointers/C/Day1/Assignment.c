#include <stdio.h>

int main (void){
	
	int Var1 , Var2 ,Var3;
	
	/* Assignment 1 */
	printf("\t     *     \n");
	printf("\t    ***    \n");
	printf("\t   *****   \n");
	printf("\t  *******  \n");
	printf("\t ********* \n");
	printf("\t***********\n");
	
	/* Assignment 2 */
	
	printf("\nPlease Enter the number 1 :\t");
	scanf("%i",&Var1);
	printf("\nPlease Enter the number 2 :\t");
	scanf("%i",&Var2);
	printf("\nPlease Enter the number 2 :\t");
	scanf("%i",&Var3);
	printf("\n the 3rd number %d \n ",Var3);
	printf("\n the 2nd number %d \n ",Var2);
	printf("\n the 1st number %d \n ",Var1);
	
	/* Assignment 3 */
	
	printf("\nPlease Enter the number 1 :\t");
	scanf("%i",&Var1);
	printf("\nPlease Enter the number 2 :\t");
    scanf("%i",&Var2);
    printf("\n a+b = %d \n ",Var1+Var2);
    printf("\n a-b = %d \n ",Var1-Var2);
	printf("\n a&b = %d \n ",Var1&Var2);
	printf("\n a|b = %d \n ",Var1|Var2);
	printf("\n a^b = %d \n ",Var1^Var2);	
	
	return 0;
}