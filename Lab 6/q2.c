#include<stdio.h>
#include<stdlib.h>

int opcount = 0;

void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
	opcount++;
}

int partition(int arr[],int low,int high){
	int pivot = arr[high];
	int i = low-1;

	for(int j=low;j<=high;j++){
		if(arr[j]<pivot){
			//opcount++;
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[high]);
	return i+1;
}

void quickSort(int arr[],int low,int high){
	if(low<high){
		//opcount++;
		int pi = partition(arr,low,high);
		quickSort(arr,low,pi-1);
		quickSort(arr,pi,high);
	}
}

int main()
{
	int n;
	printf("Enter the number of elements:");
	scanf("%d",&n);
	int arr[10];
	printf("Enter elements:\n");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}

	quickSort(arr,0,n-1);

	printf("Sorted array : ");
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("Opcount = %d",opcount);
	return 0;
}