#include <stdio.h>
#include <stdlib.h>

#include "../std_types.h"
#include "../bit_math.h"

// Tree traversal in C

#include <stdio.h>
#include <stdlib.h>

void func(u32 ** ARG_u32ppVar){
	*ARG_u32ppVar = (u32*)malloc(sizeof(32));
	(**ARG_u32ppVar)=20;
}
int main() {
	
	u32 * ptr = (u32*)malloc(sizeof(32));
	
	*ptr = 50;
	printf("ptr before change is 0x%p , %d\n ",ptr,*ptr); fflush(stdout);
	
	func(&ptr);
	printf(" ptr after change is 0x%p , %d\n ",ptr,*ptr);
	free(ptr);
	
	
}

