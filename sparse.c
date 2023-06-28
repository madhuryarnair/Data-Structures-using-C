//Sparse Matrix

#include<stdio.h>

void sparse(int a[10][10], int m, int n)
{
	int size = 0, i, j;
	for (i=0 ; i<m ; i++)
	{
		for (j=0 ; j<n ; j++)
		{
			if (a[i][j] != 0)
				size++;
		}
	}
	
	int b[size][3], k = 0;
	
	for (i=0 ; i<m ; i++)
	{
		for (j=0 ; j<n ; j++)
		{
			if (a[i][j] != 0)
			{
				b[k][0] = i;
				b[k][1] = j;
				b[k][2] = a[i][j];
				
				k++;
			}
		}
	}	
	
	
	printf("\nThe Representation of Sparse Matrix is:\n");
	printf("Row\tColumn\tValue\n");
		for (i=0; i<size; i++)
		{
			for (j=0; j<3; j++)
			{
				printf("%d\t", b[i][j]);
			}
			printf("\n");
		}
}

void main()
{
	int m, n, a[10][10], i, j;
	
	printf("\nEnter the number of rows and columns of the Sparse Matrix:\n");
	scanf("%d%d", &m, &n);
	
	printf("\nEnter the elements of the Sparse Matrix:\n");
		for (i=0 ; i<m ; i++)
			for (j=0 ; j<n ; j++)
				scanf("%d", &a[i][j]);
				
	printf("\nThe Sparse Matrix is:\n");
		for (i=0; i<m; i++)
		{
			for (j=0; j<n; j++)
			{
				printf("%d\t", a[i][j]);
			}
			printf("\n");
		}
		
	sparse(a, m, n);	
}		
				
	