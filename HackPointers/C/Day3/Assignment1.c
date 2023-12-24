#include <stdio.h>

int get_the_maximum(int,int,int,int);
int get_the_minimum(int,int,int,int);

int main() {
	int i,x,y,z,c;

	printf("Enter the 4 values \n");fflush(stdout);
	
	scanf("%d%d%d%d",&x,&y,&z,&c);
	fflush(stdin);
	printf("the Maximum value is %d",get_the_maximum(x,y,z,c));
	printf("the Minimum value is %d",get_the_minimum(x,y,z,c));
    return 0;

}

int get_the_maximum(int Copy_x,int Copy_y,int Copy_z,int Copy_c){
	int Local_intmax=Copy_x;
	if(Copy_y>Local_intmax){
		Local_intmax=Copy_y;
	}else{}
	if(Copy_z>Local_intmax){Local_intmax=Copy_z;}else{}
	if(Copy_c>Local_intmax){Local_intmax=Copy_c;}else{}
	return Local_intmax;
}
int get_the_minimum(int Copy_x,int Copy_y,int Copy_z,int Copy_c){
	int Local_intmin=Copy_x;
	if(Copy_y<Local_intmin){
		Local_intmin=Copy_y;
	}else{}
	if(Copy_z<Local_intmin){Local_intmin=Copy_z;}else{}
	if(Copy_c<Local_intmin){Local_intmin=Copy_c;}else{}
	return Local_intmin;
}
