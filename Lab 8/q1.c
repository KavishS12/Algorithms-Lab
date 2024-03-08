#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int opcount = 0;

void heapify(int arr[],int index) {
    int parent = (index-1)/2;
    while (index>0 && arr[index]>arr[parent]) {
        opcount++;
        swap(&arr[index], &arr[parent]);
        index = parent;
        parent = (index-1)/2;
    }
}

void buildHeapTopDown(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        heapify(arr, i);
    }
}

void printHeap(int arr[], int size) {
    printf("Heap: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
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

    buildHeapTopDown(arr,n);
    printHeap(arr, n);

    printf("Opcount = %d",opcount);  

    return 0;
}
