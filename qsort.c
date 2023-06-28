//Quick Sort

#include<stdio.h>

void qsort(int a[], int start, int end)
{
	if (start < end)
	{
		int l, r, temp, pivot;
	
		pivot = a[start];
		l = start;
		r = end;
	
		while (l < r)
		{
			while (a[l] <= pivot)
				l++;
		
			while (a[r] > pivot)
				r--;
		
			if (l < r)
			{
				temp = a[l];
				a[l] = a[r];
				a[r] = temp;
			}
		}
	
		a[start] = a[r];
		a[r] = pivot;
	
		qsort(a, start, r-1);
		qsort(a, r+1, end);
	}
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
			
	qsort(a, 0, n-1);

	printf("\n\nThe array after sorting is,\n");
	for (i=0 ; i<n ; i++)
		printf("%d\t", a[i]);
}