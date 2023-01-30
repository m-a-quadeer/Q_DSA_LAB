//Stacks using Single Link List

#include <stdio.h>
#include <stdlib.h>

struct NODE
{
	int data ;
	struct NODE *link ;
};
struct STACK 
{
	struct NODE *top ;
};

int isSTACKEmpty(struct STACK*) ;
void push(struct STACK *, int) ;
int pop(struct STACK *) ;
void display(struct STACK *) ;
int getTopElement(struct STACK *) ;

int main ()
{
	struct STACK * s ; 
	int choice , element ; 
	s =(struct STACK *)malloc(sizeof(struct STACK)) ;
	s -> top = NULL ;
	while (1) 
	{
		printf("\n1. Status of STACK\n") ;
		printf("2. Push\n") ;
		printf("3. Pop\n") ;
		printf("4. Get Top Element\n") ;
		printf("5. Display\n") ;
		printf("6. Exit\n") ;
		printf("Enter choice : ") ;
		scanf("%d",&choice) ;
		if (choice == 6) break ;
		switch (choice)
		{
			case 1 : if (isSTACKEmpty(s))
					printf("\nSTACK is empty\n") ;
				 else 
					printf("\nSTACK is NOT empty\n") ;
					break ;

			case 2 : printf("Enter the element to be inserted : ") ;
				 scanf("%d",&element) ;
				 push(s,element) ;
				 break ;

			case 3 : if (isSTACKEmpty(s))
				 	printf("\nSTACK is empty\n") ;
				 else
				 	printf("Popped element is %d", pop(s)) ;
				 break ;

			case 4 : if (isSTACKEmpty(s))
				 	printf("\nSTACK is empty\n") ;
				 else 
				 	printf("Top element in STACK is %d", getTopElement(s)) ;
				break ;

			case 5 : if (isSTACKEmpty(s))
				 	printf("\nSTACK is empty\n") ;
				 else 
				 	display(s) ;
				break ;

			//case 6 : exit(1) ;
		}

	}
}

int isSTACKEmpty(struct STACK *s)
{
	if (s == NULL) return (1) ;
	if (s -> top == NULL) return (1) ;
	return (0) ;
}

void push (struct STACK *s , int e)
{
	struct NODE *newNODE ;
	newNODE =(struct NODE *)malloc(sizeof(struct NODE)) ;
	newNODE -> data = e ;
	newNODE -> link = s -> top ;
	s -> top = newNODE ;
}

int pop (struct STACK *s)
{
	int result ;
	struct NODE * curr ;
	if (isSTACKEmpty(s)) return (-1) ;
	curr = s -> top ;
	result = curr -> data ;
	s -> top = curr -> link ; 
	free(curr) ;
	return (result) ;
}

int getTopElement(struct STACK *s)
{
	if (isSTACKEmpty(s)) return (-1) ;
	return (s -> top -> data) ;
}

void display(struct STACK *s)
{
	struct NODE *curr ;
	if (isSTACKEmpty(s)) return ;
	curr = s -> top ;
	//int count = 0 ;
	while (curr != NULL)
	{
		//printf("%d (%d)",curr -> data, count) ;
		//count ++ ;
		printf("%d",curr -> data) ;
		curr = curr -> link ;
	}
	printf("\n") ;
}
