#include <stdio.h>

int opcount = 0;

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[],int n,int i) {
    opcount++;
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left<n && arr[left]>arr[largest])
        largest = left;

    if (right<n && arr[right]>arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i],&arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildHeapBottomUp(int arr[],int n) {
    for (int i = n/2 - 1;i >= 0;i--){
        heapify(arr,n,i);
    }
}

void heapSort(int arr[],int n) {
    buildHeapBottomUp(arr,n);

    for (int i=n-1;i > 0;i--) {
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);
    }
}

int main() {
    int n;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    int arr[20];
    printf("Enter elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printf("Array before sorting:");
    for (int i = 0;i < n;i++){
        printf("%d ",arr[i]);
    }
    
    heapSort(arr, n);

    printf("\nArray after heap sort:");
    for (int i = 0;i < n;i++){
        printf("%d ", arr[i]);
    }
    printf("\nOpcount = %d",opcount);               
    
    return 0;
}
