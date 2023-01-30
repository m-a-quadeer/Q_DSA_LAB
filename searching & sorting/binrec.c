//Program to find using BInary search by recursion

# include <stdio.h>
int main(){
	int  n;
	printf("Enter the size of array : "); 
	scanf("%d", &n);

	int arr[20], i;
	printf("Enter array elements : ");
	for (i=0; i<n; i++)
		scanf("%d", &arr[i]);
	
	int key;
	printf("Enter key : ");
	scanf("%d", &key);

	int low=0, high=n-1 ;
	int bin=binrec(arr, low, high, key);
	if (bin==-1)
		printf("not found");
	else
		printf("Index postion = %d\n", bin);
		printf("Position = %d\n", bin+1);
}

int binrec(int arr[], int low, int high, int key){
	int mid;
	if (low>high) return(-1);
	mid = (low + high)/2;
	if (key==arr[mid]) return (mid);
	if (key < arr[mid]) return (binrec (arr, low ,mid-1, key));
	if (key > arr[mid]) return (binrec (arr, mid+1, high, key));
}
   	
