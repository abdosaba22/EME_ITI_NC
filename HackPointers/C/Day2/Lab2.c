#include <stdio.h>

int main (void){
	/* Lab 2 */
	int  Local_intworkinghour ;
	
	printf("please Enter your working hour:\t\n");
	scanf("%d",&Local_intworkinghour);
	
	if(40<Local_intworkinghour)
	{
		printf("your salary is %d",Local_intworkinghour*50 );
		
	}
	else
	{
		printf("your salary is %d",(Local_intworkinghour*45) );
		
	}

	
	return 0;
}