#include <stdio.h>

int main() {
    int num1, num2, num3;

    printf("Enter three numbers:\n");fflush(stdout);
	
	printf("Enter number1:\n");fflush(stdout);
    scanf("%d", &num1);fflush(stdin);
	printf("Enter number2:\n");fflush(stdout);
    scanf("%d", &num2);fflush(stdin);
	printf("Enter number3:\n");fflush(stdout);
    scanf("%d", &num3);fflush(stdin);

    int max = num1;
	/* cascaded if  */
    if (num2 > max) {
        max = num2;
    }
    if (num3 > max) {
        max = num3;
    }

    printf("The maximum number is %d.\n", max);fflush(stdout);

    return 0;
}