//Program to implement stacks using double linked list 

#include <stdio.h>
#include <stdlib.h>

struct DNODE
{
	int data ;
	struct DNODE * llink ;
	struct DNODE * rlink ;
};
struct DSTACK
{
	struct DNODE *top ;
};

void push (struct DSTACK * , int ) ;
int pop (struct DSTACK *) ;
int isEmpty (struct DSTACK *) ;
int getTopElement (struct DSTACK *) ;
void display (struct DSTACK *) ;

int main ()
{
	struct DSTACK * dst ;
	int choice , element ;
	dst = (struct DSTACK *)malloc(sizeof(struct DSTACK)) ;
	dst -> top = NULL ;
	while (1)
	{
		printf("\n1. Check status of STACK") ;
		printf("\n2. Push") ;
		printf("\n3. Pop") ;
		printf("\n4. Get Top Element") ;
		printf("\n5. Display") ;
		printf("\n6. Exit") ;
		printf("\nEnter choice : ") ;
		scanf("%d", &choice) ;
		if (choice == 6) break ;
		switch (choice)
		{
			case 1 : if (isEmpty(dst))
				 	printf("\nSTACK is empty\n") ;
				 else 
				 	printf("\nSTACK is NOT empty\n") ;
				 break ;
			case 2 : printf("\nEnter element to be entered : ") ;
				 scanf("%d", &element) ;
				 push (dst , element) ;
				 break ;
			case 3 : if (isEmpty(dst))
				 	printf("\nSTACK is empty\n") ;
				 else 
				 	printf("\nPopped element is %d\n", pop(dst)) ;
					break ;
			case 4 : if (isEmpty(dst))
				 	printf("\nSTACK is empty\n") ;
				 else 
				 	printf("\nTop element in STACK is %d \n",getTopElement(dst)) ;
				 break ;
			case 5 : if (isEmpty(dst))
				 	printf("\nSTACK is empty\n") ;
				 else 
				 	display(dst) ;
				 break ;
		}
	}
}

void push (struct DSTACK * dst , int e) 
{
	struct DNODE * newDNODE ;
	newDNODE = (struct DNODE *)malloc(sizeof(struct DNODE)) ;
	newDNODE -> data = e ;
	newDNODE -> llink = NULL ;
	newDNODE -> rlink = dst -> top ;
	if (dst -> top != NULL)
	{
		dst -> top -> llink = newDNODE ;
	}
	dst -> top = newDNODE ;
}

int pop (struct DSTACK * dst ) 
{
	int result ; 
	struct DNODE * curr ;
	if (dst -> top == NULL) return (0) ;
	curr = dst -> top ;
	result = curr -> data ;
	dst -> top = curr -> rlink ;
	if (curr -> rlink != NULL)
		curr -> rlink -> llink = NULL ;
	free(curr) ;
	return (result) ;
}

int isEmpty (struct DSTACK * dst )
{
	if (dst == NULL) return (1) ;
	if (dst -> top == NULL) return (1) ;
	return (0) ;
}

int getTopElement (struct DSTACK * dst ) 
{
	if (dst -> top == NULL) return (0) ;
	return (dst -> top -> data) ;
}

void display(struct DSTACK * dst )
{
	struct DNODE * curr ;
	if (isEmpty(dst)) return ;
	curr = dst -> top ;
	while (curr != NULL)
	{
		printf("%d  ", curr -> data) ;
		curr = curr -> rlink ;
	}
	printf ("\n") ;
}
