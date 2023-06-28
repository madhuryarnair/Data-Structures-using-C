//Insertion Sort

#include<stdio.h>

void isort(int a[], int n)
{
	int i, j, temp;
	
	for (i=1 ; i<n ; i++)
	{
		j = i-1;
		temp = a[i];
		
		while ((j >= 0) && (a[j] > temp))
		{
			a[j+1] = a[j];
			j--;
		}
		
		a[j+1] = temp;
	}
	
	printf("\n\nThe array after sorting is,\n");
	for (i=0 ; i<n ; i++)
		printf("%d\t", a[i]);
}

void main()  
{  
    int a[20], n, i;  
	
	printf("\nEnter the number of elements of the array: ");
	scanf("%d", &n);
	
	printf("\nEnter the array:\n");
	for (i=0; i<n; i++)
		scanf("%d", &a[i]);
	
	printf("\nThe array before sorting is,\n");
	for (i=0 ; i<n ; i++)
		printf("%d\t", a[i]);
			
	isort(a, n);	
}