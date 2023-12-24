#include <stdio.h>

int main() {
	
	int Local_intID,Password,i;
					 //ID , pass -  ID ,Pass	
	int array[2][2]={{1234,1111},{4563,0000}};char arrname[2][15]={"Ahmed","Leo"};
 	printf("please Enter the ID:\t");
	fflush(stdout);
	scanf("%d",&Local_intID);
	fflush(stdin);
	
	/* 1st sol without array */
	switch(Local_intID){
		/* valid IDs */
		case 1234:  
			printf("please Enter your password:\t");
			fflush(stdout);
			scanf("%d",&Password);
			fflush(stdin);
			if(1111==Password){
				printf("welcome Ahmed\n");fflush(stdout);
			}
			else {
				printf("Incorrect Password \n");fflush(stdout);
			}
			break;
		case 4563:  
			printf("please Enter your password:\t");fflush(stdout);
			scanf("%d",&Password);fflush(stdin);
			if(0000==Password){
				printf("welcome Leo\n");fflush(stdout);
			}
			else {
				printf("Incorrect Password \n");fflush(stdout);
			}
			break;	
		default: printf("Incorrect ID ");fflush(stdout); break;
	}
	
	
	/* 2nd sol */
	for(i=0;i<2;i++){
		if(Local_intID==array[i][0]){
			printf("please Enter your password:\t");
			fflush(stdout);
			scanf("%d",&Password);
			fflush(stdin);
			if(Password==array[i][1]){
				printf("welcome %s!\n",arrname[i]);fflush(stdout);
			}
			else {
				i=-1;
			}
			break;	
		}	
	}
	switch(i){
		case -1: printf("Incorrect Password \n");fflush(stdout); break;
		case 2 : printf("Incorrect ID ");fflush(stdout); break;
		default: break;
	}
	
    return 0;
}