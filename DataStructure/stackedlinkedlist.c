#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
}; 

typedef struct node node;
node *head; 

void push(){
	int val ;
	node* temp,*pre;
	printf("\nENTER A VALUE: ");
	scanf("%d",&val);
	
	temp=(node*)malloc(sizeof(node));
	temp->data = val;
	
	if(head == NULL){
		head= temp;
		temp->next = NULL;
	}else{
		pre = head;
		while (pre->next != NULL){
			pre = pre->next;
		}
		pre->next = temp;
		temp->next =  NULL;
		printf("\nELEMENT INSERTED");
		
	}
}





void pop(){
	node *pre = head;
	if (head == NULL){
		printf("\n STACK UNDERFLOW\n");
	}else{
		while( pre->next->next != NULL){
			pre = pre->next; 
		}
		printf("\n%d ELEMENT DELETED",pre->next->data);
		pre->next = NULL;
		
	}
}



void display(){
	node *pre = head;
	int i=0;
	
	if (head == NULL){
		printf("\n STACK IS EMPTY\n");
	}else{
		while( pre->next != NULL){
			printf("\n STACK[%d] : %d\n", i,pre->data);
			pre = pre->next; 
			i += 1;
		}
		printf("\n STACK[%d] : %d\n", i,pre->data);
	}
}

int main(){
	int opt;
	do{
		printf("\n------------------\n1. PUSH\n2. POP\n3. DISPLAY\n4. QUIT\n------------------\nCHOOSE AN OPTION:  \n");
		scanf("%d", &opt);
		switch(opt){
			case 1: push();
				break;
			case 2: pop();
				break;
			case 3: display();
				break;
			case 4: exit(0);
			default: printf("\nEnter a valid option");	
		}
		
	}while(1);
	return 0;
}
