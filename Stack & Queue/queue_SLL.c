//Program  to implement queues using single linked list 

#include <stdio.h>
#include <stdlib.h>

struct  NODE 
{
	int data ;
	struct NODE * link ;
};
struct queue 
{
	struct NODE * front ;
	struct NODE * rear ;
};

void enqueue (struct queue * , int ) ;
int dequeue (struct queue * ) ;
int isQueueEmpty(struct queue *) ;
int getFrontElement(struct queue *) ;
int getRearElement(struct queue *) ;
void display(struct queue *) ;

int main()
{
	struct queue * q ;
	int choice , element ;
	q = (struct queue *)malloc(sizeof(struct queue)) ;
	q -> front = NULL ;
	q -> rear = NULL ;
	while (1) 
	{
		printf("\n1. Status of Queue") ;
		printf("\n2. Enqueue") ;
		printf("\n3. Dequeue") ;
		printf("\n4. Get Front Element") ;
		printf("\n5. Get Rear Element") ;
		printf("\n6. Display") ;
		printf("\n7. Exit") ;
		printf("\nEnter choice : ") ;
		scanf("%d", &choice) ;
		if (choice == 7) break ;
		switch (choice)
		{
			case 1 : if (isQueueEmpty(q))
				 	printf("\nQueue is empty\n") ;
				 else 
				 	printf("\nQueue is NOT empty\n") ;
				 break ;

			case 2 : printf("\nEnter element to be inserted : ") ;
				 scanf("%d", &element) ;
				 enqueue(q , element) ;
				 break ;

			case 3 : if (isQueueEmpty(q))
				 	printf("\nQueue is empty\n") ;
				 else
				 	printf("\nDeleted element is %d\n",dequeue(q)) ;
				 break ;

			case 4 : if (isQueueEmpty(q)) 
				 	printf("\nQueue is empty\n") ;
				 else 
				 	printf("\nFront element of queue is %d\n",getFrontElement(q)) ;
				 break ;

			case 5 : if (isQueueEmpty(q))
				 	printf("\nQueue is empty\n") ;
				 else 
				 	printf("\nRear element of queue is %d\n",getRearElement(q)) ;
				 break ;

			case 6 : if (isQueueEmpty(q))
				 	printf("Queue is empty") ;
				 else
				 	display(q) ;
				 break ;

		}
	}
}

void enqueue (struct queue * q , int e)
{
	struct NODE * newNODE ;
	newNODE = (struct NODE *)malloc(sizeof(struct NODE)) ;
	newNODE -> data = e ;
	newNODE -> link = NULL ;
	if (isQueueEmpty(q))
	{
		q -> front = newNODE ;
		q -> rear = newNODE ;
		return ;
	}
	else 
	{
		q -> rear -> link = newNODE ;
		q -> rear = newNODE ;
		return ;
	}
}

int dequeue(struct queue * q)
{
	int result ;
	struct NODE * curr ;
	if ((isQueueEmpty)) return (-1) ;
	curr = q -> front ;
	result = curr -> data ;
	q -> front = q -> front -> link ;
	if (q -> front == NULL)
		q -> rear = NULL ;
	free (curr) ;
	return (result) ;
}

int isQueueEmpty(struct queue * q)
{
	if (q == NULL) return (1) ;
	if (q -> front == NULL) return (1) ;
	return (0) ;
}

int getFrontElement(struct queue * q)
{
	if (isQueueEmpty(q)) return (-1) ;
	return (q -> front -> data) ;
}

int getRearElement(struct queue * q)
{
	if (isQueueEmpty(q)) return (-1) ;
	return (q -> rear -> data) ;
}

void display(struct queue * q)
{
	struct NODE * curr ;
	if (isQueueEmpty(q)) return ;
	curr = q -> front ;
	while (curr != NULL)
	{
		printf("%d ", curr -> data) ;
		curr = curr -> link ;
	}
	printf("\n") ;
}
