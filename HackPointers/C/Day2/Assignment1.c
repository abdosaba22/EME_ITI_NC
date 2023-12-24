#include <stdio.h>

int main() {
    int numbers[10];
    int searchNum, i, found = 0;
	// 1st solu  
	/* 
	* we can use 10 variable numX num1 to num10
	* then read the search num and check in if cond 
	* if search num == numX print X 
	*/
	// 2nd solu 
    printf("Enter 10 numbers:\n");
	fflush(stdout);
    for (i = 1; i <=10; i++) {
        printf("Enter number %d : ",i);
		fflush(stdout);
		scanf("%d", &numbers[i]);
		fflush(stdin);
    }

    printf("Enter the number to search for:\n");
    fflush(stdout);
	scanf("%d", &searchNum);
	fflush(stdin);
    for (i = 1; i <= 10; i++) {
        if (numbers[i] == searchNum) {
            printf("The number is found at location %d.\n", i );
            fflush(stdout);
			found = 1;
            break;
        }
    }

    if (!found) {
        printf("number no exist\n");
		fflush(stdout);
    }

    return 0;
}