#include <stdio.h>
#include <stdlib.h>

#include "../std_types.h"
#include "../bit_math.h"

typedef struct ST_Node_t Node ;

struct ST_Node_t{
u32 data;
Node * next;
};

void Add_Node(Node ** Copy_head, u32 data);
Node * Delete_Node(Node * Copy_head);
void Display (Node * Copy_head);

int main (void)
{
	u32 data;
	u8 choice;
	Node * head =NULL;
		
	printf("Enter 0 to add element. \nEnter 1 to print List. \nEnter 2 to delete element\n\t your choice is :\t");fflush(stdout);
	scanf("%d",&choice);fflush(stdin);
	
	while(choice != 3){
		switch(choice){
			case 0:
				//printf("%p\n",head);fflush(stdout);
				printf("Enter data to add :\t");fflush(stdout);
				scanf("%d",&data);fflush(stdin);
				Add_Node(&head,data); 
				break;
			case 1:  
				printf("%p\n",head);fflush(stdout);
				Display(head);
				break;
			case 2:	head=Delete_Node(head); 
			break;
			default: 
			break;
		}
		//printf("%p\n",head);fflush(stdout);
		printf("Enter 0 to add element. \nEnter 1 to print List. \nEnter 2 to delete element\n\t your choice is :\t");fflush(stdout);
		scanf("%d",&choice);fflush(stdin);
		
	}
	printf("End prog");fflush(stdout);
	return 0;
}

void Display (Node * Copy_head){
	
	Node * temp = Copy_head;
	
	while(temp!=NULL){
		printf("%d \n",temp->data);fflush(stdout);
		temp=temp->next;
		//printf("%d\n",i);
	}
	
}

void Add_Node(Node ** Copy_head, u32 data) {
	
	Node * p = (Node*) malloc(sizeof(Node));
	p->data = data;
	p->next = NULL;
	
	if (*Copy_head == NULL) {
		// if the list is empty, set the head to point to the new node
		*Copy_head = p;
	} else {
		// traverse the list to find the last node
		Node * temp = *Copy_head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		// add the new node to the end of the list
		temp->next = p;
	}
	
	printf("%p\n",*Copy_head);fflush(stdout);
	
	// return the updated head pointer
	//return *Copy_head;
}

Node * Delete_Node(Node * Copy_head){
	
	Node * p=Copy_head;
	
	if(p== NULL) 
	{
		printf("The list is empty \n");
		return p;
	}
	else if(p->next ==NULL) 
	{
		Copy_head =NULL;
	}
	else {
		
		while (p->next->next!=NULL) 
			p=p->next;  
		p->next=NULL;
	
	}
	
	return Copy_head;
}