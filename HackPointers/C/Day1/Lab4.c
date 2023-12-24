#include <stdio.h>

int main (void){
	/*  4rd Lab  have 2 Variables from user and print some operations */
	int Var1 , Var2 ;
	printf("\nPlease Enter the number 1 :\t");
	scanf("%i",&Var1);
	printf("\nPlease Enter the number 2 :\t");
	scanf("%i",&Var2);
	/*  printing */
	printf("\n a&b = %d \n ",Var1&Var2); 	/* res=4 			*/
 	printf("\n a|b = %d \n ",Var1|Var2); 	/* res=7 			*/
	printf("\n a^b = %d \n ",Var1^Var2); 	/* res=3 			*/
	printf("\n a>>1 = %d \n ",Var1>>1);	 	/* res=3  div by 2 	*/
	printf("\n b<<2 = %d \n ",Var2<<2);	 	/* res=16 mul by 4 	*/
	return 0;
}
