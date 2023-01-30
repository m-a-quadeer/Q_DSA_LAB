//Program to implement single linked list 

#include <stdio.h>
#include <stdlib.h>

struct NODE
{
	int data ;
	struct NODE* link ;
};
struct SSL
{
	struct NODE *first ;
};
//Function Declarations
int isEmpty(struct SSL*);
void insertAtFirst(struct SSL* , int ) ;
void insertAtLast(struct SSL*, int ) ;
int deleteAtFirst(struct SSL*) ;
int deleteAtLast(struct SSL*) ;
int findElement(struct SSL* , int ) ;
void display(struct SSL*) ;

int main()
{
	struct SSL *sptr ;
	int choice , element , result ;
	sptr = (struct SSL*)malloc(sizeof(struct SSL)) ;
	sptr -> first = NULL ;
	
	while(1)
	{
		printf("\nMenu\n") ;
		printf("1. Check Status\n") ;
		printf("2. Insert at first\n") ;
		printf("3. Insert at last\n") ;
		printf("4. Delete at first\n") ;
		printf("5. Delete at last\n") ;
		printf("6. Find element\n") ;
		printf("7. Display\n") ;
		printf("8. Exit\n") ;
		printf("Enter choice : ") ;
		scanf("%d", &choice) ;
		if (choice == 8)
			break ;
		switch (choice)
		{
			case 1 : if (isEmpty(sptr))
				 	printf("\nSingle Linked List is empty\n") ;
				 else 
					printf("\nSingle Linked List is NOT empty\n") ;
					break ;
			case 2 : printf("\nEnter the element to be inserted at 1st place : ") ;
				 scanf("%d", &element) ;
				 insertAtFirst(sptr , element) ;
				 break ;
			case 3 : printf("\nEnter the element to be inserted at last place : ") ;
				 scanf("%d", &element) ;
				 insertAtLast(sptr , element) ;	
				 break ;
			case 4 : if (isEmpty(sptr))
				 	printf("\nEmpty List\n") ;
				 else 
				 {
				 	result = deleteAtFirst(sptr) ;
					printf("\nDeleted item is %d", result) ;
				 }
				 break ;
			case 5 : if (isEmpty(sptr))
				 	printf("\nEmpty List\n") ;
				 else 
				 {
				 	result = deleteAtLast(sptr) ;
					printf("\nDeleted item is %d", result) ;	
				 }
				 break ;
			case 6 : if (isEmpty(sptr))
				 	printf("\nEmpty List\n") ;
				 else 
				 {
				 	printf("\nEnter the key element : ") ;
					scanf("%d", &element) ;
					result = findElement(sptr , element) ;
					if (result == -1)
						printf("\nElement NOT found\n") ;
					else
						printf("\nElement found\n") ;
				 }
				 break ;
			case 7 : if (isEmpty(sptr))
				 	printf("\nEmpty list\n") ;
				 else
					display(sptr) ;
		}
	}
}

int isEmpty(struct SSL *sptr)
{
	if (sptr -> first == NULL)
		return (-1) ;
	else
		return (0) ;
}

void insertAtFirst(struct SSL *sptr , int e)
{
	struct NODE *nptr ;
	nptr = (struct NODE*)malloc(sizeof(struct NODE)) ;
	nptr -> data = e ;
	nptr -> link = sptr -> first ;
	sptr -> first = nptr ;
}

void insertAtLast(struct SSL *sptr , int e)
{
	struct NODE *nptr ;
	struct NODE *last ;
	nptr = (struct NODE *) malloc (sizeof(struct NODE)) ;
	nptr -> data = e ;
	nptr -> link = NULL ;
	if (sptr -> first == NULL)
		sptr -> first = nptr ;
	else 
	{
		last = sptr -> first ;
		while ((last -> link) != NULL)
		{
			last = last -> link ;
			//last -> link = nptr ;
		}

		last -> link = nptr ;
	}
}

int deleteAtFirst(struct SSL *sptr)
{
	struct NODE *curr ;
	int result ;
	if (isEmpty(sptr)) return (-1) ;
	curr = sptr -> first ;
	sptr -> first = curr -> link ;
	result = curr -> data ;
	free (curr) ;
	return (result) ; 
}

int deleteAtLast(struct SSL *sptr)
{
	struct NODE *curr , *prev ;
	int result ; 
	if (isEmpty)
		return (-1) ;
	if (sptr -> first -> link == NULL)           //Check if one node or more nodes
	{
		curr = sptr -> first ;
		result = curr -> data ;
		free (curr) ;
		sptr -> first = NULL ;
		return (result) ;
	}
	else 
	{
		prev = sptr -> first ;
		while (prev -> link -> link != NULL)
			prev = prev -> link ;
		curr = prev -> link ;
		prev -> link = NULL ;
		result = curr -> data ;
		free (curr) ;
		return (result) ;
	}
}

int findElement(struct SSL *sptr , int e)
{
	struct NODE *curr ;
	int result ;
	if (isEmpty(sptr)) return (-1) ;
	curr = sptr -> first ;
	result = 1 ;
	while (curr != NULL)
	{
		if (curr -> data == e) return (result) ;
		curr = curr -> link ;
		result ++ ;
	}
	return (-1) ;
}

void display(struct SSL *sptr)
{
	if (isEmpty(sptr))
		printf("\nEmpty list\n") ;
	else
	{
		struct NODE* temp ;
		temp = sptr -> first ;
		while (temp != NULL)
		{
			printf("%d ", temp -> data ) ;
			temp = temp -> link ;
		}
		printf("\n") ;
	}
}
