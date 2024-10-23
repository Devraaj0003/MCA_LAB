#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* prev;
	struct node *next;
	
}Node;

Node *start = NULL;
void insert_begin(int x){
	Node *ptr = (Node *) malloc(sizeof(Node));
	ptr->prev =NULL;
	ptr->data = x;
	ptr->next = start;
	if(start != NULL){
		start->prev =ptr;
	}
	start = ptr;
	printf("\n%d insertef at athe beginning",x);
}

void insert_end(int x){
	Node *ptr = (Node *) malloc(sizeof(Node));
	ptr->data = x;
	ptr->next = NULL;
	if(start == NULL){
		ptr->prev = NULL;
		start = ptr;
	}else{
		Node *temp = start;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = ptr;
		ptr->prev = temp;
	}
	printf("\n%d inserted at athe end",x);
}

void insert_pos(int x, int pos){
	if(pos < 1){
		printf("\nInvalid position");
		return;
	}
	if(pos ==1){
		insert_begin(x);
		return;
	}
	Node *ptr = (Node*)malloc(sizeof(Node));
	ptr->data = x;
	Node *temp = start;
	for(int i = 1; i < pos-1 && temp != NULL; i++){
		temp = temp->next;
	}
	if(temp == NULL){
		printf("\nPosition out of bound");
		free(ptr);
		return;
	}
	ptr->next = temp->next;
	ptr->prev = temp;
	if(temp->next !=NULL){
		temp->next->prev = ptr;
	}
	temp->next = ptr;
	printf("\n%d inserted at position %d",x,pos);
}


void delete_begin(){
	if(start == NULL){
		printf("\n List is empty");
		return;
	}
	Node *ptr = start;
	start = start->next;
	if(start != NULL){
		start->prev = NULL;
	}
	printf("\n%d deleted from beginning", ptr->data);
	free(ptr);
}


void delete_end(){
	if(start ==NULL){
		printf("\n List is empty");
		return;
	}
	Node *ptr = start;
	if(ptr->next ==NULL){
		printf("\n%d deleted from end",ptr->data);
		free(ptr);
		start = NULL;
		return;
	}
	while(ptr->next != NULL){
		ptr= ptr->next;
	}
	ptr->prev->next = NULL;
	printf("\n%d deleted from the end", ptr->data);
	free(ptr);
	
}
	
void delete_pos(int pos){
	if(start == NULL || pos < 1){
		printf("\nList is empty of Invalid position");
		return;
	}
	if(pos ==1){
		delete_begin();
		return;
	}
	Node *ptr = start;
	for(int i =1; i< pos&& ptr!= NULL;i++){
		ptr = ptr->next;
	}
	if(ptr == NULL){
		printf("\nPosition out of bound");
		return ;
	}
	if(ptr->next != NULL){
		ptr->prev->next= ptr->next;
		printf("\n%d deleted from position %d", ptr->data, pos);
		free(ptr);
		
	}
}

void display(){
	Node* ptr = start;
	if(ptr == NULL){
		printf("\nList is empty");
		return;
	}
	printf("\nList is ");
	while(ptr != NULL){
		printf("%d <->", ptr->data);
		ptr = ptr->next;
	}
	printf("NULL");
}



int main(){
	int choice, value, position;
	while(1){
		printf("\n1. Insert at beginning\n2. Insert at end\n3. Insert at position\n4. Delete at beginning\n5. Delete at end\n6. Delete at position\n7. Display list\n8.Exit\n Enter the choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 1: printf("enter value: ");
				scanf("%d", &value);
				insert_begin(value);
				break;
			case 2: printf("enter value: ");
				scanf("%d", &value);
				insert_end(value);
				break;
			case 3: printf("enter value and position: ");
				scanf("%d%d", &value, &position);
				insert_pos(value,position);
				break;
			case 4: delete_begin();
				break;
			case 5: delete_end();
				break;
			case 6: printf("enter position to be deleted: ");
				scanf("%d", &position);
				delete_pos(position);
				break;
			case 7: display();
				break;
			case 8: exit(0);
			default: printf("\nInvalid choice");
			}
	}
}
			
			

