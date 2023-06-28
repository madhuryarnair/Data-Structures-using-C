//DFS and BFS

#include<stdio.h>
#include<stdlib.h>

int adj[20][20];
int n, ed;

void create()
{
	int i, j, x, y;
	
	printf("Enter the number of vertices: ");
	scanf("%d", &n);
	
	printf("Enter the total number of edges: ");
	scanf("%d", &ed);
	
	printf("Enter the edges between vertices one by one: \n");
	for (i=1; i<=ed ; i++)
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
}

void dfs()
{
	int v, pop_v, stack[20], visited[20], top = -1, i;
	
	for (i=1 ; i<=n ; i++)
		visited[i]=0;
	
	printf("Enter the starting vertex: ");
	scanf("%d", &v);
	
	top++;
	stack[top] = v;
	
	while (top >= 0)
	{
		pop_v = stack[top];
		top--;
		
		if (visited[pop_v] != 1)
		{
			printf("%d\t", pop_v);
			visited[pop_v] = 1;
		}
		
		for (i=n ; i>=1 ; i--)
		{
			if ((adj[pop_v][i] == 1) && (visited[i] == 0))
			{
				top++;
				stack[top] = i;
			}
		}
	}
}

void bfs()
{
	int v, temp, queue[20], visited[20], front = -1, rear = -1, i;
	
	for (i=1 ; i<=n ; i++)
		visited[i]=0;
	
	printf("Enter the starting vertex: ");
	scanf("%d", &v);
	
	visited[v] = 1;
	rear++;
	front++;
	
	printf("%d\t", v);
	queue[rear] = v;
	
	while (front <= rear)
	{
		temp = queue[front];
		front++;
		
		for (i=1 ; i<=n ; i++)
		{
			if ((adj[temp][i] == 1) && (visited[i] == 0))
			{
				printf("%d\t", i);
				visited[i] = 1;
				rear++;
				queue[rear] = i;
			}
		}
	}
}

void main()
{
	char ch;

	create();
	
	while (1)
	{
		printf("\n\nMain Menu:");
		printf("\n1: Depth First Search");
		printf("\n2: Breadth First Search");
		printf("\n3: Exit");
		
		printf("\n\nEnter your choice: ");
		scanf(" %c",&ch);
	
		switch(ch)
		{
			case '1':
					printf("Depth First Search,\n");
					dfs();
					break;
	
			case '2':
					printf("Breadth First Search,\n");
					bfs();
					break;
	
			case '3':
					exit(0);
	
			default:
					printf("\nPlease enter a valid choice\n");
		}
	}
}
	

		
		
