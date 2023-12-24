#include <stdio.h>
#include <stdlib.h>

#include "../std_types.h"
#include "../bit_math.h"

// Tree traversal in C

#include <stdio.h>
#include <stdlib.h>

typedef struct ST_Node_t Node ;


struct ST_Node_t {

	u32 Data;
	Node* Left;
	Node* Right;

};


// Inorder traversal
void inorderTraversal(Node* root) {
  if (root == NULL) return;

  inorderTraversal(root->Left);
  printf("%d ->", root->Data);
  inorderTraversal(root->Right);

}

// Preorder traversal
void preorderTraversal(Node* root) {

  if (root == NULL) return;

  printf("%d ->", root->Data);
  preorderTraversal(root->Left);
  preorderTraversal(root->Right);

}

// Postorder traversal
void postorderTraversal(Node* root) {
  if (root == NULL) return;
  
  postorderTraversal(root->Left);
  postorderTraversal(root->Right);
  printf("%d ->", root->Data);

}

// Create a new Node
Node* createNode(u32 value) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->Data = value;
  newNode->Left = NULL;
  newNode->Right = NULL;

  return newNode;
}

// Insert on the left of the node
Node* insertLeft(Node* root, u32 value) {
  root->Left = createNode(value);
  return root->Left;
}

// Insert on the right of the node
Node* insertRight(Node* root, u32 value) {
  root->Right = createNode(value);
  return root->Right;
}


void printSpaces(int count) {
    for (int i = 0; i < count; i++) {
        printf(" ");
    }
}

void printLevel(Node* root, int level, int space) {
    if (root == NULL ) {
        return;
    }
    if (level == 1) {
        printSpaces(space);
        printf("%d", root->Data);
        //printf(" ");
    } else {
        printLevel(root->Left, level - 1, space);
        printLevel(root->Right, level - 1, space);
    }
}

void printTree(Node* root,u32 level) {
    u32 space = 5 * level; 	
    
    for (int i = 1; i <= level; i++) {
        
		printLevel(root, i, space);
		space -=5;
        printf("\n");
		printf("\n");
		
    }
}


int main() {
  Node* root = createNode(1);
  insertLeft(root, 2);
  insertRight(root, 3);
  insertLeft(root->Left, 4);
  insertRight(root->Left, 5);
  insertLeft(root->Right, 6);
  insertRight(root->Right, 7);
  //insertLeft(root->Left->Left, 8);
  //insertRight(root->Left->Right, 9);
  //insertLeft(root->Right->Left, 10);
  //insertRight(root->Right->Right, 11);


  printf("Inorder traversal \n");
  inorderTraversal(root);

  printf("\nPreorder traversal \n");
  preorderTraversal(root);

  printf("\nPostorder traversal \n");
  postorderTraversal(root);
  
  printf("\n\n");
  
  printTree(root, 3);
}

