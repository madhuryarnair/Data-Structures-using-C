//Linear Search

#include<stdio.h>  
 
 
void ls(int a[], int  n)
{
	int item, pos, flag = 0, i, index;
	
	printf("\nEnter the element to be searched: ");  
    scanf("%d", &item);  
	
    for (i = 0; i< n; i++)  
    {  
        if(a[i] == item)   
        {  
            flag = 1; 
			index = i;
			pos = i + 1; 			
            break;  
        }   
    } 
	
    if (flag == 1)   
        printf("Element was found at the index %d and position %d respectively\n", index, pos); 
  
    else    
        printf("Element not found\n");     
}	
	
void main()  
{  
    int a[20], n, i;  
	
	printf("\nEnter the number of elements of the array: ");
	scanf("%d", &n);
	
	printf("\nEnter the array:\n");
	for (i=0; i<n; i++)
		scanf("%d", &a[i]);
			
	ls(a, n);		
}   