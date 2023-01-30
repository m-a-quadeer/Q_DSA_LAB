//Program to Evaluate postfix expression

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 80 

struct STACK 
{
	int arr[MAX] ;
	int top ;
};

void push(struct STACK * , int) ;
int pop(struct STACK *) ;
int isSTACKEmpty(struct STACK *) ;

int main ()
{
	struct STACK * st ; 
	char input [MAX] ;
	int operand1 ,operand2 , i , len , result ;
	st = (struct STACK *)malloc(sizeof(struct STACK)) ;
	st -> top = -1 ;
	printf("\nEnter the expression in POSTFIX  form for evaluation : ") ;
	scanf("%s",input) ;
	len = strlen(input) ;
	for (i = 0 ; i < len ; i ++)
	{
		switch (input[i])
		{
			case '+' : if (isSTACKEmpty(st))
				   {
				   	printf("\nInvalid input expression (+)\n") ;
					exit(0) ;
				   }
				   else 
				   operand2 = pop(st) ;
				   if (isSTACKEmpty(st))
				   {
				   	printf("\nInvalid input expression (++)\n") ;
					exit(0) ;
				   }
				   else 
				   	operand1 = pop(st) ;
				   push(st,operand1 + operand2) ;
				   break ;

			case '-' : if (isSTACKEmpty(st))
				   {
				   	printf("\nInvalid input expression (-)\n") ;
					exit(0) ;
				   }
				   else 
				   operand2 = pop(st) ;
				   if (isSTACKEmpty(st))
				   {
				   	printf("\nInvalid input expression (--)\n") ;
					exit(0) ;
				   }
				   else 
				   	operand1 = pop(st) ;
				   push(st,operand1 - operand2) ;
				   break ;

			case '*' : if (isSTACKEmpty(st))
				   {
				   	printf("\nInvalid input expression (*)\n") ;
					exit(0) ;
				   }
				   else 
				   operand2 = pop(st) ;
				   if (isSTACKEmpty(st))
				   {
				   	printf("\nInvalid input expression (**)\n") ;
					exit(0) ;
				   }
				   else 
				   	operand1 = pop(st) ;
				   push(st,operand1 * operand2) ;
				   break ;

			case '/' : if (isSTACKEmpty(st))
				   {
				   	printf("\nInvalid input expression (/)\n") ;
					exit(0) ;
				   }
				   else 
				   operand2 = pop(st) ;
				   if (isSTACKEmpty(st))
				   {
				   	printf("\nInvalid input expression (//)\n") ;
					exit(0) ;
				   }
				   else 
				   	operand1 = pop(st) ;
				   if (operand2 == 0) 
				   {
				   	printf("\nDivision by 0 not possible\n") ;
					exit(0) ;
				   }
				   else
				   	push(st , operand1 / operand2) ;
				   break ;
			case '0' : push(st,0);
				   break ;			
			case '1' : push(st,1);
				   break ;
			case '2' : push(st,2);
				   break ;
			case '3' : push(st,3);
				   break ;
			case '4' : push(st,4);
				   break ;
			case '5' : push(st,5);
				   break ;
			case '6' : push(st,6);
				   break ;
			case '7' : push(st,7);
				   break ;
			case '8' : push(st,8);
				   break ;
			case '9' : push(st,9);
				   break ;
			default  : printf("\nInvalid expression\n");
				   exit(0) ;
		}
	}
	result = pop(st) ;
	if((isSTACKEmpty(st)) != (1) )
	{
		printf("\nInvalid expression\n") ;
		exit(0) ;
	}
	else 
		printf("\nThe final evaluation of the given expression is %d : ",result) ;
}

void push (struct STACK * st, int element)
{
	(st -> top)++ ;
	st -> arr[st -> top] = element ;
	return ;
}

int pop (struct STACK * st ) 
{
	if (isSTACKEmpty(st)) return 0 ;
	return (st -> arr[(st -> top)--]) ;
}

int isSTACKEmpty (struct STACK * st)
{
	if (st -> top == -1) return 1 ;
	else return 0 ;
}
