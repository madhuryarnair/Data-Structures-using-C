//Implementation of Circular Queue

#include<stdio.h>
#include<stdlib.h>

#define n 3

int cqueue[n], front = -1, rear = -1;


void display()
{
	if ((front == -1) && (rear == -1))
		printf("\nCircular Queue Empty");
	
	else
	{	
		int i;
		
		if (front <= rear)
		{
			for (i=front ; i<=rear ; i++)
				printf("%d\t", cqueue[i]);
		}
		
		else
		{
			for (i=front ; i<n ; i++)
				printf("%d\t", cqueue[i]);
				
			for (i=0 ; i<=rear ; i++)
				printf("%d\t", cqueue[i]);
		}		
	}	
}		


void enqueue_cq(int item)
{
	if (front == (rear + 1) % n)
		printf("\nCircular Queue is Full");
		
	else
	{
		rear = (rear + 1) % n;
		cqueue[rear] = item;
		
		if (front == -1)
			front = 0;
		
		printf("The Circular Queue after insertion of %d is,\n", item);
		display();
	}
}	


void dequeue_cq()
{	
	if((front == -1) && (rear == -1))
		printf("\nCircular Queue is Empty");
		
	else
	{
		int item = cqueue[front];
		printf("The deleted element is %d\n", item);
		
		if (front == rear)
			front = rear = -1;
		
		else
			front = (front + 1) % n;
		
		printf("The Circular Queue after deletion of %d is,\n", item);
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
		printf("\n3: Display the contents of the Circular Queue");
		printf("\n4: Exit");
		
		printf("\n\nEnter your choice: ");
		scanf("%d", &ch);
		
		switch(ch)
		{
			case 1:
					printf("Enter the element to be added to the Circular Queue: ");
					scanf("%d", &item);
					enqueue_cq(item);
					break;
					
			case 2:
					dequeue_cq();
					break;
					
			case 3:
					printf("The contents of the Circular Queue is,\n");
					display();
					break;
					
			case 4:
					exit(0);
					
			default:
					printf("\nPlease enter a valid choice");
					
		}
	}
}