//Merge Sort

#include<stdio.h>

int a[20], n, temp[20];

void merge(int low, int mid, int high)
{
	int i, j, k;
	
	i = low;
	j = mid+1;
	k = low;
	
	while ((i <= mid) && (j <= high))
	{
		if (a[i] <= a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}
	
	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}
	
	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}
	
	for (i=low ; i<=high ; i++)
		a[i] = temp[i];
}

void msort(int low, int high)
{
	int mid;
	
	if (low != high)
	{
		mid = (low+high)/2;
		msort(low, mid);
		msort(mid+1, high);
		merge(low, mid, high);
	}
}

void main()  
{  
    int i;  
	
	printf("\nEnter the number of elements of the array: ");
	scanf("%d", &n);
	
	printf("\nEnter the array:\n");
	for (i=0; i<n; i++)
		scanf("%d", &a[i]);
	
	printf("\nThe array before sorting is,\n");
	for (i=0 ; i<n ; i++)
		printf("%d\t", a[i]);
			
	msort(0, n-1);

	printf("\n\nThe array after sorting is,\n");
	for (i=0 ; i<n ; i++)
		printf("%d\t", a[i]);
}