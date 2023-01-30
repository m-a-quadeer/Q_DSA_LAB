//Program to convert infix to postfix 

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# define MAX 10

/*struct Stack
{
	int s[MAX] ;
	int top ;
};*/

int isEmpty(int *) ;
void push(char [] , int * , int) ;
int pop(char [] , int * ) ;
//void display(char [] , int *) ;

int isOperand(char );
int pre(char ) ;
char * convert (char [] , int *) ;

int main()
{
	char arr[MAX] ;
	int top = -1 ;
	printf("\nEnter in INFIX form : \n") ;
	scanf("%s", arr) ;
	printf("%s\n", convert(arr,&top)) ;
}

int isEmpty(int * top)
{
	if (*top == -1)
		return 1 ;
	else
		return 0 ;
}

void push(char arr[] , int * top , int element)
{
	//if (*top == MAX -1) return 1 ;
	arr[++(*top)] = element ;
	return ;
}

int pop(char arr[] , int * top)
{
	if (isEmpty(top)) return -1 ;
	return (arr[(*top)--]) ;
}

int isOperand(char op)
{
	if (op == '+' || op == '-' || op == '*' || op == '/')
		return 0 ;
	else
		return 1 ;
}

int prec(char op)
{
	if (op == '+' || op == '-')
		return 1 ;
	else if (op == '*' || op == '/')
		return 2 ;
	else
		return 0 ;		
}

char *convert (char arr[] , int *top)
{
	char *postfix = (char *)malloc( (strlen(arr)+1) * sizeof(char)) ;
	int i = 0 , j = 0 ;
	while (arr[i] != '\0')
	{
		if (isOperand(arr[i]))
		{
			postfix[j] = arr[i] ;
			i++ ;
			j++ ;
		}
		else
		{
			if (prec(arr[i]) > prec(arr[*top]))
			{
				push(arr , top , arr[i++]) ;
			}
			else
				postfix[j++] = pop(arr,top) ;
		}
	}
	while (!isEmpty(top))
	{
		postfix[j++] = pop(arr , top) ;
	}
	postfix[j] = '\0' ;
	return postfix ;
}
