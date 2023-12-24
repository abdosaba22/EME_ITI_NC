#include <stdio.h>

int main() {
	int i,arr_intnums[10];
	long long int Sum=0;
	
	for(i=1;i<11;i++){
		printf("Enter number %d: ",i);
		fflush(stdout);
		scanf("%d",&arr_intnums[i]);fflush(stdin);
		Sum+=arr_intnums[i];
	}
	
	printf("The values in reversed order \n");
	for(i=10;i>0;i--){
		printf("%d\n",arr_intnums[i]);fflush(stdout);
	}
	
	printf("sum of arr elem is %lld \n average is %.2f",Sum,(Sum/10.0));
    
	return 0;
}
