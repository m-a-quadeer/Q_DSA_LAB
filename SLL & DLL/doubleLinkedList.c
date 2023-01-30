//Program to implement Doubly Linked List (DLL)

#include <stdio.h>
#include <stdlib.h>

struct DNODE
{
	int data ;
	struct DNODE * llink ;
	struct DNODE * rlink ;
};
struct DLL
{
	struct DNODE * head ;
	struct DNODE * tail ;
};

int insertFirst(struct DLL * , int) ;
int insertLast(struct DLL * , int) ;
int insertAfterNth(struct DLL * , int , int) ;
int insertBeforeNth(struct DLL * , int, int) ;
int insertAfterValue(struct DLL * , int, int) ;
int insertBeforeValue(struct DLL * , int, int) ;

int deleteFirst(struct DLL * ) ;
int deleteLast(struct DLL * ) ;
int deleteAfterNth(struct DLL * , int) ;
int deleteBeforeNth(struct DLL * , int) ;
int deleteAfterValue(struct DLL * , int) ;
int deleteBeforeValue(struct DLL * , int) ;

int isDLLEmpty(struct DLL * ) ;
int size(struct DLL *) ;
int searchValue(struct DLL * , int) ;
int getHeadValue(struct DLL * ) ;
int getTailValue(struct DLL * ) ;
int getNthValue(struct DLL * , int) ;

void display(struct DLL * ) ;


int main()
{
	struct DLL * d ;
	int choice , element , pos ;
	d = (struct DLL *)malloc(sizeof(struct DLL)) ;
	d -> head = NULL ;
	d -> tail = NULL ;
	while (1)
	{
		printf("Menu\n") ;
		printf("1. Check Status\n") ;

		printf("2. Insert at first\n") ;
		printf("3. Insert at last\n") ;
		printf("4. Insert after nth\n") ;
		printf("5. Insert before nth\n") ;
		printf("6. Insert after value\n") ;
		printf("7. Insert before value\n") ;

		printf("8. Delete at first\n") ;
		printf("9. Delete at last\n") ;
		printf("10. Delete after nth\n") ;
		printf("11. Delete before nth\n") ;
		printf("12. Delete after value\n") ;
		printf("13. Delete before value\n") ;

		printf("14. Get head value\n") ;
		printf("15. Get tail value\n") ;
		printf("16. Get nth value\n") ;
		printf("17. Display\n") ;
		printf("18. Exit\n") ;
		printf("Enter choice : ") ;
		scanf("%d", &choice) ;
		if (choice == 18) break ;
		switch(choice)
		{
			case 1 : if (isDLLEmpty(d))
				 	printf("\nDLL is empty\n") ;
				 else 
				 	printf("\nDLL is NOT empty\n") ;

			case 2 : printf("\nEnter Element to be inserted at 1st position : ") ;
				 scanf("%d", &element) ;
				 insertFirst(d, element) ;

			case 3 : printf("\nEnter element to be inserted at last position : ") ;
				 scanf("%d", &element) ;
				 insertLast(d, element) ;

			case 4 : printf("\nEnter element to be inserted : ") ;
				 scanf("%d", &element) ;
				 printf("\nEnter position after which the element is to be inserted : ") ;
				 scanf("%d", &pos) ;
				 insertAfterNth(d, element , pos) ;
		}
	}
}

int isDLLEmpty(struct DLL * d )
{
	if (d -> rlink == NULL) 
		return (-1) ;
	else
		return (0) ;

}

int size(struct DLL * d)
{
	struct DNODE * temp ;
	int i = 0 ;
	if (d -> head == NULL)
		return 0 ;
	else
	{
		temp = d -> head ;
		while (temp -> rlink != NULL)
		{
			temp = temp -> rlink ;
			i++
		}
		free(temp) ;
		return (i) ;
	}
}
int searchValue(struct DLL * d , int value)
{
	struct DNODE * temp ;
	if (d -> head == NULL)
		return -1 ;
	else 
	{
		int i = 0 ;
		temp = d -> head ;
		while (temp -> data != value && temp -> rlink != NULL)
		{
			temp = temp -> rlink ;
			i++ ;	
		}
		return (i) ;
	}
}

int insertFirst(struct DLL * d , int e)
{
	struct DNODE * newDNODE ;
	newDNODE = (struct DNODE *)malloc(sizeof(struct DNODE)) ;
	newDNODE -> data = e ;
	newDNODE -> llink = NULL ;
	newDNODE -> rlink = d -> head ;
	if (d -> head != NULL)
		d -> head -> llink = newDNODE ;
	else
		d -> tail = newDNODE ;
	d -> head = newDNODE ;
	return (1) ;
}

int insertLast(struct DLL * d , int e)
{
	struct DNODE * newDNODE ;
	newDNODE = (struct DNODE * )malloc(sizeof(struct DNODE)) ;
	newDNODE -> data = e ;
	if (d -> head == NULL)
	{
		newDNODE -> llink = NULL ;
		newDNODE -> rlink = NULL ;
		d -> head = newDNODE ;
		d -> tail = newDNODE ;
	}
	else
	{
		newDNODE -> rlink = NULL ;
		d -> tail -> rlink = newDNODE ;
		newDNODE -> llink = d -> tail ;
	}
	return (1) ;
}

int insertAfterNth(struct DLL * d , int e , int pos)
{
	struct DNODE * newDNODE , temp ;
	newDNODE = (struct DNODE *)malloc(sizeof(struct DNODE)) ;
	newDNODE -> data = e ;
	if (d -> head == NULL )
	{
		newDNODE -> llink = NULL ;
		newDNODE -> rlink = NULL ;
		d -> head = newDNODE ;
		d -> tail = newDNODE ;
	}
	else if (size(d) > pos)
	{
		temp = temp -> head ;
		int i = 1 ;
		while (i != pos)
		{
			temp = temp -> rlink ;
			i++ ;
		}
		newDNODE -> llink = temp ;
		newDNODE -> rlink = temp -> rlink ;
		temp -> rlink -> llink = newDNODE ;
		temp -> rlink = newDNODE ;
		free(temp) ;
		return (1) ;
	}
	else
	{
		newDNODE -> rlink = NULL ;
		d -> tail -> rlink = newDNODE ;
		newDNODE -> llink = d -> tail ;
	}
}

int insertBeforeNth(struct DLL * d , int e , int pos)
{
	struct DNODE * newDNODE , temp ;
	newDNODE = (struct DNODE *)malloc(sizeof(struct DNODE)) ;
	newDNODE -> data = e ;
	if (d -> head == NULL )
	{
		newDNODE -> llink = NULL ;
		newDNODE -> rlink = NULL ;
		d -> head = newDNODE ;
		d -> tail = newDNODE ;
	}
	else if (size(d) > pos)
	{
		temp = temp -> head ;
		int i = 1 ;
		while (i != pos - 1)
		{
			temp = temp -> rlink ;
			i++ ;
		}
		temp -> rlink -> rlink -> llink = newDNODE ;
		newDNODE -> llink = temp -> rlink ;
		free(temp) ;
		return (1) ;
	}
	else
	{
		newDNODE -> llink = NULL ;
		newDNODE -> rlink = d -> head ;
		d -> head -> llink = newDNODE ;
		d -> head = newDNODE ;
	}
}

int insertAfterValue(struct DLL * d , int e , int value)
{
	struct DNODE * newDNODE , temp ;
	int pos ;
	newDNODE = (struct DNODE *)malloc(sizeof(struct DNODE)) ;
	newDNODE -> data = e ;
	if (d -> head == NULL )
	{
		newDNODE -> llink = NULL ;
		newDNODE -> rlink = NULL ;
		d -> head = newDNODE ;
		d -> tail = newDNODE ;
	}
	pos = searchValue(d,value) ;
	else if (size(d) > pos)
	{
		temp = temp -> head ;
		while (temp -> data != value)
		{
			temp = temp -> rlink ;
		}
		temp -> rlink -> rlink -> llink = newDNODE ;
		newDNODE -> llink = temp -> rlink ;
		free(temp) ;
		return (1) ;
	}
	else
	{
		newDNODE -> rlink = NULL ;
		d -> tail -> rlink = newDNODE ;
		newDNODE -> llink = d -> tail ;
	}
}

int insertBeforeValue(struct DLL * d , int e , int value)
{
	struct DNODE * newDNODE , temp ;
	int pos ;
	newDNODE = (struct DNODE *)malloc(sizeof(struct DNODE)) ;
	newDNODE -> data = e ;
	if (d -> head == NULL )
	{
		newDNODE -> llink = NULL ;
		newDNODE -> rlink = NULL ;
		d -> head = newDNODE ;
		d -> tail = newDNODE ;
	}
	pos = searchValue(d,value) ;
	else if (size(d) > pos - 1)
	{
		temp = temp -> head ;
		while (temp -> data != value)
		{
			temp = temp -> rlink ;
		}
		temp -> rlink -> rlink -> llink = newDNODE ;
		newDNODE -> llink = temp -> rlink ;
		free(temp) ;
		return (1) ;
	}
	else
	{
		newDNODE -> rlink = NULL ;
		d -> tail -> rlink = newDNODE ;
		newDNODE -> llink = d -> tail ;
	}
}


