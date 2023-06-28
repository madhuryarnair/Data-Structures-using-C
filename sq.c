//Implementation of queue using stack

#include<stdio.h>
#include<stdlib.h>

int stack1[20], stack2[20], top1 = -1, top2 = -1;

void push1(int item)
{
	top1++;
	stack1[top1] = item;
}

void push2(int item)
{
	top2++;
	stack2[top2] = item;
}

int pop1()
{
	int data = stack1[top1];
	top1--;
	return data;
}

int pop2()
{
	int data = stack2[top2];
	top2--;
	return data;
}

int isEmpty1()
{
	if (top1 == -1)
		return 1;
	
	else
		return 0;
}

int isEmpty2()
{
	if (top2 == -1)
		return 1;
	
	else
		return 0;
}

void enqueue(int item)
{
	if (!isEmpty2())
	{
		while (!isEmpty2())
		{
			int temp = pop2();
			push1(temp);
		}
		
		push1(item);
	}
		
	else
		push1(item);
	
	printf("\nInsertion successful");
}

void dequeue()
{
	while (!isEmpty1())
	{
		int temp = pop1();
		push2(temp);
	}
	
	int data = pop2();
	
	if (data == 0)
		printf("Queue Empty");
	
	else
	{
		printf("\nThe element being deleted is %d", data);
		printf("\nDeletion Successful");
		
		while (!isEmpty2())
		{
			int temp = pop2();
			push1(temp);
		}
	
	}
}

void display()
{
	if (isEmpty1())
		printf("\nThe queue is empty");
	
	else
	{
		while (!isEmpty1())
		{
			int temp = pop1();
			push2(temp);
		}
		
		printf("\nThe elements of the queue is,\n");
		
		for (int i=top2 ; i>=0 ; i--)
			printf("%d\t", stack2[i]);
	}
}
			
void main()
{
	int ch, item;
	
	while (1)
	{
		printf("\n\nMain Menu:");
		printf("\n1:Insert an element to the queue");
		printf("\n2:Delete an element from the queue");
		printf("\n3:Display the contents of the queue");
		printf("\n4:Exit");
		printf("\nEnter your choice: ");
		scanf("%d", &ch);
		
		switch(ch)
		{
			case 1: 
					printf("\nEnter the element to be inserted: ");
					scanf("%d", &item);
					
					enqueue(item);
					break;
					
			case 2: 
					dequeue();
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
	