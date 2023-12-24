#include <stdio.h>

int main() {
	
	int Local_intID,Password,i,j;
					 //ID , pass -  ID ,Pass	
	int array[2][2]={{1234,1111},{4563,0000}};char arrname[2][15]={"Ahmed","Leo"};
 	printf("please Enter the ID:\t");
	fflush(stdout);
	scanf("%d",&Local_intID);
	fflush(stdin);
	
	
	/* 2nd sol */
	for(i=0;i<2;i++){
		if(Local_intID==array[i][0]){
			Local_intID=1;
			printf("please Enter your password:\t");
			fflush(stdout);
			for(j=0;j<3;j++){
				scanf("%d",&Password);
				fflush(stdin);
				if(Password==array[i][1]){
					printf("welcome %s!\n",arrname[i]);fflush(stdout);
				}
				else if (j<2) {
					printf("Try again :\t");fflush(stdout); continue;
				}
				else {
					i=-1;
				} 
				break;
			}
			
		}
		else{
			continue;
		}
		if(Local_intID=1) {break;}	
	}
	//printf("%d",i);
	switch(i){
		case -1: printf("Incorrect Password for 3 times \n");fflush(stdout); break;
		case 2 : printf("Incorrect ID ");fflush(stdout); break;
		default: break;
	}
    return 0;
}