//Program to implement insertion sort

# include <stdio.h>

void insertSort(int arr[] , int n)
{
	int i , j , temp ;
	for (i = 1 ; i < n ; i++)
	{
		temp = arr[i] ;
		j = i - 1 ;
		while  (j >= 0 && arr[j] > temp)
		{
			arr[j+1] = arr[j] ;
			j-- ;
		}
		arr[j+1] = temp ;
	}
}

int main()
{
	printf("Enter the size of array : ") ;
	int n ;
	scanf("%d", &n) ;
	int arr[n] ;
	int i ; 
	for (i = 0 ; i < n ; i++)
	{ 
		printf("Enter the elements : ") ;
		scanf("%d", &arr[i]) ;
	}
	insertSort(arr , n) ;
	printf("Elements after sorting : ") ;
	for (i = 0 ; i < n ; i++)
		printf("%d", arr[i]) ;

}
