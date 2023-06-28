//Binary Search

#include<stdio.h>  
 
void bs(int a[], int n)
{
	int mid, low, high, item;
	char flag = 'f';
	
	low = 0;
	high = n-1;
	
	printf("\nEnter the element to be searched: ");  
    scanf("%d", &item);  
	
	while ((flag == 'f') && (low <= high))
	{
		mid = (low+high)/2;
			
		if (a[mid] == item)
		{
			flag = 't';
			printf("Element was found at the index %d and position %d respectively\n", mid, (mid+1));
		}	
		
		else if (a[mid] < item)
			low = mid + 1;
		
		else 
			high = mid - 1;
	}
	
	if (low > high)
		printf("Element not found\n");
}	
	
void main()  
{  
    int a[20], n, i;
	char flag = 'f';
	
	printf("\nEnter the number of elements of the array: ");
	scanf("%d", &n);
	
	printf("\nEnter the array:\n");
	for (i=0; i<n; i++)
		scanf("%d", &a[i]);
			
	bs(a, n);
}