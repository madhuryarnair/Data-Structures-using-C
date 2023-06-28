//Binary Search Tree

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *lchild;
	struct node *rchild;
};
typedef struct node NODE;

NODE *root, *par;

void preorder(NODE *p)
{
	if (p != NULL)
	{
		printf("%d\t", p->data);
		preorder(p->lchild);
		preorder(p->rchild);
	}
}


void inorder(NODE *p)
{
	if (p != NULL)
	{
		inorder(p->lchild);
		printf("%d\t", p->data);
		inorder(p->rchild);
	}
}


void postorder(NODE *p)
{
	if (p != NULL)
	{
		postorder(p->lchild);
		postorder(p->rchild);
		printf("%d\t", p->data);
	}
}


void search_BST(NODE *p, int key)
{
	if (p == NULL)
		printf("Key not found, Node does not exist");
	
	else
	{
		if (key == p->data)
		{
			printf("Key found");
			
			if (p->data == root->data)
				printf("\n%d is the root node", key);
		
			else
				printf("\nThe parent of %d is %d", key, par->data);
		}

		else if (key < p->data)
		{
			par = p;
			search_BST(p->lchild, key);
		}
		
		else
		{
			par = p;
			search_BST(p->rchild, key);
		}
	}
}


NODE* insert_BST(NODE *p, int item)
{
	if (p == NULL)
	{
		p = (NODE*)malloc(sizeof(NODE));
		p->data = item;
		p->lchild = NULL;
		p->rchild = NULL;
	}

	else if (item < p->data)
		p->lchild = insert_BST(p->lchild, item);
	
	else if (item > p->data)
		p->rchild = insert_BST(p->rchild, item);
	
	return p;
}


NODE* succ(NODE *p)
{
	NODE *ptr1;
	
	ptr1 = p->rchild;
	
	while (ptr1->lchild != NULL)
		ptr1 = ptr1->lchild;
	
	return ptr1;
}
		
void delete_BST(NODE *p, int item)
{
	NODE *par_p;
	char flag = 'f';
	int cas;
	
	if (p == NULL)
	{
		printf("\nEmpty tree");
		return;
	}
	
	while ((p != NULL) && (flag == 'f'))
	{
		if (item < p->data)
		{
			par_p = p;
			p = p->lchild;
		}
		
		else if (item > p->data)
		{
			par_p = p;
			p = p->rchild;
		}
		
		else
			flag = 't';
	}
	
	if (flag == 'f')
		printf("\nItem not found");
	
	else
	{
		if ((p->lchild == NULL) && (p->rchild == NULL))
			cas = 1;
	
		else if ((p->lchild != NULL) && (p->rchild != NULL))
			cas = 3;
	
		else
			cas = 2;
	
		if (cas == 1)
		{
			if (par_p->lchild == p)
				par_p->lchild = NULL;
			
			else 
				par_p->rchild = NULL;
		
			free(p);
			
			printf("Deletion Successful");
			
			return;
		}
	
		else if (cas == 2)
		{
			if (par_p->lchild == p)
			{
				if (p->lchild == NULL)
					par_p->lchild = p->rchild;
			
				else
					par_p->lchild = p->lchild;
			}
		
			else if (par_p->rchild == p)
			{
				if (p->rchild == NULL)
					par_p->rchild = p->lchild;
			
				else
					par_p->rchild = p->rchild;
			}
		
			free(p);
			
			printf("Deletion Successful");
			
			return;
		}	
	
		else if (cas == 3)
		{
			NODE *succ_p = succ(p);
			int temp = succ_p->data;
			delete_BST(root, temp);
			p->data = temp;
		}
	}
}
				
		
void main()
{
	NODE *ptr;
	
	char ch;
	int item, t;
	
	printf("\nEnter the data value of the root node: ");
	scanf("%d", &item);
	
	root = insert_BST(root, item);
	
	do
	{
		printf("Enter the data value of the next node: ");
		scanf("%d", &item);
		
		ptr = insert_BST(root, item);
		
		if (ptr != NULL)
			printf("Insertion successful");
		
		printf("\nDo you want to continue (Y/N) ? ");
		scanf(" %c", &ch);
	}
	while ((ch == 'Y') || (ch == 'y'));
	
	while(1)
	{
		printf("\n\nMain Menu:");
		printf("\n1: Insert an element");
		printf("\n2: Search an element");
		printf("\n3: Delete an element");
		printf("\n4: Preorder Traversal");
		printf("\n5: Inorder Traversal");
		printf("\n6: Postorder Traversal");
		printf("\n7: Exit");
		
		printf("\n\nEnter your choice: ");
		scanf("%d", &t);
		
		switch(t)
		{
			case 1:
					printf("Enter the data value of the node to be inserted: ");
					scanf("%d", &item);
					
					ptr = insert_BST(root, item);
					
					if (ptr != NULL)
					printf("Insertion  Successful");
		
					break;
					
			case 2:
					printf("Enter the data value of the node to be searched: ");
					scanf("%d", &item);
					
					search_BST(root, item);
				
					break;
					
			case 3: 
					printf("Enter the data value of the node to be deleted: ");
					scanf("%d", &item);
					
					delete_BST(root, item);
				
					break;
					
			case 4:
					printf("The preorder traversal is,\n");
					preorder(root);
					break;
					
			case 5:
					printf("The inorder traversal is,\n");
					inorder(root);
					break;
					
			case 6:
					printf("The postorder traversal is,\n");
					postorder(root);
					break;
					
			case 7:
					exit(0);
					
			default:
					printf("\nPlease enter a valid option");
					
		}
	}
}	
