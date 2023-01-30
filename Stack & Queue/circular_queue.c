//Program to implement queue
# include <stdio.h>
# include <stdlib.h>
# define MAX 10

//Function protocol
//void ins(int [] , int * , int * , int);
//int del(int [] , int * , int *);
//int isEmpty(int[] , int * , int *);
//int isFull(int [] , int * , int *);
//void display(int [] , int * , int *);

int isEmpty(int arr[] , int * front , int * rear )
{
	if ((*front) == -1 && (*rear) == -1) return (1) ;
	else return (0) ;
}

int isFull(int arr[] , int * front  , int * rear )
{
	if ((*rear) == (MAX-1)) return (1) ;
	else return (0) ;
}

void ins(int arr[] , int * front  , int * rear  , int element)
{
	if (isFull(arr , front , rear)) return ;
	arr[((*rear)+1) % MAX] = element ;
	if ((*front) == -1) 
		(*front) == 0; //(*front)++;
	return ;
}

int del(int arr[] , int * front  , int * rear )
{
	if (isEmpty(arr, front, rear)) return(0) ;
	return (arr[((*front)+1) % MAX]) ;
}

void display(int arr[] , int * front  , int * rear )
{
	int i ;
	if  (isEmpty(arr , front , rear)) return;
	for (i = (*front) ; i <= (*rear) ; i++)
		printf("%d (%d)", arr[i] ,i) ;
	printf("\n") ;
}

int main()
{
	int arr[MAX] ;
	int choice ;
	int front = -1 ;
	int rear = -1 ;
	int element ;
	while (1)
	{
		printf("1. Insert\n") ;
		printf("2. Delete\n") ;
		printf("3. Display\n") ;
		printf("4. Exit\n") ;
		printf("Enter choice : ") ;
		scanf("%d", &choice) ;
		
		if (choice == 4) break ;
		
		switch (choice)
		{
			case 1 : printf("Enter element to be inserted : ") ;
				 scanf("%d", &element) ;
				 ins(arr , &front , &rear , element);
				 break ;

			case 2 : del(arr , &front , &rear) ;
				 break ;

			case 3 : display(arr , &front , &rear) ;
				 break ;
		}
	}
}
