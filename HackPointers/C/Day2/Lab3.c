#include <stdio.h>

int main (void){
	/* Lab 3 */
/* 	int Local_intID;
	
 	printf("please Enter the Number:\t");
	scanf("%d",&Local_intID);
 */
/*	
	if( (Local_intTemp&1) && (Local_intTemp%2!=0) ){
		printf("The Num %d is Odd ",Local_intTemp);
	}
	else {
		printf("The Num %d is Even ",Local_intTemp);
	}
 */
	/* if( (Local_intTemp ==( Local_intTemp/2)*2 )  && ( )) {
		printf("The Num %d is Even ",Local_intTemp);
	}
	else {
		printf("The Num %d is Odd ",Local_intTemp);
	}
 */
/* 	if(Local_intgrade >= 85){
		printf("grade is Excellent");
	}
	else if(Local_intgrade >= 75){
		printf("grade is very good");
	}
	else if(Local_intgrade >= 65){
		printf("grade is good");
	}	
	else if(Local_intgrade >= 50){
		printf("grade is Normal");
	}
	else {
		printf("failed");
	}	
 */
	/* int j =6;
	switch(Local_intID){
		int y;
		j++;
		case 1: printf("welcome Ahmed")	; break;
		case 2: printf("welcome Ahmed")	; break;
		case 34: printf("welcome Ahmed")	; break;
		case 1234: printf("welcome Ahmed")	; break;
		case 5678: printf("welcome Youssef"); printf("  j is %d , y is %d",j,y);break;
		case 1145: printf("welcome Mina")	; break;
		default:   printf("wrong ID ")		; break;
	}
	 */
	 
//	int i=1,Local_Enterednum , sum=0;
	
	/* for(;i<10;i++){
		printf("Abdalrahman \n");
	} */
	/* printf(" Please Enter 10 Numbers \n");
	for(;i<=10;i++){
		printf(" Number %d is : ",i);
		fflush(stdout);
		scanf("%d",&Local_Enterednum);
		fflush(stdin);
		sum+=Local_Enterednum;	
	}
	printf("the sum is %d the average is %.2f \n",sum,(sum/10.0));
	 */
/* 	int res ; 
	printf("Enter the res of 3 * 4 = ");
	fflush(stdout);
	scanf("%d",&res);
	fflush(stdin);
	while(res!=12){
		printf("Not correct , please try again: ");
		fflush(stdout);
		scanf("%d",&res);
		fflush(stdin);
	}
	printf("Thank you");
	fflush(stdout);
	 */
	/* int given_num , i=1;
	printf("Enter number to display its Multiplication table : ");
	fflush(stdout);
	scanf("%d",&given_num);
	fflush(stdin);
	
	while(i<=given_num){
		
		printf(" %d * %d \n",given_num,i++);
		
		fflush(stdout);
	}
	/*
	do{
		printf(" %d * %d \n",given_num,i++);
		//fflush(stdout);
	}while(i<=given_num);
	*/
	int x , res=1;
	printf("Enter number to display its factorial: ");
	fflush(stdout);
	scanf("%d",&x);
	fflush(stdin);
	while(x>=1){
		res*=x--;
	}
	printf("factorial is %d: ",res);
	fflush(stdout);
	
	
	
	return 0;
}