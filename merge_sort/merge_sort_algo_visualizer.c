#include <stdio.h>
#include <stdlib.h>


void merge(int arr[], int left[], int right[], int left_length, int right_length)
{
    int i=0,j=0,k=0;

    while (i < left_length && j < right_length)
    {
        if (left[i]<=right[j])
        {
            arr[k]=left[i];
            i++;
        }
        else
        {
            arr[k]=right[j];
            j++;
        }
        k++;
    }

    while (i<left_length)
    {
        arr[k]=left[i];
        i++;
        k++;
    }
    while (j<right_length)
    {
        arr[k]=right[j];
        j++;
        k++;
    }
    
    

    
}

void merge_sort(int arr[], int length)
{
    if (length<2) return;

    int mid = length/2;
    int left[mid];
    int right [length-mid];

    for (int i = 0; i < mid; i++)
    {
        left[i]=arr[i];
    }
    for (int i = mid; i < length; i++)
    {
        right[i-mid]=arr[i];
    }

    merge_sort(left,mid);
    merge_sort(right,length-mid);
    
    merge(arr,left,right,mid,length-mid);
    
    

}



int main ()
{
    int arr[] = {7, 4, 1 ,10 ,2 ,3};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    merge_sort(arr,arr_size);

    printf("Sorted array: ");
    for (int i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }
     
    return 0;
}