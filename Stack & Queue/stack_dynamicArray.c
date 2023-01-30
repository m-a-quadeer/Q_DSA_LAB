//Program to implement stack using dynamic array 

# include <stdio.h>
# include <stdlib.h>

struct Stack
{
	int * arr ;
	int top ;
	int size ;
};

struct Stack * createStack(struct Stack * , int) ;
void destroyStack(struct Stack *) ;

int isEmpty(struct Stack * ) ;
void push(struct  Stack * , int ) ;
int pop(struct Stack * ) ;
void display(struct Stack * ) ;

int main()
{
	struct Stack * st ;
	st = createStack(st , 5) ;
	int choice , element ;

	while (1)
	{
		printf("\nMenu") ;
		printf("\n1. Check if empty") ;
		printf("\n2. Push") ;
		printf("\n3. Pop") ;
		printf("\n4. Display") ;
		printf("\n5. Exit") ;
		printf("\nEnter choice : ") ;
		scanf("%d", &choice) ;
		if (choice == 5)
		{
			destroyStack(st) ;
			break ;
		}

		switch (choice)
		{
			case 1 : if (isEmpty(st))
				 	printf("\nStack is empty\n") ;
				 else
				 	printf("\nStack is NOT empty\n") ;
				 break ;

			case 2 : printf("\nEnter element to be pushed : ") ;
				 scanf("%d", &element) ;
				 push(st , element) ;
				 break ;

			case 3 : if (isEmpty(st))
				 	printf("\nStack is empty\n") ;
				 else
				 	printf("\nPopped element is %d\n", pop(st)) ;
				 break ;

			case 4 : if (isEmpty(st))
				 	printf("\nStack is empty\n") ;
				 else
					display(st) ;
				 break ;
		}
	}
}


struct Stack * createStack(struct Stack * st , int size)
{
	st = (struct Stack *)malloc(sizeof(struct Stack)) ;
	st -> arr = (int *)malloc(0) ;
	st -> top = -1 ;
	st -> size = size ;
	return st ;
}
void destroyStack(struct Stack * st)
{
	free(st -> arr) ;
	free(st) ;
}


int isEmpty(struct Stack * st )
{
	if (st -> top == -1)
		return 1 ;
	return 0 ;
}

void push(struct Stack * st , int e)
{
	if (st -> top == (st -> size - 1))
	{
		//Resizing the array . . . . .
		st -> arr = (int *)realloc(st -> arr , (sizeof(int) * (st -> size + 1))) ;
		st -> size += 1 ;
		//Array hasd been resized
	}
	(st -> top)++ ;
	st -> arr[st -> top] = e ;
	return ;
}

int pop(struct Stack * st)
{
	return (st -> arr[(st -> top)--]) ;
}

void display(struct Stack * st)
{
	int i ;
	for (i = 0 ; i <= st -> top ; i++)
		printf("%d ", st -> arr[i]) ;
}
