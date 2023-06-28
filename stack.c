//Implementation of Stack

#include<stdio.h>
#include<stdlib.h>

#define n 30

int stack[n], top = -1;


void display()
{
	if (top == -1)
		printf("\nStack Empty");
	
	else
	{	
		for (int i=top ; i>=0 ; i--)
			printf("%d\n", stack[i]);
	}	
}		


void push(int item)
{
	if (top == n-1)
		printf("\nStack Overflow");
		
	else
	{
		top += 1;
		stack[top] = item;
		
		printf("The Stack after insertion of %d is,\n", item);
		display();
	}
}	


void pop()
{	
	if (top == -1)
		printf("\nStack Underflow");
		
	else
	{
		int item = stack[top];
		printf("The deleted element is %d\n", item);
		
		top -= 1;
		
		printf("The Stack after deletion of %d is,\n", item);
		display();
	}
}	
		

void main()
{
	int ch, item;
	
	while(1)
	{
		printf("\nMain Menu:");
		printf("\n1: Add an Element");
		printf("\n2: Delete an Element");
		printf("\n3: Display the contents of the Stack");
		printf("\n4: Exit");
		
		printf("\n\nEnter your choice: ");
		scanf("%d", &ch);
		
		switch(ch)
		{
			case 1:
					printf("Enter the element to be added to the Stack: ");
					scanf("%d", &item);
					push(item);
					break;
					
			case 2:
					pop();
					break;
					
			case 3:
					printf("The contents of the Stack is,\n");
					display();
					break;
					
			case 4:
					exit(0);
					
			default:
					printf("\nPlease enter a valid choice");
					
		}
	}
}	
					
					