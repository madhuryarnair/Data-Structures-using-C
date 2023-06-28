//Hash Table - Chaining

#include<stdio.h>
#include<stdlib.h>

struct hash
{
    int data;
    struct hash *link;
};

typedef struct hash HT;

int n;

HT* table[100];

void declare()
{
    int i;
    for (i=0 ; i<n ; i++)
    {
        table[i] = NULL;
    }
}

void insert()
{
	HT *new;
    int value,index;
	
    printf("Enter the value to be inserted: ");
    scanf("%d", &value);
	
    new = (HT*)malloc(sizeof(HT));
	
    new->data = value;
    new->link = NULL;
	
    index = value % n;
	
    if (table[index] == NULL)
        table[index] = new;
   
	
    else
    {
		new->link = table[index];
        table[index] = new;
    }
}

void search()
{
	HT *ptr;
    int value, index, i = 0;
	
    printf("Enter the value to be searched: ");
    scanf("%d", &value);
	
    index = value % n;
	
    ptr = table[index];
	
    while ((ptr != NULL) && (ptr->data != value))
    {
        i++;
        ptr = ptr->link;
    }
	
    if (ptr->data == value)
        printf("Element is present in hash table with key %d at index %d\n", index, i);
	
    else
        printf("Element is not found\n");
}

void display()
{
    int i;
	
    for (i=0 ; i<n ; i++)
    {
        HT *ptr = table[i];
		
        printf("\nKey %d->", i);
		
        while (ptr != NULL)
        {
            printf("-%d", ptr->data);
            ptr = ptr->link;
        }
    }
	printf("\n");
}

void main()
{
    int ch;
	
	printf("Enter the size of the Hash Table: ");
	scanf("%d", &n);
	
    declare();
	
    while(1)
    {
		printf("\nMain Menu:");
        printf("\n1: Insert");
		printf("\n2: Display");
		printf("\n3: Search");
		printf("\n4: Exit");
		printf("\n\nEnter your choice: ");
        scanf("%d",&ch);
		
		switch(ch)
		{
			case 1: 
					insert();
					printf("Insertion Successful\n");
					break;
					
			case 2:
					printf("The Hash Table is,");
					display();
					break;
					
			case 3:
					search();
					break;
					
			case 4:
					exit(0);
					
			default:
					printf("\nPlease enter a valid choice");
		}
	}
}