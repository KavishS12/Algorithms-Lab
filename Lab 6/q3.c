#include<stdio.h>
#include<stdlib.h>

int opcount = 0;

void merge(int arr[],int left,int right,int mid){
	int n1 = mid-left+1;
	int n2 = right-mid;
	int temp1[10],temp2[10];

	for(int i=0;i<n1;i++){
		temp1[i] = arr[left+i];
	}
	for(int i=0;i<n2;i++){
		temp2[i] = arr[mid+1+i];
	}

	int i,j,k;
	i=j=0;
	k=left;
	while(i<n1 && j<n2){
		if(temp1[i]<temp2[j]){
			arr[k++] = temp1[i++];
		}
		else{
			arr[k++] = temp2[j++];
		}
	}

	while(i<n1){
		arr[k++] = temp1[i++];
	}
	while(j<n2){
		arr[k++] = temp2[j++];
	}
	opcount++;
}

void mergeSort(int arr[],int left,int right){
	if(left<right){
		opcount++;
		int mid = (left+right)/2;
		mergeSort(arr,left,mid);
		mergeSort(arr,mid+1,right);
		merge(arr,left,right,mid); 
	}
}

int main()
{
	int n;
	printf("Enter the number of elements:");
	scanf("%d",&n);
	int arr[20];
	printf("Enter elements:\n");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}

	mergeSort(arr,0,n-1);

	printf("Sorted array : ");
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("Opcount = %d",opcount);
	return 0;
}