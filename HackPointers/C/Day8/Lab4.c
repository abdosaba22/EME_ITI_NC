#include <stdio.h>
#include <stdlib.h>

#include "../std_types.h"
#include "../bit_math.h"

typedef struct node_t node  ;

struct node_t{
	u32 data;
	node * next;
}*head;

void display (node *);
void add_first(u32 data);
void deletelast(void);
void deletefirst(void);
void Add_end(u32 data);


int main(){
	
	u32 data;
	u8 choice;
	
	printf("Enter 0 to add element. \nEnter 1 to print List. \nEnter 2 to delete element\nEnter 3 to end element\n your choice is :\t");fflush(stdout);
	scanf("%d",&choice);fflush(stdin);
	
	while(choice != 3){
		switch(choice){
			case 0:

				printf("Enter data to add :\t");fflush(stdout);
				scanf("%d",&data);fflush(stdin);
				Add_end(data); 
				break;
			case 1:  
				printf("Printing data ..\n");
				display(head);
				break;
			case 2:	
				deletelast(); 
				printf("deleted ..\n");
			break;
			default: 
			break;
		}
		printf("Enter 0 to add element. \nEnter 1 to print List. \nEnter 2 to delete element\n\t your choice is :\t");fflush(stdout);
		scanf("%d",&choice);fflush(stdin);
		
	}
	printf("End prog");fflush(stdout);
	return 0;
}

void display (node * copy_head){
	
	if(NULL==copy_head){
		printf("List is empty.\n");
	}
	else{
		u32 i =0;
		while(copy_head!=NULL){
			printf("Node %d: %d\n",i,copy_head->data);
			copy_head=copy_head->next;
			i++;
		}
		
	}	
}
void Add_first(u32 data){

	node * copy_head=(node*)malloc(sizeof(node));
	copy_head->data = data;
	
	if(head==NULL) {head=copy_head;copy_head->next=NULL;}
	else {copy_head->next=head; head=copy_head; }

}

void deletefirst(void){
	
	if(head== NULL) {
		/* printf("List empty"); */
	}
	else{ 
		/* printf("Node %d deleted ",hed->data); create temp to save add to free it  */
		head=head->next;
		
	}
}

void deletelast(void){
	
	if(head== NULL) {
		 printf("List empty"); 
		//return ;
	}
	else if(head->next ==NULL) {
		head =NULL;
	}
	else {
		
		node * copy_head=head;
		while (copy_head->next->next!=NULL) 
		{	
			copy_head=copy_head->next;
		}
		
		/* temp node to save the add of deleted node */
		node* temp =copy_head->next;
		copy_head->next=NULL; /*much saver to set ptr next = Null before free to avoid dangling */
		free(temp);
		
	}

}

void Add_end(u32 data) {
	
	node * p = (node*) malloc(sizeof(node));
	p->data = data;
	p->next = NULL;
	
	if ( NULL==head ) {
		// if the list is empty, set the head to point to the new node
		head = p;
	} else {
		// traverse the list to find the last node
		node * temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		// add the new node to the end of the list
		temp->next = p;
	}
	
	printf("Node dded..\n");fflush(stdout);
	
	
}
