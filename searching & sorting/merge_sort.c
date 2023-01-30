//Program to use merge sort 

#include <stdio.h>

void mergesort(int [] , int , int ) ;
void merge(int [] , int , int , int ) ;

int main ()
{
	//Input size 
	int n ;
	printf("Enter the size of the array : ") ;
	scanf("%d", &n) ;
	
	//Reading array elements 
	int arr[n] , i ;
	for (i = 0 ; i < n ; i++ )
		{
			printf("Enter the element : ") ;
			scanf("%d", &arr[i] ) ;
		}
	printf("Array before sorting\n") ;
	for (i = 0 ; i < n ; i++)
		printf("%d", arr[i]) ;
	
	// Calling merge function
	mergesort(arr , 0 , n-1) ;

	//Printing array
	printf("\nAfter sorting :\n") ;
	for (i = 0 ; i < n ; i++)
		printf("%d", arr[i]) ;
}

void mergesort (int arr [] , int low , int high) 
{
	int mid ; 
	if (low < high)
	{
		mid = (low + high ) / 2 ;
		mergesort(arr , low , mid) ;
		mergesort(arr , mid + 1 , high) ;
		merge(arr , low , mid , high) ;
	}
}

void merge (int arr [] , int l1 , int l2 , int h)
{
	int temp [10] , i = l1 , j = l2 + 1 , k ;
	k = l1 ;
	for (i = l1 , j = l2 + 1 ; i <= l2 && j <= h ; )
	{
		if (arr[i] <= arr[j])
		{
			temp[k] = arr[i] ;
			k ++ ;
			j ++ ;
		}
		else 
		{
			temp[k] = arr[j] ;
			k ++ ;
			j ++ ;
		}
	}
	if (i <= l2)
	{
		while (i <= l2)
		{
			temp[k] = arr[i] ;
			k ++ ;
			i ++ ;
		}
	}
	if (j <= h)
	{
		while (j <= h)
		{
			temp[k] = arr[j] ;
			k ++ ;
			j ++ ;
		}
	}
	int q ;
	for (q = l1 ; q <= h ; q++)
		arr[q] = temp[q] ;
}
