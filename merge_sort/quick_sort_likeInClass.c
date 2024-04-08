#include <stdio.h>
void printArray(int arr[], int size);

// Función para intercambiar dos elementos de un arreglo
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Función para encontrar el pivote y realizar la partición
void partition(int arr[], int low, int high, int* pivot) {
    int i = high+1;
    int j = low;

    *pivot = high;

    do
    {
        if (arr[i]<=arr[*pivot])     
        {
            i++;
        }
        else if (arr[j]>=arr[*pivot])
        {
            j--;
        }
        else {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }

        
    } while (i <= j);
    
    swap(&arr[*pivot],&arr[j]);
    *pivot=j;
    
    
}

// Función recursiva de QuickSort
void quickSort(int arr[], int low, int high) {
    
    if (high>low)
    {
        int pivot;
        partition(arr,high,low,&pivot);
        
        quickSort(arr,low,pivot-1);
        quickSort(arr,pivot+1,high);
    }
    
}

// Función para imprimir un arreglo
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Ejemplo de uso
int main() {
    int arr[] = {10, 7,1,7,2,0,12,32};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Arreglo original:\n");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Arreglo ordenado:\n");
    printArray(arr, n);
    return 0;
}
