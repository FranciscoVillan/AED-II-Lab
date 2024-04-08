#include <stdio.h>

void printArray(int arr[], int size) ;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void partition(int arr[], int low, int high, int* pivot) {
    
    *pivot = high;

    int j=low;  

    for (int i = low; i < high; i++)
    {
        if (arr[i]<=arr[*pivot])
        {
            swap(&arr[i],&arr[j]);   
            j++;

        }
    }
    swap(&arr[j],&arr[*pivot]);
    *pivot=j;
}

void quickSort(int arr[], int low, int high) {

    if (high>low)
    {
        int pivot;
        partition(arr,low,high,&pivot);
  
        quickSort(arr,low,pivot-1);
        quickSort(arr,pivot+1,high);
    }
    
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {3,2,5,0,1,8,7,6,9,4};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Arreglo original:\n");
    printArray(arr, n);

    quickSort(arr,0,n-1);

    printf("Arreglo ordenado:\n");
    printArray(arr, n);
    return 0;
}
