#include <stdio.h>
#include <stdlib.h>

#include "../std_types.h"
#include "../bit_math.h"

/* stack */

typedef struct ST_Node_t Node ;


struct ST_Node_t {

	u32 Data;
	Node* Next;

};

Node * createNode(u32 data);
void push(Node ** Node_Top, u32 data);
u32 pop(Node ** Node_Top);
u32 peek(Node * Node_Top);
u8 isEmpty(Node * Node_Top);
void printStack(Node * Node_Top);


int main(void){
	u32 data;
	u32 choice;
	Node * Top1= NULL;
	
	printf("Enter 1 to Push element. \nEnter 2 to pop.\nEnter 3 to print stack\nEnter 4 to pop element\nEnter 5 to end element\n your choice is :\t");fflush(stdout);
	scanf("%d",&choice);fflush(stdin);
	
	while(choice != 5){
		switch(choice){
			case 1:
				printf("Enter data to add :\t");fflush(stdout);
				scanf("%d",&data);fflush(stdin);
				push(&Top1,data);
				printf("data added \n");fflush(stdout);
				break;
			case 2:  
				printf("deleting ..\n");
				data= pop(&Top1);
				if( 0!= data)
				printf("poped data is %d\n",data);
				break;
			case 3:	
				printf("Printing stack ..\n");
				printStack(Top1); 
				//printf("deleted ..\n");
				break;
				
			case 4:	
				printf("Printing the peeked ..\n");
				peek(Top1); 
				//printf("deleted ..\n");
				break;
				
			default: 
				break;
		
		}
		
		printf("Enter 1 to Push element. \nEnter 2 to pop.\nEnter 3 to print stack\nEnter 4 to pop element\nEnter 5 to end element\n your choice is :\t");fflush(stdout);

		scanf("%d",&choice);fflush(stdin);	
	}
	
	printf("End prog");fflush(stdout);
	
	return 0;
}


Node * createNode(u32 data){
	Node * new_node = (Node*)malloc(sizeof(Node));
	new_node->Data =data;
	new_node->Next =NULL;
	
	
	return new_node;
}
void push(Node ** Node_Top, u32 data){
	Node* new_node= createNode(data);
	
	/* must check if mem allocation failed (NULL==new_node) */
	
	
	/* assign top to new node  */
	new_node-> Next = *Node_Top;
	(*Node_Top)= new_node;
	
}
u32 pop(Node ** Node_Top){
	u32 data = 0;

	if(1==isEmpty(*Node_Top)){
		/* stack is empty */
		printf("stack is empty..\n");fflush(stdout); 
	}
	else{

		Node* temp_node= (Node*)malloc(sizeof(Node));
		temp_node=*Node_Top;
		(*Node_Top)=(*Node_Top)-> Next;
		data = (*Node_Top)-> Data;	
		
	}

	return data;
}

u32 peek(Node * Node_Top){
	u32 data = 0;

	if(1==isEmpty(Node_Top)){
		/* stack is empty */
		printf("stack is empty..\n");fflush(stdout); 
	}
	else{
		data = Node_Top-> Data;	
	}
	
	return data;
}

u8 isEmpty(Node * Node_Top){
	
	/* return 1 if stack empty */
	return (NULL==Node_Top)?1:0;

}

void printStack(Node * Node_Top){

	if(1==isEmpty(Node_Top)){
		/* stack is empty */
		printf("stack is empty..\n");fflush(stdout); 
	}else{
		printf("Stack: \n");
		while ( NULL!=Node_Top ) {
			printf("%d \n", Node_Top->Data);
			Node_Top = Node_Top->Next;
		}
		printf("\n");
	}
		
}

