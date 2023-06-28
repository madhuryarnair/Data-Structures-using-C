//Polynomial Linked List

#include<stdio.h>
#include<stdlib.h>

struct polynode
{
	float coeff;
	int exp;
	struct polynode *link;
};

typedef struct polynode pnode;
pnode *a, *b, *c, *last, *start1, *start2, *start3, *start4;

pnode* create()
{
	char ch;
	pnode *ptr, *cptr, *start;
	
	ptr = (pnode*)malloc(sizeof(pnode));
	
	printf("Enter the coefficient of the first term: ");
	scanf("%f", &ptr->coeff);
	
	printf("Enter the exponent of the first term: ");
	scanf("%d", &ptr->exp);

	start = ptr;
	ptr->link = NULL;
	
	
	do
	{
		cptr = (pnode*)malloc(sizeof(pnode));
		
		printf("Enter the coefficient of the next term: ");
		scanf("%f", &cptr->coeff);
		printf("Enter the exponent of the next term: ");
		scanf("%d", &cptr->exp);
		
		cptr->link = NULL;
		ptr->link = cptr;
		ptr = cptr;
		
		printf("\nDo you want to continue (Y/N) ? ");
		scanf(" %c", &ch);
	}
	while (ch == 'Y' || ch == 'y');
	return start;
}
	

void attach(float coeff, int exp)
{
	pnode *new;
	new = (pnode*)malloc(sizeof(pnode));
	
	new->coeff = coeff;
	new->exp = exp;
	new->link = NULL;
	
	last->link = new;
	last = new;
}

	
pnode* add()
{
	pnode *temp;
	float sum;
	
	a = start1;
	b = start2;
	
	last = (pnode*)malloc(sizeof(pnode));
	c = last;
	
	while ((a != NULL) && (b != NULL))
	{
		if (a->exp < b->exp)
		{
			attach(b->coeff, b->exp);
			b = b->link;
		}
		
		else if (a->exp > b->exp)
		{
			attach(a->coeff, a->exp);
			a = a->link;
		}
			
		else
		{
			sum = a->coeff + b->coeff;
			if(sum != 0)
				attach(sum, a->exp);
				
			a = a->link;
			b = b->link;
		}
	}

	while (a != NULL)
	{
		attach(a->coeff, a->exp);
		a = a->link;
	}

	while (b != NULL)
	{
		attach(b->coeff, b->exp);
		b = b->link;
	}

	last->link = NULL;
	
	temp = c;
	c = c->link;
	free(temp);
	return c;
}


pnode* mul()
{
	pnode *temp, *ptr, *cptr, *test;
	float coef;
	int ex;
	
	a = start1;
	
	last = (pnode*)malloc(sizeof(pnode));
	c = last;
	
	while (a != NULL)
	{
		b = start2;
		while (b != NULL)
		{
			coef = a->coeff * b->coeff;
			ex = a->exp + b->exp;
			
			if (coef != 0)
				attach(coef, ex);
			
			b = b->link;
		}
		
		a = a->link;
	}
	
	last->link = NULL;
	
	temp = c;
	c = c->link;
	free(temp);
	
	ptr = c;
	
	while (ptr->link != NULL)
	{
		test = ptr->link;
		cptr = ptr;
		
		while (test != NULL)
		{
			if (test->exp == ptr->exp)
			{
				ptr->coeff += test->coeff;
				
				cptr->link = test->link;
				cptr = test;
				test = test->link;
				free(cptr);
			}
			
			else
			{
				cptr = test;
				test = test->link;
			}
		}
		ptr = ptr->link;
	}
	return c;
}
	

void display(pnode *start)
{
	pnode *ptr;
	
	ptr = start;
	
	while (ptr->link != NULL)
	{
		printf("%fx^%d + ", ptr->coeff, ptr->exp);
		ptr = ptr->link;
	}	
	
	if (ptr->exp == 0)
		printf("%f", ptr->coeff);
		
	else
		printf("%fx^%d", ptr->coeff, ptr->exp);
		
	printf("\n");
}


void main()
{
	printf("\nEnter the coefficient and exponent of terms of first polynomial: \n");
	start1 = create();
	
	printf("\nEnter the coefficient and exponent of terms of second polynomial: \n");
	start2 = create();
	
	start3 = add();
	start4 = mul();
	
	printf("\nThe first polynomial is,\n");
	display(start1);
	
	printf("\nThe second polynomial is,\n");
	display(start2);
	
	printf("\n\nThe resultant polynomial after addition is,\n");
	display(start3);
	
	printf("\n\nThe resultant polynomial after multiplication is,\n");
	display(start4);
}	