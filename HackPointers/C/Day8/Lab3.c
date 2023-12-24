#include <stdio.h>
#include <stdlib.h>

#include "../std_types.h"
#include "../bit_math.h"

typedef struct ST_Node_t Node ;

struct ST_Node_t{
	u32 data;
	Node * next;
};

Node * Add_Node(Node * Copy_head,u32 data);
Node * Delete_Node(Node * Copy_head);
void Display (Node * Copy_head);

u32 fir = 1;

int main (void)
{
	u32 choice;
	Node * head =NULL;
	u32 data;
	printf("Enter 0 to add element. \nEnter 1 to print List. \nEnter 2 to delete element\n\t your choice is :\t");fflush(stdout);
	scanf("%d",&choice);fflush(stdin);
	
	while(choice != 3){
		//printf("in main add of head before do choice :%p\n",head);fflush(stdout);
		switch(choice){
			case 0:
				//printf("%p\n",head);fflush(stdout);
				printf("Enter data to add :\t");fflush(stdout);
				scanf("%d",&data);fflush(stdin);
				if(fir == 1)
				{
					head=Add_Node(head,data); 
					fir = 0;
				}
				else
				{
					Add_Node(head,data); 
				}
				
				break;
			case 1:  
				//printf("%p\n",head);fflush(stdout);
				Display(head);
				break;
			case 2:
				head=Delete_Node(head); 
				break;
			default: 
				break;
		}
		//printf("in main add of head after do choice :%p\n",head);fflush(stdout);
		printf("Enter 0 to add element. \nEnter 1 to print List. \nEnter 2 to delete element\n\t your choice is :\t");fflush(stdout);
		scanf("%d",&choice);fflush(stdin);	
	}

	printf("End prog");fflush(stdout);
	return 0;
}

void Display (Node * Copy_head){
	
	while(Copy_head!=NULL){
		printf("%d \n",Copy_head->data);fflush(stdout);
		Copy_head=Copy_head->next;
	}
	
}

Node * Add_Node(Node * Copy_head,u32 data){
	/* new node */
	Node * p=(Node*)malloc(sizeof( Node));
	p->data = data;
	p->next=NULL;
	
	if(Copy_head==NULL) 
	{
		return p;
	}
	else 
	{
		
		while(NULL !=Copy_head->next) 
		{
			Copy_head=Copy_head->next;
		}
		Copy_head->next=p;
		
	}
	//printf("add of head %p after add elem\n ",Copy_head);fflush(stdout);
	//printf("%p\n",Copy_head);fflush(stdout);
	
	return 0;
}

Node * Delete_Node(Node * Copy_head){
	Node * p=Copy_head;
	
	if(p== NULL) 
	{
		return p;
	}
	else if(p->next ==NULL) 
	{
		Copy_head =NULL;
		fir=1;
	}
	else {
		while (p->next->next!=NULL) 
			p=p->next;
		p->next=NULL;
	}
	
	return Copy_head;
}