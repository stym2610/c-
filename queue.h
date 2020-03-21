#include<stdio.h>
#include<iostream>
 struct node
 {
 	int data;
 	node* next;
 };
 
 class queue
 {
 	private:
 	node *start , *rear;
 	public :
	queue()
	{
		start = NULL;
		rear = NULL;
	}
	node* getstart()
	{
		return start;
	}
	void create_queue()
	{
		int n, i;
		printf("enter no queue_nodes\n");
		scanf("%d",&n);
		for(i = 0; i<n; i++)
		{
			if(start == NULL)
			{
				start = new node();
				printf("enter data\n");
				scanf("%d", &start->data);
				rear = start;
				start->next = NULL;
				rear->next = NULL;
			}
			else
			{
				rear->next = new node();
				printf("enter data\n");
				scanf("%d", &rear->next->data);
				rear = rear->next;
				rear->next = NULL;  
			}
		}
	} 	
	
	void enqueue(int x)
	{
		if(start == NULL)
		{
			start = new node();
			start->data = x;
			rear = start;
			rear->next = NULL;
			start->next = NULL;
		}
		else
		{
			rear->next = new node();
			rear->next->data = x;
			rear = rear->next;
			rear->next = NULL;  
		}
	}
	
	node* dequeue()
	{
		int x;
		if(start == NULL)
		  printf("queue is empty\n");
		 node* temp = start; 
		if(start == rear)
		{
			start = rear = NULL;
		}  
		else
		{
			start = start->next;
		}
		return temp;
	}	
	
	void display_queue()
	{
		node* temp = start;
		printf("your queue is:-\n");
		while(temp!=NULL)
		{
			printf("%d  ", temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
 };
 
 