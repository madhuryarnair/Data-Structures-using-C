//DLL-String Palindrome

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	char ch;
	struct node *llink;
	struct node *rlink;
};
typedef struct node NODE;

NODE *start;

void insert_DLL(char str)
{
	NODE *ptr, *new;
	
	new = (NODE*)malloc(sizeof(NODE));	
	new->ch = str;
	
	if (start == NULL)
	{
		new->rlink = NULL;
		new->llink = NULL;
		start = new;
	}
	
	else if (start->rlink == NULL)
	{
		new->llink = start;
		new->rlink = NULL;
		start->rlink = new;
	}

	else
	{
		ptr = start;
		
		while ((ptr->rlink) != NULL)
			ptr = ptr->rlink;
		
		new->rlink = NULL;
		new->llink = ptr;
		ptr->rlink = new;
	}
}	

int palindrome()
{
	int f = 0;
	
	NODE *ptr;
	
	ptr = start;
	
	while ((ptr->rlink) != NULL)
		ptr = ptr->rlink;
	
	while (start != ptr)
	{	
		if ((start->ch) != (ptr->ch))
		{
			f = 1;
			return f;
		}
	
		start = start->rlink;
		ptr = ptr->llink;
	}	
	return f;
}
		
void main()
{
	char str[40];
	int len, i, flag;
	
	printf("\nEnter the string: ");
	scanf("%s", str);
	
	len = strlen(str);
	
	for (i=0 ; i<len ; i++)
	insert_DLL(str[i]);
	
	flag = palindrome();
	
	if (flag == 0)
		printf("The string is Palindrome\n");
	
	else
		printf("The string is not Palindrome\n");
}	
	
	