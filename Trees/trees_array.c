//Program to represent trees using array

#include <stdio.h>
#define MAX 10

void addNode(int [] , int ) ;
int removeNode(int [] , int ) ;
int parentOf(int [] , int ) ;
int leftChildOf(int [] , int ) ;
int rightChildOf(int [] , int ) ;
void display(int [] ) ;
int isFull(int []) ;

int main()
{
	int t[MAX] ;
	int i , element , index , choice ;
	for (i = 0 ; i < MAX ; i++)
		t[i] = -1 ;  //Creating a -1 tree

	while (1)
	{
		printf("\nMenu") ;
		printf("\n1. Is Full ?") ;
		printf("\n2. Add a node") ;
		printf("\n3. Remove a node") ;
		printf("\n4. Parent of") ;
		printf("\n5. Left child of") ;
		printf("\n6. Right child of") ;
		printf("\n7. Display") ;
		printf("\n8. Exit") ;
		printf("\nEnter choice : ") ;
		scanf("%d", &choice) ;
		if (choice >= 8) break ;
		switch (choice)
		{
			case 1 : if (isFull(t))
				 	printf("\nCannot add as tree is full\n") ;
				 else
				 	printf("\nTree is not full\n") ;
				 break ;

			case 2 : if (isFull(t))
				 	printf("\nCannot add as tree is full\n") ;
				 else
				 {
				 	printf("\nEnter element : ") ;
				 	scanf("%d", &element) ;
				 	addNode(t,element) ;
				 }
				 break ;
			
			case 3 : printf("\nEnter index of element to be deleted : ") ;
				 scanf("%d", &index) ;
				 element = removeNode(t,index) ;
				 if (element == -1)
				 	printf("\nThere is no node at index %d\n",index) ;
				 else
				 	printf("\n%d has been deleted from %d index\n",element,index) ;
				 break ;

			case 4 : printf("\nEnter the index of node : ") ;
				 scanf("%d",&index) ;
				 if (index < 0 || index >= MAX)
				 {
				 	printf("\nThis represents your IQ level\n") ;
					break ;
				 }
				 else if (index == 0)
				 {
				 	printf("\nThis is root node. Root node does not have a parent\n") ;
					break ;
				 }
				 else
				 	printf("\nParent of the node with %d index is %d\n",index,parentOf(t,index)) ;
				 break ;

			case 5 : printf("\nEnter the index of node : ") ;
				 scanf("%d",index) ;
				 if (index < 0 || index >= MAX)
				 {
				 	printf("\nThis represents your IQ level\n") ;
					break ;
				 }
				 else
				 {
				 	printf("\nLeft child of index %d is %d\n",index,leftChildOf(t,index)) ;
				 }
				 break ;

			case 6 : printf("\nEnter the index of node : ") ;
				 scanf("%d", &index) ;
				 if (index < 0 || index >= MAX)
				 {
				 	printf("\nThis represents your IQ level\n") ;
					break ;
				 }
				 else
				 {
				 	printf("\nRight child of index %d is %d\n", index ,rightChildOf(t,index)) ;
				 }
				 break ;

			case 7 : display(t) ;
				 break ;

		}
	}
}

int isFull(int t[])
{
	int i ;
	for (i = 0 ; i <= MAX ; i++)
		if (t[i] == -1) return (0) ;
	return 1 ;
}

void addNode(int t[] , int e)
{
	int i ;
	for (i = 0 ; i < MAX ; i++)
		if(t[i] == -1)
		{
			t[i] = e ;
			return ;
		}
}

int removeNode(int t[] , int ind)
{
	int i , result , parent , lchild , rchild ;
	result = t[ind] ;
	if(result != -1)
	{
		parent = ind ;
		lchild = 2*parent + 1 ;
		rchild = 2*parent + 2 ;
		while (t[parent] != -1)
		{
			if (lchild < MAX && t[lchild] != -1)
			{
				t[parent] = t[lchild] ;
				parent = lchild ;
				lchild = 2*parent + 1 ;
				rchild = 2*parent + 2 ;
				continue ;
			}
			if (rchild < MAX && t[rchild] != -1)
			{
				t[parent] = t[rchild] ;
				parent = rchild ;
				lchild = 2*parent + 1 ;
				rchild = 2*parent + 2 ;
				continue ;
			}
			t[parent] = -1 ;
			break ;
		}
	}
	return(result) ;
}

int parentOf(int t[] , int ind)
{
	return (t[(ind-1)/2]) ;
}

int leftChildOf(int t[] , int ind)
{
	return (t[(2*ind)+1]) ;
}

int rightChildOf(int t[] , int ind)
{
	return (t[(2*ind)+2]) ;
}

void display(int t[])
{
	int i , lchild , rchild , parent ;
	printf("\nNode\tValue\tLchild\tRchild\n") ;
	for (i = 0 ; i < MAX ; i++)
	{
		if (t[i] == -1 ) continue ;
		printf("%d\t%d\t", i , t[i]) ;
		parent = i ;
		lchild = 2*parent + 1 ;
		rchild = 2*parent + 2 ;
		if (lchild >= MAX || t[lchild] == -1)
			printf("-\t") ;
		else
			printf("%d\t", t[lchild]) ;
		if (rchild >= MAX || t[rchild] == -1)
			printf("-\n") ;
		else
			printf("%d\n", t[rchild]) ;
	}
}
