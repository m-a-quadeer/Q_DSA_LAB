//Program to find using Linear search by recursion

# include <stdio.h>
int main(){
	int  n;
	printf("Enter the size of array : "); 
	scanf("%d", &n);

	int arr[n], i;
	printf("Enter array elements : ");
	for (i=0; i<n; i++)
		scanf("%d", &arr[i]);
	
	int key;
	printf("Enter key : ");
	scanf("%d", &key);

	for (i=0; i<n ; i++){
		if (key==arr[i]){
		printf("Element found at : %d", i);
		break ;
		}
	}
	if (i==n){
	printf("Element NOT found");
	}
}
   	
