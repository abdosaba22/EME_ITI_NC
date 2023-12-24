#include <stdio.h>
#include <stdlib.h>

#include "../std_types.h"
#include "../bit_math.h"
#define SIZE   15
u32 Queue[SIZE]={0};
u32 front=-1 ;
u32 rear=-1 ;

void enQueue(u32 data);
u32 deQueue(void);
u32 peek(void);
u32 isFull(void);
u32 isEmpty(void);
void printQueue();

int main(void){
	u32 data;
	u32 choice;
	
	printf("Enter 1 to enqueue element. \nEnter 2 to print the peek. \nEnter 3 to print queue\nEnter 4 to dequeu element\nEnter 5 to end element\n your choice is :\t");fflush(stdout);
	scanf("%d",&choice);fflush(stdin);
	
	while(choice != 5){
		switch(choice){
			case 1:
				printf("Enter data to add :\t");fflush(stdout);
				scanf("%d",&data);fflush(stdin);
				enQueue(data);
				printf("data added \n");fflush(stdout);
				break;
			case 2:  
				printf("Printing peek ..\n");
				data= peek();
				if(0!=data)
				printf("peek is %d\n",data);
				break;
			case 3:	
				printf("Printing Queue ..\n");
				printQueue(); 
				//printf("deleted ..\n");
			break;
			case 4:	
				data= deQueue();
				if(0!=data){
					printf("dequeued is %d",data);fflush(stdout);
					printf("deleted ..\n");fflush(stdout);
				}
				
			break;
			default: 
			break;
		}
		printf("front is %d , rear is %d \n",front,rear);fflush(stdout);
		
		printf("Enter 1 to enqueue element. \nEnter 2 to print the peek. \nEnter 3 to print queue\nEnter 4 to dequeu element\nEnter 5 to end element\n your choice is :\t");fflush(stdout);
		scanf("%d",&choice);fflush(stdin);
		
	}
	printf("End prog");fflush(stdout);
	return 0;

}

void enQueue(u32 data){
	if(1==isFull()){
		printf("Queue is Full.\n");fflush(stdout);
	}
	else{
		if(1==isEmpty()){
			front= 0;
			rear=0;
		}	
		else{
			rear++;
		}
		Queue[rear]=data;
	}
	
}

u32 deQueue(void){
	u32 value =0;
	if(1==isEmpty()){
		printf("Queue is Empty.\n"); fflush(stdout);
	}
	else{
		value =Queue[front]; 
		Queue[front]=0; 
		if(front==rear){
			rear = -1;
			front = -1;
		}	
		else{
			front++;
		}
	
	}
	return value;
}

u32 peek(void){
	u32 value =0;
	if(1==isEmpty()){
		printf("Queue is Empty.\n");fflush(stdout);
	}
	else{
		value = Queue[front];
	}
	return value;
}
u32 isFull(void){
	u32 full=0;
	if( ((SIZE -1)==rear) && (0==front))
	{
		full = 1;
	}
	else {
		/* do nothing  */
	}
	
	return full;
}

u32 isEmpty(void){
	u32 empty=0;
	if( (-1==front) && (-1==rear))
	{
		empty = 1;
	}
	else {
		/* do nothing  */
	}
	
	return empty;	
}
void printQueue(){
	u32 i ;
	if(1==isEmpty()){
		
		/* print empty \n */
		printf("Queue is Empty.\n"); fflush(stdout);
	}
	else{
		for(i=front;(i<=rear );i++){
			printf("Queue %d is : %d\n",i,Queue[i]);fflush(stdout);
		}
	}
}
