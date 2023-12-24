#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	printf("Hello world Bro ITI Day1! \n");
	
	return 0;
}




// unsigned char MaxConsecutiveOnesARR(unsigned char* copy_arr, unsigned char arrSize)
// {
	// unsigned char i=0,k=0,max=0;
	
	// for(i=0;i<arrSize;i++)
	// {
		
		// if(copy_arr[i]==0)
		// {
			
			// max=(k>max)?  k:max;
			// k=0;
		// }
		// else{
			// k++;
		// }
		
	// }
	// /* to chech if the max in the end of arr */
	// return max=(k>max)?  k:max;

	//return max;
// }


// char ** fizzBuzz(int n, int * returnSize)
// {
    // char**arr = (char**)malloc( n * sizeof(char*) );
    
	// *returnSize = n;
    
	// for(int i=0;i<n;i++)
    // {
        // arr[i] = malloc(9 * sizeof(char));
        // /* 1st Num can divid by 3 & 5 is (3*5) */
		// if( (i+1)%15==0 )
        // arr[i] = "FizzBuzz";
        // else if( (i+1)%3==0 )
        // arr[i]="Fizz";
        // else if( (i+1)%5==0 )
        // arr[i]="Buzz";
        // else
        // arr[i] = i+49;
    // }
    
    // return arr;
// }
// char * fizzBuzz(int n, int returnSize)
// {
    // char**arr = malloc(n*sizeof(char*));
    // *returnSize = n;
    // for(int i=1;i<=n;i++)
    // {
        // arr[i - 1] = malloc(9 * sizeof(char));
        // if(i%15==0)
        // arr[i-1] = "FizzBuzz";
        // else if(i%3==0)
        // arr[i-1]="Fizz";
        // else if(i%5==0)
        // arr[i-1]="Buzz";
        // else
        // sprintf(arr[i-1], "%d", i);
    // }    
    // return arr;
// }
