#include <stdio.h>

long int Add(void);
long int Sub(void);
long int Mul(void);
float Div(void);
long int And(void);
long int OR(void);
long int Not(void);
long int Xor(void);
long int Rem(void);
long int Inc(void);
long int Dec(void);

int main() {
	int OperationID;
	long int res;
	printf("The operation ID is ");fflush(stdout);
	scanf("%d",&OperationID);fflush(stdin);
	printf("Enter the operands: ");fflush(stdout);
	switch(OperationID){
		case 1 : printf("%ld ",Add()); fflush(stdout);    break;
		case 2 : printf("%ld ",Sub()); fflush(stdout);    break;
		case 3 : printf("%ld ",Mul()); fflush(stdout);    break;
		case 4 : printf("%.2f",Div()); fflush(stdout);    break;
		case 5 : printf("%ld ",And()); fflush(stdout);    break;
		case 6 : printf("%ld ", OR()); fflush(stdout);    break;
		case 7 : printf("%ld ",Not()); fflush(stdout);    break;
		case 8 : printf("%ld ",Xor()); fflush(stdout);    break;
		case 9 : printf("%ld ",Rem()); fflush(stdout);    break;
		case 10: printf("%ld ",Inc()); fflush(stdout);    break;
		case 11: printf("%ld ",Dec()); fflush(stdout);    break;
		default:      break;
		
	}
	
    return 0;
}

long int Add(void){ 
	int Operand1,Operand2;
	long int res;
	scanf("%d%d",&Operand1,&Operand2); fflush(stdin);
	res=Operand1+Operand2;
	printf("%d + %d = ",Operand1,Operand2);fflush(stdout);
	return res;
}
long int Sub(void){ 
	int Operand1,Operand2;
	long int res;
	scanf("%d%d",&Operand1,&Operand2);fflush(stdin);
	res=Operand1-Operand2;
	printf("%d - %d = ",Operand1,Operand2);fflush(stdout);
	return res;
}
long int Mul(void){
	int Operand1,Operand2;
	long int res;
	scanf("%d%d",&Operand1,&Operand2);fflush(stdin);
	res=Operand1*Operand2;
	printf("%d * %d = ",Operand1,Operand2);fflush(stdout);
	return res;
}
float Div(void){
	float Operand1,Operand2;
	float res;
	scanf("%f%f",&Operand1,&Operand2);fflush(stdin);
	res=Operand1/Operand2;
	printf("%.2f / %.2f = ",Operand1,Operand2);fflush(stdout);
	return res;
}
long int And(void){
	int Operand1,Operand2;
	long int res;
	scanf("%d%d",&Operand1,&Operand2);fflush(stdin);
	res=Operand1&Operand2;
	printf("%d & %d = ",Operand1,Operand2);fflush(stdout);
	return res;
}
long int OR(void) { 
	int Operand1,Operand2;
	long int res;
	scanf("%d%d",&Operand1,&Operand2);
	res=Operand1|Operand2;
	printf("%d | %d = ",Operand1,Operand2);
	return res;
}
long int Not(void){ 
	int Operand1;
	long int res;
	scanf("%d",&Operand1);
	res=~Operand1;
	printf("~ %d = ",Operand1);
	return res;
}
long int Xor(void){ 
	int Operand1,Operand2;
	long int res;
	scanf("%d%d",&Operand1,&Operand2);
	res=Operand1^Operand2;
	printf("%d ^ %d = ",Operand1,Operand2);
	return res;
}
long int Rem(void){ 
	int Operand1,Operand2;
	long int res;
	scanf("%d%d",&Operand1,&Operand2);
	res=Operand1%Operand2;
	printf("%d % %d = ",Operand1,Operand2);
	return res;

}
long int Inc(void){ 
	int Operand1;
	long int res;
	scanf("%d",&Operand1);
	res=++Operand1;
	printf("++ %d = ",Operand1);
	return res;
}
long int Dec(void){ 
	int Operand1;
	long int res;
	scanf("%d",&Operand1);
	res=--Operand1;
	printf("-- %d = ",Operand1);
	return res;
}
