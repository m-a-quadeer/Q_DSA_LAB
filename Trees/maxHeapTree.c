//Program to implement trees according to MAX HEAP logic

#include <stdio.h>
#define MAX 10

void addNode(int [] , int ) ;
int removeNode(int [] , int ) ;
int removeNodeElementWise(int [] , int ) ;
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
		printf("\n4. Remove a node by value") ;
		printf("\n5. Parent of") ;
		printf("\n6. Left child of") ;
		printf("\n7. Right child of") ;
		printf("\n8. Display") ;
		printf("\n9. Exit") ;
		printf("\nEnter choice : ") ;
		scanf("%d", &choice) ;
		if (choice >= 9) break ;
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

			case 4 : printf("\nEnter element (ie value) to be deleted : ") ;
				 scanf("%d", &element) ;
				 element = removeNodeElementWise(t,element) ;
				 if (element != -1)
				 	printf("\nDeleted element is %d\n" , element) ;
				 else
				 	printf("\nElement NOT found in tree\n") ;
				 break ;

			case 5 : printf("\nEnter the index of node : ") ;
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

			case 6 : printf("\nEnter the index of node : ") ;
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

			case 7 : printf("\nEnter the index of node : ") ;
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

			case 8 : display(t) ;
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
	int i , parent , temp ;
	for (i = 0 ; i < MAX ; i++)
	{
		if(t[i] == -1)
		break ;
	}
	if (i == MAX) return ;
	t[i] = e ;
	parent = (i-1)/2 ;
	while (parent >= 0 && t[parent] < t[i])
	{
		temp = t[i] ;
		t[i] = t[parent] ;
		t[parent] = temp ;
		i = parent ;
		parent = (i-1)/2 ;
	}
}

int removeNode(int t[] , int ind)
{
	int i , result , parent , lchild , rchild , max ;
	result = t[ind] ;
	if(result != -1)
	{
		parent = ind ;
		lchild = 2*parent + 1 ;
		rchild = 2*parent + 2 ;
		while ((lchild < MAX && t[lchild] != -1) || (rchild < MAX && t[rchild] != -1))
		{
			max = lchild ;
			if (t[max] < t[rchild])
				max = rchild ;
			t[parent] = t[max] ;
			parent = max ;
			lchild = 2*parent + 1 ;
			rchild = 2*parent + 2 ;
		}
		t[parent] = -1 ;
	}
	return(result) ;
}

int removeNodeElementWise(int t[] , int e)
{
	int i ; 
	for (i = 0 ; i < MAX ; i++)
	{
		if (t[i] == e)
			return (removeNode(t,i)) ;
	}
	return (-1) ;
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
