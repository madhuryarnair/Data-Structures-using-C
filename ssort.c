//Selection Sort

#include<stdio.h>

void ssort(int a[], int n)
{
	int i, j, temp, index;
	
	for (i=0 ; i<n-1 ; i++)
	{
		index = i;
		for (j=i+1 ; j<n ; j++)
		{
			if (a[j] < a[index])
				index = j;
		}
		
		temp = a[i];
		a[i] = a[index];
		a[index] = temp;
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
			
	ssort(a, n);	
}