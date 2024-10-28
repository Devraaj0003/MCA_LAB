#include <stdio.h>
#include <stdlib.h>

// Definition of the binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the binary tree
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// In-order traversal
void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Pre-order traversal
void preOrder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Post-order traversal
void postOrder(struct Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

// Function to free the allocated memory for the tree
void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

//Function to search a root 
struct Node* search(struct Node* root, int key) { 
  if (root == NULL) 
    printf("\nNot FOUND!\n"); 
  else if (root->data == key)
    printf("\nFOUND!\n");
  else{
  	if (root->data < key) 
    return search(root->right, key); 
  return search(root->left, key);
  } 
}


// Main function to demonstrate the binary tree
int main(){
	int opt;
	int value,searchv,key;
	struct Node* root = NULL;
	do{
		printf("\n1)Create Root Node \n2)Insert Node\n3)Search\n");
		printf("4)inorderTraversal \n5)preorderTraversal \n6)postorderTraversal \n7)Quit \n");
		printf("Choose Option :: ");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				printf("\nEnter a number : ");
				scanf("%d",&value);
				root = createNode(value);
				break;
			case 2:
				printf("\nEnter a number : ");
				scanf("%d",&value);
				root = insert(root,value);
				break;
			case 3:
				printf("\nEnter a number : ");
				scanf("%d",&searchv);
				search(root,searchv);
				break;
			case 4:
				printf("\n..................................\n");
				inOrder(root);
				printf("\n..................................\n");
				break;
			case 5:
				printf("\n..................................\n");
				preOrder(root);
				printf("\n..................................\n");
				break;
			case 6:
				printf("\n..................................\n");
				postOrder(root);
				printf("\n..................................\n");
				break;
		
			defualt:
				printf("Invalid option!");
		}
	}while(opt!=7);
	return 0;
}
