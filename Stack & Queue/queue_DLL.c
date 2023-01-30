//Program to implement queue using DLL

#include <stdio.h>
#include <stdlib.h>

struct DNODE
{
	int data ;
	struct DNODE * llink ;
	struct DNODE * rlink ;
};
struct DQUEUE
{
	struct DNODE * front ;
	struct DNODE * rear ;
};

int isQueueEmpty(struct DQUEUE * ) ;
void enqueue(struct DQUEUE * , int ) ;
int dequeue(struct DQUEUE *) ;
int getFrontElement(struct DQUEUE *) ;
int getRearElement(struct DQUEUE *) ;
void display(struct DQUEUE *) ;

int main()
{
	struct DQUEUE * dq ;
	int choice , element ;
	dq = (struct DQUEUE *)malloc(sizeof(struct DQUEUE)) ;
	dq -> front = NULL ;
	dq -> rear = NULL ;
	while (1)
	{
		printf("1. Check status\n") ;
		printf("2. Enqueue\n") ;
		printf("3. Dequeue\n") ;
		printf("4. Get front element\n") ;
		printf("5. Get rear element\n") ;
		printf("6. Display\n") ;
		printf("7. Exit\n") ;
		printf("Enter choice : ") ;
		scanf("%d", &choice) ;
		if (choice == 7) break ;
		switch (choice)
		{
			case 1 : if (isQueueEmpty(dq))
				 	printf("\nDqueue is empty\n") ;
				 else
				 	printf("\nDqueue is NOT empty\n") ;
				 break ;

			case 2 : printf("\nEnter the element to be entered : \n") ;
				 scanf("%d", &element) ;
				 enqueue(dq,element) ;

			case 3 : if (isQueueEmpty(dq))
					printf("\nDqueue is empty\n") ;
				 else
				 {
				 	printf("\nDeleted element is %d\n", dequeue(dq)) ;
				 }
				 break ;

			case 4 : if (isQueueEmpty(dq))
				 	printf("\nDqueue is empty\n") ;
				 else
				 	printf("\nFront element in Dqueue is %d\n", getFrontElement(dq)) ;
				 break ;

			case 5 : if (isQueueEmpty(dq))
				 	printf("\nDqueue is empty\n") ;
				 else 
				 	printf("\nRear element is %d\n", getRearElement(dq)) ;

			case 6 : display(dq) ;
				 
		}
	}
}

int isQueueEmpty(struct DQUEUE * dq )
{
	if (dq -> front == NULL) return ;
	return 0 ;
}

void enqueue(struct DQUEUE * dq  , int e)
{
	struct DNODE * newDNODE ;
	newDNODE = (struct DNODE *)malloc(sizeof(struct DNODE)) ;
	newDNODE -> data = e ;
	newDNODE -> rlink = NULL ;
	if (dq -> front == NULL)
	{
		newDNODE -> llink = NULL ;
		dq -> front = newDNODE ;
		dq -> rear = newDNODE ;
		return ;
	}
	newDNODE -> llink = dq -> rear ;
	dq -> rear -> rlink = newDNODE ;
	dq -> rear = newDNODE ;
}

int dequeue(struct DQUEUE * dq)
{
	int result ; 
	result = dq -> front -> data ;
	struct DNODE * curr ;
	curr = dq -> front ;
	if (curr -> rlink == NULL)
	{
		dq -> front = NULL ;
		dq -> rear == NULL ;
		free (curr) ;
		return result ;
	}
	curr -> rlink -> llink = NULL ;
	dq -> front = curr -> rlink ;
	free(curr) ;
	return result ;
}

int getFrontElement(struct DQUEUE * dq)
{
	if (isQueueEmpty(dq)) return -1 ;
	return (dq -> front -> data);
}

int getRearElement(struct DQUEUE * dq)
{
	if (isQueueEmpty(dq)) return -1 ;
	return (dq -> rear -> data) ;
}

void display(struct DQUEUE * dq)
{
	struct DNODE * curr ;
	if (isQueueEmpty(dq)) return ;
	curr = dq -> front ;
	while (curr != NULL )
	{
		printf("%d ", curr -> data) ;
		curr = curr -> rlink ;
	}
	printf("\n") ;
}
