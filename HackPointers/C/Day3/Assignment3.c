#include <stdio.h>


int main() {
    int grades[3][10]={
		{60,10,44,80,50,60,100,55,20,40},//6
		{46,25,44,80,66,42,88,58,20,30} ,//10
		{34,24,44,80,99,60,99,55,88,80} };//17
    int passed = 0, failed = 0;
    int highest = 0, lowest = 100, total = 0;
    float avg = 0.0f;
    
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 10; j++) {
            
            if (grades[i][j] >= 50) {
                passed++;
            }
			else {
                failed++;
            }
            total += grades[i][j];
        }
    }
    
    // Calculate the average grade
    avg = (float) total / (30);
    
    // Print the statistics
    printf("Number of passed students: %d\n", passed);
    printf("Number of failed students: %d\n", failed);
    printf("Highest grade: %d\n", highest);
    printf("Lowest grade: %d\n", lowest);
    printf("Average grade: %.2f\n", avg);
    
    return 0;
}