//Polynomial Array

#include<stdio.h>

void add(int a[], int b[], int n, int m)
{
	int s[40], i, j;
	
	if (n < m)
	{
		while (n <= m)
		{
			j = m;
			n++;
			a[n]=0;
		}	
	}
	
	else
	{
		while (m <= n)
		{
			j = n;
			m++;
			b[m] = 0;
		}
	}

	for (i=0 ; i<=j ; i++)
	{
		s[i] = 0;
		s[i] = a[i] + b[i];
	}
	
	printf("\n\nThe resultant polynomial is,\n");
		for (i=j ; i>0 ; i--)
			printf("%dx^%d + ", s[i], i);
		if (i == 0)
			printf("%dx^%d", s[i], i);
}

void mul(int a[], int b[], int n, int m)
{
	int p[40], i, j;
	
	for (i=0 ; i<=(n+m) ; i++)
		p[i] = 0;
	
	for (i=0 ; i<=n ; i++)
		for (j=0 ; j<=m ; j++)
			p[i+j] += (a[i] * b[j]);
		
	printf("\n\nThe resultant polynomial is,\n");
		for (i=(n+m) ; i>0 ; i--)
			printf("%dx^%d + ", p[i], i);
		if (i == 0)
			printf("%dx^%d", p[i], i);
}

		
void main()
{
	int a[20], b[20], n, m, i;
	
	printf("\nEnter the highest degree of the first polynomial: ");
	scanf("%d", &n);
		
	printf("Enter the coefficients of the first polynomial:\n");
	for (i=n ; i>=0 ; i--)
	{
		printf("Enter the coefficient when degree = %d: ", i);
		scanf("%d", &a[i]);
	}	
		
	printf("\nEnter the highest degree of the second polynomial: ");
	scanf("%d", &m);
		
	printf("Enter the coefficients of the second polynomial:\n");
	for (i=m ; i>=0 ; i--)
	{
		printf("Enter the coefficient when degree = %d: ", i);
		scanf("%d", &b[i]);
	}	
		
	printf("\nThe first polynomial is,\n");
		for (i=n ; i>0 ; i--)
			printf("%dx^%d + ", a[i], i);
		if (i == 0)
			printf("%dx^%d", a[i], i);
				
	printf("\nThe second polynomial is,\n");
		for (i=m ; i>0 ; i--)
			printf("%dx^%d + ", b[i], i);
		if (i == 0)
			printf("%dx^%d", b[i], i);		
			
	add(a, b, n, m);
	mul(a, b, n, m);
}		