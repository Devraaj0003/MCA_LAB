#include<stdio.h>
#define MAX 10
int c,queue[MAX],item,front=-1,rear=-1,i,n,flag=0;

int main(){
	 do
	{
		 printf("\n1)Insertion\n2)Deletion\n3)Search\n4)Display\n5)Exit\n");
		 scanf("%d",&c);
		 switch(c)
		{
			case 1: enqueue();
	 		        break;
			case 2: dequeue();
 	            		break;       
 	            	case 3: display();
 	            		break;
			case 4: printf("\n****************Exit point***************\n");
 				break;
			default:
				printf("\n enter a valied choice 1 or 2 or 3 or 4 or 5");
		}
	}while(c!=5);
}


void enqueue()
{
	if((rear+1)%MAX==front){
		printf("\n****************** QUEUE OVERFLOW******************");
	}
	else
	{
		if(rear==-1)
		front=0;
		printf("\nEnter the element to insert : ");
		scanf("%d",&item);
		rear=(rear+1)%MAX;
		queue[rear]=item;
	}
}


void dequeue(){
 if(front==-1){
 	printf("\n***********************QUEUE UNDERFLOW***************");
 }
 else if(front==rear){
	printf("\nThe deleted element is:%d\n",queue[front]);
	front=rear=-1;
}
else{
	printf("\nThe deleted element is:%d\n",queue[front]);
	front=(front+1)%MAX;
}
}


void display(){
	if(front==-1){
 	printf("\n***********************QUEUE UNDERFLOW***************\n");
 	}
 	else{
 		printf("\n.............................\n");
	int front_pos=front,rear_pos=rear;
	if(front_pos>rear_pos){
		while(front_pos>rear_pos)
			{
				printf(" %d ",queue[front_pos]);
				front_pos=((front_pos+1))%MAX;
			}	
	}
	if(front_pos<=rear_pos){
		for(i=front_pos;i<=rear_pos;i++)
		printf(" %d ",queue[i]);
	}
	printf("\n.............................\n");
	}
	
}
