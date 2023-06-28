//Binary Tree

#include<stdio.h>
#include<stdlib.h>

#define size 15

char a[size];


void preorder(int index)
{
	int i = index;
	
    printf("%c\t",a[i]);
	
    if (a[2*i] != 0)
		preorder(2*i);
  
    if (a[2*i+1] != 0)
		preorder(2*i+1);
	
}


void inorder(int index)
{
	int i = index;
	
    if (a[2*i] != 0)
		inorder(2*i);
  
    printf("%c\t",a[i]);
	
    if (a[2*i+1] != 0)
		inorder(2*i+1);
	
}


void postorder(int index)
{
	int i = index;
	
    if (a[2*i] != 0)
		postorder(2*i);
  
    if (a[2*i+1] != 0)
		postorder(2*i+1);
  
    printf("%c\t",a[i]);
		
}


int search_seq_BT(int index, char key)
{
	int i,l;
	i = index;
	
	if (a[i] != key)
	{
		if (i > size)
			return 0;
		
		else 
		{
			l = search_seq_BT(2*i, key);
			
			if (l == 0)
				l = search_seq_BT(2*i+1, key);
		}
	}
	else
		return i;
}


void insert_seq_BT(char item)
{
	int l, key;
	char option;
	
	printf("Enter the parent of %c: ", item);
	scanf(" %c", &key);
	
	l = search_seq_BT(1, key);
	
	if (l == 0)
	{
		printf("\nSearch unsuccessful, insertion not possible\n");
		return;
	}

	if ((a[2*l] == 0) || (a[2*l+1] == 0))
	{
		printf("Enter the position at which to insert (L/R): ");
		scanf(" %c", &option);
		
		if ((option == 'l') || (option == 'L'))
		{
			if (a[2*l] == 0)
			{
				a[2*l] = item;
				printf("Insertion successful");
			}
			
			else
			{
				printf("\nDesired insertion not possible\n");
				return;
			}	
		}
		
		else if ((option == 'r') || (option == 'R'))
		{
			if (a[2*l+1] == 0)
			{
				a[2*l+1] = item;
				printf("Insertion successful");
			}
			
			else
			{
				printf("\nDesired insertion not possible\n");
				return;
			}
		}
	}	
		
	else
		printf("\nItem cannot be inserted as leaf node\n");
	return;
		
}


void delete_seq_BT(char item)
{
	int l;
	l = search_seq_BT(1, item);
	
	if (l == 0)
	{
		printf("\nElement does not exist, deletion not possible\n");
		return;
	}

	if ((a[2*l] == 0) && (a[2*l+1] == 0))
	{
		printf("Successfully deleted the element");
		a[l] = 0;
	}
	
	else
	{
		printf("\nThe node containing element is not a leaf node, deletion not possible\n");
		return;
	}	
}	

	
void main()
{
	char item, ch;
	int t;
	
	printf("\nEnter the root element: ");
	scanf(" %c", &a[1]);
	
	do
	{
		printf("\nEnter the next element to be inserted: ");
		scanf(" %c", &item);
		
		insert_seq_BT(item);
		
		printf("\n\nDo you want to continue (Y/N) ? ");
		scanf(" %c", &ch);
	}
	while ((ch == 'Y') || (ch == 'y'));
	
	while(1)
	{
		printf("\n\nMain Menu:");
		printf("\n1: Insert an element");
		printf("\n2: Search an element");
		printf("\n3: Delete an element");
		printf("\n4: Preorder Traversal");
		printf("\n5: Inorder Traversal");
		printf("\n6: Postorder Traversal");
		printf("\n7: Exit");
		
		printf("\n\nEnter your choice: ");
		scanf("%d", &t);
		
		switch(t)
		{
			case 1:
					printf("Enter the element to be inserted: ");
					scanf(" %c", &item);
					
					insert_seq_BT(item);
					
					break;
					
			case 2:
					printf("Enter the element to be searched: ");
					scanf(" %c", &item);
					
					int x = search_seq_BT(1,item);
					
					if (x == 1)
						printf("%c is the root element", item);
					
					else if (x == 0)
						printf("Element not found");
					
					else
					{
						x /= 2;
						printf("The parent of %c is %c", item, a[x]);
					}
					break;
					
			case 3: 
					printf("Enter the element to be deleted: ");
					scanf(" %c", &item);
					
					delete_seq_BT(item);
					break;
			
			case 4:
					printf("The preorder traversal is,\n");
					preorder(1);
					break;
					
			case 5:
					printf("The inorder traversal is,\n");
					inorder(1);
					break;
					
			case 6:
					printf("The postorder traversal is,\n");
					postorder(1);
					break;
					
			case 7:
					exit(0);
					
			default:
					printf("\nPlease enter a valid option\n");
					
		}
	}
}	