//Program to implement Quick sort or Partition exchange sort or Pivot sort 
# include <stdio.h>
# include <stdlib.h>

void quicksort(int arr[] , int low , int high)
{
	if (low >= high) return ;
	int pivot , temp , i , j ;
	pivot = arr[low] ;
	i = low+1 ;
	j = high ;
	while ( i < j )
	{
		while (pivot > arr[i] && i < high) i++ ;
		while (pivot < arr[j] && j > low) j-- ;
		if ( i < j)
		{
			temp = arr[i] ;
			arr[i] = arr[j] ;
			arr[j] = temp ;
		}
	}
	temp = arr[low] ;
	arr[low] = arr[j] ;
	arr[j] = temp ;
	quicksort(arr , low , j-1) ;
	quicksort(arr , j+1 , high) ;
}

int main()
{
	int n ;
	printf("Enter size of array : ") ;
	scanf("%d" , &n) ;
	int arr[n] , i ;
	for (i=0 ; i<n ; i++)
	{
		printf("Enter elements : ");
		scanf("%d", &arr[i]);
	}
	quicksort(arr , 0 , n-1);
	for (i=0 ; i<n ; i++)
		printf("%d", arr[i]);
}
