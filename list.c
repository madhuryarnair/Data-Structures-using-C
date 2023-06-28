//Adjacency List

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int vertex;
	struct node *link;
};
typedef struct node NODE;

NODE graph[50];

