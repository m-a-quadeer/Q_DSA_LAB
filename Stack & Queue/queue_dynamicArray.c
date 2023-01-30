//Program to implement dynamic queue

# include <stdio.h>
# include <stdlib.h>

struct Queue
{
	int * arr ;
	int front ;
	int rear ;
	int size ;
};

struct Queue * createQueue(struct Queue * , int ) ;
void destroyQueue(struct Queue *) ;

int isEmpty(struct Queue *) ;
void insert(struct Queue * , int ) ;
int delete(struct Queue *) ;
void display(struct Queue *) ;

int main()
{
	struct Queue * q ;
	q = createQueue(q,5) ;  //size is set 5
	int choice , element ;

	while(1)
	{
		printf("\nMenu") ;
		printf("\n1. Check if empty") ;
		printf("\n2. Insert") ;
		printf("\n3. Delete") ;
		printf("\n4. Display") ;
		printf("\n5. Exit") ;
		printf("\nEnter choice : ") ;
		scanf("%d", &choice) ;
		if (choice == 5)
		{
			destroyQueue(q) ;
			break ;
		}
		switch (choice)
		{
			case 1 : if (isEmpty(q))
				 	printf("\nQueue is empty\n") ;
				 else
				 	printf("\nQueue is NOT empty\n") ;
				 break ;

			case 2 : printf("\nEnter element to be inserted : ") ;
				 scanf("%d", &element) ;
				 insert(q, element) ;
				 break ;

			case 3 : if (isEmpty(q))
				 	printf("\nQueue is empty\n") ;
				 else
				 	printf("\nDeleted element is %d\n", delete(q)) ;
				 break ;

			case 4 : if (isEmpty(q))
				 	printf("\nQueue is empty\n") ;
				 else
				 	display(q) ;
				 break ;
		}
	}
}


struct Queue * createQueue(struct Queue * q , int size)
{
	q = (struct Queue *)malloc(sizeof(struct Queue)) ;
	q -> arr = (int *)malloc(size * sizeof(int)) ;
	q -> front = -1 ;
	q -> rear = -1 ;
	q -> size = size ;
	return (q) ;
}
void destroyQueue(struct Queue * q)
{
	free(q -> arr) ;
	free(q) ;
}


int isEmpty(struct Queue * q)
{
	if ((q -> front) == -1 && (q -> rear) == -1)
		return 1 ;
	return 0 ;
}

void insert(struct Queue * q , int e)
{
	if ((q -> rear) == (q -> size - 1))
	{
		printf("\nResizing array . . . . . .\n") ;
		q -> arr = (int *)realloc(q -> arr,(sizeof(int) * (q -> size + 1))) ;
		q -> size += 1 ;
		printf("\nNow array is of size %d\n", q -> size) ;
	}

	q -> arr[++(q -> rear)] = e ;

	if (q -> front == -1 )
		q -> front ++ ;
	return ;
}

int delete(struct Queue * q)
{
	return (q -> arr[(q -> front)++]) ;
}

void display(struct Queue * q)
{
	int i ;
	for (i = (q -> front) ; i <= (q -> rear) ; i++)
	//for (i = 0 ; i <= (q -> size -1) ; i++)
		printf("%d ", q -> arr[i]) ;
}
