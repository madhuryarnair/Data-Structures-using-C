//Hash Table - Linear Probing

#include<stdio.h>
#include<stdlib.h>

int n, table[100];

void declare()
{
    int i;
    for (i=0 ; i<n ; i++)
    {
        table[i] = 0;
    }
}

void insert()
{
    int value, index, i;
	
    printf("\nEnter the value to be inserted: ");
    scanf("%d", &value);
	
    index = value % n;
	
    if (table[index] == 0)
    {
        table[index] = value;
    }
	
    else
    {
        int ind;
		
		for(i=1 ; i<n ; i++)
		{
			ind = (index + i) % n;
			
			if(table[ind] == 0)
			{
				table[ind] = value;
				break;
			}
		}
		
		if (i == n)
			printf("\nElement cannot be inserted");
    }
}

void search()
{
    int value,index;
	
    printf("\nEnter the value to be searched: ");
    scanf("%d", &value);
	
    index = value % n;
	
	if(table[index] == value)
		printf("\nElement is present in hash table with key %d", index);
   
	else
	{
		int i;
		
		for (i=1 ; i<n ; i++)
		{
			int ind;
		
			ind = (index + i) % n;
			
			if (table[ind] == value)
			{
				printf("\nElement is present in hash table with key %d", ind);
				break;
			}
		}
		
		if (i == n)
			printf("\nElement is not found");
	}
}

void display()
{
    int i;
	
    for (i=0 ; i<n ; i++)
		printf("\nKey %d->%d", i, table[i]);
}

void main()
{
    int ch;
	
	printf("\nEnter the size of the Hash Table: ");
	scanf("%d", &n);
	
    declare();
	
    while(1)
    {
		printf("\nMain Menu:");
        printf("\n1: Insert");
		printf("\n2: Display");
		printf("\n3: Search");
		printf("\n4: Exit");
		printf("\nEnter your choice: ");
        scanf("%d",&ch);
		
		switch(ch)
		{
			case 1: 
					insert();
					break;
					
			case 2:
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

