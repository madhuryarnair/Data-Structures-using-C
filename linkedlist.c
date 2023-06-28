//Linked List

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

typedef struct node NODE;
NODE *start;

	
void create_SLL()
{
	NODE *new, *cptr;
	
	char ch;
	
	new = (NODE*)malloc(sizeof(NODE));
	printf("Enter the data of 1st node: ");
	scanf("%d", &new->data);
	
	start = new;
	cptr = new;
	new->link = NULL;
	
	do
	{
		new = (NODE*)malloc(sizeof(NODE));
		printf("Enter the data for the next node: ");
		scanf("%d", &new->data);
		
		new->link = NULL;
		cptr->link = new;
		cptr = new;
		
		printf("\nDo you want to continue (Y/N) ?   ");
		scanf(" %c", &ch);
	}
	
	while ((ch == 'Y') || (ch == 'y'));		
}


void traverse_SLL()
{
	if (start == NULL)
		printf("\nList is Empty");
	
	else
	{
		NODE *ptr;
		
		ptr = start;
		
		while (ptr != NULL)
		{
			printf("%d\t", ptr->data);
				
			ptr = ptr->link;
		}
	}
}


void insert_beg_SLL(int item)
{
	NODE *new;
				
	new = (NODE*)malloc(sizeof(NODE));
				
	new->data = item;
				
	new->link = start;
	start = new;
	
	printf("The Linked List after insertion is,\n");
	traverse_SLL();
}


void insert_end_SLL(int item)
{
	NODE *new, *ptr;
				
	new = (NODE*)malloc(sizeof(NODE));
				
	new->data = item;
	
	ptr = start;
	
	while (ptr->link != NULL)
		ptr = ptr->link;
		
	ptr->link = new;
	new->link = NULL;
	
	printf("The Linked List after insertion is,\n");
	traverse_SLL();
}


void insert_pos_SLL(int item, int key)
{
	NODE *new, *ptr;
				
	new = (NODE*)malloc(sizeof(NODE));
				
	new->data = item;
	
	ptr = start;
	
	while ((ptr->data != key) && (ptr->link != NULL))
		ptr = ptr->link;
		
	if (ptr->link == NULL)
		printf("\nNo node with data %d exists, insertion is not possible", key);
		
	else
	{
		new->link = ptr->link;
		ptr->link = new;
		
		printf("The Linked List after insertion is,\n");
		traverse_SLL();
	}
}


void del_beg_SLL()
{
	if (start == NULL)
		printf("\nList is Empty, Deletion is not possible");
	
	else
	{	
		NODE *ptr;
		
		ptr = start;
		start = start->link;
			
		printf("The element being deleted is %d", ptr->data);
			
		free(ptr);
			
		printf("\nThe Linked List after deletion is,\n");
		traverse_SLL();
	}		
}


void del_end_SLL()
{
	if (start == NULL)
		printf("\nList is Empty, Deletion is not possible");
	
	else if (start->link == NULL)
	{
		printf("The element being deleted is %d", start->data);
		free(start);
		
		printf("\nThe Linked List after deletion is,\n");
		traverse_SLL();
	}

	else
	{
		NODE *ptr, *prev;
		
		ptr = start;
		
		while (ptr->link != NULL)
		{
			prev = ptr;
			
			ptr = ptr->link;
		}
			
		printf("The element being deleted is %d", ptr->data);
		free(ptr);
		prev->link = NULL;
		
		printf("\nThe Linked List after deletion is,\n");
		traverse_SLL();
	}
}


void del_pos_SLL(int key)
{
	if (start == NULL)
		printf("\nList is Empty, Deletion is not possible");
	
	else if (start->link == NULL)
	{
		printf("The element being deleted is %d", start->data);
		free(start);
		
		printf("\nThe Linked List after deletion is,\n");
		traverse_SLL();
	}

	else
	{
		NODE *ptr, *prev;
		
		ptr = start;
		
		while ((ptr->data != key) && (ptr->link != NULL))
		{
			prev = ptr;
			
			ptr = ptr->link;
		}
		
		if (ptr->link == NULL)
			printf("\nKey not found, Deletion is not possible");
		
		else
		{	
			printf("The element being deleted is %d", ptr->data);
			prev->link = ptr->link;
			free(ptr);
			
			printf("\nThe Linked List after deletion is,\n");
			traverse_SLL();
		}
	}
}	
		
	
void main()
{
	int t, item, key;
	
	start = (NODE*)malloc(sizeof(NODE));
	
	create_SLL();
	
	while(1)
	{
		printf("\n\nMain Menu:");
		printf("\n1: Display the elements of the Linked List");
		printf("\n2: Insert an element at the beginning");
		printf("\n3: Insert an element at the end");
		printf("\n4: Insert an element at an arbitrary position");
		printf("\n5: Delete an element from the beginning");
		printf("\n6: Delete an element from the end");
		printf("\n7: Delete an element from an arbitrary position");
		printf("\n8: Exit");
		
		printf("\n\nEnter your choice: ");
		scanf("%d", &t);
		
		switch(t)
		{
			case 1:
					printf("The elements of the Linked List is,\n");
					traverse_SLL();
					break;
					
			case 2:
					printf("Enter the element to be inserted: ");
					scanf("%d", &item);
					
					insert_beg_SLL(item);
					break;
					
			case 3:
					printf("Enter the element to be inserted: ");
					scanf("%d", &item);
					
					insert_end_SLL(item);
					break;
					
			case 4:
					printf("Enter the element to be inserted: ");
					scanf("%d", &item);
					
					printf("Enter the data value of the node after which %d should be inserted: ", item);
					scanf("%d", &key);
					
					insert_pos_SLL(item, key);
					break;
					
			case 5:
					del_beg_SLL();
					break;
					
			case 6:
					del_end_SLL();
					break;
					
			case 7:
					printf("Enter the data value of the node to be deleted: ");
					scanf("%d", &key);
					
					del_pos_SLL(key);
					break;
					
			case 8:
					exit(0);
			
			default:
					printf("\nPlease enter a valid choice");
					
		}
	}
}	
	
	

	
				
				
				
				
	