#include <stdio.h>
void printArray(int arr[], int size);

// Función para intercambiar dos elementos de un arreglo
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Función para encontrar el pivote y realizar la partición
int partition(int arr[], int low, int high) {
                printf("-------------Inicio del partition-------------\n\n");
    int pivot = arr[high]; // seleccionamos el último elemento como pivote
                printf("seleccionamos el último elemento como pivote: %i",pivot);
                printf("\n");
    int i = (low - 1); // índice del elemento más pequeño
                    printf("Indice dele elemento mas chico: %i \n", i);

    for (int j = low; j <= high - 1; j++) {
        // Si el elemento actual es menor o igual al pivote
                        printf("Si el elemento actual, %i, es menor o igual al pivote %i...\n", arr[j],pivot);
        if (arr[j] <= pivot) {
            i++; // incrementamos el índice del elemento más pequeño
            swap(&arr[i], &arr[j]); // intercambiamos arr[i] y arr[j]
                            printf("Incrementamos el indice del elemento mas pequeño: %i\nIntercambiamos arr[%i] y arr[%i]", i,i,j);
        }
    }
    swap(&arr[i + 1], &arr[high]); // colocamos el pivote en su posición correcta
                    printf("Colocamos el pivote en su posicion correcta: \n posicion: %i \n pivote: %i \n",i+1,arr[high]);
                    printf("Y devolvemos el indice del pivote: %i\n", i+1);
                    printf("-------------Fin del partition-------------\n\n");
                    printf("Array modificado: ");
                    printArray(arr,2);
                    printf("\n\n");
    return (i + 1); // devolvemos el índice del pivote
    
}

// Función recursiva de QuickSort
void quickSort(int arr[], int low, int high) {
                    printf("-------------Inicio de quickSort-------------\n\n");
                    printf("Si %i < %i ...\n",low,high);
    if (low < high) {
                            printf("Encontremos el indice del pivote: \n");
        // encontramos el índice del pivote
        int pi = partition(arr, low, high);
                            printf("indice del pivote: %i\n",pi);
        // ordenamos los elementos antes y después del pivote
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
                        printf("-------------Fin de quickSort-------------\n\n");
}

// Función para imprimir un arreglo
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Ejemplo de uso
int main() {
    int arr[] = {10, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Arreglo original:\n");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Arreglo ordenado:\n");
    printArray(arr, n);
    return 0;
}
