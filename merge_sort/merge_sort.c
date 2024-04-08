#include <stdio.h>
#include <stdlib.h>

void printArray(int A[], int size);

// Function to merge two halves of an array
// Function to merge two halves of an array
void merge(int arr[], int left, int mid, int right) {
    // Tamaño de los sub-arrays
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Crear sub-arrays temporales L y R
    int L[n1], R[n2];

    // Copiar datos a los sub-arrays temporales L[] y R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Índices iniciales para los sub-arrays L, R y el array final arr
    int i = 0, j = 0, k = left;

    // Imprimir información sobre la fusión
    printf("Fusionando y ordenando arr[%d:%d] y arr[%d:%d]\n", left, mid, mid + 1, right);
    printf("Sub-Array izquierdo (L): ");
    printArray(L, n1);
    printf("Sub-Array derecho (R): ");
    printArray(R, n2);

    // Fusionar los sub-arrays temporales en el array final arr
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de L[] si hay alguno
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de R[] si hay alguno
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Imprimir el proceso de fusión y ordenamiento
    printf("Array fusionado y ordenado: ");
    for (int idx = left; idx <= right; idx++) {
        printf("%d ", arr[idx]);
    }
    printf("\n\n");
}

// Function to sort an array using merge sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Encontrar el punto medio del array
        int mid = left + (right - left) / 2;

        // Imprimir información sobre cómo se divide el array original
        printf("Dividiendo arr[%d:%d] en dos mitades\n", left, right);

        // Recursivamente ordenar las dos mitades
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Fusionar las dos mitades ordenadas
        merge(arr, left, mid, right);
    }
}


// Function to print an array
void printArray(int A[], int size) {
    printf("[");
    if (size > 0) {
        printf("%d", A[0]);
        for (int i = 1; i < size; i++) {
            printf(", %d", A[i]);
        }
    }
    printf("]\n");
}


// Main function to test the above functions
int main() {
    int arr[] = {7, 4, 1 ,10 ,2 ,3};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}
