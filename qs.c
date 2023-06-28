//Queue and Stack

#include<stdio.h>
#define n 50

int stack[n], queue[n], front = -1, rear = -1, top = -1;

void display()
{
	int i;
	
	for (i=front ; i<=rear ; i++)
	printf("%d\t", queue[i]);
}		

void push(int data)
{
	top++;
	stack[top] = data;
}

int pop()
{
	int data = stack[top];
	top--;
	
	return data;
}

void enqueue(int item)
{
	rear++;
	queue[rear] = item;
	
	if (front == -1)
		front = 0;
}	

int dequeue()
{
	int data = queue[front];
	
	if (front == rear)
		front = rear = -1;
		
	else
		front++;
	
	return data;
}

void copy_to_stack()
{
	int i, data;
	
	for (i=front ; i<=rear ; i++)
	{
		data = dequeue();
	
		push(data);
	}
}

void reverse_queue()
{
	int i, data;
	
	for (i=top ; i>=0; i--)
	{
		data = pop();
	
		enqueue(data);
	}
}	
	
void create_q()
{
	char ch;
	int item;
	
	printf("\nEnter the first element to be added: ");
	scanf("%d", &item);
	
	enqueue(item);
	
	do
	{
		printf("Enter the next element to be added:" );
		scanf("%d", &item);
		
		enqueue(item);
		
		printf("\nDo you want to continue (Y/N) ? ");
		scanf(" %c", &ch);
	}
	while ((ch == 'Y') || (ch == 'y'));
}

void main()
{
	printf("\nEnter the elements of the queue:");
	create_q();
	
	printf("\nThe contents of the queue is,\n");
	display();
	
	copy_to_stack();
	
	reverse_queue();
	
	printf("\nThe contents of the queue after reversing is,\n");
	display();
}	
	
	
	