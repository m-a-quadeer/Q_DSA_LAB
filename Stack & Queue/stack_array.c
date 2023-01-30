//Program to perform stacking
# include<stdio.h>
# include<stdlib.h>
# define MAX 5

int isEmpty(int arr[],int *top){
	if (*top==-1) return 1;
	else return 0;
}

int isFull(int arr[],int *top){
	if (*top==(MAX-1)) return 1;
	else return 0;
}

void push(int arr[],int *top,int element){
	if (isFull(arr,top)) return ;
	arr[++(*top)] = element;
	return ;
}

int pop(int arr[],int *top){
	if (isEmpty(arr,top)) return 0;
	return (arr[(*top) --]);
}

void display(int arr[],int *top){
	int i ;
	for (i=0 ; i<=(*top) ; i++)
		printf("%d(%d)",arr[i],i);
	printf("\n");
}


int main(){
	int arr[MAX];
	int choice ;
	int element ;
	int top=-1;
	
	while(1){
		printf("1.Push\n");
		printf("2.Pop\n");
		printf("3.Display\n");
		printf("4.Exit\n");
		scanf("%d",&choice);
		
		switch(choice){

		case 1 :
			printf("Enter element to be added : ");
			scanf("%d",&element);
			push(arr,(&top),element);
			break;
		case 2 :
			pop(arr,(&top));
			break;
		case 3 : 
			display(arr,(&top));
			break;
		case 4 :
			exit(1);
		}
	}
}		
