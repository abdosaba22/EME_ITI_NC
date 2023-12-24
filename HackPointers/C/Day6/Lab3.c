#include <stdio.h>
#include "../std_types.h"

typedef struct{
	u16 Math;
	u16 Language;
	u16 Physics;
	u16 Chemistry;
}S_Students_t;

int main() {
	u16 Student_ID=0;
	S_Students_t  arr_ofstudents[10]={
		{60,80,100,90}, {50,40,80,90},
		{100,100,60,50},{100,50,90,60},
		{80,30,90,50} , {60,60,60,90}, 
		{80,60,80,90} , {90,60,100,50},
		{20,40,80,70} , {100,60,20,60}
	};
	
	printf("Pease Enter The Student ID: ");fflush(stdout);
	scanf("%d",&Student_ID);fflush(stdin);
	
	if(Student_ID>9 || Student_ID<0){
		printf("Invalid ID ..");fflush(stdout);
	}
	else{
		printf("Math grade is %d \nLanguage grade is %d \nPhysics grade is %d \nChemistry grade is %d \n"\
		,arr_ofstudents[Student_ID].Math,arr_ofstudents[Student_ID].Language,arr_ofstudents[Student_ID].Physics,arr_ofstudents[Student_ID].Chemistry);fflush(stdout);
	}
	
    return 0;
}