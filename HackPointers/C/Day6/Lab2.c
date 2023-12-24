#include <stdio.h>
#include "../std_types.h"

typedef struct{
	u16 Salary;
	u16 Bonus;
	u16 Deduction;
}S_EMPLOYEES_t;

int main() {
	u32 res=0;
	S_EMPLOYEES_t Ahmed ,Amr,Waleed;
	
	printf("Pease Enter Ahmed Salary: ");fflush(stdout);
	scanf("%d",&Ahmed.Salary);fflush(stdin);
	printf("Pease Enter Ahmed Bonus: ");fflush(stdout);
	scanf("%d",&Ahmed.Bonus);fflush(stdin);
	printf("Pease Enter Ahmed Deduction: ");fflush(stdout);
	scanf("%d",&Ahmed.Deduction);fflush(stdin);
	printf("Pease Enter Waleed Salary: ");fflush(stdout);
	scanf("%d",&Waleed.Salary);fflush(stdin);
	printf("Pease Enter Waleed Bonus: ");fflush(stdout);
	scanf("%d",&Waleed.Bonus);fflush(stdin);
	printf("Pease Enter Waleed Deduction: ");fflush(stdout);
	scanf("%d",&Waleed.Deduction);fflush(stdin);
	printf("Pease Enter Amr Salary: ");fflush(stdout);
	scanf("%d",&Amr.Salary);fflush(stdin);
	printf("Pease Enter Amr Bonus: ");fflush(stdout);
	scanf("%d",&Amr.Bonus);fflush(stdin);
	printf("Pease Enter Amr Deduction: ");fflush(stdout);
	scanf("%d",&Amr.Deduction);fflush(stdin);
		
	res= Ahmed.Salary+Waleed.Salary+Amr.Salary+Ahmed.Bonus+Waleed.Bonus+Amr.Bonus -Ahmed.Deduction - Waleed.Deduction -Amr.Deduction;
	
	printf("Total value needed is %d",res );fflush(stdout);
	
	
    return 0;
}