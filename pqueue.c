//Priority Queue

#include<stdio.h>
#include<stdlib.h>
#define n 30

struct PriorityQueue 
{
    int item;
    int priority;
};
typedef struct PriorityQueue PQ;

PQ pqueue[n];

int front=-1, rear=-1;

void display()
{
    if ((front == -1) && (rear == -1))
    {
        printf("\nPriority Queue is Empty");
        return;
    }
	
    for (int i=front ; i<=rear ; i++)
        printf("%d-%d\t", pqueue[i].item, pqueue[i].priority);
}

void check_and_insert(PQ data)
{
    int i,j;
 
    for (i=0 ; i<=rear ; i++)
    {
        if (data.priority < pqueue[i].priority)
        {
            for (j=rear+1 ; j>i ; j--)
                pqueue[j] = pqueue[j-1];
			
            pqueue[i] = data;
			rear++;
			printf("\nThe Priority Queue after insertion is (value-priority),\n");
			display();
			return;
        }
    }
	
    pqueue[i] = data;
	rear++;
	printf("\nThe Priority Queue after insertion is (value-priority),\n");
	display();
}
 
void enqueue_pq(PQ data)
{
    if (rear == n-1)
    {
        printf("\nPriority Queue is Full");
        return;
    }
	
    if ((front == -1) && (rear == -1))
    {
        front++;
        rear++;
		
        pqueue[rear] = data;
		
		printf("\nThe Priority Queue after insertion is (value-priority),\n");
		display();
		return;
    }  
	
    else
        check_and_insert(data);
}

void dequeue_pq()
{
    if (front == -1)
    {
        printf("\nPriority Queue is Empty");
        return ;
    }
	
    else
    {
        printf("The element being deleted is (value-priority), %d-%d\n", pqueue[front].item, pqueue[front].priority);
        front = front + 1;
		
		printf("\nThe Priority Queue after deletion is (value-priority),\n");
		display();
    }
} 
 
 
void main()
{
	int ch;
	PQ data;
	
	while(1)
	{
		printf("\n\nMain Menu:");
		printf("\n1: Add an Element");
		printf("\n2: Delete an Element");
		printf("\n3: Display the contents of the Priority Queue");
		printf("\n4: Exit");
		
		printf("\n\nEnter your choice: ");
		scanf("%d", &ch);
		
		switch(ch)
		{
			case 1:
					printf("Enter the element to be added to the Priority Queue (value-priority): ");
					scanf("%d-%d", &data.item, &data.priority);
					enqueue_pq(data);
					break;
					
			case 2:
					dequeue_pq();
					break;
					
			case 3:
					printf("\nThe contents of the Priority Queue is (value-priority),\n");
					display();
					break;
					
			case 4:
					exit(0);
					
			default:
					printf("\nPlease enter a valid choice");
					
		}
	}
}
