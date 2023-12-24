#include <stdio.h>
#include "../std_types.h"

#define ROW 	3
#define COL 	3
int main() {
    u16 arr[ROW][COL];
    u16 *ptr=&arr[0][0],i, j;
	
	/* access 2 dimensional array using arr[][] */

    // Read in the values for the array from the user
     printf("Enter the values for the array:\n");
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            printf("arr[%d][%d]: ", i, j); fflush(stdout);
            scanf("%d",&arr[i][j]) ;fflush(stdin);
        }
    }
/*
    // Print out the values in the array
    printf("The values in the array are:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d\t",arr[i][j]);  fflush(stdout);
        }
        printf("\n");
    }
 */

    /* Accessing the elements of the array
     *	using pointer arithmetic
	 *	Base + (i * Nofcoulmns)+ j
	*/

	printf("Using pointer arithmetic:\n");
    
		
	for ( i = 0; i < ROW; i++) {
        for ( j = 0; j < COL; j++) {
            printf("%d\t", *(ptr + i * COL + j));
        }
        printf("\n");
    }


    return 0;
}