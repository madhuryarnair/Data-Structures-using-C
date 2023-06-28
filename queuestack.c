//Implementation of stack using queue

#include<stdio.h>
#include<stdlib.h>

int queue1[20], queue2[20], front1 = -1, rear1 = -1, front2 = -1, rear2 = -1;

void enqueue1(int item)
{
	rear1++;
	queue1[rear1] = item;
	if (front1 == -1)
		front1 = 0;
}

void enqueue2(int item)
{
	rear2++;
	queue2[rear2] = item;
	if (front2 == -1)
		front2 = 0;
}

int dequeue1()
{
	int data = queue1[front1];
	if (front1 == rear1)
		front1 = rear1 = -1;
	
	else
		front1++;
	
	return data;
}

int dequeue2()
{
	int data = queue2[front2];
	if (front2 == rear2)
		front2 = rear2 = -1;
	
	else
		front2++;
	
	return data;
}

int isEmpty1()
{
	if (front1 == -1)
		return 1;
	
	else
		return 0;
}

int isEmpty2()
{
	if (front2 == -1)
		return 1;
	
	else
		return 0;
}

void push(int item)
{
	if (!isEmpty1())
	{
		while (!isEmpty1())
		{
			int temp = dequeue1();
			enqueue2(temp);
		}
		
		enqueue1(item);
		
		while (!isEmpty2())
		{
			int temp = dequeue2();
			enqueue1(temp);
		}
	}
	
	else
		enqueue1(item);
	
	printf("\nInsertion Successful");
}

void pop()
{
	int data = dequeue1();
	
	if (data == 0)
		printf("Stack Empty");
	
	else
	{
		printf("\nThe element being deleted is %d", data);
		printf("\nDeletion Successful");
	}
}

void display()
{
	if (isEmpty1())
		printf("Stack Underflow");
	
	else
	{
		printf("\nThe elements of the stack is,\n");
		for (int i=front1 ; i<=rear1 ; i++)
			printf("%d\n", queue1[i]);
	}
}

void main()
{
	int ch, item;
	
	while (1)
	{
		printf("\n\nMain Menu:");
		printf("\n1:Insert an element to the stack");
		printf("\n2:Delete an element from the stack");
		printf("\n3:Display the contents of the stack");
		printf("\n4:Exit");
		printf("\nEnter your choice: ");
		scanf("%d", &ch);
		
		switch(ch)
		{
			case 1: 
					printf("\nEnter the element to be inserted: ");
					scanf("%d", &item);
					
					push(item);
					break;
					
			case 2: 
					pop();
					break;
					
			case 3: 
					display();
					break;
					
			case 4: 
					exit(0);
					
			default:
					printf("\nPlease enter a valid choice");
		}
	}
}
	
	
	