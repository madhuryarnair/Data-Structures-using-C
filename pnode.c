//Polynomial Arrays

#include<stdio.h>
#define size 100

struct node
{
	int coeff;
	int exp;
};
typedef struct node pnode;
pnode terms[size];

int startA, startB, startC, startD, finishA, finishB, finishC, finishD, avail;

int create(int start)
{
	int finish, a;
	char ch;
	
	a = start;
	
	printf("\nEnter the coefficient of the first term: ");
	scanf("%d", &terms[a].coeff);
	printf("Enter the exponenet of the first term: ");
	scanf("%d", &terms[a].exp);
	
	do
	{
		a++;
		printf("\nEnter the coefficient of the next term: ");
		scanf("%d", &terms[a].coeff);
		printf("Enter the exponenet of the next term: ");
		scanf("%d", &terms[a].exp);
		
		
		printf("\nDo you want to continue (Y/N) ?  ");
		scanf(" %c", &ch);
	}
	while (ch == 'Y' || ch == 'y');
	
	return a;
}


void attach(float coef, int ex)
{
	if (avail > size)
		printf("\nToo many terms, not possible");
	
	else
	{
		terms[avail].coeff = coef;
		terms[avail].exp = ex;
		avail++;
	}
}
		
	
void padd()
{
	int a, b;
	float coef;
	
	a = startA;
	b = startB;
	startC = avail;
	
	while (a <= finishA && b <= finishB)
	{
		if (terms[a].exp < terms[b].exp)
		{
			attach(terms[b].coeff, terms[b].exp);
			b++;
		}
		
		else if (terms[a].exp > terms[b].exp)
		{
			attach(terms[a].coeff, terms[a].exp);
			a++;
		}
		
		else
		{
			coef = terms[a].coeff + terms[b].coeff;
			
			if (coef != 0)
				attach(coef, terms[a].exp);
			
			a++;
			b++;
		}
	}
	
	for ( ; a<=finishA ; a++)
		attach(terms[a].coeff, terms[a].exp);
	
	for ( ; b<=finishB ; b++)
		attach(terms[b].coeff, terms[b].exp);
		
	finishC = avail - 1;
}
		
			
void pmul()
{
	int a, b, ex;
	float coef;
	
	a = startA;
	startD = avail;
	
	while (a <= finishA)
	{
		b = startB;
		
		while (b <= finishB)
		{
			coef = terms[a].coeff * terms[b].coeff;
			ex = terms[a].exp + terms[b].exp;
			
			if (coef != 0)
				attach(coef, ex);
			
			b++;
		}
		a++;
	}
	
	finishD = avail - 1;
}

	
void display(int start, int finish)
{
	for ( ; start<finish ; start++)
		printf("%dx^%d + ", terms[start].coeff, terms[start].exp);
	
	if (terms[start].exp == 0)
		printf("%d", terms[start].coeff);
	
	else
		printf("%dx^%d", terms[start].coeff, terms[start].exp);
}
	

void main()
{
	printf("\nEnter the first polynomial: ");
	startA = 0;
	finishA = create(startA);
	printf("\nEnter the second polynomial: ");
	startB = finishA + 1;
	finishB = create(startB);
	avail = finishB + 1;
	padd();
	pmul();
	printf("\nThe first polynomial is,");
	display(startA, finishA);
	printf("\nThe second polynomial is,");
	display(startB, finishB);
	printf("\nThe resultant polynomial after addition is,");
	display(startC, finishC);
	printf("\nThe resultant polynomial after multiplication is,");
	display(startD, finishD);
}