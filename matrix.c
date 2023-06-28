//Adjacency Matrix

#include<stdio.h>
#include<stdlib.h>

int adj[20][20];
int n, ed, in[20], out[20];

void degree()
{
	int i, j;
	
	for (i=1 ; i<=n ; i++)
	{
		for (j=1 ; j<=n ; j++)
		{
			if (adj[i][j] == 1)
			{
				out[i]++;
				in[j]++;
			}
		}
	}
	
	printf("\nIn_degree of all vertices:");
	for (i=1 ; i<=n ; i++)
		printf("\nIn_degree of %d - %d", i, in[i]);
	
	printf("\n\nOut_degree of all vertices:");
	for (i=1 ; i<=n ; i++)
		printf("\nOut_degree of %d - %d", i, out[i]);
}
	

void create()
{
	int i, j, x, y;
	
	printf("Enter the number of vertices: ");
	scanf("%d", &n);
	
	printf("Enter the total number of edges: ");
	scanf("%d", &ed);
	
	printf("Enter the edges between vertices one by one: \n");
	for (i=1 ; i<=ed ; i++)
	{
		scanf("%d\t%d", &x, &y);
		adj[x][y] = 1;
	}
	
	printf("\nThe adjacency matrix representation of the graph is,\n");
	for (i=1 ; i<=n ; i++)
	{
		for (j=1 ; j<=n ; j++)
		{
			printf("%d\t", adj[i][j]);
		}
		
		printf("\n");
	}
	
	degree();
}


void main()
{
	create();
}
