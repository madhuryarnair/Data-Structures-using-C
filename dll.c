//Doubly Linked List

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *rlink;
	struct node *llink;
};

typedef struct node NODE;
NODE *start;

	
void create_DLL()
{
	NODE *new, *cptr;
	
	char ch;
	
	new = (NODE*)malloc(sizeof(NODE));
	printf("Enter the data of 1st node: ");
	scanf("%d", &new->data);
	
	start = new;
	cptr = new;
	new->rlink = NULL;
	new->llink = NULL;
	
	do
	{
		new = (NODE*)malloc(sizeof(NODE));
		printf("Enter the data for the next node: ");
		scanf("%d", &new->data);
		
		new->rlink = NULL;
		new->llink = cptr; 
		cptr->rlink = new;
		cptr = new;
		
		printf("\nDo you want to continue (Y/N) ?   ");
		scanf(" %c", &ch);
	}
	
	while ((ch == 'Y') || (ch == 'y'));		
}


void traverse_DLL()
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
				
			ptr = ptr->rlink;
		}
	}
}


void insert_beg_DLL(int item)
{
	NODE *new;
				
	new = (NODE*)malloc(sizeof(NODE));
				
	new->data = item;
				
	new->rlink = start;
	new->llink = NULL;
	start->llink = new;
	start = new;
	
	printf("The Doubly Linked List after insertion is,\n");
	traverse_DLL();
}


void insert_end_DLL(int item)
{
	NODE *new, *ptr;
				
	new = (NODE*)malloc(sizeof(NODE));
				
	new->data = item;
	
	ptr = start;
	
	while (ptr->rlink != NULL)
		ptr = ptr->rlink;
		
	ptr->rlink = new;
	new->llink = ptr;
	new->rlink = NULL;
	
	printf("The Doubly Linked List after insertion is,\n");
	traverse_DLL();
}


void insert_pos_DLL(int item, int key)
{
	NODE *new, *ptr;
				
	new = (NODE*)malloc(sizeof(NODE));
				
	new->data = item;
	
	ptr = start;
	
	while ((ptr->data != key) && (ptr->rlink != NULL))
		ptr = ptr->rlink;
		
	if (ptr->rlink == NULL)
		printf("\nNo node with data %d exists, insertion is not possible", key);
		
	else
	{
		(ptr->rlink)->llink = new;
		new->rlink = ptr->rlink;
		ptr->rlink = new;
		new->llink = ptr;
		
		printf("The Doubly Linked List after insertion is,\n");
		traverse_DLL();
	}
}


void del_beg_DLL()
{
	if (start == NULL)
		printf("\nList is Empty, Deletion is not possible");
	
	else
	{	
		NODE *ptr;
		
		ptr = start;
		start = start->rlink;
			
		printf("The element being deleted is %d", ptr->data);
			
		free(ptr);
		
		if (start != NULL)
			start->llink = NULL;
			
		printf("\nThe Doubly Linked List after deletion is,\n");
		traverse_DLL();
	}		
}


void del_end_DLL()
{
	if (start == NULL)
		printf("\nList is Empty, Deletion is not possible");
	
	else if (start->rlink == NULL)
	{
		printf("The element being deleted is %d", start->data);
		free(start);
		
		printf("\nThe Doubly Linked List after deletion is,\n");
		traverse_DLL();
	}

	else
	{
		NODE *ptr;
		
		ptr = start;
		
		while (ptr->rlink != NULL)
			ptr = ptr->rlink;
		
		(ptr->llink)->rlink = NULL;
		
		printf("The element being deleted is %d", ptr->data);
		free(ptr);
		
		printf("\nThe Doubly Linked List after deletion is,\n");
		traverse_DLL();
	}
}


void del_pos_DLL(int key)
{
	if (start == NULL)
		printf("\nList is Empty, Deletion is not possible");
	
	else if (start->rlink == NULL)
	{
		printf("The element being deleted is %d", start->data);
		free(start);
		
		printf("\nThe Doubly Linked List after deletion is,\n");
		traverse_DLL();
	}

	else
	{
		NODE *ptr;
		
		ptr = start;
		
		while ((ptr->data != key) && (ptr->rlink != NULL))
			ptr = ptr->rlink;
		
		if (ptr->rlink == NULL)
			printf("\nKey not found, Deletion is not possible");
		
		else
		{	
			(ptr->llink)->rlink = ptr->rlink;
			(ptr->rlink)->llink = ptr->llink;
			
			printf("The element being deleted is %d", ptr->data);
			free(ptr);
			
			printf("\nThe Doubly Linked List after deletion is,\n");
			traverse_DLL();
		}
	}
}	
		
	
void main()
{
	int t, item, key;
	
	start = (NODE*)malloc(sizeof(NODE));
	
	create_DLL();
	
	while(1)
	{
		printf("\n\nMain Menu:");
		printf("\n1: Display the elements of the Doubly Linked List");
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
					printf("The elements of the Doubly Linked List is,\n");
					traverse_DLL();
					break;
					
			case 2:
					printf("Enter the element to be inserted: ");
					scanf("%d", &item);
					
					insert_beg_DLL(item);
					break;
					
			case 3:
					printf("Enter the element to be inserted: ");
					scanf("%d", &item);
					
					insert_end_DLL(item);
					break;
					
			case 4:
					printf("Enter the element to be inserted: ");
					scanf("%d", &item);
					
					printf("Enter the data value of the node after which %d should be inserted: ", item);
					scanf("%d", &key);
					
					insert_pos_DLL(item, key);
					break;
					
			case 5:
					del_beg_DLL();
					break;
					
			case 6:
					del_end_DLL();
					break;
					
			case 7:
					printf("Enter the data value of the node to be deleted: ");
					scanf("%d", &key);
					
					del_pos_DLL(key);
					break;
					
			case 8:
					exit(0);
			
			default:
					printf("\nPlease enter a valid choice");
					
		}
	}
}	