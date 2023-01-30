//Program for polynomial

#include <stdio.h>
#define MAX 5

void readPoly(int []);
void addPoly(int [] , int [] , int []) ;
void subPoly(int [] , int [] , int []) ;
void mulPoly(int [] , int [] , int []) ;
void display(int []) ;
//void divPoly(int [] , int []) ;

int main() 
{
	int a [MAX] , b[MAX] , c[MAX] ;
	int choice ;
	
	while(1)
	{
		printf("\n1. Add") ;
		printf("\n2. Subtrct") ;
		printf("\n3. Multiply") ;
		printf("\n4. Exit") ;
		printf("\nEnter choice : ") ;
		scanf("%d", &choice) ;
		if (choice == 4)
			break ;

		printf("\nEnter 1st polynomial : ") ;
		readPoly(a) ;
		printf("\nEnter 2nd polynomial : ") ;
		readPoly(b) ;

		switch(choice)
		{
			case 1 : addPoly(a,b,c) ;
				 display(c) ;
				 break ;
			case 2 : subPoly(a,b,c) ;
				 display(c) ;
				 break ;
			case 3 : mulPoly(a,b,c) ;
				 display(c) ;
				 break ;
		}
	}
}

void readPoly(int x[])
{
	int i ;
	for (i = 0 ; i < MAX ; i++)
		scanf("%d" , &x[i]) ;
}
void addPoly(int x[] , int y[] , int z[])
{
	int i ;
	for (i = 0 ; i < MAX ; i++)
		z[i] = x[i] + y[i] ;
}
void subPoly(int x[] , int y[] , int z[])
{
	int i ;
	for (i = 0 ; i < MAX ; i++)
		z[i] = x[i] - y[i] ;
}
void mulPoly(int x[] , int y[] , int z[])
{
	int i , j ;
	for (i = 0 ; i < MAX ; i++)
		z[i] = 0 ;
	for (i = 0 ; i < MAX ; i++)
	{
		for (j = 0 ; j < MAX ; j++)
		{
			if ((i + j) < MAX)
				z[i+j] += x[i] * y[j] ;
		}
	}
	
}
void display(int z[])
{
	int i ;
	for (i = 0 ; i < MAX ; i++)
		printf("%d" , z[i]) ;
}
