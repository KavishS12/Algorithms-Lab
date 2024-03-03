#include<stdio.h>

int main()
{
	int n;
	int opcount = 0;
	printf("Enter the number of elements:");
	scanf("%d",&n);

	int arr[10];
	printf("Enter elements:\n");
	for(int i=0;i<n;i++){
			scanf("%d",&arr[i]);
	}

	for(int i=n-1;i>0;i--){
		for(int j=0;j<i;j++){
			opcount++;
			if(arr[j] > arr[j+1]){
				opcount++;
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}

	printf("After sorting : ");
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\nOpcount = %d",opcount);

}