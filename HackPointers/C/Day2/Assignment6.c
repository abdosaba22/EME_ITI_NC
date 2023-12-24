#include <stdio.h>

int main() {
    int num,i,j;

    printf("please Enter the height of the pyramid :\t");fflush(stdout);
	scanf("%d",&num);fflush(stdin);
	printf("\n");fflush(stdout);
	for(i=1;i<=num;i++){
		for(j=1;j<num*2;j++){
			if( (j<=(num-i)) || (j>=(num+i)) ){
				printf(" ");fflush(stdout);
			}
			else {
				printf("*");fflush(stdout);
			}
			
		}
		printf("\n");fflush(stdout);
	}

    return 0;
}