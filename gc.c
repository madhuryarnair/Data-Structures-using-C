//Garbage Collector

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int size;
    struct node *rlink;
    struct node *llink;
};
typedef struct node NODE;

NODE* avail = NULL;

NODE* GetNode(int space)
{
    NODE *ptr, *ptr1;
	
    if (avail == NULL)
        printf("\nInsufficient memory");
	
    else 
    {
        ptr = avail;
		
        while ((ptr->rlink != NULL) && (ptr->size < space))
        {
            ptr1 = ptr;
            ptr = ptr->rlink;
        }
		
        if ((ptr->rlink == NULL) && (ptr->size < space))
            printf("\nInsufficient memory space");
		
        else if ((ptr->rlink == NULL) && (ptr->size >= space))
        {
            ptr1->rlink = NULL;
            return ptr;
        }
		
        else if (ptr == avail) 
        {
            if (ptr->rlink == NULL)
            {
                avail = NULL;
                return ptr;
            }
			
            else
            {
                avail = ptr->rlink;
                avail->llink = NULL;
                return ptr;
            }
        }
		
        else
        {
            ptr1->rlink = ptr->rlink;
            ptr1 = ptr->rlink;
            ptr1->llink = ptr->llink;
            return ptr;
        }
    }
}

void ReturnNode(NODE* p)
{
    NODE *ptr, *ptr1;
	
    ptr = avail;
	
    if (ptr == NULL)
    {
        avail = p;
        p->llink = NULL;
        p->rlink = NULL;
    }
	
    else
    {
        while ((ptr->rlink != NULL) && (ptr->size < p->size))
        {
            ptr1 = ptr;
            ptr = ptr->rlink;
        } 
		
        if (ptr->size >= p->size)
        {
            if (ptr == avail)
            {
                p->rlink = ptr;
                ptr->llink = p;
                p->llink = NULL;
                avail = p;
            }
			
            else 
            {
                p->rlink = ptr;
                p->llink = ptr1;
                ptr1->rlink = p;
                ptr->llink = p;
            }
        }
		
        else
        {
            p->llink = ptr;
            ptr->rlink = p;
            p->rlink = NULL;
        }
    }
}

void display()
{	
	printf("\nThe memory is as follows: \n");
					
	NODE *ptr = avail;
					
	while (ptr != NULL)
	{
		printf("Size= %d\n", ptr->size);
		ptr = ptr->rlink;
	}       
}

void main()
{
    int ch,s;
	
    NODE *ptr;

    while(1)
    {
        printf("\nMain Menu:");
		printf("\n1: GetNode");
		printf("\n2: ReturnNode");
		printf("\n3: Display");
		printf("\n4: Exit");
		printf("\n\nEnter your choice: ");
        scanf("%d",&ch);
		
        switch(ch)
        {
            case 1:
					printf("Input the space required: ");
					scanf("%d", &s);
					
					ptr = GetNode(s);
					
					printf("Size of memory: %d\n", ptr->size);
					
					break;
					
            case 2:
					printf("Input the space of memory to be returned to system: ");
					scanf(" %d", &s);
					
					ptr = (NODE*)malloc(sizeof(NODE));
					
					ptr->size = s;   
					
					ReturnNode(ptr);
					
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