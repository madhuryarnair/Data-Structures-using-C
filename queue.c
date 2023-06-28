//Implementation of Queue

#include<stdio.h>
#include<stdlib.h>

#define n 30

int queue[n], front = -1, rear = -1;


void display()
{
	if (front == -1)
		printf("\nQueue Empty");
	
	else
	{	
		for (int i=front ; i<=rear ; i++)
			printf("%d\t", queue[i]);
	}	
}		


void enqueue(int item)
{
	if (rear == n-1)
		printf("\nQueue is Full");
		
	else
	{
		rear += 1;
		queue[rear] = item;
		
		if (front == -1)
			front = 0;
		
		printf("The Queue after insertion of %d is,\n", item);
		display();
	}
}	


void dequeue()
{	
	if (front == -1)
		printf("\nQueue is Empty");
		
	else
	{
		int item = queue[front];
		printf("The deleted element is %d\n", item);
		
		if (front == rear)
			front = rear = -1;
		
		else
			front += 1;
		
		printf("The Queue after deletion of %d is,\n", item);
		display();
	}
}	
		

void main()
{
	int ch, item;
	
	while(1)
	{
		printf("\n\nMain Menu:");
		printf("\n1: Add an Element");
		printf("\n2: Delete an Element");
		printf("\n3: Display the contents of the Queue");
		printf("\n4: Exit");
		
		printf("\n\nEnter your choice: ");
		scanf("%d", &ch);
		
		switch(ch)
		{
			case 1:
					printf("Enter the element to be added to the Queue: ");
					scanf("%d", &item);
					enqueue(item);
					break;
					
			case 2:
					dequeue();
					break;
					
			case 3:
					printf("The contents of the Queue is,\n");
					display();
					break;
					
			case 4:
					exit(0);
					
			default:
					printf("\nPlease enter a valid choice");
					
		}
	}
}