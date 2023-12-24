#include <stdio.h>
#include <stdlib.h>

#include "../std_types.h"
#include "../bit_math.h"

/* stack */

typedef struct ST_Node_t Node ;


struct ST_Node_t {

	u32 Data;
	Node* Left;
	Node* Right;

};

Node * createNode(u32 data);
void insertLeft(Node * root, u32 data);
void insertRight(Node * root, u32 data);

void Traversal_preOrder(Node * root);
void Traversal_inOrder(Node * root);
void Traversal_postOrder(Node * root);


int main(void){
	u32 data;
	u32 choice;
	Node * Root= createNode(1);
	
	insertLeft(Root, 2);
	insertRight(Root, 3);
	
	insertLeft(Root->Left, 4);
	insertRight(Root->Left, 5);
	
	insertLeft(Root->Right, 6);
	insertRight(Root->Right, 7);
	

	printf("\nPreOreder ..  \n");fflush(stdout);
	Traversal_preOrder(Root);
	printf("\n");fflush(stdout);
	
	
	printf("\ninOreder ..  \n");fflush(stdout);
	Traversal_inOrder(Root);
	printf("\n");fflush(stdout);
	
	
	printf("\nPostOreder ..  \n");fflush(stdout);
	Traversal_postOrder(Root);
	printf("\n");fflush(stdout);
	
	
	return 0;
}


Node * createNode(u32 data){
	Node * new_node = (Node*)malloc(sizeof(Node));
	new_node->Data =data;
	new_node->Left =NULL;
	new_node->Right =NULL;
	
	return new_node;
}

void insertLeft(Node * root, u32 data){
	root->Left= createNode(data);
}
void insertRight(Node * root, u32 data){
	root->Right= createNode(data);
}

/* Root , Left , Right */
void Traversal_preOrder(Node * root){
	
	if(NULL==root){return;}
	else{

		printf(" %d -> ", root->Data);fflush(stdout);
		Traversal_preOrder(root->Left);
		Traversal_preOrder(root->Right);
		
	}
	
}

/* Left .. Root .. Right */
void Traversal_inOrder(Node * root){
	
	if(NULL==root){return;}
	else{	
		Traversal_inOrder(root->Left);
		printf(" %d -> ", root->Data);fflush(stdout);
		Traversal_inOrder(root->Right);
	
	}
	
}

/* Left .. Right .. Root */
void Traversal_postOrder(Node * root){
	if(NULL==root){return;}
	else{	
		Traversal_postOrder(root->Left);
		Traversal_postOrder(root->Right);
		printf(" %d -> ", root->Data);fflush(stdout);
	
	}
	
}

