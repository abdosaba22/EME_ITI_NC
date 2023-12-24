#include <stdio.h>
#include <stdlib.h>

#include "../std_types.h"
#include "../bit_math.h"

#define SIZE   15

typedef struct ST_Node_t Node ;


struct ST_Node_t {

	u32 Data;
	Node* Next;

};

typedef struct ST_Stack_t Stack ;

struct ST_Stack_t {

    u32 Size;
	u32 Counter;
    Node* Top;

};

Stack* Create_Stack(u32 size);
void push(Stack* stack, u32 data);
u32 pop(Stack* stack);
u8 isFull(Stack* copy_stack);
u8 isEmpty(Stack* copy_stack);
void printStack(Node* Node_Top);


int main(void){
	u32 data;
	u32 choice;
	Stack* stack= Create_Stack(SIZE);
	printf("Enter 1 to Push element. \nEnter 2 to pop.\nEnter 3 to print stack\nEnter 4 to dequeu element\nEnter 5 to end element\n your choice is :\t");fflush(stdout);
	scanf("%d",&choice);fflush(stdin);
	
	while(choice != 5){
		switch(choice){
			case 1:
				printf("Enter data to add :\t");fflush(stdout);
				scanf("%d",&data);fflush(stdin);
				push(stack,data);
				printf("data added \n");fflush(stdout);
				break;
			case 2:  
				printf("deleting ..\n");
				data= pop(stack);
				if( 0!= data)
				printf("poped data is %d\n",data);
				break;
			case 3:	
				printf("Printing stack ..\n");
				printStack(stack->Top); 
				//printf("deleted ..\n");
				break;
			default: 
				break;
		
		}
		
		printf("Enter 1 to Push element. \nEnter 2 to pop.\nEnter 3 to print stack\nEnter 4 to end element\n your choice is :\t");fflush(stdout);
		scanf("%d",&choice);fflush(stdin);	
	}
	
	printf("End prog");fflush(stdout);
	
	return 0;
}


Stack* Create_Stack(u32 size) {
    
	Stack* new_stack = (Stack*)malloc(sizeof(Stack));
    if(NULL!=new_stack){
		new_stack->Size = size;
		new_stack->Counter = 0;
		new_stack->Top = NULL;
	}
	else{
		
	}
	
    return new_stack;
}

void push(Stack* stack, u32 data) {
    
    if(1==isFull(stack)){
		/* printf full */
		printf("Stack is full..\n");fflush(stdout);
	}
	else{
		Node* new_node = (Node*)malloc(sizeof(Node));
		if( NULL==new_node ){
			/* printf Memory allocation failed */
			printf("Overflow...\n");fflush(stdout);
		}
		else{
			new_node->Data = data;
			new_node->Next = stack->Top;
			stack->Top = new_node;
			stack->Counter ++;
		}
	}

}

u32 pop(Stack* stack) {
    u32 data = 0; // empty 
	if(1==isEmpty(stack))
	{
		/* stack is empty */
		printf("stack is empty..\n");fflush(stdout); 
	}
	else{
	
		Node * Temp_node = stack->Top; /* copy addr of 1st node to free it */
		data = Temp_node->Data;
		stack->Top = stack->Top->Next; /* front point to next elem */
		free(Temp_node);
		
		stack->Counter--;
	}
	
	return data;
}

u8 isFull(Stack* copy_stack){
	u8 local_u8error=0;
	if(copy_stack->Size==copy_stack->Counter){
		local_u8error=1;
	}
	else{
		/* do nothing */
	}

	return local_u8error;
}

u8 isEmpty(Stack* copy_stack){
	u8 local_u8error=0;
	if(0==copy_stack->Counter){
		local_u8error=1;
	}
	else{
		/* do nothing */
	}
	
	return local_u8error;
}

void printStack(Node* Node_Top) {
    printf("Stack: \n");
    while ( NULL!=Node_Top ) {
        printf("%d \n", Node_Top->Data);
        Node_Top = Node_Top->Next;
    }
    printf("\n");
}

