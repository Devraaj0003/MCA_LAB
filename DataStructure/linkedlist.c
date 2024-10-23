#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *link;
};
struct node *head = NULL;
int count  = 0;

void insert_begin(){
	int data, n, i;
	
	printf("Enter the elements: \n");
	scanf("%d", &data);
	
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	
	
	newnode->link = head;
	head= newnode;
	count++;
	printf("Inserted at begin\n");
	
}

void insert_end(){
	int data, n, i;
	//struct node *head = NULL;
	
	printf("Enter the elements: \n");
	scanf("%d", &data);
	
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	
	if (head == NULL){
		head = newnode;
		
	}else{
		struct node *current = head;
		while(current->link != NULL){
			current= current->link;
		}
		current->link = newnode;
	
	}
	count++;
	printf("Inserted at end\n");
}

void insert_pos(){
	int data, n, index = 2, pos;
	
	printf("Enter the position within %d: \n",count);
	scanf("%d", &pos);
	
	printf("Enter the elements: \n");
	scanf("%d", &data);
	
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	
	if(head == NULL){
		printf("\nList is Empty \n");
	}
	else if(pos == 1){
			newnode->link=head;
			head=newnode;
	}
	else{
		struct node *current = head;
		while(current->link != NULL){
			if(pos==index){
				newnode->link=current->link;
				current->link=newnode;
				break;
			}
			else{
				current=current->link;
				index++;
			
			}
		}
	}	
	count++;
	printf("Inserted at position %d\n", pos);	
}

void del_begin(){
	
	struct node* del = head;
	
	if (del != NULL){
		head = del->link;
		printf("\n %d deleted", del->data);
		free(del);
	}else{
		printf("List is Empty");
	}
	
}

void del_end(){
	
	struct node* del,*pre;
	
	pre = NULL;
	del = head;
	if(del != NULL){
		while(del->link != NULL){
			pre = del;
			del = del-> link;
		}
		printf("\n %d deleted", del->data);
		
		if(del == head){
			head = NULL;
			free(del);
		}else{
			pre->link = NULL;
			free(del);
		}
	}else{
		printf("List is Empty");
	}
	
}

void del_pos(){
	struct node* temp, *pre;
	int pos, i=1;
	
	printf("Enter the position within %d: \n",count);
	scanf("%d",&pos);
	
	if(head == NULL){
		printf("\nList is Empty \n");
	}
	
	if (pos==1){
		del_begin();
	}else{
		temp = head;
		while(i < pos-1){
			temp =temp->link;
			i++;
		}
		pre =temp->link;
		if(pre->link == NULL){
			temp->link = NULL;
		}else{
			temp->link = pre->link;
		}
		free(pre);
	}
	
}


void display(){
	
	
	struct node *temp;
	int count=1;
	temp=head;
	if(head == NULL){
		printf("\nList is Empty \n");
	}
	else{
	while(temp->link != NULL){
		printf("List [%d] : %d\n",count,temp->data);
		temp=temp->link;
		count++;
	}
	printf("List [%d] : %d\n",count,temp->data);
}
	
}
int main(){
	
	int c;
	
	while(c){
		printf("\n1. Insertion At Beginning\n2. Insertion at End\n3. Insertion at Position\n4. Delete At Beginning\n5. Delete at End\n6. Delete at Position\n7. Display\n");
		printf("Enter the  choice\n");
		scanf("%d", &c);
		switch(c){
			case 1: insert_begin();
				break;
			case 2: insert_end();
				break;
			case 3: insert_pos();
				break;	
			case 4: del_begin();
				break;
			case 5: del_end();
				break;
			case 6: del_pos();
				break;	
			case 7: display();
				break;
		
		
		default: printf("Invalid option ! Try Again..");
		}
	}	
	

	

	return 0;
}







