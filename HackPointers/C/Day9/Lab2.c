#include <stdio.h>
#include <stdlib.h>

#include "../std_types.h"
#include "../bit_math.h"

#define SIZE   15

typedef struct ST_Node_t Node ;

struct ST_Node_t{
	u32 Data;
	Node * Next;
};


typedef struct ST_Queue_t Queue ;

struct ST_Queue_t{
	u32 Size;
	u32 Counter;
	Node * Front; 
	Node * Rear;  	
};

/*  
 *  front 		   	   rear
 *    |				  	|	
 *	  w				    w
 *	 node     node     node
 *   
 *  first              end
 *
 */
 

Queue* Creat_Queue(u32 size);

void enQueue(Queue* copy_queue ,u32 data);

u32 deQueue(Queue* copy_queue);

u32 peek(Queue* copy_queue);

u8 isFull(Queue* copy_queue);

u8 isEmpty(Queue* copy_queue);

void printQueue(Node * copy_front);

int main(void){
	u32 data;
	u32 choice;
	Queue* queue= Creat_Queue(SIZE);
	printf("Enter 1 to enqueue element. \nEnter 2 to print the peek. \nEnter 3 to print queue\nEnter 4 to dequeu element\nEnter 5 to end element\n your choice is :\t");fflush(stdout);
	scanf("%d",&choice);fflush(stdin);
	
	while(choice != 5){
		switch(choice){
			case 1:
				printf("Enter data to add :\t");fflush(stdout);
				scanf("%d",&data);fflush(stdin);
				enQueue(queue,data);
				printf("data added \n");fflush(stdout);
				break;
			case 2:  
				printf("Printing peek ..\n");
				data= peek(queue);
				if( 0!= data)
				printf("peek is %d\n",data);
				break;
			case 3:	
				printf("Printing Queue ..\n");
				printQueue(queue->Front); 
				//printf("deleted ..\n");
				break;
			case 4:	
				data= deQueue(queue);
				if(0!=data){
					printf("dequeued is %d \n",data);fflush(stdout);
					printf("deleted ..\n");fflush(stdout);
				}
				break;
			default: 
				break;
		
		}
		
		printf("Enter 1 to enqueue element. \nEnter 2 to print the peek. \nEnter 3 to print queue\nEnter 4 to dequeu element\nEnter 5 to end element\n your choice is :\t");fflush(stdout);
		scanf("%d",&choice);fflush(stdin);	
	}
	
	printf("End prog");fflush(stdout);
	
	return 0;
}


Queue* Creat_Queue(u32 size){
	Queue* new_queue =(Queue*)malloc(sizeof(Queue));
	new_queue->Size=size;
	new_queue->Counter=0;
	new_queue->Front=NULL;
	new_queue->Rear=NULL;
	
	return new_queue;
}

void enQueue(Queue* copy_queue ,u32 data){
	
	if(1==isFull(copy_queue)){
		/* Queue is full */
		printf("Queue is full..\n");fflush(stdout); 
	}
	else{
		/* creat new node */
		Node * new_node = (Node *) malloc(sizeof(Node));
		new_node->Data=data;
		new_node->Next=NULL;
		
		if(NULL==new_node){
			/* overflow -- Memory allocation failed */
			printf("Overflow...\n");fflush(stdout);
		}
		else{
			/* first node */
			if(NULL==copy_queue->Front){
				copy_queue->Front=copy_queue->Rear=new_node;
			}
			else{
				copy_queue->Rear->Next= new_node; /* add node end elem */
				copy_queue->Rear= new_node; /* change rear to point to last elem */
			}
			copy_queue->Counter++;
			/* print element added */
		}
	}
}

u32 deQueue(Queue* copy_queue){
	u32 data = 0; // empty 
	if(1==isEmpty(copy_queue))
	{
		/* Queue is empty */
		printf("Queue is empty..\n");fflush(stdout); 
	}
	else{
	
		Node * Temp_node = copy_queue->Front; /* copy addr of 1st node to free it */
		data = Temp_node->Data;
		copy_queue->Front = copy_queue->Front->Next; /* front point to next elem */
		free(Temp_node);
		
		/* check if one node in queue */
		if(1==copy_queue->Counter)
		{
			copy_queue->Rear=NULL; /* Front is NULL */
		}
		
		copy_queue->Counter--;
		
	}
	
	return data;
}

u32 peek(Queue* copy_queue){
	u32 data = 0; // empty 
	if(1==isEmpty(copy_queue))
	{	
		/* Queue is empty */
		printf("Queue is empty..\n");fflush(stdout);
	}
	else
	{
		data =copy_queue->Front->Data;
	}
	
	return data;
}

u8 isFull(Queue* copy_queue){
	u8 local_u8error=0;
	if(copy_queue->Size==copy_queue->Counter){
		local_u8error=1;
	}
	else{
		/* do nothing */
	}

	return local_u8error;
}

u8 isEmpty(Queue* copy_queue){
	u8 local_u8error=0;
	if(0==copy_queue->Counter){
		local_u8error=1;
	}
	else{
		/* do nothing */
	}
	
	return local_u8error;
}

void printQueue(Node * copy_front){
	
	while(copy_front!=NULL){
		printf("%d \n",copy_front->Data);fflush(stdout);
		copy_front=copy_front->Next;
	}

}
